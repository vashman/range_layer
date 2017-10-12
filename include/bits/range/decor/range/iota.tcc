//

//          Copyright Sundeep S. Sangha 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_IOTA_TCC
#define RANGE_LAYER_IOTA_TCC

#include <limits>

namespace range_layer {

/*===========================================================
  ctor
===========================================================*/
template <typename T>
range<iota<T> * const>::range (
  iota<T> * const _ptr
) : range<const iota<T> * const> {_ptr}
, handle {_ptr}
{}

/*===========================================================
  ctor
===========================================================*/
template <typename T>
range<const iota<T> * const>::range (
  const iota<T> * const _ptr
) : const_handle {_ptr}
{}

/*===========================================================
  read
===========================================================*/
template <typename T>
T const &
range<const iota<T> * const>::read (
) const {
return this->const_handle->var;
}

/*===========================================================
  advance
===========================================================*/
template <typename T>
void
range<iota<T> * const>::advance (
){
++(this->handle->var);
}

/*===========================================================
  reverse
===========================================================*/
template <typename T>
void
range<iota<T> * const>::reverse (
){
--(this->handle->var);
}

/*===========================================================
  advance_n
===========================================================*/
template <typename T>
void
range<iota<T> * const>::advance_n (
  T const & _n
){
(this->handle->var) += _n;
}

/*===========================================================
  reverse_n
===========================================================*/
template <typename T>
void
range<iota<T> * const>::reverse_n (
  T const & _n
){
(this->handle->var) -= _n;
}

/*===========================================================
  size
===========================================================*/
template <typename T>
typename range<const iota<T> * const>::size_type
range<const iota<T> * const>::size (
) const {
return std::numeric_limits<size_type>::max();
}

/*===========================================================
  position
===========================================================*/
template <typename T>
typename range<const iota<T> * const>::size_type
range<const iota<T> * const>::position (
) const {
return this->const_handle->var;
}

/*===========================================================
  has_readable
===========================================================*/
template <typename T>
bool
range<const iota<T> * const>::has_readable (
) const {
return !(
   (std::numeric_limits<T>::max() == this->const_handle->var)
|| (std::numeric_limits<T>::min() == this->const_handle->var)
);
}

} //----------------------------------------------range layer
#endif
