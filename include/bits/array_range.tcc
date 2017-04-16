//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ARRAY_RANGE_TCC
#define RANGE_LAYER_ARRAY_RANGE_TCC

namespace range_layer {

template <typename T>
array_range<T>::array_range (
  T * _array
, T * _end
)
: array (_array)
, pos {_array}
, end_pos {_end}
{}

template <typename T>
T&
read (
  array_range<T> & _range
){
return *_range.pos;
}

template <typename T>
T&
read (
  array_range<T> && _range
){
return read(_range);
}

template <typename T>
bool
has_readable (
  array_range<T> const & _range
){
return _range.end_pos != _range.pos;
}

template <typename T>
void
write (
  array_range<T> & _range
, T const & _var
){
*_range.pos = _var;
}

template <typename T>
void
write (
  array_range<T> && _range
, T const & _var
){
write(_range, _var);
}

template <typename T>
bool
has_writable (
  array_range<T> const & _range
){
return has_readable(_range);
}

template <typename T>
void
advance (
  array_range<T> & _range
, std::size_t const _n
){
_range.pos += _n;
}

template <typename T>
array_range<T>
next (
  array_range<T> _range
, std::size_t const _n
){
_range.pos += _n;
return _range;
}

template <typename T>
void
prev_advance (
  array_range<T> & _range
, std::size_t const _n
){
_range.pos -= _n;
}

template <typename T>
array_range<T>
prev (
  array_range<T> _range
, std::size_t _n
){
_range.pos -= _n;
return _range;
}

} /* range layer */
#endif

