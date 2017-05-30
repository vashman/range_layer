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

template <typename Pred, typename T>
struct replace_if_func {

T new_value;
Pred pred;

T operator ()(T const & _value){
  if (this->pred(_value)) return this->new_value;
return _value;
}

};

} /* bits */

template <typename Range, typename T>
auto
input_replace_range (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (input_transform_range
  (_range, bits::replace_func<T>{_old_value, _new_value}))
{
return input_transform_range
  (_range, bits::replace_func<T>{_old_value, _new_value});
}

template <typename Range, typename T>
auto
output_replace_range (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (output_transform_range (
  _range, bits::replace_func<T>{_old_value, _new_value}))
{
return output_transform_range (
  _range, bits::replace_func<T>{_old_value, _new_value});
}

template <typename Range, typename T, typename Pred>
auto
input_replace_if_range (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (input_transform_range
  (_range, bits::replace_if_func<T,Pred>{_new_value, _pred}))
{
return input_transform_range
  (_range, bits::replace_if_func<T,Pred>{_new_value, _pred});
}

template <typename Range, typename T, typename Pred>
auto
output_replace_if_range (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (output_transform_range (
  _range, bits::replace_if_func<T,Pred>{_new_value, _pred}))
{
return output_transform_range (
  _range, bits::replace_if_func<T, Pred>{_new_value, _pred});
}

} /* range layer */
#endif
