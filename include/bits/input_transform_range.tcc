//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_INPUT_TRANSFORM_RANGE_TCC
#define RANGE_LAYER_INPUT_TRANSFORM_RANGE_TCC

namespace range_layer {

template <typename Range, typename Func>
input_transform_range<Func, Range>
make_input_transform_range (
  Range _range
, Func _func
){
return input_transform_range<Func, Range>{_range, _func};
}

template <typename Func, typename Range>
auto
read (
  input_transform_range<Func, Range> & _range
)
-> decltype (_range.func(read(_range.range)))
{
return _range.func(read(_range.range));
}

template <typename Func, typename Range>
auto
read (
  input_transform_range<Func, Range> && _range
)
-> decltype (_range.func(read(_range.range)))
{
return read(_range);
}

template <typename Func, typename Range>
bool
has_readable (
  input_transform_range<Func, Range> & _range
){
return has_readable(_range.range);
}

template <typename Func, typename Range>
bool
has_readable (
  input_transform_range<Func, Range> && _range
){
return has_readable(_range.range);
}

template <typename Func, typename Range>
bool
prev_has_readable (
  input_transform_range<Func, Range> & _range
){
return prev_has_readable(_range.range);
}

template <typename Func, typename Range>
bool
prev_has_readable (
  input_transform_range<Func, Range> && _range
){
return prev_has_readable(_range.range);
}

template <typename T, typename Range, typename Func>
void
write (
  input_transform_range<Func, Range> & _range
, T const & _var
){
write(_range.range, _range.func(_var));
}

template <typename T, typename Range, typename Func>
void
write (
  input_transform_range<Func, Range> && _range
, T const & _var
){
write(_range, _var);
}

template <typename Func, typename Range>
bool
has_writeable (
  input_transform_range<Func, Range> & _range
){
return has_writeable(_range.range);
}

template <typename Func, typename Range>
bool
has_writeable (
  input_transform_range<Func, Range> && _range
){
return has_writeable(_range.range);
}

template <typename Func, typename Range>
bool
prev_has_writeable (
  input_transform_range<Func, Range> & _range
){
return prev_has_writeable(_range.range);
}

template <typename Func, typename Range>
bool
prev_has_writeable (
  input_transform_range<Func, Range> && _range
){
return prev_has_writeable(_range.range);
}

template <typename Func, typename Range>
input_transform_range<Func, Range>
next (
  input_transform_range<Func, Range> & _range
){
_range.range = next(_range.range);
return _range;
}

template <typename Func, typename Range>
input_transform_range<Func, Range>
next (
  input_transform_range<Func, Range> && _range
){
_range.range = next(_range.range);
return _range;
}

template <typename Func, typename Range, typename N>
input_transform_range<Func, Range>
next (
  input_transform_range<Func, Range> & _range
, N _n
){
_range.range = next(_range.range, _n);
return _range;
}

template <typename Func, typename Range, typename N>
input_transform_range<Func, Range>
next (
  input_transform_range<Func, Range> && _range
, N _n
){
_range.range = next(_range.range, _n);
return _range;
}

template <typename Func, typename Range>
void
advance (
  input_transform_range<Func, Range> & _range
){
advance(_range.range);
}

template <typename Func, typename Range, typename N>
void
advance (
  input_transform_range<Func, Range> & _range
, N _n
){
advance(_range.range, _n);
}

template <typename Func, typename Range>
void
prev_advance (
  input_transform_range<Func, Range> & _range
){
prev_advance(_range.range);
}

template <typename Func, typename Range, typename N>
void
prev_advance (
  input_transform_range<Func, Range> & _range
, N _n
){
prev_advance(_range.range, _n);
}

template <typename Func, typename Range>
input_transform_range<Func, Range>
prev (
  input_transform_range<Func, Range> & _range
){
_range.range = prev(_range.range);
return _range;
}

template <typename Func, typename Range>
input_transform_range<Func, Range>
prev (
  input_transform_range<Func, Range> && _range
){
_range.range = prev(_range.range);
return _range;
}

template <typename Func, typename Range, typename N>
input_transform_range<Func, Range>
prev (
  input_transform_range<Func, Range> & _range
, N _n
){
_range.range = prev(_range.range, _n);
return _range;
}

template <typename Func, typename Range, typename N>
input_transform_range<Func, Range>
prev (
  input_transform_range<Func, Range> && _range
, N _n
){
_range.range = prev(_range.range, _n);
return _range;
}

template <typename Func, typename Range>
Range
erase (
  input_transform_range<Func, Range> & _range
){
return erase(_range.range);
}

template <typename Func, typename Range>
Range
erase (
  input_transform_range<Func, Range> && _range
){
return erase(_range.range);
}

template <typename Func, typename Range>
Range
insert (
  input_transform_range<Func, Range> & _range
){
return insert(_range.range);
}

template <typename Func, typename Range>
Range
insert (
  input_transform_range<Func, Range> && _range
){
return insert(_range.range);
}

template <typename Func, typename Range, typename N>
Range
expand (
  input_transform_range<Func, Range> & _range
, N _n
){
return expand(_range.range, _n);
}

template <typename Func, typename Range, typename N>
Range
shrink (
  input_transform_range<Func, Range> & _range
, N _n
){
return shrink(_range.range, _n);
}

template <typename Func, typename Range, typename N>
Range
expand (
  input_transform_range<Func, Range> && _range
, N _n
){
return expand(_range.range, _n);
}

template <typename Func, typename Range, typename N>
Range
shrink (
  input_transform_range<Func, Range> && _range
, N _n
){
return shrink(_range.range, _n);
}

} /* range layer */
#endif

