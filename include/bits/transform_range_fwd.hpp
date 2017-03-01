//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP
#define RANGE_LAYER_TRANSFORM_RANGE_FWD_HPP

namespace range_layer {

template <typename Range, typename Func>
struct input_transform_range;

template <typename Range, typename Func>
struct output_transform_range;

// Input
template <typename Range, typename Func>
auto
read (
  input_transform_range<Range, Func> & _range
)
-> decltype (_range.func(read(_range.range)));

template <typename Range, typename Func>
auto
read (
  input_transform_range<Range, Func> && _range
)
-> decltype (_range.func(read(_range.range)));

template <typename Range, typename Func>
bool
is_readable (
  input_transform_range<Range, Func> &
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
input_size (
  input_transform_range<Range, Func> &
);

template <typename Range, typename Func>
bool
is_readable (
  input_transform_range<Range, Func> &&
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
input_size (
  input_transform_range<Range, Func> &&
);

template <typename T, typename Range, typename Func>
void
write (
  input_transform_range<Range, Func> &
, T const & _var
);

template <typename T, typename Range, typename Func>
void
write (
  input_transform_range<Range, Func> &&
, T const & _var
);

template <typename Range, typename Func>
bool
is_writable (
  input_transform_range<Range, Func> &
);

template <typename Range, typename Func>
bool
is_writable (
  input_transform_range<Range, Func> &&
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
output_size (
  input_transform_range<Range, Func> &
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
output_size (
  input_transform_range<Range, Func> &&
);

template <typename Range, typename Func>
input_transform_range<Range, Func>
next (
  input_transform_range<Range, Func> &
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Range, typename Func>
input_transform_range<Range, Func>
next (
  input_transform_range<Range, Func> &&
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Range, typename Func>
input_transform_range<Range, Func>
prev (
  input_transform_range<Range, Func> &&
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Range, typename Func>
input_transform_range<Range, Func>
prev (
  input_transform_range<Range, Func> &
, typename range_traits<Range>::difference_type _n = 1
);

// Output
template <typename Range, typename Func>
auto
read (
  output_transform_range<Range, Func> & _range
)
-> decltype (read(_range.range));

template <typename Range, typename Func>
auto
read (
  output_transform_range<Range, Func> && _range
)
-> decltype (read(_range.range));

template <typename Range, typename Func>
bool
is_readable (
  output_transform_range<Range, Func> &
);

template <typename Range, typename Func>
bool
is_readable (
  output_transform_range<Range, Func> &&
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
input_size (
  output_transform_range<Range, Func> &
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
input_size (
  output_transform_range<Range, Func> &&
);

template <typename T, typename Range, typename Func>
void
write (
  output_transform_range<Range, Func> &
, T const & _var
);

template <typename T, typename Range, typename Func>
void
write (
  output_transform_range<Range, Func> &&
, T const & _var
);

template <typename Range, typename Func>
bool
is_writable (
  output_transform_range<Range, Func> &
);

template <typename Range, typename Func>
bool
is_writable (
  output_transform_range<Range, Func> &&
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
output_size (
  output_transform_range<Range, Func> &
);

template <typename Range, typename Func>
typename range_traits<Range>::difference_type
output_size (
  output_transform_range<Range, Func> &&
);

template <typename Range, typename Func>
output_transform_range<Range, Func>
next (
  output_transform_range<Range, Func> &
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Range, typename Func>
output_transform_range<Range, Func>
next (
  output_transform_range<Range, Func> &&
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Range, typename Func>
output_transform_range<Range, Func>
prev (
  output_transform_range<Range, Func> &&
, typename range_traits<Range>::difference_type _n = 1
);

template <typename Range, typename Func>
output_transform_range<Range, Func>
prev (
  output_transform_range<Range, Func> &
, typename range_traits<Range>::difference_type _n = 1
);

} /* range layer */
#endif

