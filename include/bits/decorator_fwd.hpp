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
#include "range_fwd.hpp"

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

template <typename Range, typename Func>
class as_range;

template <template <typename> class Decor>
struct decor_tag_base;

} //-----------------------------------------------------bits

/*===========================================================
  disable decorator func
===========================================================*/
template
< typename Range
, typename std
  ::enable_if <range_trait::is_decorator<Range>::value, int>
  ::type = 0
>
auto
disable_decorator_func (
  Range _range
) -> decltype (disable_decorator(_range.disable()));

/*===========================================================
  disable decorator func
===========================================================*/
template
< typename Range
, typename std
  ::enable_if <!range_trait::is_decorator<Range>::value, int>
  ::type = 0
>
Range
disable_decorator_func (
  Range
);

/*===========================================================
  disable decorator
===========================================================*/
struct disable_decorator;

/*===========================================================
  remove decorator

* Removes the decorator status of the range, making the
  decorator permanent.
===========================================================*/
struct remove_decorator;

/*===========================================================
  remove if
===========================================================*/
template <typename Pred>
struct remove_if;

template <typename Pred>
remove_if<Pred>
make_remove_if (
  Pred
);

/*===========================================================
  remove
===========================================================*/
template <typename T>
struct remove;

template <typename T>
remove<T>
make_remove (
  T
);

/*===========================================================
  replace_read
===========================================================*/
template <typename T>
struct replace_read;

template <typename T>
replace_read<T>
make_replace_read (
  T _old_value
, T _new_value
);

/*===========================================================
  output replace
===========================================================*/
template <typename T>
struct replace_write;

template <typename T>
replace_write<T>
make_replace_write (
  T _old_value
, T _new_value
);

/*===========================================================
  input_replace if
===========================================================*/
template <typename T, typename Pred>
struct replace_if_read;

template <typename T, typename Pred>
replace_if_read<T, Pred>
make_replace_if_read (
  T
, Pred
);

/*===========================================================
  output_replace if
===========================================================*/
template <typename T, typename Pred>
struct replace_if_write;

template <typename T, typename Pred>
replace_if_write<T, Pred>
make_replace_if_write (
  T
, Pred
);

/*===========================================================
  write transform
===========================================================*/
template <typename Func>
struct transform_write;

template <typename Func>
transform_write<Func>
make_transform_write (
  Func
);

/*===========================================================
  read transform
===========================================================*/
template <typename Func>
struct transform_read;

template <typename Func>
transform_read<Func>
make_transform_read (
  Func
);

/*===========================================================
  transform
===========================================================*/
template <typename Func>
struct transform;

template <typename Func>
transform<Func>
make_transform (
  Func
);

/*===========================================================
  backward
===========================================================*/
struct backward;

/*===========================================================
  sub_range_n
===========================================================*/
template <typename N>
struct sub_range_n;

template <typename N>
sub_range_n<N>
make_sub_range_n (
  N
);

/*===========================================================
  circular
===========================================================*/
struct circular;

/*===========================================================
  disable_input
===========================================================*/
struct disable_read;

/*===========================================================
  disable_output
===========================================================*/
struct disable_write;

/*===========================================================
  select
===========================================================*/
template <std::size_t I>
struct select;

/*===========================================================
  extend_life
===========================================================*/
template <typename... Ts>
struct extend_life {

std::tuple<std::shared_ptr<Ts>...> variable;

/*===========================================================
  ctor
===========================================================*/
extend_life (
  Ts &&... _ts
)
: variable {std::make_shared<Ts>(_ts)...}
{}

extend_life (extend_life &&) = default;
extend_life (extend_life const &) = default;
extend_life & operator = (extend_life &&) = default;
extend_life & operator = (extend_life const &) = default;
~extend_life () = default;

template <typename Range>
bits::extend_life<Range, Ts...>
range (
  Range _range
){
return
bits::extend_life<Range, Ts...>{_range, this->variable};
}

};

/*===========================================================
  sub_range
===========================================================*/
template <typename Sentinal>
struct sub_range;

template <typename Sentinal>
sub_range<Sentinal>
make_sub_range (
  Sentinal
);

/*===========================================================
  checked_range
===========================================================*/
struct checked_range;

/*===========================================================
  back_insert
===========================================================*/
struct back_insert;

/*===========================================================
  extend_range
===========================================================*/
template <typename T, typename Func>
auto
extend_range (
  T && _con
, Func _func
) -> decltype(extend_life(_func(_con), std::move(_con)));

} //----------------------------------------------range layer
#endif

