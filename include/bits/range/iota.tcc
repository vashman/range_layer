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
  ctor range<T *>
===========================================================*/
template <typename T>
range<T *, range_class::iota>::range (
  T * _ptr
)
: handle {_ptr}
{}

/*===========================================================
  ctor range<const T *>
===========================================================*/
template <typename T>
range<const T *, range_class::iota>::range (
  const T * _ptr
)
: range<const T *, range_class::variable> {_ptr}
{}

/*================================================================
  read

* Can only have a single postion that is readable.
* Ignores the index value, completly.
================================================================*/
template <typename T>
const T &
range<T *, range_class::iota>::read (
  const T //unsued
) const {
return this->handle;
}

/*===========================================================
  next
===========================================================*/
template <typename T>
void
range<T *, range_class::iota>::next (
){
++(this->handle);
}

/*===========================================================
  prev
===========================================================*/
template <typename T>
void
range<T *, range_class::iota>::prev (
){
--(this->handle);
}

/*===========================================================
  size
===========================================================*/
template <typename T>
T
range<T *, range_class::iota>::size (
) const {
return std::numeric_limits<T>::max();
}

/*===========================================================
  position
===========================================================*/
template <typename T>
T
range<T *, range_class::iota>::position (
) const {
return this->handle;
}

/*===========================================================
  has_io
===========================================================*/
template <typename T>
constexpr bool
range<T *, range_class::iota>::has_io (
) const {
return !(
   (std::numeric_limits<T>::max() == *this->handle)
|| (std::numeric_limits<T>::min() == *this->handle)
);
}

} //----------------------------------------------range layer
#endif

