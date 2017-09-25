//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_VECTOR_RANGE_HPP
#define RANGE_LAYER_VECTOR_RANGE_HPP

#include <vector>
#include <memory>
#include "../../range_traits.hpp"

namespace range_layer {
namespace bits {

template <typename T, bool Is_Unique>
struct range_ptr {

// Is deleted by default.
using type = std::unique_ptr<T>

};

template <typename T>
struct range_ptr <T, false> {

using type = std::shared_ptr<const T>;

};

/*===========================================================
  vector_range
===========================================================*/
template <typename T, typename Alloc, bool Is_Unique>
struct vector_range;

/*===========================================================
  mut_vector_range
===========================================================*/
template <typename T, typename Alloc>
struct mut_vector_range <T, Alloc>;

/*===========================================================
  vector_range

  * Read only
  * Shared pointer to container.
===========================================================*/
template <typename T, typename Alloc, bool Is_Unique>
class vector_range {

protected:

range_ptr<Is_Unique>::type con;
std::size_t pos;

public:

/*===========================================================
  copy ctor
===========================================================*/
vector_range (vector_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
vector_range (vector_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
vector_range & operator = (vector_range const &) = default;

/*===========================================================
  move assignment operator
===========================================================*/
vector_range & operator = (vector_range &&) = default;

/*===========================================================
  dtor
===========================================================*/
~vector_range() = default;

/*===========================================================
  size
===========================================================*/
std::size_t
size () const;

/*===========================================================
  position
===========================================================*/
std::size_t
position () const;

/*===========================================================
  read
===========================================================*/
T const &
read (
){
return (*this->vec)[this->pos-1];
}

/*===========================================================
  operator ++
===========================================================*/
vector_range &
operator ++ (
){
++this->pos;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
vector_range &
operator -- (
){
--this->pos;
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
vector_range &
operator += (
  std::size_t const _n
){
this->pos += _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
vector_range &
operator -= (
  std::size_t const _n
){
this->pos -= _n;
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const _sen
) const {
return this->pos <= this->vec->size();
}

}; //--------------------------------------------vector range

/*===========================================================
  mut_vector_range
===========================================================*/
template <typename T, typename Alloc>
class mut_vector_range
: public vector_range<T, Alloc, true>
{

public:

using write_type = T;

/*===========================================================
  ctor
===========================================================*/
mut_vector_range (
  std::unique_ptr<std::vector<T, Alloc>, Deleter>
);

/*===========================================================
  save
===========================================================*/
/*vector_range
save () const;*/

/*===========================================================
  write
===========================================================*/
void
write (
  T const & _var
){
(*(this->vec))[this->pos-1] = _var;
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::writable const _sen
) const {
return *this == sentinel::readable{};
}

/*===========================================================
  expand
===========================================================*/
vector_range
expand (
  std::size_t _n
){
_n += this->vec->size();
this->vec->resize(_n);
return *this;
}

/*===========================================================
  shrink
===========================================================*/
vector_range
shrink (
  std::size_t _n
){
_n = this->vec->size() - _n;
this->vec->resize(_n);
return *this;
}

/*===========================================================
  insert
===========================================================*/
vector_range
insert (
  write_type const & _var
){
this->vec->insert(this->vec->begin() + this->pos, _var);
return *this;
}

/*===========================================================
  erase_all
===========================================================*/
mut_vector_range &
erase_all ();

/*===========================================================
  erase
===========================================================*/
mut_vector_range &
erase ();

}; //--------------------------------------------vector range

/*===========================================================
  vector_range:: ctor
===========================================================*/
template <typename T, typename Alloc, bool Is_Unique>
vector_range<T, Alloc, Is_Unique>::vector_range (
  std::unique_ptr<std::vector<T, Alloc>, Deleter> _vec
)
: vec {_vec}
, pos {1}
{}

/*===========================================================
  vector_range:: erase
===========================================================*/
template <typename T, typename Alloc>
vector_range<T, Alloc, true> &
vector_range<T, Alloc, true>::erase (
){
this->vec->erase(this->vec->begin() + this->pos);
return *this;
}

/*===========================================================
  vector_range:: erase_all
===========================================================*/
template <typename T, typename Alloc, typename Deleter>
vector_range<T, Alloc, Deleter> &
vector_range<T, Alloc, Deleter>::erase_all (
){
this->vec->clear();
return *this;
}

/*===========================================================
  vector_range:: size
===========================================================*/
template <typename T, typename Alloc, bool Is_Unique>
std::size_t
vector_range<T, Alloc, Is_Unique>::size (
) const {
return this->vec->size();
}

/*===========================================================
  vector_range:: position
===========================================================*/
template <typename T, typename Alloc, bool Is_Unique>
std::size_t
vector_range<T, Alloc, Is_Unique>::position (
) const {
return this->pos;
}

/*===========================================================
  vector_range:: save
===========================================================*/
/*template <typename T, typename Alloc, typename Deleter>
vector_range<T, Alloc, Deleter>
vector_range<T, Alloc, Deleter>::save (
) const {
vector_range<T, Alloc, Deleter> {Ptr{}}
return *this;
}*/

} //-----------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc, typename Deleter>
bits::vector_range<T, Alloc>
range (
  std::vector<T, Alloc> &
);

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc, typename Deleter>
auto
range (
  std::vector<T, Alloc> && _con
);

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc, typename Deleter>
auto
range (
  std::vector<T, Alloc> & _vec
){
return xrange (

return type{_vec};
}

/*===========================================================
  move range
===========================================================*/
template <typename T, typename Alloc, typename Deleter>
bits::vector_range<T, Alloc>
range (
  std::vector<T, Alloc> && _vec
){
auto lam = [](auto * _con){delete _con;}
using type = bits::vector_range<T, Alloc, decltype(lam)>;
bits::range_assert<type>();
bits::read_assert<type>();
bits::write_assert<type>();
bits::not_decorator_assert<type>();
bits::shrinkable_assert<type>();
bits::erase_assert<type>();

return bits::vector_range<T, Alloc, Deleter>
{std::unique_ptr<std::vector<T, Alloc>, Deleter>
{new std::vector<T, Alloc>{_vec}, lam};
}

} //----------------------------------------------range layer
#endif

