//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ARRAY_RANGE_HPP
#define RANGE_LAYER_BITS_ARRAY_RANGE_HPP

#include <iterator>

namespace range_layer {

template <typename T>
class array_range {

T * array;
T * pos;
T * end_pos;

public:

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_input_contiguous = true;
static constexpr bool const is_input_temporary = false;
static constexpr bool const is_input_size_known = true;
static constexpr bool const is_input_position_known = true;
static constexpr bool const is_output_contiguous = true;
static constexpr bool const is_output_temporary = false;
static constexpr bool const is_output_size_known = true;
static constexpr bool const is_output_position_known = true;
static constexpr bool const is_reversable = true;
using difference_type
  = typename std::iterator_traits<T*>::difference_type;

array_range (
  T *
, T *
);

array_range(array_range const &) = default;
array_range& operator = (array_range const &) = default;
array_range& operator = (array_range &&) = default;
array_range(array_range &&) = default;
~array_range() = default;

friend T& read<T> (array_range &);
friend bool is_readable<T> (array_range const &);
friend difference_type input_size<T> (array_range const &);
friend void write<T> (array_range &, T const &);
friend bool is_writable<T> (array_range const &);
friend difference_type output_size<T> (array_range const &);
friend array_range next<T> (array_range, difference_type);
friend array_range prev<T> (array_range, difference_type);
friend
difference_type input_position<T> (array_range const &);

friend
difference_type output_position<T>(array_range const &);

};

} /* range layer */
#endif

