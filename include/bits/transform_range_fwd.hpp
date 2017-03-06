//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP
#define RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP

namespace range_layer {

template <typename Func, typename Range, typename Traits>
struct input_transform_range;

template <typename Func, typename Range, typename Traits>
struct output_transform_range;

// Input
template <typename Func, typename Range, typename Traits>
auto
read (
  input_transform_range<Func, Range, Traits> & _range
)
-> decltype (_range.func(read(_range.range)));

template <typename Func, typename Range, typename Traits>
auto
read (
  input_transform_range<Func, Range, Traits> && _range
)
-> decltype (_range.func(read(_range.range)));

template <typename Func, typename Range, typename Traits>
bool
is_readable (
  input_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
input_size (
  input_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
bool
is_readable (
  input_transform_range<Func, Range, Traits> &&
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
input_size (
  input_transform_range<Func, Range, Traits> &&
);

template
<typename T, typename Range, typename Traits, typename Func>
void
write (
  input_transform_range<Func, Range, Traits> &
, T const & _var
);

template
<typename T, typename Range, typename Traits, typename Func>
void
write (
  input_transform_range<Func, Range, Traits> &&
, T const & _var
);

template <typename Func, typename Range, typename Traits>
bool
is_writable (
  input_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
bool
is_writable (
  input_transform_range<Func, Range, Traits> &&
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
output_size (
  input_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
output_size (
  input_transform_range<Func, Range, Traits> &&
);

template <typename Func, typename Range, typename Traits>
input_transform_range<Func, Range, Traits>
next (
  input_transform_range<Func, Range, Traits> &
, typename Traits::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
input_transform_range<Func, Range, Traits>
next (
  input_transform_range<Func, Range, Traits> &&
, typename Traits::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
input_transform_range<Func, Range, Traits>
prev (
  input_transform_range<Func, Range, Traits> &&
, typename Traits::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
input_transform_range<Func, Range, Traits>
prev (
  input_transform_range<Func, Range, Traits> &
, typename Traits::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
  typename range_traits
  <input_transform_range<Func, Range, Traits>>
::difference_type
input_position (
 input_transform_range<Func, Range, Traits> & _range
);

template <typename Func, typename Range, typename Traits>
  typename range_traits
  <input_transform_range<Func, Range, Traits>>
::difference_type
output_position (
 input_transform_range<Func, Range, Traits> & _range
);

// Output
template <typename Func, typename Range, typename Traits>
auto
read (
  output_transform_range<Func, Range, Traits> & _range
)
-> decltype (read(_range.range));

template <typename Func, typename Range, typename Traits>
auto
read (
  output_transform_range<Func, Range, Traits> && _range
)
-> decltype (read(_range.range));

template <typename Func, typename Range, typename Traits>
bool
is_readable (
  output_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
bool
is_readable (
  output_transform_range<Func, Range, Traits> &&
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
input_size (
  output_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
input_size (
  output_transform_range<Func, Range, Traits> &&
);

template
<typename T, typename Range, typename Traits, typename Func>
void
write (
  output_transform_range<Func, Range, Traits> &
, T const & _var
);

template
<typename T, typename Range, typename Traits, typename Func>
void
write (
  output_transform_range<Func, Range, Traits> &&
, T const & _var
);

template <typename Func, typename Range, typename Traits>
bool
is_writable (
  output_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
bool
is_writable (
  output_transform_range<Func, Range, Traits> &&
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
output_size (
  output_transform_range<Func, Range, Traits> &
);

template <typename Func, typename Range, typename Traits>
typename Traits::difference_type
output_size (
  output_transform_range<Func, Range, Traits> &&
);

template <typename Func, typename Range, typename Traits>
output_transform_range<Func, Range, Traits>
next (
  output_transform_range<Func, Range, Traits> &
, typename Traits::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
output_transform_range<Func, Range, Traits>
next (
  output_transform_range<Func, Range, Traits> &&
, typename Traits::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
output_transform_range<Func, Range, Traits>
prev (
  output_transform_range<Func, Range, Traits> &&
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
output_transform_range<Func, Range, Traits>
prev (
  output_transform_range<Func, Range, Traits> &
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Func, typename Range, typename Traits>
  typename range_traits
  <output_transform_range<Func, Range, Traits>>
::difference_type
input_position (
 output_transform_range<Func, Range, Traits> & _range
);

template <typename Func, typename Range, typename Traits>
  typename range_traits
  <output_transform_range<Func, Range, Traits>>
::difference_type
output_position (
 output_transform_range<Func, Range, Traits> & _range
);

} /* range layer */
#endif

