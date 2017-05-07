//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REPLACE_RANGE_TCC
#define RANGE_LAYER_REPLACE_RANGE_TCC

#include "range.hpp"
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

};

} /* bits */

template <typename Range, typename T>
using input_replace_range
  = input_transform_range<bits::replace_func<T>, Range>;

template <typename Range, typename T>
using output_replace_range
  = output_transform_range<bits::replace_func<T>, Range>;

template <typename Range, typename T>
input_replace_range<Range, T>
make_input_replace_range (
  Range _range
, T _old_value
, T _new_value
){
return input_replace_range<Range,T>
  {_range, bits::replace_func<T>{_old_value, _new_value}};
}

template <typename Range, typename T>
output_replace_range<Range, T>
make_output_replace_range (
  Range _range
, T _old_value
, T _new_value
){
return output_replace_range<Range,T>
  {_range, bits::replace_func<T>{_old_value, _new_value}};
}

} /* range layer */
#endif
