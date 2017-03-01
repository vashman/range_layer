//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_TCC
#define RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_TCC

namespace range_layer {

template <typename Range, typename Func>
auto
read (
  output_transform_range<Range, Func> & _range
)
-> decltype (_range.func(read(_range.range)))
{
return _range.func(read(_range.range));
}

template <typename Range, typename Func>
auto
read (
  output_transform_range<Range, Func> && _range
)
-> decltype (read(_range.range))
{
return read(_range);
}

template <typename Range, typename Func>
bool
is_readable (
  output_transform_range<Range, Func> & _range
){
return is_readable(_range.range);
}

template <typename Range, typename Func>
bool
is_readable (
  output_transform_range<Range, Func> && _range
){
return is_readable(_range.range);
}

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
input_size (
  output_transform_range<Range, Func> & _range
){
return input_size(_range.range);
}

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
input_size (
  output_transform_range<Range, Func> && _range
){
return input_size(_range);
}

template <typename T, typename Range, typename Func>
void
write (
  output_transform_range<Range, Func> & _range
, T const & _var
){
write(_range.range, _range.func(_var));
}

template <typename T, typename Range, typename Func>
void
write (
  output_transform_range<Range, Func> && _range
, T const & _var
){
write(_range, _var);
}

template <typename Range, typename Func>
bool
is_writable (
  output_transform_range<Range, Func> & _range
){
return is_writable(_range.range);
}

template <typename Range, typename Func>
bool
is_writable (
  output_transform_range<Range, Func> && _range
){
return is_writable(_range);
}

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
output_size (
  output_transform_range<Range, Func> & _range
){
return output_size(_range.range);
}

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
output_size (
  output_transform_range<Range, Func> && _range
){
return output_size(_range);
}

template <typename Range, typename Func>
output_transform_range<Range, Func>
next (
  output_transform_range<Range, Func> & _range
, typename range_traits<Range>::difference_type _n
){
_range.range = next(_range.range, _n);
return _range;
}

template <typename Range, typename Func>
output_transform_range<Range, Func>
next (
  output_transform_range<Range, Func> && _range
, typename range_traits<Range>::difference_type _n
){
_range.range = next(_range.range, _n);
return _range;
}

template <typename Range, typename Func>
output_transform_range<Range, Func>
prev (
  output_transform_range<Range, Func> & _range
, typename range_traits<Range>::difference_type _n
){
_range.range = prev(_range.range, _n);
return _range;
}

template <typename Range, typename Func>
output_transform_range<Range, Func>
prev (
  output_transform_range<Range, Func> && _range
, typename range_traits<Range>::difference_type _n
){
_range.range = prev(_range.range, _n);
return _range;
}

} /* range layer */
#endif

