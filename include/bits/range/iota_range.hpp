//

//          Copyright Sundeep S. Sangha 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_IOTA_RANGE_HPP
#define RANGE_LAYER_IOTA_RANGE_HPP

#include <limits>
#include <type_traits>
#include "../../range_traits.hpp"

namespace range_layer {

/*===========================================================
  iota
===========================================================*/
template <typename T>
struct iota;

/*===========================================================
  iota_range
===========================================================*/
namespace bits {

template <typename T>
class iota_range;

} //-----------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
//template <typename T>
//bits::iota_range<T>
//range (
//  iota<T>
//);

/*===========================================================
  iota
===========================================================*/
template <typename T>
struct iota {

T var;

}; //----------------------------------------------------iota

namespace bits {

template <typename T>
class iota_range {

iota<T> count;

using size_type
  = typename std
    ::remove_cv<typename std::make_unsigned<T>::type>::type;

public:

/*===========================================================
  ctor
===========================================================*/
iota_range (
  iota<T> _var
)
: count (_var)
{}

/*===========================================================
  copy ctor
===========================================================*/
iota_range (iota_range const &) = delete;

/*===========================================================
  move ctor
===========================================================*/
iota_range (iota_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
iota_range & operator = (iota_range const &) = delete;

/*===========================================================
  move assignment operator
===========================================================*/
iota_range & operator = (iota_range &&) = default;

/*===========================================================
  dtor
===========================================================*/
~iota_range() = default;

/*===========================================================
  read
===========================================================*/
T const & read ();

/*===========================================================
  operator ++
===========================================================*/
iota_range & operator ++ ();

/*===========================================================
  operator --
===========================================================*/
iota_range & operator -- ();

/*===========================================================
  operator +=
===========================================================*/
iota_range & operator += (T const &);

/*===========================================================
  operator -=
===========================================================*/
iota_range & operator -= (T const &);

/*===========================================================
  operator ==
===========================================================*/
bool operator == (sentinel::readable const &) const;

/*===========================================================
  operator ==
===========================================================*/
bool operator == (T const &) const;

/*===========================================================
  save
===========================================================*/
iota_range save();

/*===========================================================
  size
===========================================================*/
size_type
size (
) const {
return std::numeric_limits<size_type>::max();
}

/*===========================================================
  position
===========================================================*/
size_type
position (
) const {
return this->count.var;
}

}; //----------------------------------------------iota range

/*===========================================================
  size
===========================================================*/
template <typename T>
iota_range<T>
iota_range<T>::save (
){
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename T>
bool
iota_range<T>::operator == (
  sentinel::readable const & _sentinel
) const {
return !(
   (std::numeric_limits<T>::max() == this->count.var)
|| (std::numeric_limits<T>::min() == this->count.var)
);
}

/*===========================================================
  operator ==
===========================================================*/
template <typename T>
bool
iota_range<T>::operator == (
  T const & _sentinel
) const {
return this->count.var == _sentinel;
}

/*===========================================================
  operator ++
===========================================================*/
template <typename T>
iota_range<T> &
iota_range<T>::operator ++ (
){
++this->count.var;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename T>
iota_range<T> &
iota_range<T>::operator -- (
){
--this->count.var;
return *this;
}

/*===========================================================
  read
===========================================================*/
template <typename T>
T const &
iota_range<T>::read (
){
return this->count.var;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename T>
iota_range<T> &
iota_range<T>::operator += (
  T const & _n
){
this->count.var += _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename T>
iota_range<T> &
iota_range<T>::operator -= (
  T const & _n
){
this->count.var -= _n;
return *this;
}
} //-----------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
/*template <typename T>
bits::iota_range<T>
range (
  iota<T> _var
){
return bits::iota_range<T>{_var};
}*/

} //----------------------------------------------range layer
#endif

