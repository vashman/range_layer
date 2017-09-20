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
namespace bits {

/*===========================================================
  decor_tag_base:: range
===========================================================*/
template <template <typename> class Decor>
template <typename Range>
Decor<Range>
decor_tag_base<Decor>::range (
  Range _range
){
return Decor<Range>{_range};
}

} //-----------------------------------------------------bits

/*===========================================================
  disable_decorator_func
===========================================================*/
template
< typename Range
, typename std
  ::enable_if <range_trait::is_decorator<Range>::value, int>
  ::type
>
auto
disable_decorator_func (
  Range _range
){
bits::range_assert<Range>();
bits::decorator_assert<Range>();

return disable_decorator(_range.disable());
}

/*===========================================================
  disable_decorator_func
===========================================================*/
template
< typename Range
, typename std
  ::enable_if<! range_trait::is_decorator<Range>::value, int>
  ::type
>
Range
disable_decorator_func (
  Range _range
){
bits::range_assert<Range>();
bits::not_decorator_assert<Range>();

return _range;
}

/*===========================================================
  disable_decorator:: range
===========================================================*/
template <typename Range>
auto
disable_decorator::range (
  Range _range
){
return disable_decorator_func(_range);
}

/*===========================================================
  remove_if<Pred>:: remove if
===========================================================*/
template <typename Pred>
template <typename Range>
bits::remove_range<Range, Pred>
remove_if<Pred>::range (
  Range _range
){
using type = bits::remove_range<Range, Pred>;
bits::range_assert<Range>();
bits::predicate_assert<Pred>();
bits::range_assert<type>();

return bits::remove_range<Range, Pred>{_range, this->pred};
}

template <typename Pred>
remove_if<Pred>
make_remove_if (
  Pred _pred
){
return remove_if<Pred>{_pred};
}

/*===========================================================
  remove<T>:: remove
===========================================================*/
template <typename T>
template <typename Range>
bits::remove_range<Range, bits::remove_pred<T>>
remove<T>::range (
  Range _range
){
return bits::remove_range<Range, bits::remove_pred<T>>
  {_range, bits::remove_pred<T>{this->var}};
}

template <typename T>
remove<T>
make_remove (
  T _var
){
return remove_if<T>{_var};
}

/*===========================================================
  replace_read<T>:: replace_read
===========================================================*/
template <typename T>
template <typename Range>
auto
replace_read<T>::range (
  Range _range
){
bits::range_assert<Range>();
bits::read_assert<Range>();

return xrange (
  _range
, make_transform_read
  (bits::replace_func<T>{this->old_value, this->new_value})
);
}

template <typename T>
replace_read<T>
make_replace_read (
  T _old_value
, T _new_value
){
return replace_read<T>{_old_value, _new_value};
}

/*===========================================================
  replace_write<T>:: replace_write
===========================================================*/
template <typename T>
template <typename Range>
auto
replace_write<T>::range (
  Range _range
){
bits::range_assert<Range>();
bits::write_assert<Range>();

return xrange (
  _range
, make_transform_write
  (bits::replace_func<T>{this->old_value, this->new_value})
);
}

template <typename T>
replace_write<T>
make_replace_write (
  T _old_value
, T _new_value
){
return replace_write<T>{_old_value, _new_value};
}

/*===========================================================
  replace_if_read<T, Pred>:: range
===========================================================*/
template <typename T, typename Pred>
template <typename Range>
auto
replace_if_read<T, Pred>::range (
  Range _range
){
bits::range_assert<Range>();
bits::read_assert<Range>();

return xrange (
  _range
, make_transform_read
  (bits::replace_if_func<T, Pred>{this->new_value, this->pred})
);
}

template <typename T, typename Pred>
replace_if_read<T, Pred>
make_replace_if_read (
  T _new_value
, Pred _pred
){
return replace_if_read<T, Pred>{_new_value, _pred};
}

/*===========================================================
 replace_if_write<T, Pred>:: range
===========================================================*/
template <typename T, typename Pred>
template <typename Range>
auto
replace_if_write<T, Pred>::range (
  Range _range
){
bits::range_assert<Range>();
bits::write_assert<Range>();

return xrange (
  _range
, make_transform_write
  (bits::replace_if_func<T, Pred>{this->new_value, this->pred})
);
}

