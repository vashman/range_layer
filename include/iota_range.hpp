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
static constexpr bool const is_input_contiguous = false;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_input_size_known = true;
static constexpr bool const is_output_contiguous = false;
static constexpr bool const is_output_temporary = false;
static constexpr bool const is_output_size_known = false;
static constexpr bool const is_reversable = true;
using difference_type = T;

// must be ++, --
T count;

};

template <typename T>
T
read (
  iota_range<T> & _range
){
return _range.count++;
}

template <typename T>
T
read (
  iota_range<T> && _range
){
return read(_range);
}

template <typename T>
bool
is_readable (
  iota_range<T> const & _range
){
return !(
   (std::numeric_limits<T>::max() == _range.count)
|| (std::numeric_limits<T>::min() == _range.count)
);
}

template <typename T>
iota_range<T>
prev (
  iota_range<T> _range
, typename range_traits<iota_range<T>>::difference_type _n = 1
){
_range.count -= _n;
return _range;
}

template <typename T>
iota_range<T>
next (
  iota_range<T> _range
, typename range_traits<iota_range<T>>::difference_type _n = 1
){
_range.count += _n;
return _range;
}

template <typename T>
typename range_traits<iota_range<T>>::difference_type
input_size (
  iota_range<T> const & _range
){
return std::numeric_limits<T>::max() - _range.count;
}

} /* range layer */
#endif

