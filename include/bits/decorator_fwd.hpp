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

/*template <typename Range, template <typename> class Ptr, typename... Ts>
class extend_life;*/

template <typename Range>
class checked_range;

template
  <typename Range, typename Decorator, typename... Traits>
class base_decor;

template <typename Range, typename Func, typename Range2>
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
);

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

/*===========================================================
  remove decorator

* Removes the decorator status of the range, making the
  decorator permanent.
===========================================================*/

/*===========================================================
  extend_range
===========================================================*/
template <typename T, typename Func>
auto
extend_range (
  T &&
, Func
);

/*===========================================================
  as_range
===========================================================*/
template <typename Func>
struct as_range;

template <typename Func>
as_range<Func>
make_as_range (
  Func &&
);

} //----------------------------------------------range layer
#endif

