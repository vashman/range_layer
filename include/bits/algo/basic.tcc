// Basic range operations.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ALGO_BASIC_TCC
#define RANGE_LAYER_BITS_ALGO_BASIC_TCC

//#include "asserts.hpp"
#include <memory>

namespace range_layer {

/*==============================================================================
  read
==============================================================================*/
template <typename R>
const auto &
read (
  const R & _range
){
return _range.read();
}

/*==============================================================================
  drain
==============================================================================*/
template <typename R, typename T>
R
drain (
  R _range
, T & _var
){
_range.drain(_var);
return _range;
}

/*==============================================================================
  write
==============================================================================*/
template <typename R, typename... Ts>
void
write (
  R & _range
, Ts &&... _var
){
_range.write(_var...);
}

/*==============================================================================
  swap
==============================================================================*/
template <typename R, typename T>
void
swap (
  R & _range
, T & _var
){
_range.swap(_var);
}

/*==============================================================================
  write
==============================================================================*/
template <typename R, typename... Ts>
void
write (
  R && _range
, Ts &&... _var
){
_range.write(_var...);
}

/*==============================================================================
  insert
==============================================================================*/
template <typename R, typename... Ts>
R
insert (
  R _range
, Ts &&... _var
){
_range.insert(std::forward<Ts...>(_var...));
return _range;
}

/*==============================================================================
  has_input
==============================================================================*/
template <typename R>
bool
has_input (
  const R & _range
){
return bits::has_input(_range, tag<typename is_synced<R>::type, is_synced<R>>{});
}

/*==============================================================================
  has_output
==============================================================================*/
template <typename R>
bool
has_output (
  const R & _range
){
return bits::has_output(_range, tag<typename is_synced<R>::type, is_synced<R>>{});
}

/*==============================================================================
  has_io
==============================================================================*/
template <typename R>
bool
has_io (
  const R & _range
){
return bits::has_io(_range, tag<typename is_synced<R>::type, is_synced<R>>{});
}

/*==============================================================================
  next
==============================================================================*/
template <typename R>
R
next (
  R _range
){
_range.next();
return _range;
}

/*==============================================================================
  prev
==============================================================================*/
template <typename R>
R
prev (
  R _range
){
_range.prev();
return _range;
}

/*==============================================================================
  next (R, N)
==============================================================================*/
template <typename R, typename N>
R
next (
  R _range
, N _n
){
return bits::next (
  std::move(_range)
, std::move(_n)
, tag<typename bits::has_next<R>::type, bits::has_next<R>>{}
);
}

/*==============================================================================
  prev (R, N)
==============================================================================*/
template <typename R, typename N>
R
prev (
  R _range
, N _n
){
return bits::prev (
  std::move(_range)
, std::move(_n)
, tag<typename bits::has_prev<R>::type, bits::has_prev<R>>{}
);
}

/*==============================================================================
  read_size
==============================================================================*/
template <typename R>
decltype(auto)
read_size (
  const R & _range
){
return bits::read_size(_range, tag<typename is_synced<R>::type, is_synced<R>>{});
}

/*==============================================================================
  write_size
==============================================================================*/
template <typename R>
decltype(auto)
write_size (
  const R & _range
){
return bits::write_size(_range, tag<typename is_synced<R>::type, is_synced<R>>{});
}

/*==============================================================================
  rw_size
==============================================================================*/
template <typename R>
decltype(auto)
rw_size (
  const R & _range
){
return bits::rw_size(_range, tag<typename is_synced<R>::type, is_synced<R>>{});
}

/*==============================================================================
  size
==============================================================================*/
template <typename R>
decltype(auto)
size (
  const R & _range
){
return _range.size();
}

/*==============================================================================
  position
==============================================================================*/
template <typename R>
decltype(auto)
position (
  const R & _range
){
return _range.position();
}

/*===========================================================
  end_of
===========================================================*/
/*template <typename Range>
Range
end_of (
  Range _range
){
bits::range_assert<Range>();
bits::finite_assert<Range>();
bits::write_assert<Range>();
bits::read_assert<Range>();

  while (
     range_layer::has_readable(_range)
  || range_layer::has_writable(_range)
  ){
  _range = range_layer::next(_range);
  }
return _range;
}*/

/*===========================================================
  end_of_output
===========================================================*/
/*template <typename Range>
void
end_of_output (
  Range && _range
){
bits::write_assert<Range>();
bits::finite_assert<Range>();
bits::write_assert<Range>();

  while (range_layer::has_writable(_range))
  range_layer::advance(_range);
}*/

/*===========================================================
  end_of_input
===========================================================*/
/*template <typename Range>
void
end_of_input (
  Range && _range
){
bits::range_assert<Range>();
bits::finite_assert<Range>();
bits::read_assert<Range>();

  while (range_layer::has_readable(_range))
  range_layer::advance(_range);
}*/

/*===========================================================
  start_of
===========================================================*/
/*template <typename Range>
void
start_of (
  Range && _range
){
bits::range_assert<Range>();
bits::reversible_assert<Range>();
//bits::position_assert<Range>();

  while (
     range_layer::has_readable(_range)
  || range_layer::has_writable(_range)
  ){
  range_layer::reverse(_range);
  }
}*/

/*===========================================================
  start_of_output
===========================================================*/
/*template <typename Range>
void
start_of_output (
  Range && _range
){
bits::range_assert<Range>();
bits::write_assert<Range>();
bits::reversible_assert<Range>();
bits::position_assert<Range>();

  while (range_layer::has_writable(_range))
  range_layer::reverse(_range);
}*/

/*===========================================================
  start_of_input
===========================================================*/
/*template <typename Range>
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
}*/

/*===========================================================
  shrink
===========================================================*/
/*template <typename Range, typename N>
Range
shrink (
  Range _range
, N _n
){
bits::range_assert<Range>();
bits::shrinkable_assert<Range>();

_range.shrink(_n);
return _range;
}*/

/*===========================================================
  erase
===========================================================*/
/*template <typename Range>
void
erase (
  Range && _range
){
bits::range_assert<Range>();
bits::erase_assert<Range>();

_range.erase();
}*/

/*===========================================================
  erase_all
===========================================================*/
/*template
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
}*/

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
  expand
===========================================================*/
/*template <typename Range, typename N>
void
expand (
  Range && _range
, N _n
){
bits::range_assert<Range>();

_range.expand(_n);
}*/

/*===========================================================
  save
===========================================================*/
/*template <typename Range>
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
}*/

namespace bits {

/*==============================================================================
  next (R, N)
==============================================================================*/
template <typename R, typename N>
R
next (
  R _range
, N _n
, const tag<std::false_type, bits::has_next<R>>
){
  while (0 != _n--){
  _range = next(std::move(_range));
  }
return _range;
}

/*==============================================================================
  next (R, N)
==============================================================================*/
template <typename R, typename N>
R
next (
  R _range
, N _n
, const tag<std::true_type, bits::has_next<R>>
){
_range.next(_n);
return _range;
}

/*==============================================================================
  prev (R, N)
==============================================================================*/
template <typename R, typename N>
R
prev (
  R _range
, N _n
, const tag<std::false_type, bits::has_prev<R>>
){
  while (0 != _n--){
  _range = prev(std::move(_range));
  }
return _range;
}

/*==============================================================================
  prev (R, N)
==============================================================================*/
template <typename R, typename N>
R
prev (
  R _range
, N _n
, const tag<std::true_type, bits::has_prev<R>>
){
_range.prev(_n);
return _range;
}

/*==============================================================================
  has_input
==============================================================================*/
template <typename R>
bool
has_input (
  const R & _range
, const tag<std::true_type, is_synced<R>>
){
return _range.has_io();
}

/*==============================================================================
  has_input
==============================================================================*/
template <typename R>
bool
has_input (
  const R & _range
, const tag<std::false_type, is_synced<R>>
){
return _range.has_input();
}

/*==============================================================================
  has_output
==============================================================================*/
template <typename R>
bool
has_output (
  const R & _range
, const tag<std::true_type, is_synced<R>>
){
return _range.has_io();
}

/*==============================================================================
  has_output
==============================================================================*/
template <typename R>
bool
has_output (
  const R & _range
, const tag<std::false_type, is_synced<R>>
){
return _range.has_output();
}

/*==============================================================================
  has_io
==============================================================================*/
template <typename R>
bool
has_io (
  const R & _range
, const tag<std::true_type, is_synced<R>>
){
return _range.has_io();
}

/*==============================================================================
  has_io
==============================================================================*/
template <typename R>
bool
has_io (
  const R & _range
, const tag<std::false_type, is_synced<R>>
){
return (has_input(_range) && has_output(_range));
}

/*==============================================================================
  read_size
==============================================================================*/
template <typename R>
decltype(auto)
read_size (
  const R & _range
, const tag<std::true_type, is_synced<R>>
){
return _range.rw_size();
}

/*==============================================================================
  read_size
==============================================================================*/
template <typename R>
decltype(auto)
read_size (
  const R & _range
, const tag<std::false_type, is_synced<R>>
){
return _range.read_size();
}

/*==============================================================================
  write_size
==============================================================================*/
template <typename R>
decltype(auto)
write_size (
  const R & _range
, const tag<std::true_type, is_synced<R>>
){
return _range.rw_size();
}

/*==============================================================================
  write_size
==============================================================================*/
template <typename R>
decltype(auto)
write_size (
  const R & _range
, const tag<std::false_type, is_synced<R>>
){
return _range.write_size();
}

/*==============================================================================
  rw_size
==============================================================================*/
template <typename R>
decltype(auto)
rw_size (
  const R & _range
, const tag<std::true_type, is_synced<R>>
){
return _range.rw_size();
}

/*==============================================================================
  rw_size
==============================================================================*/
template <typename R>
decltype(auto)
rw_size (
  const R & _range
, const tag<std::false_type, is_synced<R>>
){
return std::min(read_size(_range), write_size(_range));
}

} //------------------------------------------------------------------------bits
} //-----------------------------------------------------------------range layer
#endif
