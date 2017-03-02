//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP

namespace range_layer {

template <
  typename Func
, typename Range
, typename Traits = range_traits<Range> >
struct output_transform_range {

static constexpr bool const is_output = Traits::is_output;
static constexpr bool const is_input = Traits::is_input;
static constexpr bool const
  is_input_contiguous = Traits::input::is_contiguous;

static constexpr bool const
  is_input_temporary = Traits::input::is_temporary;

static constexpr bool const
  is_input_size_known = Traits::input::is_size_known;

static constexpr bool const
  is_output_contiguous = Traits::output::is_contiguous;

static constexpr bool const
  is_output_temporary = Traits::output::is_temporary;

static constexpr bool const
  is_output_size_known = Traits::output::is_size_known;

static constexpr bool const
  is_reversable = Traits::is_reversable;

Range range;
Func func;

};

} /* range layer */
#endif

