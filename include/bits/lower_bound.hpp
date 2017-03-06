//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_LOWER_BOUND_HPP
#define RANGE_LAYER_LOWER_BOUND_HPP

namespace range_layer {

template <
  typename Range, typename Traits = range_traits<Range> >
struct lower_bound {

static constexpr bool const is_output = Traits::is_output;
static constexpr bool const is_input = Traits::is_input;
static constexpr bool const
  is_input_contiguous = Traits::input::is_contiguous;

static constexpr bool const
  is_input_temporary = Traits::input::is_temporary;

static constexpr bool const
  is_input_size_known = Traits::input::is_size_known;

static constexpr bool const is_input_position_known
  = Traits::input::is_position_known;

static constexpr bool const
  is_output_contiguous = Traits::output::is_contiguous;

static constexpr bool const
  is_output_temporary = Traits::output::is_temporary;

static constexpr bool const
  is_output_size_known = Traits::output::is_size_known;

static constexpr bool const is_output_position_known
  = Traits::output::is_position_known;

static constexpr bool const
  is_reversable = Traits::is_reversable;

using difference_type = typename Traits::difference_type;

Range range;
difference_type start; // = 1; >= c++14
difference_type pos; // = 0;

}; /* lower bound */

template <typename Range, typename Traits>
auto
read (
  lower_bound<Range, Traits> & _range
) -> decltype (read(_range.range))
{
++_range.pos;
return read(_range.range);
}

template <typename Range, typename T, typename Traits>
void
write (
  lower_bound<Range, Traits> & _range
, T const & _var
){
++_range.pos;
write(_range.range, _var);
}

template <typename Range, typename Traits>
auto
read (
  lower_bound<Range, Traits> && _range
) -> decltype (read(_range.range))
{
return read(_range.range);
}

template <typename Range, typename T, typename Traits>
void
write (
  lower_bound<Range, Traits> && _range
, T const & _var
){
write(_range, _var);
}

template <typename Range, typename Traits>
bool
is_readable (
  lower_bound<Range, Traits> _range
){
  if (_range.pos < 1) return false;
return is_readable(_range.range);
}

template <typename Range, typename Traits>
typename Traits::difference_type
input_size (
  lower_bound<Range, Traits> _range
){
return input_size(_range.range);
}

template <typename Range, typename Traits>
typename Traits::difference_type
output_size (
  lower_bound<Range, Traits> _range
){
return output_size(_range.range);
}

template <typename Range, typename Traits>
bool
is_writable (
  lower_bound<Range, Traits> _range
){
  if (_range.pos < 1) return false;
return is_writable(_range.range);
}

template <typename Range, typename Traits>
lower_bound<Range, Traits>
next (
  lower_bound<Range, Traits> _range
, typename Traits::difference_type _n = 1
){
_range.pos += _n;
_range.range = next(_range.range, _n);
return _range;
}

template <typename Range, typename Traits>
lower_bound<Range, Traits>
prev (
  lower_bound<Range, Traits> _range
, typename Traits::difference_type _n = 1
){
_range.pos -= _n;
  if (_range.pos < _range.start)
  _range.pos = _range.start - 1; // set past the start

_range.range = prev(_range.range, _n);
return _range;
}

template <typename Range, typename Traits>
typename Traits::difference_type
input_position (
  lower_bound<Range, Traits> _range
){
return input_position(_range);
}

template <typename Range, typename Traits>
typename Traits::difference_type
output_position (
  lower_bound<Range, Traits> _range
){
return output_position(_range);
}

} /* range layer */
#endif

