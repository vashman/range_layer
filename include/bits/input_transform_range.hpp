//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_INPUT_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_INPUT_TRANSFORM_RANGE_HPP

namespace range_layer {

template <typename Range, typename Func>
struct input_transform_range {

using trait = range_traits<Range>;
static constexpr bool const is_output = trait::is_output;
static constexpr bool const is_input = trait::is_input;
static constexpr bool const is_input_contiguous = false;
static constexpr bool const is_input_temporary = true;

static constexpr bool const
  is_input_size_known = trait::input::is_size_known;

static constexpr bool const
  is_output_contiguous = trait::output::is_contiguous;

static constexpr bool const
  is_output_temporary = trait::output::is_temporary;

static constexpr bool const
  is_output_size_known = trait::output::is_size_known;

static constexpr bool const
  is_reversable = trait::is_reversable;

using difference_type = typename trait::difference_type;

Range range;
Func func;

};

} /* range layer */
#endif

