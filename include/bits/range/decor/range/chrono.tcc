// ranges for std::chrono types

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_CHRONO_TCC
#define RANGE_LAYER_BITS_CHRONO_TCC

namespace range_layer {

/*===========================================================
  range
===========================================================*/
template <typename Clock>
bits::clock_range<Clock>
range (
  std::chrono::time_point<Clock> _point
){
return bits::clock_range<Clock>{_point};
}

} // range layer--------------------------------------------
#endif

