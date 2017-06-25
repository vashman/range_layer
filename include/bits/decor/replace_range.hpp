//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REPLACE_RANGE_TCC
#define RANGE_LAYER_REPLACE_RANGE_TCC

#include "transform_range.hpp"

namespace range_layer {
namespace bits {

template <typename T>
struct replace_func {

T old_value;
T new_value;

T operator ()(T const & _value){
  if (_value == this->old_value) return this->new_value;
return _value;
}

}; /* replace func */

template <typename Pred, typename T>
struct replace_if_func {

T new_value;
Pred pred;

T operator ()(T const & _value){
  if (this->pred(_value)) return this->new_value;
return _value;
}

}; /* replace if func */

} /* bits */ } /* range layer */
#endif
