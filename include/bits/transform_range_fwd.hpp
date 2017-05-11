//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP
#define RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP

namespace range_layer {

namespace bits {
template <typename Func, typename Range>
struct input_transform_range;

template <typename Func, typename Range>
struct output_transform_range;

template <typename Func, typename Range>
struct transform_range;

} /* bits */

template <typename Range, typename Func>
bits::output_transform_range<Func, Range>
output_transform_range (
  Range
, Func
);

template <typename Range, typename Func>
bits::input_transform_range<Func, Range>
input_transform_range (
  Range
, Func
);

template <typename Range, typename Func>
bits::transform_range<Func, Range>
transform_range (
  Range
, Func
);

} /* range layer */
#endif

