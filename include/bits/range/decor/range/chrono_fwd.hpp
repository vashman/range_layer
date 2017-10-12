// ranges for std::chrono types

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_CHRONO_FWD_HPP
#define RANGE_LAYER_BITS_CHRONO_FWD_HPP

#include <chrono>

namespace range_layer {
namespace bits {

/*===========================================================
  clock_range
===========================================================*/
template <typename Clock>
class clock_range;

} // bits---------------------------------------------------

/*===========================================================
  range
===========================================================*/
template <typename Clock>
bits::clock_range<Clock>
range (
  std::chrono::time_point<Clock>
);

} // range layer--------------------------------------------
#endif

