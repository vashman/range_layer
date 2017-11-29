//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DECOR_SMART_POINTER_HPP
#define RANGE_LAYER_BITS_RANGE_DECOR_SMART_POINTER_HPP

//#include <memory>
#include "smart_pointer.fwd"

namespace range_layer {

/*===========================================================
  const range
===========================================================*/
template <typename Pointer>
class range <Pointer, const enable_range::smart_pointer>
: public bits::base_from_member<Pointer>
, public range<const typename Pointer::type * const> {

public:

explicit range (Pointer);

}; //---------------------------------------------const range

/*===========================================================
  range
===========================================================*/
template <typename Pointer>
class range <Pointer, enable_range::smart_pointer>
: public bits::base_from_member<Pointer>
, public range<typename Pointer::type * const> {

public:

explicit range (Pointer);

}; //---------------------------------------------------range
} //----------------------------------------------range layer
#endif
#include "smart_pointer.tcc"
