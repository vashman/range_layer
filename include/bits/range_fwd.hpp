// forward definitions for range

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_FWD_HPP
#define RANGE_LAYER_RANGE_FWD_HPP

#include "../range_traits.hpp"
#include <type_traits>

//#include "bits/variable_range_fwd.hpp"

namespace range_layer {

/*===========================================================
  read
===========================================================*/
template <typename Range>
auto read (Range & _range) -> decltype (*_range);

/*===========================================================
  write
===========================================================*/
template <typename Range, typename T>
void write (Range &, T const &);

/*===========================================================
  advance
===========================================================*/
template <typename Range, typename... Ranges>
void advance (Range &, Ranges &...);

/*===========================================================
  reverse
===========================================================*/
template <typename Range, typename... Ranges>
void reverse (Range &, Ranges &...);

namespace bits {

/*===========================================================
  advance_n

* Enabled when the type is linear.
===========================================================*/
template
< typename Range
, typename N
, typename std::enable_if
  <range_trait::is_linear<Range>::value, int>::type = 0
>
void advance_n (N const, Range &);

/*===========================================================
  advance_n

* Enabled when the type is not linear.
===========================================================*/
template
< typename Range
, typename N
, typename std::enable_if
  <! range_trait::is_linear<Range>::value, int>::type = 0
>
void advance_n (N const, Range &);

/*===========================================================
  reverse_n

* Enabled when the type is not linear.
===========================================================*/
template <
  typename Range
, typename N
, typename std::enable_if
  <range_trait::is_linear<Range>::value, int>::type = 0 >
void reverse_n (N const, Range &);

/*===========================================================
  reverse_n

* Enabled when the type is not linear.
===========================================================*/
template <
  typename Range
, typename N
, typename std::enable_if
  <! range_trait::is_linear<Range>::value, int>::type = 0 >
void reverse_n (N const, Range &);

}
//bits-------------------------------------------------------

/*===========================================================
  advance_n
===========================================================*/
template <typename N, typename Range, typename... Ranges>
void advance_n (N const, Range &, Ranges &...);

/*===========================================================
  reverse_n
===========================================================*/
template <typename N, typename Range, typename... Ranges>
void reverse_n (N const, Range &, Ranges &...);

/*===========================================================
  next
===========================================================*/
template <typename Range>
Range next (Range);

/*===========================================================
  next
===========================================================*/
template <typename Range, typename N>
Range next (N, Range);

/*===========================================================
  prev
===========================================================*/
template <typename Range>
Range prev (Range);

/*===========================================================
  prev
===========================================================*/
template <typename Range, typename N>
Range prev (N, Range);

/*===========================================================
  has_readable
===========================================================*/
template <typename Range>
bool has_readable (Range const &);

/*===========================================================
  has_writable
===========================================================*/
template <typename Range>
bool has_writable (Range const &);

/*===========================================================
  size

* The size can only change when extending or shrinknig the
  range. Otherwise the range is invalidated.
===========================================================*/
template <typename Range>
auto size (Range const & _range) -> decltype(_range.size());

/*===========================================================
  position

* UB to call once the range has ended.
* The position starts at zero.
===========================================================*/
template <typename Range>
auto position (Range const & _range) -> decltype(_range.position());

/*===========================================================
  end_of
===========================================================*/
template <typename Range>
Range end_of (Range);

/*===========================================================
  end_of_output
===========================================================*/
template <typename Range>
Range end_of_output (Range _range);

/*===========================================================
  end_of_input
===========================================================*/
template <typename Range>
Range end_of_input (Range);

/*===========================================================
  start_of
===========================================================*/
template <typename Range>
Range start_of (Range);

/*===========================================================
  start_of_output
===========================================================*/
template <typename Range>
Range start_of_output (Range);

/*===========================================================
  start_of_input
===========================================================*/
template <typename Range>
Range start_of_input (Range);

/*===========================================================
  shrink
===========================================================*/
template <typename Range, typename N>
Range shrink (Range, N);

/*===========================================================
  erase
===========================================================*/
template <typename Range>
Range erase (Range);

/*===========================================================
  erase_all
===========================================================*/
template <typename Range>
Range erase_all (Range);

/*===========================================================
  insert
===========================================================*/
template <typename Range, typename... Args>
Range insert (Range, Args &&...);

/*===========================================================
  expand
===========================================================*/
template <typename Range, typename N>
Range expand (Range, N);

/*===========================================================
  save

* Does not gurantee the returned type will be the same as the
  range passed in, or convertable to it.
===========================================================*/
template <typename Range>
auto save (Range _range) -> decltype(_range.save());

/*===========================================================
  const range
===========================================================*/
template <typename T>
auto crange (T const & _var)
  -> decltype (
remove_decorator ( disable_output (
  range(const_cast<T&>(_var))
)));

/*===========================================================
  const move crange
===========================================================*/
template <typename T>
auto crange (T const && _var)
  ->decltype(extend_life(range(_var), _var));

}
//range layer------------------------------------------------
#endif
