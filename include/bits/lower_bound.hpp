//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_LOWER_BOUND_HPP
#define RANGE_LAYER_LOWER_BOUND_HPP

namespace range_layer {

template <typename Range>
struct lower_bound {

using trait = range_traits<Range>;

static constexpr bool const is_output = trait::is_output;
static constexpr bool const is_input = trait::is_input;
static constexpr bool const is_erasable = trait::is_erasable;

static constexpr bool const
  is_insertable = trait::is_insertable;

static constexpr bool const
  is_io_synced = trait::is_io_synced;

static constexpr bool const
  is_reversable = trait::is_reversable;

static constexpr validation_type const
  validation = trait::validation;

static constexpr bool const
  is_input_temporary = trait::input::is_temporary;

static constexpr range_size const
  input_size_type = trait::input::size_type;

static constexpr bool const
  is_output_temporary = trait::output::is_temporary;

static constexpr range_size const
  output_size_type = trait::output::size_type;

Range range;

N start; // = 1; if >= c++14
N pos; // = 0;

}; /* lower bound */


template <typename Range>
bool
has_readable (
  lower_bound<Range> & _range
){
  if (_range.pos 
auto a = _range.start;
auto b = read_count(_range.range);
return !(b<a)?a:b;
}

template <typename Range>
auto
has_writable (
  lower_bound<Range> & _range
){
  if (_range.pos < 1) return false;
return is_writable(_range.range);
}

} /* range layer */
#endif

