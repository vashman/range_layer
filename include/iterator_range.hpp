// Range wrapper for iterators.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ITERATOR_RANGE_HPP
#define RANGE_LAYER_ITERATOR_RANGE_HPP

#include <iterator>
#include "range_traits.hpp"

namespace range_layer {

template <typename Iter, typename IterEnd = Iter>
struct iterator_range {

static constexpr bool const is_output = false;
static constexpr bool const is_input = true;
static constexpr bool const is_input_contiguous = false;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_input_size_known = false;
static constexpr bool const is_output_contiguous = false;
static constexpr bool const is_output_temporary = false;
static constexpr bool const is_output_size_known = false;
static constexpr bool const is_reversable = false;
using difference_type
  = std::iterator_traits<Iter>::difference_type;

Iter iter_begin;
IterEnd iter_end;

};

template <typename Iter>
struct iterator_range<Iter, void> {

static constexpr bool const is_output = true;
static constexpr bool const is_input = false;
static constexpr bool const is_input_contiguous = false;
static constexpr bool const is_input_temporary = false;
static constexpr bool const is_input_size_known = false;
static constexpr bool const is_output_contiguous = false;
static constexpr bool const is_output_temporary = true;
static constexpr bool const is_output_size_known = false;
static constexpr bool const is_reversable = false;
using difference_type
  = std::iterator_traits<Iter>::difference_type;

Iter iter_begin;

};

template <typename Iter, typename IterEnd>
Iter
begin (
  iterator_range<Iter, IterEnd> & _range
){
return _range.iter_begin;
}

template <typename Iter, typename IterEnd>
Iter
end (
  iterator_range<Iter, IterEnd> & _range
){
return _range.iter_end;
}

template <typename Iter, typename IterEnd>
Iter
begin (
  iterator_range<Iter, IterEnd> const & _range
){
return _range.iter_begin;
}

template <typename Iter, typename IterEnd>
Iter
end (
  iterator_range<Iter, IterEnd> const & _range
){
return _range.iter_end;
}

template <typename Iter, typename IterEnd>
typename std::iterator_traits<Iter>::value_type
read (
  iterator_range<Iter, IterEnd> _range
){
return *begin(_range)++;
}

template <typename Iter, typename IterEnd, typename T>
void
write (
  iterator_range<Iter, IterEnd> & _range
, T const & _var
){
*begin(_range)++ = _var;
}

template <typename Iter, typename IterEnd>
bool
is_readable (
  iterator_range<Iter, IterEnd> const _range
){
// UB if called on incremented iterator.
return begin(_range) == end(_range);
}

template <typename Iter, typename IterEnd>
bool
is_writable (
  iterator_range<Iter, IterEnd> const _range
){
// UB if called on incremented iterator. ie next (range);
return begin(_range) != end(_range);
}

template <typename Iter>
bool
is_writable (
  iterator_range<Iter, void> const _range
){
return false;
}

template <typename Iter, typename IterEnd>
iterator_range<Iter, IterEnd>
next (
  iterator_range<Iter, IterEnd> _range
,   typename range_traits<iterator_range<Iter, IterEnd>
  ::difference_type _n = 1
){
  while (0 != _n--) ++_range.iter_begin;
return _range;
}

template <typename Iter, typename IterEnd>
iterator_range<Iter, IterEnd>
prev (
  iterator_range<Iter, IterEnd> _range
,   typename range_traits<iterator_range<Iter, IterEnd>
  ::difference_type _n = 1
){
  while (0 != _n--) --_range.iter_begin;
return _range;
}

} /* range layer */
#endif
