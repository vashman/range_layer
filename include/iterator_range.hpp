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
, typename Cat =std::iterator_traits<Iter>::iterator_category
>
struct iterator_range;

// Input Iterator
template <typename Iter, typename IterEnd = Iter>
struct iterator_range
<Iter, IterEnd, std::input_iterator_tag> {

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_reversable = false;

static constexpr bool const is_io_synced = true;
static constexpr bool const is_erasable = false;
static constexpr bool const is_insertable = false;
static constexpr bool const is_input_temporary = true;
static constexpr bool const is_output_temporary = true;

static constexpr validation_type const
  validation = validation_type::single;

static constexpr range_size const
  input_size_type = range_size::countable;

static constexpr range_size const
  output_size_type = range_size::countable;

Iter iter_begin;
IterEnd iter_end;

std::iterator_traits<Iter>::reference
operator * (
){
return *this->iter_begin;
}

template <typename T>
void
operator = (
  T const & _var
){
*this->iter_begin = _var;
}

iterator_range &
operator ++ (
){
++this->iter_begin;
return *this;
}

iterator_range &
operator ++ (
  int
){
this->iter_begin++;
return *this;
}

};

template <typename Iter, typename IterEnd = Iter>
struct iterator_range
<Iter, IterEnd, std::forward_iterator_tag>
: public
  iterator_range<Iter, IterEnd, std::input_iterator_tag>
{

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_reversable = false;
static constexpr bool const is_linear = true;

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

};

template <typename Iter, typename IterEnd = Iter>
struct iterator_range
<Iter, IterEnd, std::bidirectional_iterator_tag>
: public
  iterator_range<Iter, IterEnd, std::forward_iterator_tag>
{

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_reversable = true;
static constexpr bool const is_linear = true;

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

iterator_range &
operator -- (
){
--this->iter_begin;
return *this;
}

};

template <typename Iter, typename IterEnd = Iter>
struct iterator_range
<Iter, IterEnd, std::random_iterator_tag>
: public
  iterator_range
  <Iter, IterEnd, std::bidirectional_iterator_tag>
{

static constexpr bool const is_output = true;
static constexpr bool const is_input = true;
static constexpr bool const is_reversable = true;
static constexpr bool const is_linear = false;

static constexpr bool const is_io_synced = true;
static constexpr bool const is_erasable = false;
static constexpr bool const is_insertable = false;
static constexpr bool const is_input_temporary = false;
static constexpr bool const is_output_temporary = false;

static constexpr validation_type const
  validation = validation_type::unsynced;

static constexpr range_size const
  input_size_type = range_size::countable;

static constexpr range_size const
  output_size_type = range_size::countable;

iterator_range &
operator += (
  std::iterator_traits<Iter>::difference_type const & _n
){
this->iter_begin += _n;
return *this;
}

iterator_range &
operator -= (
  std::iterator_traits<Iter>::difference_type const & _n
){
this->iter_begin -= _n;
return *this;
}

std::iterator_traits<Iter>::reference
operator [](
  int _n
){
return this->iter_begin[_n];
}

};

template <typename Iter>
struct iterator_range<Iter, void> {

static constexpr bool const is_output = true;
static constexpr bool const is_input = false;
static constexpr bool const is_reversable = false;
static constexpr bool const is_linear = true;

static constexpr bool const is_io_synced = false;
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

void
operator = (
  std::iterator_traits<Iter>::value_type _var
){
*this->iter_begin = _var;
}

iterator_range &
operator ++ (
){
++this->iter_begin;
}

};

template
  <typename Iter, typename End, typename Cat, typename T>
bool
operator == (
  iterator_range<Iter, End, Cat> const & _range
, T const & _sentinel
){
return _range.iter_begin == _sentinel;
}

template
  <typename Iter, typename End, typename Cat, typename T>
bool
operator != (
  iterator_range<Iter, End, Cat> const & _range
, T const & _sentinel
){
return _range.iter_begin != _sentinel;
}

template <typename Iter, typename IterEnd, typename Cat>
bool
operator == (
  iterator_range<Iter, IterEnd, Cat> const & _range
, sentinel::readable const & _sentinel
){
return _range.iter_begin == _range.iter_end;
}

template <typename Iter, typename IterEnd, typename Cat>
bool
operator != (
  iterator_range<Iter, IterEnd, Cat> const & _range
, sentinel::readable const & _sentinel
){
return _range.iter_begin != _range.iter_end;
}

template <typename Iter, typename IterEnd, typename Cat>
bool
operator == (
  iterator_range<Iter, IterEnd, Cat> const & _range
, sentinel::writable const & _sentinel
){
return _range.iter_begin == _range.iter_end;
}

template <typename Iter, typename IterEnd, typename Cat>
bool
operator != (
  iterator_range<Iter, IterEnd, Cat> const & _range
, sentinel::writable const & _sentinel
){
return _range.iter_begin != _range.iter_end;
}

template <typename Iter, typename T>
bool
operator == (
  iterator_range<Iter, void, std::output_iterator_tag>
  const & _range
, T const & _sentinel
){
return true;
}

template <typename Iter, typename T>
bool
operator != (
  iterator_range<Iter, void, std::output_iterator_tag>
  const & _range
, T const & _sentinel
){
return false;
}

template <typename Iter>
bool
operator == (
  iterator_range<Iter, void, std::output_iterator_tag>
  const & _range
, sentinel::readable const & _sentinel
){
return true;
}

template <typename Iter>
bool
operator != (
  iterator_range<Iter, void, std::output_iterator_tag>
  const & _range
, sentinel::readable const & _sentinel
){
return false;
}

template <typename Iter>
bool
operator == (
  iterator_range<Iter, void, std::output_iterator_tag>
  const & _range
, sentinel::writable const & _sentinel
){
return true;
}

template <typename Iter>
bool
operator != (
  iterator_range<Iter, void, std::output_iterator_tag>
  const & _range
, sentinel::writable const & _sentinel
){
return false;
}

} /* range layer */
#endif

