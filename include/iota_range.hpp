//

//          Copyright Sundeep S. Sangha 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_IOTA_RANGE_HPP
#define RANGE_LAYER_IOTA_RANGE_HPP

#include <limits>
#include "range_traits.hpp"

namespace range_layer {

template <typename T>
struct iota_range {

static constexpr bool const is_output = false;
static constexpr bool const is_input = true;
static constexpr bool const is_io_synced = true;
static constexpr bool const is_reversable = true;
static constexpr bool const is_erasable = false;
static constexpr bool const is_insertable = false;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_output_temporary = true;

static constexpr validation_type const
  validation = validation_type::unsynced;

static constexpr range_size const
  input_size_type = range_size::countable;

static constexpr range_size const
  output_size_type = range_size::countable;

T count;

};

template <typename T>
T&
read (
  iota_range<T> & _range
){
return _range.count;
}

template <typename T>
T&
read (
  iota_range<T> && _range
){
return read(_range);
}

template <typename T>
bool
has_readable (
  iota_range<T> const & _range
){
return (std::numeric_limits<T>::max() != _range.count);
}

template <typename T>
bool
prev_has_readable (
  iota_range<T> const & _range
){
return (_range.count != std::numeric_limits<T>::min());
}

template <typename T>
iota_range<T>
prev (
  iota_range<T> _range
, std::size_t _n = 1
){
_range.count -= _n;
return _range;
}

template <typename T>
iota_range<T>
next (
  iota_range<T> _range
, std::size_t _n = 1
){
_range.count += _n;
return _range;
}

template <typename T>
void
advance (
  iota_range<T> & _range
, std::size_t _n = 1
){
_range.count += _n;
}

} /* range layer */
#endif

