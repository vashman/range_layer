//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DEFAULT_TCC
#define RANGE_LAYER_BITS_RANGE_DEFAULT_TCC

namespace range_layer {

/*===========================================================
  ctor ::default range
===========================================================*/
template <typename T>
range<T>::range (
  T _var
)
: range::base_from_member {_var}
, range<T *> {&(range::base_from_member::member)}
{}

/*===========================================================
  ctor ::default const range
===========================================================*/
template <typename T>
range<const T>::range (
  const T _var
)
: range::base_from_member {_var}
, range<const T *> {&(range::base_from_member::member)}
{}

/*===========================================================
  save
===========================================================*/
//template <typename T>
//range<T>
//range<T>::save (
//) const {
//return *this;
//}

} //----------------------------------------------range layer
#endif
