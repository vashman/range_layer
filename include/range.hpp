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

/*===========================================================
  read
===========================================================*/
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

/*===========================================================
  write
===========================================================*/
template <typename Range, typename T>
void
write (
  Range & _range
, T const & _var
){
bits::write_assert<Range>();

_range = _var;
}

/*===========================================================
  write
===========================================================*/
template <typename Range, typename... Ranges>
void
advance (
  Range & _range
, Ranges &... _ranges
){
++_range;
void* list[] = {0, (static_cast<void*>(&(++_ranges)))...};
}

/*===========================================================
  reverse
===========================================================*/
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

template
< typename Range
, typename N
, typename std::enable_if
  <range_trait::is_linear<Range>::value, int>::type = 0
>
void
advance_n (
  N const _n
, Range & _range
){
N count = _n;
while (0 != count--) ++_range;
}

template
< typename Range
, typename N
, typename std::enable_if
  <! range_trait::is_linear<Range>::value, int>::type = 0
>
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

/*===========================================================
  advance_n
===========================================================*/
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

/*===========================================================
  reverse_n
===========================================================*/
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

/*===========================================================
  next
===========================================================*/
template <typename Range>
Range
next (
  Range _range
){
advance(_range);
return _range;
}

/*===========================================================
  next
===========================================================*/
template <typename Range, typename N>
Range
next (
  N _n
, Range _range
){
advance_n(_n, _range);
return _range;
}

/*===========================================================
  prev
===========================================================*/
template <typename Range>
Range
prev (
  Range _range
){
reverse(_range);
return _range;
}

/*===========================================================
  prev
===========================================================*/
template <typename Range, typename N>
Range
prev (
  N _n
, Range _range
){
reverse_n(_n, _range);
return _range;
}

/*===========================================================
  has_readable
===========================================================*/
template <typename Range>
bool
has_readable (
  Range const & _range
){
return _range == sentinel::readable{};
}

/*===========================================================
  has_writable
===========================================================*/
template <typename Range>
bool
has_writable (
  Range const & _range
){
return _range == sentinel::writable{};
}

/*template <typename Range, typename T>
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
}*/

/*===========================================================
  size
===========================================================*/
template <typename Range>
auto
size (
  Range const & _range
) -> decltype(_range.size()) {
bits::range_assert<Range>();

return _range.size();
}

/*===========================================================
  position
===========================================================*/
template <typename Range>
auto
position (
  Range const & _range
) -> decltype (_range.position()) {
bits::range_assert<Range>();

return _range.position();
}

/*===========================================================
  end_of
===========================================================*/
template <typename Range>
Range
end_of (
  Range _range
){
bits::range_assert<Range>();

while (has_readable(_range) || has_writable(_range))
advance(_range);

return _range;
}

/*===========================================================
  end_of_output
===========================================================*/
template <typename Range>
Range
end_of_output (
  Range _range
){
bits::write_assert<Range>();

while (has_writable(_range)) advance(_range);

return _range;
}

/*===========================================================
  end_of_input
===========================================================*/
template <typename Range>
Range
end_of_input (
  Range _range
){
bits::range_assert<Range>();

while (has_readable(_range)) advance(_range);

return _range;
}

/*===========================================================
  start_of
===========================================================*/
template <typename Range>
Range
start_of (
  Range _range
){
bits::range_assert<Range>();

while (has_readable(_range) || has_writable(_range))
reverse(_range);

return _range;
}

/*===========================================================
  start_of_output
===========================================================*/
template <typename Range>
Range
start_of_output (
  Range _range
){
bits::write_assert<Range>();

while (has_writable(_range)) reverse(_range);

return _range;
}

/*===========================================================
  start_of_input
===========================================================*/
template <typename Range>
Range
start_of_input (
  Range _range
){
bits::range_assert<Range>();

while (has_readable(_range))
reverse(_range);

return _range;
}

/*===========================================================
  advance_shrink
===========================================================*/
template <typename Range, typename N>
Range
advance_shrink (
  Range _range
, N _n
){
bits::range_assert<Range>();

return _range.advance_shrink(_n);
}

/*===========================================================
  reverse_shrink
===========================================================*/
template <typename Range, typename N>
Range
reverse_shrink (
  Range _range
, N _n
){
bits::range_assert<Range>();

return _range.reverse_shrink(_n);
}

/*===========================================================
  erase
===========================================================*/
template <typename Range>
Range
erase (
  Range _range
){
bits::range_assert<Range>();

return _range.erase();
}

/*===========================================================
  advance_erase
===========================================================*/
template <typename Range>
Range
advance_erase (
  Range _range
){
bits::range_assert<Range>();

return _range.advance_erase();
}

/*===========================================================
  reverse_erase
===========================================================*/
template <typename Range>
Range
reverse_erase (
  Range _range
){
bits::range_assert<Range>();

return _range.reverse_erase();
}

/*===========================================================
  reverse_insert
===========================================================*/
template <typename Range, typename T>
Range
reverse_insert (
  Range _range
, T const & _var
){
bits::range_assert<Range>();

return _range.reverse_insert(_var);
}

/*===========================================================
  advance_insert
===========================================================*/
template <typename Range, typename T>
Range
advance_insert (
  Range _range
, T const & _var
){
bits::range_assert<Range>();

return _range.advance_insert(_var);
}

/*===========================================================
  insert
===========================================================*/
template <typename Range, typename T>
Range
insert (
  Range _range
, T const & _var
){
bits::range_assert<Range>();

return _range.insert(_var);
}

/*===========================================================
  advance_expand
===========================================================*/
template <typename Range, typename N>
Range
advance_expand (
  Range _range
, N _n
){
bits::range_assert<Range>();

return _range.advance_expand(_n);
}

/*===========================================================
  reverse_expand
===========================================================*/
template <typename Range, typename N>
Range
reverse_expand (
  Range _range
, N _n
){
bits::range_assert<Range>();

return _range.reverse_expand(_n);
}

} /* range layer */
#endif
#include "bits/decorator.hpp"
