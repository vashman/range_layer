//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_VARIABLE_RANGE_FWD_HPP
#define RANGE_LAYER_VARIABLE_RANGE_FWD_HPP

namespace range_layer {
namespace bits {

/*===========================================================
  variable_range
===========================================================*/
template <typename T>
class variable_range;

}
//bits-------------------------------------------------------

/*===========================================================
  range
===========================================================*/
template <typename T>
variable_range<T>
range (
  T &
);

}
//range layer------------------------------------------------
