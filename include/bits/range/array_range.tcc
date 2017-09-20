//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ARRAY_RANGE_TCC
#define RANGE_LAYER_ARRAY_RANGE_TCC

#include "../decorator.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  ctor
===========================================================*/
template <typename T>
array_range<T>::array_range (
  T * _array
, T * _end
)
: array (_array)
, pos {_array}
, end_pos {_end}
{}

/*===========================================================
  operator ==
===========================================================*/
template <typename T>
bool
array_range<T>::operator == (
  sentinel::readable const & _rhs
) const {
return this->pos != this->end_pos;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename T>
bool
operator == (
  array_range<T> const & _lhs
, sentinel::writable const & _rhs
){
return _lhs == sentinel::readable{};
}

} //-----------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
template <typename T>
bits::array_range <T>
range (
  T * _ptr
, std::size_t _size
){
return bits::array_range<T>{_ptr, _ptr + _size};
}

/*===========================================================
  range
===========================================================*/
template <typename T, std::size_t N>
bits::array_range <T>
range (
  std::array<T, N> & _arr
){
return bits::array_range<T>{_arr.data(), _arr.data() + N};
}

/*===========================================================
  move range
===========================================================*/
template <typename T, std::size_t N>
auto
range (
  std::array<T, N> && _con
){
auto temp
  = xrange(range(_con), make_extend_life(std::move(_con)));

temp.set_range(range(* std::get<0>(temp.variable).get()));
return temp;
}

} //----------------------------------------------range layer
#endif

