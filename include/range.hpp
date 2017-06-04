// Basic range operations and includes.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_HPP
#define RANGE_LAYER_RANGE_HPP

#include "range_traits.hpp"
#include <type_traits>

namespace range_layer {

template <typename Range>
auto
read (
  Range & _range
)
-> decltype (*_range)
{
return *_range;
}

template <typename Range, typename T>
void
write (
  Range & _range
, T const & _var
){
_range = _var;
}

template <typename Range, typename... Ranges>
void
advance (
  Range & _range
, Ranges &... _ranges
){
++_range;
void* list[] = {0, (static_cast<void*>(&(++_ranges)))...};
}

template <typename Range, typename... Ranges>
void
advance_prev (
  Range & _range
, Ranges &... _ranges
){
--_range;
void* list[] = {0, (static_cast<void*>(&(--_ranges)))...};
}

namespace bits {

template <typename Range, typename N
, typename std::enable_if
  <range_traits<Range>::is_linear, int>::value = 0
>
void
advance_n (
  N const _n
, Range & _range
){
N count = _n;
while (0 != count--) ++_range;
}

template <typename Range, typename N
, typename std::enable_if
  <! range_traits<Range>::is_linear, int>::type = 0
>
void
advance_n (
  N const _n
, Range & _range
){
_range += _n;
}

template <typename Range, typename N
, typename std::enable_if
  <range_traits<Range>::is_linear, int>::type = 0
>
void
advance_prev_n (
  N const _n
, Range & _range
){
N count = _n;
while (0 != count--) --_range;
}

template <typename Range, typename N
, typename std::enable_if
  <! range_traits<Range>::is_linear, int>::type = 0
>
void
advance_prev_n (
  N const _n
, Range & _range
){
_range -= _n;
}
} /* bits */

template <typename N, typename Range, typename... Ranges>
void
advance_n (
  N const _n
, Range & _range
, Ranges &... _ranges
){
bits::advance_n(_n, _range);
void* list[] = {0, (bits::advance_n(_n, _ranges), 0)...};
}

template <typename N, typename Range, typename... Ranges>
void
advance_prev_n (
  N const _n
, Range & _range
, Ranges &... _ranges
){
bits::advance_prev_n(_n, _range);
void* list[] = {0, (bits::advance_prev_n(_n, _ranges),0)...};
}

template <typename Range>
Range
next (
  Range _range
){
advance(_range);
return _range;
}

template <typename Range, typename N>
Range
next (
  N _n
, Range _range
){
advance_n(_n, _range);
return _range;
}

template <typename Range>
Range
prev (
  Range _range
){
advance_prev(_range);
return _range;
}

template <typename Range, typename N>
Range
prev (
  N _n
, Range _range
){
advance_prev_n(_n, _range);
return _range;
}

template <typename Range>
bool
has_readable (
  Range const & _range
){
return _range == sentinel::readable{};
}

template <typename Range>
bool
has_writable (
  Range const & _range
){
return _range == sentinel::writable{};
}

template <typename Range, typename T>
bool
has_readable (
  Range const & _range
, T const & _sentinel
){
return
(_range == sentinel::readable{}) && (_range == _sentinel);
}

template <typename Range, typename T>
bool
has_writable (
  Range const & _range
, T const & _sentinel
){
return
(_range == sentinel::writable{}) && (_range == _sentinel);
}

} /* range layer */
#endif
#include "remove_range.hpp"
#include "replace_range.hpp"
#include "transform_range.hpp"
#include "reverse_range.hpp"
#inlcude "sub_range.hpp"

