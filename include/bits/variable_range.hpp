//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_VARIABLE_RANGE_HPP
#define RANGE_LAYER_VARIABLE_RANGE_HPP

#include "../range_traits.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  variable_range
===========================================================*/
template <typename T>
class variable_range {

T * var;

public:

using read_type = T;
using write_type = read_type;

/*===========================================================
  ctor
===========================================================*/
variable_range (
  T &
);

variable_range (variable_range const &) = default;
variable_range (variable_range &&) = default;
variable_range & operator = (variable_range &&) = default;
~variable_range() = default;

variable_range &
operator = (
  variable_range const &
) = default;

/*===========================================================
  size
===========================================================*/
constexpr
std::size_t
size (
) const {
return 1;
}

/*===========================================================
  position
===========================================================*/
constexpr
std::size_t
position (
) const {
return 0;
}

/*===========================================================
  operator *
===========================================================*/
T const &
operator * (){
return *this->var;
}

/*===========================================================
  operator =
===========================================================*/
void
operator = (
  T const & _var
){
this->var = _var;
}

/*===========================================================
  operator ++
===========================================================*/
variable_range &
operator ++ (
){
this->var = nullptr;
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const & _sen
) const {
return (this->var != nullptr);
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::writable const & _sen
) const {
return *this == sentinel::readable{};
}

};
//variable range---------------------------------------------

/*===========================================================
  vector_range:: ctor
===========================================================*/
template <typename T>
variable_range<T>::variable_range (
  T & _var
)
: var {&_var}
{}

}
//bits-------------------------------------------------------

/*===========================================================
  range
===========================================================*/
template <typename T>
bits::variable_range<T>
range (
  T & _var
){
return bits::variable_range<T> {_var};
}

}
//range layer------------------------------------------------
#endif

