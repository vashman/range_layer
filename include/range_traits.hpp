// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_TRAITS_HPP
#define RANGE_LAYER_RANGE_TRAITS_HPP

namespace range_layer {

enum class validation_type {
  // Only a single instance may be transversed.
  single
  // All instances transverse at the same time. 
, synced
  // All instances maintain there postion indepent of others
, unsynced
};

template <typename Range>
struct range_traits {

/* interface traits */
/* next */
/* write, write_size, is_write_end */
static constexpr bool const is_output = Range::is_output;
/* read, read_size, is_read_end */
static constexpr bool const is_input = Range::is_input;
/* prev, is_read_begin, is_write_begin */
static constexpr bool const
  is_reversable = Range::is_reversable;

static constexpr validation_type const
  validation = Range::validation;

using size_type = typename Range::size_type;
static constexpr size_type const zero = Range::zero;

/* data traits */
struct input {
  static constexpr bool const
    is_contiguous = Range::is_input_contiguous; 

  // if true, the read function performs UB when reading to
  // the same postion more than once.
  static constexpr bool const
    is_temporary = Range::is_input_temporary;
};

struct output {
  static constexpr bool const
    is_contiguous = Range::is_output_contiguous; 

  // if true, the write function performs UB when writing to
  // the same postion more than once.
  static constexpr bool const
    is_temporary = Range::is_output_temporary;
};

}; /* range traits */

} /* range layer */
#endif

