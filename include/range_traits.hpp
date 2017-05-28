// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_TRAITS_HPP
#define RANGE_LAYER_RANGE_TRAITS_HPP

namespace range_layer {

namespace sentinel {

class readable {};
class writable {};

} /* sentinel */

enum class validation_type {
  // Only a single instance may be transversed.
  single
  // All instances transverse at the same time. 
, synced
  // All instances maintain there postion indepent of others.
, unsynced
};

enum class range_size {
  finite // count <= size_type
, countable // count > size_type {N1, N2, N3...}
, uncountable // count unknown to size_type; 0, 1, infinity
};

template <typename Range>
struct range_traits {

/* interface traits */
/* ++ (advance, next) */
/* if true; = (write) */
static constexpr bool const is_output = Range::is_output;
/* if true; * (read) */
static constexpr bool const is_input = Range::is_input;
/* if false;  += N, -=N (advance N, next N, prev N) */
static constexpr bool const is_linear = Range::is_linear;
/* if true; erase, shrink */
static constexpr bool const is_erasable
  = Range::is_erasable;

/* if true; insert, expand */
static constexpr bool const
  is_insertable = Range::is_insertable;

/* if true; -- (prev, advance_prev) */
static constexpr bool const
  is_reversable = Range::is_reversable;

static constexpr validation_type const
  validation = Range::validation;

/* if true; read and write are mutually exclusive */
static constexpr bool const
  is_io_synced = Range::is_io_synced;

/* data traits */
struct input {
  /* input_size */
  static constexpr range_size const
    size_type = Range::input_size_type;

  // if true, the read function performs UB when reading to
  // the same postion more than once.
  static constexpr bool const
    is_temporary = Range::is_input_temporary;
};

struct output {
  /* output_size */
  static constexpr range_size const
    size_type = Range::output_size_type;

  // if true, the write function performs UB when writing to
  // the same postion more than once.
  static constexpr bool const
    is_temporary = Range::is_output_temporary;
};

/* if true; T& range[n] */
static constexpr bool const is_subscriptable
  = is_reversable
 && is_input
 && is_output
 && is_io_synced
 && (is_linear == false)
 && (input::size_type == range_size::finite)
 && (output::size_type == range_size::finite);

}; /* range traits */

} /* range layer */
#endif

