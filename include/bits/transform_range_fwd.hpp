//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP
#define RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP

namespace range_layer {

template <typename Func, typename Range>
struct input_transform_range;

template <typename Func, typename Range>
struct output_transform_range;

template <typename Range, typename Func>
output_transform_range<Func, Range>
make_output_transform_range (
  Range _range
, Func _func
){
return output_transform_range<Func, Range>{_range, _func};
}

} /* range layer */
#endif

