//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DECORATOR_FWD_HPP
#define RANGE_LAYER_DECORATOR_FWD_HPP

namespace range_layer {
namespace bits {

template <typename Range, typename Pred>
class remove_range;

template <typename T>
struct remove_pred;

template <typename T>
struct replace_func;

template <typename Pred, typename T>
struct replace_if_func;

template <typename Func, typename Range>
class transform_range;

template <typename Func, typename Range>
class input_transform_range;

template <typename Func, typename Range>
class output_transform_range;

template <typename Range>
class reverse_range;

template <typename Range, typename S = std::size_t>
class sub_range_n;

template <typename Range, typename Sentinel>
class sub_range;

template <typename Range>
class disable_input;

template <typename Range>
class disable_output;

template <typename Range>
class disable_reverse;

template <typename Range>
class disable_advance;

template <typename Range>
class disable_non_linear;

} /* bits */

template <typename Range>
struct is_decorator;

template <
  typename Range
, typename
  std::enable_if<is_decorator<Range>::value, int>::type = 0 >
auto
disable_decorator (
  Range _range
) -> decltype (disable_decorator(_range.disable()));

template <
  typename Range
, typename
  std::enable_if<!is_decorator<Range>::value, int>::type = 0>
Range
disable_decorator (
  Range
);

template <typename Range>
auto
remove_decorator (
  Range _range
) -> decltype (_range.disable());

template <typename Range, typename Pred>
bits::remove_range<Range, Pred>
remove_if_range (
  Range
, Pred
);

template <typename Range, typename T>
bits::remove_range<Range, bits::remove_pred<T>>
remove_range (
  Range
, T
);

template <typename Range, typename T>
auto
input_replace_range (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (input_transform_range
  (_range, bits::replace_func<T>{_old_value, _new_value}));

template <typename Range, typename T>
auto
output_replace_range (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (output_transform_range (
  _range, bits::replace_func<T>{_old_value, _new_value}));

template <typename Range, typename T, typename Pred>
auto
input_replace_if_range (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (input_transform_range (
  _range, bits::replace_if_func<T,Pred>{_new_value, _pred}));

template <typename Range, typename T, typename Pred>
auto
output_replace_if_range (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (output_transform_range (
  _range, bits::replace_if_func<T,Pred>{_new_value, _pred}));

template <typename Range, typename Func>
bits::output_transform_range<Func, Range>
output_transform_range (
  Range
, Func
);

template <typename Range, typename Func>
bits::input_transform_range<Func, Range>
input_transform_range (
  Range
, Func
);

template <typename Range, typename Func>
bits::transform_range<Func, Range>
transform_range (
  Range
, Func
);

template <typename Range>
bits::reverse_range<Range>
reverse_range (
  Range
);

template <typename Range, typename N>
bits::sub_range_n<Range, N>
sub_range_n (
  Range
, N
);

/*template <typename Range, typename Sentinal>
bits::sub_range<Range>
sub_range (
  Range _range
, Sentinal _sentinal
){
return bits::sub_range<Range>{_range, _sentinal};
}*/

} /* range layer */
#endif