//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SUB_RANGE_HPP
#define RANGE_LAYER_SUB_RANGE_HPP

#include "range_traits.hpp"

template <typename Range, typename N = std::size_t>
class sub_range {

Range range;
N pos;
N last;

public:


sub_range (
  Range
, N _start
, N _finish = 0
);

sub_range (sub_range const &) = default;
sub_range& operator = (sub_range const &) = default;
sub_range (sub_range &&) = default;
sub_range& operator = (sub_range &&) = default;
~sub_range() = default;

};

template <typename Range, typename N>
sub_range<Range, N>::sub_range (
  Range _range
, N _start
, N _finish
)
: range {_range}
, pos {0}
, last {_finish}
{}

template <typename Range, typename N>
auto
read (
  sub_range<Range, N> & _range
) -> decltype (read(_range.range))
{
_range.jump();
++_range.pos;
return read(_range.range);
}

template <typename Range, typename T, typename N>
void
write (
  sub_range<Range, N> & _range
, T const & _var
){
_range.jump();
++_range.pos;
write(_range.range, _var);
}

template <typename Range, typename N>
auto
read (
  sub_range<Range, N> && _range
) -> decltype (read(_range.range))
{
return read(_range.range);
}

template <typename Range, typename T, typename N>
void
write (
  sub_range<Range, N> && _range
, T const & _var
){
write(_range, _var);
}

template <typename Range, typename N>
bool
is_readable (
  sub_range<Range, N> _range
){
_range.jump();
  if ((_range.pos > _range.finish) && _range.finish != 0)
  return false;
return is_readable(_range.range);
}

template <typename Range, typename N>
typename N::difference_type
input_size (
  sub_range<Range, N> _range
){
return input_size(_range.range);
}

template <typename Range, typename N>
typename N::difference_type
output_size (
  sub_range<Range, N> _range
){
return output_size(_range.range);
}

template <typename Range, typename N>
bool
is_writable (
  sub_range<Range, N> _range
){
_range.jump();
  if (_range.pos < _range.start) return false;
return is_writable(_range.range);
}

template <typename Range, typename N>
sub_range<Range, N>
next (
  sub_range<Range, N> _range
, typename N::difference_type _n = 1
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

template <typename Range, typename N>
sub_range<Range, N>
prev (
  sub_range<Range, N> _range
, typename N::difference_type _n = 1
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
}*/

} /* range layer */
#endif

