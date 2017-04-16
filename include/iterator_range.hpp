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

template <
  typename Iter
, typename IterEnd = Iter
, typename Ca = std::iterator_traits<Iter>::iterator_category
>
struct iterator_range;



template <typename Iter, typename IterEnd = Iter>
struct iterator_range
<Iter, IterEnd, std::forward_iterator_tag> {

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_reversable = true;

static constexpr bool const is_io_synced = true;
static constexpr bool const is_erasable = false;
static constexpr bool const is_insertable = false;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_output_temporary = true;

static constexpr validation_type const
  validation = validation_type::unsynced;

static constexpr range_size const
  input_size_type = range_size::countable;

static constexpr range_size const
  output_size_type = range_size::countable;

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
auto
read (
  iterator_range<Iter, IterEnd> _range
)
-> decltype (*_range.iter_begin)
{
return *begin(_range);
}

template <typename Iter, typename IterEnd, typename T>
void
write (
  iterator_range<Iter, IterEnd> _range
, T const & _var
){
*_range.iter_begin = _var;
}

template <typename Iter, typename IterEnd>
auto
read_count (
  iterator_range<Iter, IterEnd> const _range
)
-> decltype (_range.iter_begin - _range.iter_end)
{
// UB if called on incremented iterator.
return _range.iter_begin - _range.iter_end;
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