template <typename T, typename Pred>
replace_if_write<T, Pred>
make_replace_if_write (
  T _new_value
, Pred _pred
){
return replace_if_write<T, Pred>{_new_value, _pred};
}

/*===========================================================
  transform<Func>:: range
===========================================================*/
template <typename Func>
template <typename Range>
bits::transform_range<Func, Range>
transform<Func>::range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::transform_range<Func, Range>>();

return bits::transform_range<Func,Range>{_range, this->func};
}

template <typename Func>
transform<Func>
make_transform (
  Func _func
){
return transform<Func>{_func};
}

/*===========================================================
  transform_read<Func>:: range
===========================================================*/
template <typename Func>
template <typename Range>
bits::input_transform_range<Func, Range>
transform_read<Func>::range (
  Range _range
){
bits::range_assert<Range>();
bits::read_assert<Range>();
bits::range_assert
  <bits::input_transform_range<Func, Range>>();
bits::read_assert
  <bits::input_transform_range<Func, Range>>();

return bits::input_transform_range<Func, Range>
  {_range, this->func};
}

template <typename Func>
transform_read<Func>
make_transform_read (
  Func _func
){
return transform_read<Func>{_func};
}

/*===========================================================
  transform_write<Func>:: range
===========================================================*/
template <typename Func>
template <typename Range>
bits::output_transform_range<Func, Range>
transform_write<Func>::range (
  Range _range
){

using decor_t = bits::output_transform_range<Func, Range>;

bits::range_assert<Range>();
bits::write_assert<Range>();
bits::range_assert<decor_t>();
bits::write_assert<decor_t>();

return decor_t{_range, this->func};
}

template <typename Func>
transform_write<Func>
make_transform_write (
  Func _func
){
return transform_write<Func>{_func};
}

/*===========================================================
  sub_range_n<N>:: range
===========================================================*/
template <typename N>
template <typename Range>
bits::sub_range_n<Range>
sub_range_n<N>::range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::sub_range_n<Range>>();

auto n
  = static_cast<range_trait::size_type_t<Range>>(this->size);
return bits::sub_range_n<Range>{_range, n};
}

template <typename N>
sub_range_n<N>
make_sub_range_n (
  N _n
){
return sub_range_n<N>{_n};
}

/*===========================================================
  sub_range<Sentinal>:: range
===========================================================*/
template <typename Sentinal>
template <typename Range>
bits::sub_range<Range, Sentinal>
sub_range<Sentinal>::range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::sub_range_n<Range>>();

return bits::sub_range<Range, Sentinal>{_range, this->sen};
}

template <typename Sentinal>
sub_range<Sentinal>
make_sub_range (
  Sentinal _sen
){
return sub_range<Sentinal>{_sen};
}

/*===========================================================
  disable_read:: range
===========================================================*/
template <typename Range>
bits::disable_input<Range>
disable_read::range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::disable_input<Range>>();
bits::not_read_assert<bits::disable_input<Range>>();

return bits::disable_input<Range> {_range};
}

/*===========================================================
  disable_write:: range
===========================================================*/
template <typename Range>
bits::disable_output<Range>
disable_write::range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::disable_output<Range>>();
bits::not_write_assert<bits::disable_output<Range>>();

return bits::disable_output<Range>{_range};
}

/*===========================================================
  select<I>:: range
===========================================================*/
template <std::size_t I>
template <typename Range>
bits::select<Range, I>
select<I>::range (
  Range _range
){
bits::range_assert<Range>();
bits::range_assert<bits::select<Range, I>>();

return bits::select<Range, I>{_range};
}

/*===========================================================
  extend life
===========================================================*/
/*template <typename Range, typename... Ts>
bits::extend_life<Range, Ts...>
extend_life (
  Range _range
, Ts &&... _ts
){
bits::range_assert<Range>();
bits::range_assert<bits::extend_life<Range, Ts...>>();

return bits::extend_life<Range, Ts...>
  {_range, std::forward<Ts>(_ts)...};
}*/

/*===========================================================
  extend range
===========================================================*/
/*template <typename T, typename Func>
auto
extend_range (
  T && _con
, Func _func
){
auto temp = extend_life(_func(_con), std::move(_con));
temp.set_range(_func(* std::get<0>(temp.variable).get()));
return temp;
}*/

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

} //----------------------------------------------range layer
#endif
