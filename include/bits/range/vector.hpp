//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_VECTOR_RANGE_HPP
#define RANGE_LAYER_VECTOR_RANGE_HPP

#include <vector>
#include "../../range_traits.hpp"
#include "../decorator.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  vector_range
===========================================================*/
template <typename T, typename Alloc>
struct vector_range;

/*===========================================================
  vector_range
===========================================================*/
template <typename T, typename Alloc>
class vector_range {

std::vector<T, Alloc> * vec;
std::size_t pos;

public:

using write_type = T;

/*===========================================================
  ctor
===========================================================*/
vector_range (
  std::vector<T, Alloc> &
);

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
  save
===========================================================*/
vector_range &
save ();

/*===========================================================
  size
===========================================================*/
std::size_t
size () const;

/*===========================================================
  position
===========================================================*/
std::size_t
position (
) const {
return this->pos;
}

/*===========================================================
  read
===========================================================*/
T const &
read (){
return (*this->vec)[this->pos-1];
}

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
vector_range &
erase_all ();

/*===========================================================
  erase
===========================================================*/
vector_range &
erase ();

}; //--------------------------------------------vector range

/*===========================================================
  vector_range:: ctor
===========================================================*/
template <typename T, typename Alloc>
vector_range<T, Alloc>::vector_range (
  std::vector<T, Alloc> & _vec
)
: vec {&_vec}
, pos {1}
{}

/*===========================================================
  vector_range:: erase
===========================================================*/
template <typename T, typename Alloc>
vector_range<T, Alloc> &
vector_range<T, Alloc>::erase (
){
this->vec->erase(this->vec->begin() + this->pos);
return *this;
}

/*===========================================================
  vector_range:: erase_all
===========================================================*/
template <typename T, typename Alloc>
vector_range<T, Alloc> &
vector_range<T, Alloc>::erase_all (
){
this->vec->clear();
return *this;
}

/*===========================================================
  vector_range:: size
===========================================================*/
template <typename T, typename Alloc>
std::size_t
vector_range<T, Alloc>::size (
) const {
return this->vec->size();
}

/*===========================================================
  vector_range:: save
===========================================================*/
template <typename T, typename Alloc>
vector_range<T, Alloc> &
vector_range<T, Alloc>::save (
){
return *this;
}

} //-----------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
bits::vector_range<T, Alloc>
range (
  std::vector<T, Alloc> &
);

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
auto
range (
  std::vector<T, Alloc> && _con
);

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
bits::vector_range<T, Alloc>
range (
  std::vector<T, Alloc> & _vec
){
using type = bits::vector_range<T, Alloc>;
bits::range_assert<type>();
bits::read_assert<type>();
bits::write_assert<type>();
bits::not_decorator_assert<type>();
bits::shrinkable_assert<type>();
bits::erase_assert<type>();

return type{_vec};
}

/*===========================================================
  move range
===========================================================*/
template <typename T, typename Alloc>
auto
range (
  std::vector<T, Alloc> && _con
){
auto temp
  = xrange (range(_con), make_extend_life(std::move(_con));

temp.set_range(range(* std::get<0>(temp.variable).get()));
return temp;
}

} //----------------------------------------------range layer
#endif

