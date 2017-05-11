//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_TCC
#define RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_TCC

namespace range_layer {

template <typename Range, typename Func>
bits::output_transform_range<Func, Range>
output_transform_range (
  Range _range
, Func _func
){
return bits::output_transform_range<Func, Range>
  {_range, _func};
}

} /* range layer */
#endif

