//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP

namespace range_layer {

template <typename Range, typename Func>
struct output_transform_range {

using trait = range_traits<Range>;
static constexpr bool const is_output = trait::is_output;
static constexpr bool const is_input = trait::is_input;
static constexpr bool const
  is_input_contiguous = trait::input::is_contiguous;

static constexpr bool const
  is_input_temporary = trait::input::is_temporary;

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

Range range;
Func func;

};

} /* range layer */
#endif

