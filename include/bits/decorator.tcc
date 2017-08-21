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
return bits::remove_decorator<Range>(_range);
}

/*===========================================================
  remove_if_range
===========================================================*/
template <typename Range, typename Pred>
bits::remove_range<Range, Pred>
remove_if_range (
  Range _range
, Pred _pred
){
return bits::remove_range<Range, Pred>{_range, _pred};
}

/*===========================================================
  remove_range
===========================================================*/
template <typename Range, typename T>
bits::remove_range<Range, bits::remove_pred<T>>
remove_range (
  Range _range
, T _value
){
return bits::remove_range<Range, bits::remove_pred<T>>
{_range, bits::remove_pred<T>{_value}};
}

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
  (_range, bits::replace_func<T>{_old_value, _new_value}))
{
return input_transform_range
  (_range, bits::replace_func<T>{_old_value, _new_value});
}

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
  _range, bits::replace_func<T>{_old_value, _new_value}))
{
return output_transform_range (
  _range, bits::replace_func<T>{_old_value, _new_value});
}

/*===========================================================
  input_replace_if_range
===========================================================*/
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

/*===========================================================
  output_replace_if_range
===========================================================*/
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

/*===========================================================
  transform_range
===========================================================*/
template <typename Range, typename Func>
bits::transform_range<Func, Range>
transform_range (
  Range _range
, Func _func
){
return bits::transform_range<Func, Range>{_range, _func};
}

/*===========================================================
  input_transform_range
===========================================================*/
template <typename Range, typename Func>
bits::input_transform_range<Func, Range>
input_transform_range (
  Range _range
, Func _func
){
return bits::input_transform_range<Func, Range>
  {_range, _func};
}

/*===========================================================
  output_transform_range
===========================================================*/
template <typename Range, typename Func>
bits::output_transform_range<Func, Range>
output_transform_range (
  Range _range
, Func _func
){
return bits::output_transform_range<Func, Range>
  {_range, _func};
}

/*===========================================================
  reverse_range
===========================================================*/
template <typename Range>
bits::reverse_range<Range>
reverse_range (
  Range _range
){
static_assert(
  range_trait::is_reversable<Range>::value
, "Cannot reverse range"
);

return bits::reverse_range<Range>{_range};
}

/*===========================================================
  sub_range_n
===========================================================*/
template <typename Range, typename N>
bits::sub_range_n<Range, N>
sub_range_n (
  Range _range
, N _n
){
return bits::sub_range_n<Range, N>{_range, _n};
}

/*===========================================================
  circular_range
===========================================================*/
template <typename Range>
bits::circular_range<Range>
circular_range (
  Range _range
){
return bits::circular_range<Range>{_range};
}

/*===========================================================
  disable_input
===========================================================*/
template <typename Range>
bits::disable_input<Range>
disable_input (
  Range _range
){
return bits::disable_input<Range>{_range};
}

/*===========================================================
  disable_output
===========================================================*/
template <typename Range>
bits::disable_output<Range>
disable_output (
  Range _range
){
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
return bits::select<Range, I> {_range};
}

/*===========================================================
  extend_life
===========================================================*/
template <typename Range, typename... Ts>
bits::extend_life<Range, Ts...>
extend_life (
  Range _range
, Ts... _ts
){
return bits::extend_life<Range, Ts...>{_range, _ts...};
}

/*===========================================================
  sub_range
===========================================================*/
template <typename Range, typename Sentinal>
bits::sub_range<Range, Sentinal>
sub_range (
  Range _range
, Sentinal _sentinal
){
return bits::sub_range<Range, Sentinal>{_range, _sentinal};
}

/*===========================================================
  checked_range
===========================================================*/
template <typename Range>
bits::checked_range<Range>
checked_range (
  Range _range
){
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
static_assert (
  range_trait::is_expandable<Range>::value
, "Range must be expandable to insert into the end."
);

return bits::back_insert<Range>{_range};
}

}
//range layer------------------------------------------------
#endif
