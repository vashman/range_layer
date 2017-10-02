//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_VECTOR_RANGE_HPP
#define RANGE_LAYER_VECTOR_RANGE_HPP

#include <vector>
#include "range.hpp"

namespace range_layer {

namespace bits {

/*===========================================================
  range_helper
===========================================================*/
template <typename Ptr, typename T, typename Alloc>
struct range_helper<Ptr, std::vector<T, Alloc>> {

protected:

Ptr handle;
std::size_t pos;

/*===========================================================
  ctor
===========================================================*/
range_helper (
  Ptr _handle
, std::size_t _pos
)
: handle {move(_handle)}
, pos {_pos}
{}

public:

/*===========================================================
  size
===========================================================*/
std::size_t
size () const {
return this->handle->size();
}

/*===========================================================
  position
===========================================================*/
std::size_t
position () const {
return this->pos;
}

/*===========================================================
  read
===========================================================*/
T const &
read (
){
return (*this->handle)[this->pos-1];
}

/*===========================================================
  operator ++
===========================================================*/
range<Ptr> &
operator ++ (
){
++this->pos;
return static_cast<range<Ptr>&>(*this);
}

/*===========================================================
  operator --
===========================================================*/
range<Ptr> &
operator -- (
){
--this->pos;
return static_cast<range<Ptr>&>(*this);
}

/*===========================================================
  operator +=
===========================================================*/
range<Ptr> &
operator += (
  std::size_t const _n
){
this->pos += _n;
return static_cast<range<Ptr>&>(*this);
}

/*===========================================================
  operator -=
===========================================================*/
range<Ptr> &
operator -= (
  std::size_t const _n
){
this->pos -= _n;
return static_cast<range<Ptr>&>(*this);
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const & _sen
) const {
return this->pos <= this->handle->size();
}

};

} //-----------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
class range <std::shared_ptr<const std::vector<T, Alloc>>>
: public bits::range_helper
< std::shared_ptr<const std::vector<T, Alloc>>
, std::vector<T, Alloc>
>
{

public:

range (
  std::shared_ptr<const std::vector<T, Alloc>> _ptr
)
: range::range_helper {_ptr, 1}
{}

}; //-------------------------------const shared vector range

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
class range <std::shared_ptr<std::vector<T, Alloc>>>
: public range <std::shared_ptr<const std::vector<T, Alloc>>>
{

public:

range (
  std::shared_ptr<std::vector<T, Alloc>> _ptr
)
: range<std::shared_ptr<const std::vector<T, Alloc>>> {_ptr}
{}

}; //-------------------------------------shared vector range

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc, typename Deleter>
class range<std::unique_ptr<std::vector<T, Alloc>, Deleter>>
: public bits::range_helper
< std::unique_ptr<std::vector<T, Alloc>, Deleter>
, std::vector<T, Alloc>
>
{

public:

/*===========================================================
  ctor
===========================================================*/
range (
  std::unique_ptr<std::vector<T, Alloc>, Deleter> _ptr
)
: range::range_helper {move(_ptr), 1}
{}

using write_type = T;

/*===========================================================
  write
===========================================================*/
void
write (
  T const & _var
){
(*(this->handle))[this->pos-1] = _var;
}

/*===========================================================
  expand
===========================================================*/
range
expand (
  std::size_t _n
){
_n += this->handle->size();
this->handle->resize(_n);
return *this;
}

/*===========================================================
  shrink
===========================================================*/
range
shrink (
  std::size_t _n
){
_n = this->handle->size() - _n;
this->handle->resize(_n);
return *this;
}

/*===========================================================
  insert
===========================================================*/
range
insert (
  write_type const & _var
){
this->handle->insert
  (this->handle->begin() + this->pos, _var);
return *this;
}

/*===========================================================
  erase_all
===========================================================*/
range &
erase_all (){
this->handle->clear();
return *this;
}

/*===========================================================
  erase
===========================================================*/
range &
erase () {
this->handle->erase(this->handle->begin() + this->pos);
return *this;
}

}; //-------------------------------------unique vector range

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
class range <std::vector<T, Alloc>>
: public range<std::unique_ptr<std::vector<T, Alloc>>>
{

public:

/*===========================================================
  ctor
===========================================================*/
range (
  std::vector<T, Alloc> _ptr
)
: range<std::unique_ptr<std::vector<T, Alloc>>>
    { std::make_unique<std::vector<T, Alloc>>(move(_ptr)) }
{}

}; //-------------------------------------------vector range

/*===========================================================
  range:: operator ==
===========================================================*/
template <typename T, typename Alloc, typename Deleter>
bool
operator == (
  range<std::unique_ptr<std::vector<T, Alloc>, Deleter>>
  const & _lhs
, sentinel::writable const & _sen
){
return _lhs == sentinel::readable{};
}

} //----------------------------------------------range layer
#endif

