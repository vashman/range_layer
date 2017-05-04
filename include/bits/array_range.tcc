//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ARRAY_RANGE_TCC
#define RANGE_LAYER_ARRAY_RANGE_TCC

namespace range_layer {

template <typename T>
array_range<T>::array_range (
  T * _array
, T * _end
)
: array (_array)
, pos {_array}
, end_pos {_end}
{}

} /* range layer */
#endif

