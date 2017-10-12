// Default spelizations of range class.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DEFAULT_HPP
#define RANGE_LAYER_BITS_RANGE_DEFAULT_HPP

#include "default.fwd"
#include "pointer.hpp"

namespace range_layer {

/*===========================================================
  default range
===========================================================*/
template <typename T>
class range<T>
: public bits::base_from_member<T>
, public range<T *>
{
public:

explicit range(T);
//range<T> save() const;

}; //-------------------------------------------default range

/*===========================================================
  default const range
===========================================================*/
template <typename T>
class range<const T>
: public bits::base_from_member<const T>
, public range<const T *>
{
public:

explicit range(const T);
//range<T> save() const;

}; //-------------------------------------default const range
} //----------------------------------------------range layer
#endif
#include "default.tcc"
