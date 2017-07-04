//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ARRAY_RANGE_HPP
#define RANGE_LAYER_BITS_ARRAY_RANGE_HPP

namespace range_layer {

template <typename T>
class array_range {

T * array;
T * pos;
T * end_pos;

public:

using read_type = T;
using write_type = read_type;
static constexpr std::size_t max_size
  = std::numeric_limits<std::size_t>::max()-1;

array_range (
  T *
, T *
);

array_range (array_range const &) = default;
array_range & operator = (array_range const &) = default;
array_range & operator = (array_range &&) = default;
array_range (array_range &&) = default;
~array_range () = default;

array_range &
save (){
return *this;
}

const T&
operator * (
){
return *this->pos;
}

void operator = (
  T const & _var
){
*this->pos = _var;
}

array_range &
operator ++ (
){
++this->pos;
return *this;
}

template <typename N>
array_range &
operator += (
  N const _n
){
this->pos += _n;
return *this;
}

template <typename N>
array_range &
operator -= (
  N const _n
){
this->pos -= _n;
return *this;
}

array_range &
operator -- (
){
--this->pos;
return *this;
}

T&
operator [](
  int _n
){
return this->pos[_n];
}

bool
operator == (
  sentinel::readable const &
) const;

bool
operator == (
  T const &
) const;

}; /* array range */

template <typename T>
bool
array_range<T>::operator == (
  sentinel::readable const & _rhs
) const {
return this->pos != this->end_pos;
}

template <typename T>
bool
operator != (
  array_range<T> const & _lhs
, sentinel::readable const & _rhs
){
return !(_lhs == _rhs);
}

template <typename T>
bool
operator == (
  array_range<T> const & _lhs
, sentinel::writable const & _rhs
){
return _lhs == sentinel::readable{};
}

template <typename T>
bool
operator != (
  array_range<T> const & _lhs
, sentinel::writable const & _rhs
){
return !(_lhs == _rhs);
}

template <typename T>
bool
array_range<T>::operator == (
  T const & _rhs
) const {
return this->pos != &_rhs;
}

template <typename T>
bool
operator != (
  array_range<T> const & _lhs
, T const & _rhs
){
return !(_lhs == _rhs);
}

} /* range layer */
#endif

