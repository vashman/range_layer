//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ARRAY_RANGE_FWD_HPP
#define RANGE_LAYER_ARRAY_RANGE_FWD_HPP

namespace range_layer {

template <typename T>
class array_range;

template <typename T>
T&
read (
  array_range<T> &
);

template <typename T>
T&
read (
  array_range<T> &&
);

template <typename T>
typename range_traits<array_range<T>>::size_type
read_size (
  array_range<T> const &
);

template <typename T>
void
write (
  array_range<T> &
, T const &
);

template <typename T>
void
write (
  array_range<T> &&
, T const &
);

template <typename T>
typename range_traits<array_range<T>>::size_type
write_size (
  array_range<T> const &
);

template <typename T>
array_range<T>
next (
  array_range<T>
, typename range_traits<array_range<T>>::size_type _n = 1
);

template <typename T>
array_range<T>
prev (
  array_range<T>
, typename range_traits<array_range<T>>::size_type _n = 1
);

template <typename T>
typename range_traits<array_range<T>>::size_type
input_position (
  array_range<T> const &
);

template <typename T>
typename range_traits<array_range<T>>::size_type
output_position (
  array_range<T> const &
);

} /* range layer */
#endif

