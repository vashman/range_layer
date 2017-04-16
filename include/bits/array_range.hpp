//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ARRAY_RANGE_HPP
#define RANGE_LAYER_BITS_ARRAY_RANGE_HPP

namespace range_layer {

template <typename T>
class array_range {

T * array;
T * pos;
T * end_pos;

public:

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_io_synced = true;
static constexpr bool const is_reversable = true;
static constexpr bool const is_erasable = false;
static constexpr bool const is_insertable = false;
static constexpr bool const is_input_temporary = false;
static constexpr bool const is_output_temporary = false;
static constexpr validation_type const
  validation = validation_type::unsynced;

static constexpr range_size const
  input_size_type = range_size::finite;

static constexpr range_size const
  output_size_type = range_size::finite;

array_range (
  T *
, T *
);

array_range (array_range const &) = default;
array_range& operator = (array_range const &) = default;
array_range& operator = (array_range &&) = default;
array_range (array_range &&) = default;
~array_range () = default;

friend T& read<T> (array_range &);
friend void write<T> (array_range &, T const &);
friend bool has_writable<T>(array_range const &);
friend bool has_readable<T>(array_range const &);
friend array_range next<T> (array_range, std::size_t const);
friend array_range prev<T> (array_range, std::size_t const);
friend void advance (array_range, std::size_t const);
friend void prev_advance (array_range, std::size_t const);

};

} /* range layer */
#endif

