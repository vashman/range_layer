//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DECORATOR_HPP
#define RANGE_LAYER_DECORATOR_HPP

#include "decorator_fwd.hpp"

#include "decor/remove_range.hpp"
#include "decor/replace_range.hpp"
#include "decor/reverse_range.hpp"
#include "decor/sub_range.hpp"
#include "decor/sub_range_n.hpp"
#include "decor/remove_decorator.hpp"
#include "decor/circular_range.hpp"
#include "decor/disable_input.hpp"
#include "decor/disable_output.hpp"
#include "decor/select.hpp"
#include "decor/extend_life.hpp"
#include "decor/checked_range.hpp"
#include "decor/back_insert.hpp"
#include "decor/transform_range.hpp"
#include "decor/input_transform_range.hpp"
#include "decor/output_transform_range.hpp"
#include "decor/as_range.hpp"
#include "decor/rewrite.hpp"

namespace range_layer {

namespace bits {

/*===========================================================
  decor_tag_base
===========================================================*/
template <template <typename> class Decor>
struct decor_tag_base {

template <typename Range>
Decor<Range>
range (
  Range
);

};

} //-----------------------------------------------------bits

/*===========================================================
  remove if
===========================================================*/
template <typename Pred>
struct remove_if {

Pred pred;

template <typename Range>
bits::remove_range<Range, Pred>
range (
  Range
);

};

/*===========================================================
  remove
===========================================================*/
template <typename T>
struct remove {

T var;

template <typename Range>
bits::remove_range<Range, bits::remove_pred<T>>
range (
  Range
);

};

/*===========================================================
  sub_range
===========================================================*/
template <typename Sentinal>
struct sub_range {

Sentinal sen;

template <typename Range>
bits::sub_range<Range, Sentinal>
range (
  Range
);

};

/*===========================================================
  disable decorator
===========================================================*/
struct disable_decorator {

template <typename Range>
auto
range (
  Range _range
);

};

/*===========================================================
  checked_range
===========================================================*/
struct checked_range
  : public bits::decor_tag_base<bits::checked_range> {};

/*===========================================================
  back_insert
===========================================================*/
struct back_insert
  : public bits::decor_tag_base<bits::back_insert> {};

/*===========================================================
  remove decorator
===========================================================*/
struct remove_decorator
  : public bits::decor_tag_base<bits::remove_decorator> {};

/*===========================================================
  backward
===========================================================*/
struct backward
  : public bits::decor_tag_base<bits::reverse_range>{};

/*===========================================================
  circular
===========================================================*/
struct circular
  : public bits::decor_tag_base<bits::circular_range> {};

/*===========================================================
  sub_range_n
===========================================================*/
template <typename N>
struct sub_range_n {

N size;

template <typename Range>
bits::sub_range_n<Range>
range (
  Range
);

};

/*===========================================================
  transform_read
===========================================================*/
template <typename Func>
struct transform_read {

Func func;

template <typename Range>
bits::input_transform_range<Func, Range>
range (
  Range
);
};

/*===========================================================
  transform_write
===========================================================*/
template <typename Func>
struct transform_write {

Func func;

template <typename Range>
bits::output_transform_range<Func, Range>
range (
  Range
);

};

/*===========================================================
  transform
===========================================================*/
template <typename Func>
struct transform {

Func func;

template <typename Range>
bits::transform_range<Func, Range>
range (
  Range
);

};

/*===========================================================
  disable_read
===========================================================*/
struct disable_read {

template <typename Range>
bits::disable_input<Range>
range (
  Range
);

};

/*===========================================================
  disable_write
===========================================================*/
struct disable_write {

template <typename Range>
bits::disable_output<Range>
range (
  Range
);

};

/*===========================================================
  replace_read
===========================================================*/
template <typename T>
struct replace_read {

T old_value;
T new_value;

template <typename Range>
auto
range (
  Range
);

};

/*===========================================================
  replace_write
===========================================================*/
template <typename T>
struct replace_write {

T old_value;
T new_value;

template <typename Range>
auto
range (
  Range
);

};

/*===========================================================
  replace_if_read
===========================================================*/
template <typename T, typename Pred>
struct replace_if_read {

T new_value;
Pred pred;

template <typename Range>
auto
range (
  Range
);

};

/*===========================================================
  replace if write
===========================================================*/
template <typename T, typename Pred>
struct replace_if_write {

T new_value;
Pred pred;

template <typename Range>
auto
range (
  Range
);

};

/*===========================================================
  select
===========================================================*/
template <std::size_t I>
struct select {

template <typename Range>
bits::select<Range, I>
range (
  Range
);

};

/*===========================================================
  as range
===========================================================*/
template <typename Func>
struct as_range {

Func func;

template <typename Range>
auto
range (
  Range
);

};

} //----------------------------------------------range layer
#endif
#include "decorator.tcc"
