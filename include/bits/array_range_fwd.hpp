//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ARRAY_RANGE_FWD_HPP
#define RANGE_LAYER_ARRAY_RANGE_FWD_HPP

#include "decorator.hpp"

namespace range_layer {

/*===========================================================
  array_range
===========================================================*/
template <typename T>
class array_range;

/*===========================================================
  range
===========================================================*/
template <typename T>
array_range <T>
range (
  T *
);

/*===========================================================
  range
===========================================================*/
template <typename T, std::size_t N>
array_range <T>
range (
  std::array<T, N> &
);

/*===========================================================
  range
===========================================================*/
template <typename T, std::size_t N>
auto
range (
  std::array<T, N> && _con
) -> decltype(extend_life(range(_con), std::move(_con)));

/*===========================================================
  operator ==
===========================================================*/
template <typename T>
bool
operator == (
  array_range<T> const &
, sentinel::writable const &
);

} //range layer----------------------------------------------
#endif

