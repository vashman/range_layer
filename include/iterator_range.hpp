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
, typename Cat
    = typename std::iterator_traits<Iter>::iterator_category
>
struct iterator_range;

// Input Iterator
template <typename Iter, typename IterEnd>
struct iterator_range
<Iter, IterEnd, std::input_iterator_tag> {

using write_type
  = typename std::iterator_traits<Iter>::value_type;

Iter iter_begin;
IterEnd iter_end;

typename std::iterator_traits<Iter>::reference
read (
){
return *this->iter_begin;
}

template <typename T>
void
write (
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

iterator_range (
  Iter _iter
, IterEnd _end
)
: iter_begin {_iter}
, iter_end {_end}
{}

iterator_range (iterator_range const &) = default;
iterator_range (iterator_range &&) = default;

iterator_range & operator = (
  iterator_range const &
) = default;

iterator_range & operator = (iterator_range &&) = default;

};

template <typename Iter, typename IterEnd>
struct iterator_range
<Iter, IterEnd, std::forward_iterator_tag>
: public
  iterator_range<Iter, IterEnd, std::input_iterator_tag>
{

using write_type
  = typename std::iterator_traits<Iter>::value_type;

iterator_range (
  Iter _iter
, IterEnd _end
)
: iterator_range<Iter, IterEnd, std::input_iterator_tag>
  {_iter, _end}
{}

template <typename T>
void
write (
  T const & _var
){
*this->iter_begin = _var;
}

iterator_range (iterator_range const &) = default;
iterator_range (iterator_range &&) = default;

iterator_range & operator = (
  iterator_range const &
) = default;

iterator_range & operator = (iterator_range &&) = default;

};

template <typename Iter, typename IterEnd>
struct iterator_range
<Iter, IterEnd, std::bidirectional_iterator_tag>
: public
  iterator_range<Iter, IterEnd, std::forward_iterator_tag>
{

using write_type
  = typename std::iterator_traits<Iter>::value_type;

iterator_range &
operator -- (
){
--this->iter_begin;
return *this;
}

iterator_range (
  Iter _iter
, IterEnd _end
)
: iterator_range<Iter, IterEnd, std::forward_iterator_tag>
  {_iter, _end}
{}

iterator_range (iterator_range const &) = default;
iterator_range (iterator_range &&) = default;

iterator_range & operator = (
  iterator_range const &
) = default;

iterator_range & operator = (iterator_range &&) = default;

}; //----------------------------bidirectional iterator range

template <typename Iter, typename IterEnd>
struct iterator_range
<Iter, IterEnd, std::random_access_iterator_tag>
: public
  iterator_range
  <Iter, IterEnd, std::bidirectional_iterator_tag>
{

using write_type
  = typename std::iterator_traits<Iter>::value_type;

template <typename T>
void
write (
  T const & _var
){
*this->iter_begin = _var;
}

iterator_range &
operator += (
  typename std::iterator_traits<Iter>::difference_type
  const & _n
){
this->iter_begin += _n;
return *this;
}

iterator_range &
operator -= (
  typename std::iterator_traits<Iter>::difference_type
  const & _n
){
this->iter_begin -= _n;
return *this;
}

typename std::iterator_traits<Iter>::reference
operator [](
  int _n
){
return this->iter_begin[_n];
}

iterator_range (
  Iter _iter
, IterEnd _end
)
: iterator_range
  <Iter, IterEnd, std::bidirectional_iterator_tag>
  {_iter, _end}
{}

iterator_range (iterator_range const &) = default;
iterator_range (iterator_range &&) = default;

iterator_range &
operator = (iterator_range const &) = default;

iterator_range & operator = (iterator_range &&) = default;

}; //----------------------------random access iterator range

template <typename Iter>
struct iterator_range<Iter, void> {

// The iterator may have a void type.
using write_type
  = typename std::iterator_traits<Iter>::value_type *;

Iter iter_begin;

template <typename T>
void
write (
  T _var
){
*this->iter_begin = _var;
}

iterator_range &
operator ++ (
){
++this->iter_begin;
return *this;
}

}; /* output iterator range */

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
return _range.iter_begin != _range.iter_end;
}

template <typename Iter, typename IterEnd, typename Cat>
bool
operator != (
  iterator_range<Iter, IterEnd, Cat> const & _range
, sentinel::readable const & _sentinel
){
return !(_range == _sentinel);
}

template <typename Iter, typename IterEnd, typename Cat>
bool
operator == (
  iterator_range<Iter, IterEnd, Cat> const & _range
, sentinel::writable const & _sentinel
){
return _range.iter_begin != _range.iter_end;
}

template <typename Iter, typename IterEnd, typename Cat>
bool
operator != (
  iterator_range<Iter, IterEnd, Cat> const & _range
, sentinel::writable const & _sentinel
){
return !(_range == _sentinel);
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

template <typename Iter, typename IterEnd>
iterator_range<Iter,IterEnd>
make_iterator_range (
  Iter _begin
, IterEnd _end
){
return iterator_range<Iter,IterEnd>(_begin, _end);
}

template <typename Iter>
iterator_range<Iter,void>
make_iterator_range (
  Iter _begin
){
return iterator_range<Iter,void>{_begin};
}

} //----------------------------------------------range layer
#endif

