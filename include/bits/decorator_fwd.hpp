// Forward declerations of decorators and suppoting classes.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_DECORATOR_FWD_HPP
#define RANGE_LAYER_BITS_DECORATOR_FWD_HPP

#include <type_traits>
#include <memory>
#include "is_detected.hpp"
#include "range_traits_fwd.hpp"

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

template <typename Range>
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

template <typename Range>
class erase_range;

template <typename Range>
class erase_if_range;

template <typename Range>
class insert_if_range;

template <typename Range>
class insert_range;

template <typename Range>
class back_insert;

template <typename Range>
class shuffle_range;

template <typename Range>
class remove_decorator;

template <typename Range>
class circular_range;

template <typename Range, std::size_t I>
class select;

template <typename Range, typename... Ts>
class extend_life;

template <typename Range>
class checked_range;

template
  <typename Range, typename Decorator, typename... Traits>
class base_decor;

} //bits-----------------------------------------------------

/*===========================================================
  disable decorator
===========================================================*/
template
< typename Range
, typename std
  ::enable_if <range_trait::is_decorator<Range>::value, int>
  ::type = 0
>
auto
disable_decorator (
  Range _range
) -> decltype (disable_decorator(_range.disable()));

/*===========================================================
  disable decorator
===========================================================*/
template
< typename Range
, typename std
  ::enable_if <!range_trait::is_decorator<Range>::value, int>
  ::type = 0
>
Range
disable_decorator (
  Range
);

/*===========================================================
  remove decorator

* Removes the decorator status of the range, making the
  decorator permanent.
===========================================================*/
template <typename Range>
bits::remove_decorator<Range>
remove_decorator (
  Range _range
);

/*===========================================================
  remove if range
===========================================================*/
template <typename Range, typename Pred>
bits::remove_range<Range, Pred>
remove_if_range (
  Range
, Pred
);

/*===========================================================
  remove range
===========================================================*/
template <typename Range, typename T>
bits::remove_range<Range, bits::remove_pred<T>>
remove_range (
  Range
, T
);

/*===========================================================
  input_replace_range
===========================================================*/
template <typename Range, typename T>
auto
input_replace_range (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (input_transform_range
  (_range, bits::replace_func<T>{_old_value, _new_value}));

/*===========================================================
  output_replace_range
===========================================================*/
template <typename Range, typename T>
auto
output_replace_range (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (output_transform_range (
  _range, bits::replace_func<T>{_old_value, _new_value}));

/*===========================================================
  input_replace if range
===========================================================*/
template <typename Range, typename T, typename Pred>
auto
input_replace_if_range (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (input_transform_range (
  _range, bits::replace_if_func<T,Pred>{_new_value, _pred}));

/*===========================================================
  output_replace if range
===========================================================*/
template <typename Range, typename T, typename Pred>
auto
output_replace_if_range (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (output_transform_range (
  _range, bits::replace_if_func<T,Pred>{_new_value, _pred}));

/*===========================================================
  output_transform_range
===========================================================*/
template <typename Range, typename Func>
bits::output_transform_range<Func, Range>
output_transform_range (
  Range
, Func
);

/*===========================================================
  input_transform_range
===========================================================*/
template <typename Range, typename Func>
bits::input_transform_range<Func, Range>
input_transform_range (
  Range
, Func
);

/*===========================================================
  transform_range
===========================================================*/
template <typename Range, typename Func>
bits::transform_range<Func, Range>
transform_range (
  Range
, Func
);

/*===========================================================
  reverse_range
===========================================================*/
template <typename Range>
bits::reverse_range<Range>
reverse_range (
  Range
);

/*===========================================================
  sub_range_n
===========================================================*/
template <typename Range>
bits::sub_range_n<Range>
sub_range_n (
  Range
, typename range_trait::size_type<Range>::type
);

/*===========================================================
  circular_range
===========================================================*/
template <typename Range>
bits::circular_range<Range>
circular_range (
  Range
);

/*===========================================================
  disable_input
===========================================================*/
template <typename Range>
bits::disable_input<Range>
disable_input (
  Range
);

/*===========================================================
  disable_output
===========================================================*/
template <typename Range>
bits::disable_output<Range>
disable_output (
  Range
);

/*===========================================================
  select
===========================================================*/
template <std::size_t I, typename Range>
bits::select<Range, I>
select (
  Range
);

/*===========================================================
  extend_life
===========================================================*/
template <typename Range, typename... Ts>
bits::extend_life<Range, Ts...>
extend_life (
  Range
, Ts &&...
);

/*===========================================================
  sub_range
===========================================================*/
template <typename Range, typename Sentinal>
bits::sub_range<Range, Sentinal>
sub_range (
  Range
, Sentinal
);

/*===========================================================
  checked_range
===========================================================*/
template <typename Range>
bits::checked_range<Range>
checked_range (
  Range
);

/*===========================================================
  back_insert
===========================================================*/
template <typename Range>
bits::back_insert<Range>
back_insert (
  Range
);

/*===========================================================
  extend_range
===========================================================*/
template <typename T, typename Func>
auto
extend_range (
  T && _con
, Func _func
) -> decltype(extend_life(_func(_con), std::move(_con)));

} //range layer----------------------------------------------
#endif

