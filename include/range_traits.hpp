// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_TRAITS_HPP
#define RANGE_LAYER_RANGE_TRAITS_HPP

namespace range_layer {

namespace execution_policy {
class sequenced {};
class parallel {};
class parallel_unsequenced {};

template <typename Policy> class gpu {};
template <typename Policy> class cpu {};
template <typename Policy> class remote {};
}

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
, countable // count -> {N1, N2, N3...}
, uncountable // count > or < size_type
};

template <typename Range>
struct range_traits {

/* interface traits */
/* next */
/* write, has_writable, write_size */
static constexpr bool const is_output = Range::is_output;
/* read, has_readable. read_size */
static constexpr bool const is_input = Range::is_input;
/* erase, shrink */
static constexpr bool const is_erasable
  = Range::is_erasable;

/* insert, expand */
static constexpr bool const
  is_insertable = Range::is_insertable;

/* prev, prev_has_readable, prev_has_writable */
static constexpr bool const
  is_reversable = Range::is_reversable;

static constexpr validation_type const
  validation = Range::validation;

/* true = read and write are mutually exclusive */
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

}; /* range traits */

namespace check {

template <typename Range>
struct is_output {
  static_assert (
    range_traits<Range>::is_output == false
  , "Error: Not an output Range."
  );
};

template <typename Range>
struct is_input {
  static_assert (
    range_traits<Range>::is_input == false
  , "Error: Not an input Range."
  );
};

template <typename Range>
struct is_reversable {
  static_assert (
    range_traits<Range>::is_reversable == false
  , "Error: Not an reversable Range."
  );
};

template <typename Range>
struct is_io_synced {
  static_assert (
    range_traits<Range>::is_io_synced == false
  , "Error: Range Input / Ouput is not synced."
  );
};

template <typename Range>
struct is_output_temporary 
: public is_output<Range>
{
  static_assert (
    range_traits<Range>::output::is_temporary == false
  , "Error: Output data is not temporary."
  );
};

template <typename Range>
struct is_input_temporary 
: public is_input<Range>
{
  static_assert (
    range_traits<Range>::input::is_temporary == false
  , "Error: Input data is not temporary."
  );
};

template <typename Range>
struct is_io_temporary 
: public is_input_temporary<Range>
, is_output_temporary<Range>
{};

template <typename Range>
struct is_input_countable
: public is_input<Range>
{
  static_assert (
     range_traits<Range>::input::size_type
  == range_size::countable
  , "Error: Input data is not countable."
  );
};

template <typename Range>
struct is_input_finite
: public is_input<Range>
{
  static_assert (
     range_traits<Range>::input::size_type
  == range_size::finite
  , "Error: Input data is not finite."
  );
};

template <typename Range>
struct is_input_uncountable
: public is_input<Range>
{
  static_assert (
     range_traits<Range>::input::size_type
  == range_size::uncountable
  , "Error: Input data is not uncountable."
  );
};

template <typename Range>
struct is_insertable {
  static_assert (
     range_traits<Range>::is_insertable == false
  , "Error: Input data is not uncountable."
  );
};

} /* check */ } /* range layer */
#endif

