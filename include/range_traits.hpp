// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_TRAITS_HPP
#define RANGE_LAYER_RANGE_TRAITS_HPP

namespace range_layer {

/* next */
template <typename Range>
struct range_traits {

/* interface traits */
/* write, is_writable */
static constexpr bool const is_output = Range::is_output;
/* read, is_readable */
static constexpr bool const is_input = Range::is_input;
/* prev */
static constexpr bool const
  is_reversable = Range::is_reversable;

using difference_type = typename Range::difference_type;

/* data traits */
struct input {
  static constexpr bool const
    is_contiguous = Range::is_input_contiguous; 

  static constexpr bool const
    is_temporary = Range::is_input_temporary;
  /* input_size */
  static constexpr bool const
    is_size_known = Range::is_input_size_known;
};

struct output {
  static constexpr bool const
    is_contiguous = Range::is_output_contiguous; 

  static constexpr bool const
    is_temporary = Range::is_output_temporary;
  /* output_size */
  static constexpr bool const
    is_size_known = Range::is_output_size_known;

};

};

} /* range layer */
#endif

