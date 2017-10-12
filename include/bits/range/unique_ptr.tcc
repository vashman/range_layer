//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_UNIQUE_POINTER_TCC
#define RANGE_LAYER_BITS_RANGE_UNIQUE_POINTER_TCC

namespace range_layer {

/*===========================================================
  ctor ::unique_ptr_range
===========================================================*/
template <typename T, typename Deleter>
range<std::unique_ptr<T, Deleter>>::range (
  std::unique_ptr<T, Deleter> _ptr
) : range::base_from_member {std::move(_ptr)}
, range<T * const> {range::base_from_member::member.get()}
{}

/*===========================================================
  ctor ::const unique_ptr_range
===========================================================*/
template <typename T, typename Deleter>
range<std::unique_ptr<const T, Deleter>>::range (
  std::unique_ptr<const T, Deleter> _ptr
) : range::base_from_member {std::move(_ptr)}
, range<const T * const>
  {range::base_from_member::member.get()}
{}

} //----------------------------------------------range layer
#endif
