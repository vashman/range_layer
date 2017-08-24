//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ARRAY_RANGE_HPP
#define RANGE_LAYER_BITS_ARRAY_RANGE_HPP

namespace range_layer {

/*===========================================================
  array_range
===========================================================*/
template <typename T>
class array_range {

T * array;
T * pos;
T * end_pos;

public:

using read_type = T;
using write_type = read_type;

/*===========================================================
  ctor
===========================================================*/
array_range (
  T *
, T *
);

/*===========================================================
  copy ctor
===========================================================*/
array_range (array_range const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
array_range & operator = (array_range const &) = default;

/*===========================================================
  move assignment operator
===========================================================*/
array_range & operator = (array_range &&) = default;

/*===========================================================
  move ctor
===========================================================*/
array_range (array_range &&) = default;

/*===========================================================
  dtor
===========================================================*/
~array_range () = default;

array_range &
save (
){
return *this;
}

/*===========================================================
  operator *
===========================================================*/
T const &
operator * (
){
return *this->pos;
}

/*===========================================================
  operator =
===========================================================*/
void
operator = (
  T const & _var
){
*this->pos = _var;
}

/*===========================================================
  operator ++
===========================================================*/
array_range &
operator ++ (
){
++this->pos;
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
array_range &
operator += (
  N const _n
){
this->pos += _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
array_range &
operator -= (
  N const _n
){
this->pos -= _n;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
array_range &
operator -- (
){
--this->pos;
return *this;
}

/*===========================================================
  operator []
===========================================================*/
T&
operator [](
  int _n
){
return this->pos[_n];
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const &
) const;

/*===========================================================
  size
===========================================================*/
std::size_t
size (
) const {
return this->end_pos - this->pos;
}

/*===========================================================
  position
===========================================================*/
std::size_t
position (
) const {
return this->array - this->end_pos;
}

}; //array range---------------------------------------------

} //range layer----------------------------------------------
#endif

