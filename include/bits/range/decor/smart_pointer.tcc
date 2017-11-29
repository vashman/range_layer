//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DECOR_SMART_POINTER_TCC
#define RANGE_LAYER_BITS_RANGE_DECOR_SMART_POINTER_TCC

namespace range_layer {

/*===========================================================
  const range
===========================================================*/
template <typename Pointer>
range <Pointer, const enable_range::smart_pointer>::range (
  Pointer _pointer
)
: range::base_from_member {_pointer}
, range<const typename Pointer::type * const>
  {range::base_from_member::member.get()}
{}

/*===========================================================
  range
===========================================================*/
template <typename Pointer>
range <Pointer, enable_range::smart_pointer>::range (
  Pointer _pointer
)
: range::base_from_member {_pointer}
, range<typename Pointer::type * const>
  {range::base_from_member::member.get()}
{}

} //----------------------------------------------range layer
#endif
