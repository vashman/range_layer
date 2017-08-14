//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_VECTOR_RANGE_HPP
#define RANGE_LAYER_VECTOR_RANGE_HPP

#include <vector>
#include "range_traits.hpp"
#include "bits/decor/extend_life.hpp"

namespace range_layer {
namespace bits {

template <typename T, typename Alloc>
struct vector_range;

template <typename T, typename Alloc>
vector_range<T, Alloc>
range (
  std::vector<T, Alloc> &
);

template <typename T, typename Alloc>
bits::extend_life
< vector_range<T, Alloc>
, std::vector<T, Alloc>
>
range (
  std::vector<T, Alloc> &&
);

template <typename T, typename Alloc>
struct vector_range {

private:

std::vector<T, Alloc> * vec;
std::size_t pos;

public:

using read_type = T;
using write_type = read_type;

vector_range (
  std::vector<T, Alloc> &
);

vector_range (vector_range const &) = default;
vector_range (vector_range &&) = default;
vector_range & operator = (vector_range const &) = default;
vector_range & operator = (vector_range &&) = default;
~vector_range() = default;

vector_range &
save (){
return *this;
}

std::size_t
size (
) const {
return this->vec->size();
}

std::size_t
position (
) const {
return this->pos;
}

T const &
operator * (){
return *this->vec[this->pos-1];
}

void
operator = (
  T const & _var
){
(*(this->vec))[this->pos-1] = _var;
}

vector_range &
operator ++ (
){
++this->pos;
return *this;
}

vector_range &
operator -- (
){
--this->pos;
return *this;
}

vector_range &
operator += (
  std::size_t const _n
){
this->pos += _n;
return *this;
}

vector_range &
operator -= (
  std::size_t const _n
){
this->pos -= _n;
return *this;
}

bool
operator == (
  sentinel::readable const _sen
) const {
return this->pos <= this->vec->size();
}

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


}; /* vector range */

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

} /* bits */

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
bits::extend_life
< bits::vector_range<T, Alloc>
, std::vector<T, Alloc>
>
range (
  std::vector<T, Alloc> && _vec
){
auto temp
  = bits::extend_life
  < bits::vector_range<T, Alloc>
  , std::vector<T, Alloc>
  >{bits::vector_range<T, Alloc> {_vec}, _vec};

temp.set_range(bits::vector_range<T, Alloc> {_vec});

return temp;
}

} /* range layer */
#endif

