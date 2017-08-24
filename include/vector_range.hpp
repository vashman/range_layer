//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_VECTOR_RANGE_HPP
#define RANGE_LAYER_VECTOR_RANGE_HPP

#include <vector>
#include "range_traits.hpp"
#include "bits/decorator.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  vector_range
===========================================================*/
template <typename T, typename Alloc>
struct vector_range;

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
vector_range<T, Alloc>
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
) -> decltype(range_layer::extend_range(std::move(_con)));

/*===========================================================
  vector_range
===========================================================*/
template <typename T, typename Alloc>
struct vector_range {

private:

std::vector<T, Alloc> * vec;
std::size_t pos;

public:

using read_type = T;
using write_type = read_type;

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
save (
){
return *this;
}

/*===========================================================
  size
===========================================================*/
std::size_t
size (
) const {
return this->vec->size();
}

/*===========================================================
  position
===========================================================*/
std::size_t
position (
) const {
return this->pos;
}

/*===========================================================
  operator *
===========================================================*/
T const &
operator * (){
return *this->vec[this->pos-1];
}

/*===========================================================
  operator =
===========================================================*/
void
operator = (
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
vector_range
erase_all (
){
this->vec->clear();
return *this;
}

/*===========================================================
  erase
===========================================================*/
vector_range
erase (
){
this->vec->erase(this->vec->begin() + this->pos);
return *this;
}

}; //vector range--------------------------------------------

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

} //bits-----------------------------------------------------

/*===========================================================
  range
===========================================================*/
template <typename T, typename Alloc>
bits::vector_range<T, Alloc>
range (
  std::vector<T, Alloc> & _vec
){
return bits::vector_range<T, Alloc> {_vec};
}

/*===========================================================
  move range
===========================================================*/
template <typename T, typename Alloc>
auto
range (
  std::vector<T, Alloc> && _con
) -> decltype(extend_life(range(_con), std::move(_con))) {
auto temp = extend_life(range(_con), std::move(_con));
temp.set_range(range(* std::get<0>(temp.variable).get()));
return temp;
}

} //range layer----------------------------------------------
#endif

