// Basic range operations and includes.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_TCC
#define RANGE_LAYER_BITS_RANGE_TCC

#include "algo/asserts.hpp"

namespace range_layer {

/*===========================================================
  read
===========================================================*/
template <typename Range>
decltype(auto)
read (
  Range && _range
){
bits::range_assert<Range>();
bits::read_assert<Range>();

return _range.read();
}

/*===========================================================
  write
===========================================================*/
template <typename Range, typename T>
void
write (
  Range && _range
, T const & _var
){
bits::range_assert<Range>();
bits::write_assert<Range>();

_range.write(_var);
}

/*===========================================================
  advance
===========================================================*/
template <typename Range, typename... Ranges>
void
advance (
  Range && _range
, Ranges &&... _ranges
){
bits::range_assert<Range>();

_range.advance();
void* list[] = {0, (static_cast<void*>(&(_ranges.advance())))...};
}

/*===========================================================
  reverse
===========================================================*/
template <typename Range, typename... Ranges>
void
reverse (
  Range && _range
, Ranges &&... _ranges
){
bits::range_assert<Range>();
bits::reversible_assert<Range>();

_range.reverse();
void* list[] = {0, (static_cast<void*>(&(_ranges.reverse())))...};
}

namespace bits {

/*===========================================================
  advance_n

* Enabled when the type is linear.
===========================================================*/
template
< typename Range
, typename N
, typename std::enable_if
  <range_trait::is_linear<Range>::value, int>::type
>
void
advance_n (
  N const _n
, Range && _range
){
bits::range_assert<Range>();

N count = _n;
while (0 != count--) _range.advance();
}

/*===========================================================
  advance_n

* Enabled when the type is not linear.
===========================================================*/
template
< typename Range
, typename N
, typename std::enable_if
  <! range_trait::is_linear<Range>::value, int>::type
>
void
advance_n (
  N const _n
, Range && _range
){
bits::range_assert<Range>();

_range.advance_n(_n);
}

/*===========================================================
  reverse_n

* Enabled when the type is not linear.
===========================================================*/
template <
  typename Range
, typename N
, typename std::enable_if
  <range_trait::is_linear<Range>::value, int>::type >
void
reverse_n (
  N const _n
, Range && _range
){
bits::range_assert<Range>();
bits::reversible_assert<Range>();

N count = _n;
while (0 != count--) _range.reverse();
}

/*===========================================================
  reverse_n

* Enabled when the type is not linear.
===========================================================*/
template <
  typename Range
, typename N
, typename std::enable_if
  <! range_trait::is_linear<Range>::value, int>::type >
void
reverse_n (
  N const _n
, Range && _range
){
bits::range_assert<Range>();
bits::reversible_assert<Range>();

_range.reverse_n(_n);
}

} //-----------------------------------------------------bits

/*===========================================================
  advance_n
===========================================================*/
template <typename N, typename Range, typename... Ranges>
void
advance_n (
  N const _n
, Range && _range
, Ranges &&... _ranges
){
bits::range_assert<Range>();

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
, Range && _range
, Ranges &&... _ranges
){
bits::range_assert<Range>();
bits::reversible_assert<Range>();

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
bits::range_assert<Range>();

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
bits::range_assert<Range>();

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
bits::range_assert<Range>();
bits::reversible_assert<Range>();

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
bits::range_assert<Range>();
bits::reversible_assert<Range>();

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
bits::range_assert<Range>();
bits::read_assert<Range>();

return _range.has_readable();
}

/*===========================================================
  has_writable
===========================================================*/
template <typename Range>
bool
has_writable (
  Range const & _range
){
bits::range_assert<Range>();
bits::write_assert<Range>();

return _range.has_writable();
}

/*===========================================================
  size

* The size can only change when extending or shrinknig the
  range. Otherwise the range is invalidated.
===========================================================*/
template <typename Range>
typename range_trait::size_type<Range>::type
size (
  Range const & _range
){
bits::range_assert<Range>();
bits::finite_assert<Range>();

return _range.size();
}

/*===========================================================
  position

* UB to call once the range has ended.
* The position starts at zero.
===========================================================*/
template <typename Range>
typename range_trait::size_type<Range>::type
position (
  Range const & _range
){
bits::range_assert<Range>();

return _range.position();
}

/*===========================================================
  end_of
===========================================================*/
template <typename Range>
void
end_of (
  Range && _range
){
bits::range_assert<Range>();
bits::finite_assert<Range>();
bits::write_assert<Range>();
bits::read_assert<Range>();

  while (
     range_layer::has_readable(_range)
  || range_layer::has_writable(_range)
  ){
  range_layer::advance(_range);
  }
}

/*===========================================================
  end_of_output
===========================================================*/
template <typename Range>
void
end_of_output (
  Range && _range
){
bits::write_assert<Range>();
bits::finite_assert<Range>();
bits::write_assert<Range>();

  while (range_layer::has_writable(_range))
  range_layer::advance(_range);
}

/*===========================================================
  end_of_input
===========================================================*/
template <typename Range>
void
end_of_input (
  Range && _range
){
bits::range_assert<Range>();
bits::finite_assert<Range>();
bits::read_assert<Range>();

  while (range_layer::has_readable(_range))
  range_layer::advance(_range);
}

/*===========================================================
  start_of
===========================================================*/
template <typename Range>
void
start_of (
  Range && _range
){
bits::range_assert<Range>();
bits::write_assert<Range>();
bits::read_assert<Range>();
bits::reversible_assert<Range>();
bits::position_assert<Range>();

  while (
     range_layer::has_readable(_range)
  || range_layer::has_writable(_range)
  ){
  range_layer::reverse(_range);
  }
}

/*===========================================================
  start_of_output
===========================================================*/
template <typename Range>
void
start_of_output (
  Range && _range
){
bits::write_assert<Range>();
bits::write_assert<Range>();
bits::reversible_assert<Range>();
bits::position_assert<Range>();

  while (range_layer::has_writable(_range))
  range_layer::reverse(_range);
}

/*===========================================================
  start_of_input
===========================================================*/
template <typename Range>
void
start_of_input (
  Range && _range
){
bits::range_assert<Range>();
bits::read_assert<Range>();
bits::reversible_assert<Range>();
bits::position_assert<Range>();

  while (range_layer::has_readable(_range))
  range_layer::reverse(_range);
}

/*===========================================================
  shrink
===========================================================*/
template <typename Range, typename N>
void
shrink (
  Range && _range
, N _n
){
bits::range_assert<Range>();
bits::shrinkable_assert<Range>();

_range.shrink(_n);
}

/*===========================================================
  erase
===========================================================*/
template <typename Range>
void
erase (
  Range && _range
){
bits::range_assert<Range>();
bits::erase_assert<Range>();

_range.erase();
}

/*===========================================================
  erase_all
===========================================================*/
template
< typename Range
, typename = typename std::enable_if
  <range_trait::is_all_erasable<Range>::value, void>::type
>
void
erase_all (
  Range && _range
){
bits::range_assert<Range>();

_range.erase_all();
}

/*===========================================================
  erase_all
===========================================================*/
/*template
< typename Range
, typename = typename std::enable_if
  <range_trait::is_erasable<Range>::value, void>::type
>
Range
erase_all (
  Range _range
){
bits::range_assert<Range>();
bits::erase_assert<Range>();

while (has_readable(_range) || has_writable(_range)){
_range.erase();
}
return _range;
}*/

/*===========================================================
  insert
===========================================================*/
template <typename Range, typename... Args>
void
insert (
  Range && _range
, Args &&... _args
){
bits::range_assert<Range>();
bits::insert_assert<Range>();

_range.insert(std::forward<Args...>(_args...));
}

/*===========================================================
  expand
===========================================================*/
template <typename Range, typename N>
void
expand (
  Range && _range
, N _n
){
bits::range_assert<Range>();

_range.expand(_n);
}

/*===========================================================
  save
===========================================================*/
template <typename Range>
Range
save (
  Range const & _range
){
bits::range_assert<Range>();
bits::not_singleton_assert<Range>();

static_assert(
  std::is_same<Range, decltype(_range.save())>::value
, "Saved range must be the same type as orginal."
);

return _range.save();
}

/*===========================================================
  copy
===========================================================*/
template <typename T>
constexpr T
copy (
  T _var
){
return _var;
}


} //----------------------------------------------range layer
#endif
