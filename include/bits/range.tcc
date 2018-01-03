//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_TCC
#define RANGE_LAYER_BITS_RANGE_TCC

#include <memory>

namespace range_layer {

/*==============================================================================
  ctor
==============================================================================*/
template <typename H>
range<H>::range (
  H _handle
)
: range_class::spec<H>::type {_handle}
{}

/*==============================================================================
  make_range
==============================================================================*/
template <typename... Ts>
range<Ts...>
make_range (
  Ts... _args
){
return range<Ts...>{std::move(_args)...};
}

/*=========================================
  Range Operations
==========================================*/
/*-----------------------------------------------------------------------------
  Non-Modifing
-----------------------------------------------------------------------------*/
template <typename H> bool           has_input  (const range<H> &);
template <typename H> bool           has_output (const range<H> &);
template <typename H> bool           has_io     (const range<H> &);
template <typename H> decltype(auto) size       (const range<H> &);
template <typename H> decltype(auto) position   (const range<H> &);
template <typename H> decltype(auto) read_size  (const range<H> &);
template <typename H> decltype(auto) write_size (const range<H> &);
template <typename H> decltype(auto) rw_size    (const range<H> &);
template <typename H> const auto &   read       (const range<H> &, size_type_t<range<H>>);

/*-----------------------------------------------------------------------------
  Modify
-----------------------------------------------------------------------------*/
template <typename H, typename... Ts> void     write (range<H> &, size_type_t<range<H>>, Ts &&...);
template <typename H, typename... Ts> void     write (range<H> &&, size_type_t<range<H>>, Ts &&...);
template <typename H, typename... Ts> range<H> insert(range<H>, Ts &&...);
template <typename H>                 void     swap  (range<H> &, value_type_t<range<H>> &);
template <typename H>                 range<H> drain (range<H>, value_type_t<range<H>> &);

/*-----------------------------------------------------------------------------
  Transversal
-----------------------------------------------------------------------------*/
template <typename H>
range<H>
next (
  range<H> _rng
){
_rng.next();
return _rng;
}

template <typename H>
range<H>
prev (
  range<H> _rng
){
_rng.prev();
return _rng;
}

template <typename H>
range<H>
next (
  range<H> _rng
, size_type_t<range<H>> _n
){
return bits::next(std::move(_rng), _n, trait_tag<is_next_linear<range<H>>>{});
}

template <typename H>
range<H>
prev (
  range<H> _rng
, size_type_t<range<H>> _n
){
return bits::prev(std::move(_rng), _n, trait_tag<is_prev_linear<range<H>>>{});
}

namespace bits {
/*-----------------------------------------------------------------------------
  Non-Modifing
-----------------------------------------------------------------------------*/
template <typename H>
bool
has_input (
  const range<H> & _rng
, true_tag <is_synced<range<H>>>
){
return has_io(_rng);
}

template <typename H>
bool
has_input (
  const range<H> & _rng
, false_tag<is_synced<range<H>>>
){
return _rng.has_input();
}

template <typename H>
bool
has_output (
  const range<H> & _rng
, true_tag <is_synced<range<H>>>
){
return has_io(_rng);
}

template <typename H>
bool
has_output (
  const range<H> & _rng
, false_tag<is_synced<range<H>>>
){
return _rng.has_output();
}

template <typename H>
bool
has_io (
  const range<H> & _rng
, true_tag <is_synced<range<H>>>
){
return _rng.has_io();
}

template <typename H>
bool
has_io (
  const range<H> & _rng
, false_tag<is_synced<range<H>>>
){
return (has_input(_rng) && has_output(_rng));
}

template <typename H>
decltype(auto)
read_size (
  const range<H> & _rng
, true_tag <is_synced<range<H>>>
){
return rw_size(_rng);
}

template <typename H>
decltype(auto)
read_size (
  const range<H> & _rng
, false_tag<is_synced<range<H>>>
){
return _rng.read_size(); 
}

template <typename H>
decltype(auto)
write_size (
  const range<H> & _rng
, true_tag <is_synced<range<H>>>
){
return rw_size(_rng);
}

template <typename H>
decltype(auto)
write_size (
  const range<H> & _rng
, false_tag<is_synced<range<H>>>
){
return _rng.write_size();
}

template <typename H>
decltype(auto)
rw_size (
  const range<H> & _rng
, true_tag <is_synced<range<H>>>
){
return _rng.rw_size();
}

template <typename H>
decltype(auto)
rw_size (
  const range<H> & _rng
, false_tag<is_synced<range<H>>>
){
return (read_size(_rng) < write_size(_rng)) ? write_size(_rng) : read_size(_rng);
}

/*-----------------------------------------------------------------------------
  Transversal
-----------------------------------------------------------------------------*/
template <typename H>
range<H>
next (
  range<H> _rng
, size_type_t<range<H>> _n
, true_tag<is_next_linear<range<H>>>
){
  while (_n > 0){
  _rng = next(_rng);
  }
return _rng;
}

template <typename H>
range<H>
prev (
  range<H> _rng
, size_type_t<range<H>> _n
, true_tag<is_prev_linear<range<H>>>
){
  while (_n > 0){
  _rng = prev(_rng);
  }
return _rng;
}

template <typename H>
range<H>
next (
  range<H> _rng
, size_type_t<range<H>> _n
, false_tag<is_next_linear<range<H>>>
){
_rng.next(_n);
return _rng;
}

template <typename H>
range<H>
prev (
  range<H> _rng
, size_type_t<range<H>> _n
, false_tag<is_prev_linear<range<H>>>
){
_rng.prev(_n);
return _rng;
}

} //------------------------------------------------------------------------bits
} //-----------------------------------------------------------------range layer
#endif

