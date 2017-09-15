//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DECORATOR_TCC
#define RANGE_LAYER_DECORATOR_TCC

#include "decor/transform_range.tcc"
#include "decor/input_transform_range.tcc"
#include "decor/output_transform_range.tcc"
#include "algo/asserts.hpp"

namespace range_layer {

/*===========================================================
  disable_decorator
===========================================================*/
template
< typename Range
, typename std
  ::enable_if <range_trait::is_decorator<Range>::value, int>
  ::type
>
auto
disable_decorator (
  Range _range
) -> decltype (disable_decorator(_range.disable())) {
bits::range_assert<Range>();
bits::decorator_assert<Range>();

return disable_decorator(_range.disable());
}

/*===========================================================
  disable_decorator
===========================================================*/
template
< typename Range
, typename std
  ::enable_if<! range_trait::is_decorator<Range>::value, int>
  ::type
>
Range
disable_decorator (
  Range _range
){
bits::range_assert<Range>();
bits::not_decorator_assert<Range>();

return _range;
}

/*===========================================================
  remove_decorator
===========================================================*/
template <typename Range>
bits::remove_decorator<Range>
remove_decorator (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::remove_decorator<Range>>();
bits::not_decorator_assert<bits::remove_decorator<Range>>();

return bits::remove_decorator<Range>(_range);
}

/*===========================================================
  remove_if
===========================================================*/
template <typename Range, typename Pred>
bits::remove_range<Range, Pred>
remove_if (
  Range _range
, Pred _pred
){
using type = bits::remove_range<Range, Pred>;
bits::range_assert<Range>();
bits::predicate_assert<Pred>();
bits::range_assert<type>();

return bits::remove_range<Range, Pred>{_range, _pred};
}

/*===========================================================
  remove
===========================================================*/
template <typename Range, typename T>
auto
remove (
  Range _range
, T _value
) -> decltype (
  remove_if(_range, bits::remove_pred<T>{_value})
){
return remove_if(_range, bits::remove_pred<T>{_value});
}

/*===========================================================
  input_replace
===========================================================*/
template <typename Range, typename T>
auto
input_replace (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (input_transform
  (_range, bits::replace_func<T>{_old_value, _new_value}))
{
bits::range_assert<Range>();
bits::read_assert<Range>();

return input_transform
  (_range, bits::replace_func<T>{_old_value, _new_value});
}

/*===========================================================
  output_replace
===========================================================*/
template <typename Range, typename T>
auto
output_replace (
  Range _range
, T _old_value
, T _new_value
)
-> decltype (output_transform (
  _range, bits::replace_func<T>{_old_value, _new_value}))
{
bits::range_assert<Range>();
bits::write_assert<Range>();

return output_transform (
  _range, bits::replace_func<T>{_old_value, _new_value});
}

/*===========================================================
  input_replace_if
===========================================================*/
template <typename Range, typename T, typename Pred>
auto
input_replace_if (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (input_transform
  (_range, bits::replace_if_func<T,Pred>{_new_value, _pred}))
{
bits::range_assert<Range>();
bits::read_assert<Range>();

return input_transform
  (_range, bits::replace_if_func<T,Pred>{_new_value, _pred});
}

/*===========================================================
  output_replace_if
===========================================================*/
template <typename Range, typename T, typename Pred>
auto
output_replace_if (
  Range _range
, Pred _pred
, T _new_value
)
-> decltype (output_transform (
  _range, bits::replace_if_func<T,Pred>{_new_value, _pred}))
{
bits::range_assert<Range>();
bits::write_assert<Range>();

return output_transform (
  _range, bits::replace_if_func<T, Pred>{_new_value, _pred});
}

/*===========================================================
  transform
===========================================================*/
template <typename Range, typename Func>
bits::transform_range<Func, Range>
transform (
  Range _range
, Func _func
){
bits::range_assert<Range>();
bits::range_assert<bits::transform_range<Func, Range>>();

return bits::transform_range<Func, Range>{_range, _func};
}

/*===========================================================
  input_transform
===========================================================*/
template <typename Range, typename Func>
bits::input_transform_range<Func, Range>
input_transform (
  Range _range
, Func _func
){
bits::range_assert<Range>();
bits::read_assert<Range>();
bits::range_assert
  <bits::input_transform_range<Func, Range>>();
bits::read_assert
  <bits::input_transform_range<Func, Range>>();

return bits::input_transform_range<Func, Range>
  {_range, _func};
}

/*===========================================================
  output_transform
===========================================================*/
template <typename Range, typename Func>
bits::output_transform_range<Func, Range>
output_transform (
  Range _range
, Func _func
){
bits::range_assert<Range>();
bits::write_assert<Range>();
bits::range_assert
  <bits::output_transform_range<Func, Range>>();
bits::write_assert
  <bits::output_transform_range<Func, Range>>();

return bits::output_transform_range<Func, Range>
  {_range, _func};
}

/*===========================================================
  backward
===========================================================*/
template <typename Range>
bits::reverse_range<Range>
backward (
  Range _range
){
bits::range_assert<Range>();
bits::reversible_assert<Range>();
bits::range_assert<bits::reverse_range<Range>>();

return bits::reverse_range<Range>{_range};
}

/*===========================================================
  sub range n
===========================================================*/
template <typename Range>
bits::sub_range_n<Range>
sub_range_n (
  Range _range
, typename range_trait::size_type<Range>::type _n
){
bits::range_assert<Range>();
bits::range_assert<bits::sub_range_n<Range>>();

return bits::sub_range_n<Range>{_range, _n};
}

/*===========================================================
  circular range
===========================================================*/
template <typename Range>
bits::circular_range<Range>
circular_range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::circular_range<Range>>();

return bits::circular_range<Range>{_range};
}

/*===========================================================
  disable input
===========================================================*/
template <typename Range>
bits::disable_input<Range>
disable_input (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::disable_input<Range>>();
bits::not_read_assert<bits::disable_input<Range>>();

return bits::disable_input<Range>{_range};
}

/*===========================================================
  disable output
===========================================================*/
template <typename Range>
bits::disable_output<Range>
disable_output (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::disable_output<Range>>();
bits::not_write_assert<bits::disable_output<Range>>();

return bits::disable_output<Range>{_range};
}

/*===========================================================
  select
===========================================================*/
template <std::size_t I, typename Range>
bits::select<Range, I>
select (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::select<Range, I>>();

return bits::select<Range, I> {_range};
}

/*===========================================================
  extend life
===========================================================*/
template <typename Range, typename... Ts>
bits::extend_life<Range, Ts...>
extend_life (
  Range _range
, Ts &&... _ts
){
bits::range_assert<Range>();
bits::range_assert<bits::extend_life<Range, Ts...>>();

return bits::extend_life<Range, Ts...>
  {_range, std::forward<Ts>(_ts)...};
}

/*===========================================================
  sub range
===========================================================*/
template <typename Range, typename Sentinal>
bits::sub_range<Range, Sentinal>
sub_range (
  Range _range
, Sentinal _sentinal
){
bits::range_assert<Range>();
bits::range_assert<bits::sub_range<Range, Sentinal>>();

return bits::sub_range<Range, Sentinal>{_range, _sentinal};
}

/*===========================================================
  checked range
===========================================================*/
template <typename Range>
bits::checked_range<Range>
checked_range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::checked_range<Range>>();

return bits::checked_range<Range>{_range};
}

/*===========================================================
  back_insert
===========================================================*/
template <typename Range>
bits::back_insert<Range>
back_insert (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::back_insert<Range>>();
bits::expandable_assert<Range>();

return bits::back_insert<Range>{_range};
}

/*===========================================================
  extend range
===========================================================*/
template <typename T, typename Func>
auto
extend_range (
  T && _con
, Func _func
) -> decltype(extend_life(_func(_con), std::move(_con))){
auto temp = extend_life(_func(_con), std::move(_con));
temp.set_range(_func(* std::get<0>(temp.variable).get()));
return temp;
}

/*===========================================================
  as range
===========================================================*/
template <typename Range, typename Func>
bits::as_range<Range, Func>
as_range (
  Range && _range
, Func _func
){
bits::range_assert<Range>();

return bits::as_range<Range, Func>{_range, _func};
}

} //range layer----------------------------------------------
#endif
