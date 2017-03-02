//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SUB_RANGE_HPP
#define RANGE_LAYER_SUB_RANGE_HPP

#include "range_traits.hpp"

namespace range_layer {

template <
  typename Range, typename Traits = range_traits<Range> >
class sub_range {

public:

Range range;
std::size_t start;
std::size_t finish;
std::size_t next_jump;
std::size_t prev_jump;
std::size_t pos;

public:

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
using difference_type = typename Traits::difference_type;

sub_range (
  Range
, std::size_t
, std::size_t _finish = 0
);

sub_range (sub_range const &) = default;
sub_range& operator = (sub_range const &) = default;
sub_range (sub_range &&) = default;
sub_range& operator = (sub_range &&) = default;
~sub_range() = default;

void jump();

};

template <typename Range, typename Traits>
void
sub_range<Range, Traits>::jump (
){
this->range = next(this->range, this->next_jump);
this->next_jump = 0;
}

template <typename Range, typename Traits>
sub_range<Range, Traits>::sub_range (
  Range _range
, std::size_t _start
, std::size_t _finish
)
: range {_range}
, start {_start}
, finish {_finish}
, next_jump {_start}
, prev_jump {0}
, pos {_start}
{}

template <typename Range, typename Traits>
auto
read (
  sub_range<Range, Traits> & _range
) -> decltype (read(_range.range))
{
_range.jump();
++_range.pos;
return read(_range.range);
}

template <typename Range, typename T, typename Traits>
void
write (
  sub_range<Range, Traits> & _range
, T const & _var
){
_range.jump();
++_range.pos;
write(_range.range, _var);
}

template <typename Range, typename Traits>
auto
read (
  sub_range<Range, Traits> && _range
) -> decltype (read(_range.range))
{
return read(_range.range);
}

template <typename Range, typename T, typename Traits>
void
write (
  sub_range<Range, Traits> && _range
, T const & _var
){
write(_range, _var);
}

template <typename Range, typename Traits>
bool
is_readable (
  sub_range<Range, Traits> _range
){
_range.jump();
  if ((_range.pos > _range.finish) && _range.finish != 0)
  return false;
return is_readable(_range.range);
}

template <typename Range, typename Traits>
typename Traits::difference_type
input_size (
  sub_range<Range, Traits> _range
){
return input_size(_range.range);
}

template <typename Range, typename Traits>
typename Traits::difference_type
output_size (
  sub_range<Range, Traits> _range
){
return output_size(_range.range);
}

template <typename Range, typename Traits>
bool
is_writable (
  sub_range<Range, Traits> _range
){
_range.jump();
  if (_range.pos < _range.start) return false;
return is_writable(_range.range);
}

template <typename Range, typename Traits>
sub_range<Range, Traits>
next (
  sub_range<Range, Traits> _range
, typename Traits::difference_type _n = 1
){
_range.next_jump += _n;
_range.pos += _range.next_jump;
  if ((_range.pos >= _range.finish) && _range.finish != 0){
  _range.pos = _range.finish + 1; // set past the end
  _range.next_jump = _range.finish; // set jump to the end
  }
_range.range = next(_range.range, _range.next_jump);
_range.next_jump = 0;
return _range;
}

template <typename Range, typename Traits>
sub_range<Range, Traits>
prev (
  sub_range<Range, Traits> _range
, typename Traits::difference_type _n = 1
){
_range.jump();
_range.prev_jump += _n;
_range.pos -= _range.prev_jump;
  if (_range.pos <= _range.start){
  _range.pos = _range.start - 1;
  _range.prev_jump = _range.finish;
  }
_range.range = prev(_range.range, _range.prev_jump);
_range.prev_jump = 0;
return _range;
}

} /* range layer */
#endif

