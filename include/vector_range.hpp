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

void
expand (
  std::size_t _n
){

}

void
advance_insert (
  write_type const & _var
){
this->vec->insert(this->vec->begin(), _var);
}

}; /* vector range */

template <typename T, typename Alloc>
vector_range<T, Alloc>::vector_range (
  std::vector<T, Alloc> & _vec
)
: vec {&_vec}
, pos {1}
{}

template <typename T, typename Alloc>
vector_range<T, Alloc>
range (
  std::vector<T, Alloc> & _vec
){
return vector_range<T, Alloc> {_vec};
}

template <typename T, typename Alloc>
bits::extend_life
< vector_range<T, Alloc>
, std::vector<T, Alloc>
>
range (
  std::vector<T, Alloc> && _vec
){
auto temp
  = bits::extend_life
  < vector_range<T, Alloc>
  , std::vector<T, Alloc>
  >{vector_range<T, Alloc> {_vec}, _vec};

temp.set_range(vector_range<T, Alloc> {_vec});

return temp;
}

} /* range layer */
#endif

