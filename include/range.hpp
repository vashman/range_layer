// Basic range operations and includes.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_HPP
#define RANGE_LAYER_RANGE_HPP

#include "range_traits.hpp"
#include "bits/algo/asserts.hpp"
#include <type_traits>

namespace range_layer {

template <typename Range>
auto
read (
  Range & _range
)
-> decltype (*_range)
{
bits::read_assert<Range>();

return *_range;
}

template <typename Range, typename T>
void
write (
  Range & _range
, T const & _var
){
bits::write_assert<Range>();

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
reverse (
  Range & _range
, Ranges &... _ranges
){
--_range;
void* list[] = {0, (static_cast<void*>(&(--_ranges)))...};
}

namespace bits {

template <
  typename Range
, typename N
, typename std::enable_if
  <range_trait::is_linear<Range>::value, int>::type = 0 >
void
advance_n (
  N const _n
, Range & _range
){
N count = _n;
while (0 != count--) ++_range;
}

template <
  typename Range
, typename N
, typename std::enable_if
  <! range_trait::is_linear<Range>::value, int>::type = 0 >
void
advance_n (
  N const _n
, Range & _range
){
_range += _n;
}

template <
  typename Range
, typename N
, typename std::enable_if
  <range_trait::is_linear<Range>::value, int>::type = 0 >
void
reverse_n (
  N const _n
, Range & _range
){
N count = _n;
while (0 != count--) --_range;
}

template <
  typename Range
, typename N
, typename std::enable_if
  <! range_trait::is_linear<Range>::value, int>::type = 0 >
void
reverse_n (
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
reverse_n (
  N const _n
, Range & _range
, Ranges &... _ranges
){
bits::reverse_n(_n, _range);
void* list[] = {0, (bits::reverse_n(_n, _ranges),0)...};
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
reverse(_range);
return _range;
}

template <typename Range, typename N>
Range
prev (
  N _n
, Range _range
){
reverse_n(_n, _range);
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

template <typename Range>
auto
size (
  Range const & _range
) -> decltype(_range.size()) {
static_assert (
  range_trait::is_range<Range>::value
, "Must be a range."
);
return _range.size();
}

template <typename Range>
auto
position (
  Range const & _range
) -> decltype (_range.position()) {
static_assert (
  range_trait::is_range<Range>::value
, "Must be a range."
);
return _range.position();
}

} /* range layer */
#endif
#include "bits/decorator.hpp"
