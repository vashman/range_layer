// ranges for std::chrono types

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_CHRONO_HPP
#define RANGE_LAYER_BITS_CHRONO_HPP

#include <chrono>
#include "../range.hpp"
#include "chrono_fwd.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  clock_range
===========================================================*/
template <typename Clock>
class clock_range {

std::chrono::time_point<Clock> point;

public:

/*===========================================================
  ctor
===========================================================*/
clock_range (
  std::chrono::time_point<Clock> _point
)
: point {_point}
{}

/*===========================================================
  copy ctor
===========================================================*/
clock_range (clock_range const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
clock_range & operator = (clock_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
clock_range (clock_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
clock_range & operator = (clock_range &&) = default;

/*===========================================================
  dtor
===========================================================*/
~clock_range() = default;

/*===========================================================
  operator *
===========================================================*/
std::chrono::time_point<Clock>
operator * (
){
return this->point;
}

/*===========================================================
  operator ++
===========================================================*/
clock_range &
operator ++ (
){
++this->point;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
clock_range &
operator -- (
){
--this->point;
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const &
) const {
return true;
}

}; // clock range-------------------------------------------

} // bits---------------------------------------------------
} // range layer--------------------------------------------
#endif
#include "chrono.tcc"

