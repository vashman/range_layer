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
array_range <T>
range (
  T *
);

template <typename T, std::size_t N>
array_range <T>
range (
  std::array<T, N> &
);

template <typename T, std::size_t N>
bits::extend_life
< array_range <T>
, std::array<T, N>
>
range (
  std::array<T, N> &&
);

} /* range layer */
#endif

