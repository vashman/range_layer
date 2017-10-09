//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_RANGE_HPP
#define RANGE_LAYER_BITS_RANGE_RANGE_HPP

#include "range.fwd"

namespace range_layer {

namespace bits {

/*===========================================================
  base_from_member
===========================================================*/
template <typename T>
struct base_from_member {

T member;

};

} //-----------------------------------------------------bits

/*===========================================================
  const_range unique_ptr
===========================================================*/
//template<typename T, typename Deleter>
//range<std::unique_ptr<const T, Deleter>>
//const_range (
//  range<std::unique_ptr<T, Deleter>> _range
//){
//return {std::move(_range)};
//}

/*===========================================================
  const_range shared_ptr
===========================================================*/
//template<typename T>
//range<std::shared_ptr<const T>>
//const_range (
//  range<std::shared_ptr<T>> _range
//){
//return {_range};
//}

/*===========================================================
  shared_range unique_ptr
===========================================================*/
//template<typename T, typename Deleter>
//range<std::shared_ptr<T>>
//shared_range (
//  range<std::unique_ptr<T, Deleter>> _range
//){
//return {std::move(_range)};
//}

/*===========================================================
  shared_range unique_ptr const
===========================================================*/
//template<typename T, typename Deleter>
//range<std::shared_ptr<const T>>
//shared_range (
//  range<std::unique_ptr<const T, Deleter>> _range
//){
//return {std::move(_range)};
//}

/*===========================================================
  shared_range weak_ptr
===========================================================*/
//template<typename T>
//range<std::shared_ptr<const T>>
//shared_range (
//  range<std::weak_ptr<const T>> _range
//){
//_range.lock()
//return {};
//}

/*===========================================================
  weak_range
===========================================================*/
//template<typename T>
//range<std::weak_ptr<const T>>
//weak_range (
//  const range<std::shared_ptr<T>> _range
//){
//return {_range};
//}

/*===========================================================
  weak_range const
===========================================================*/
//template<typename T>
//range<std::weak_ptr<const T>>
//weak_range (
//  const range<std::shared_ptr<const T>> _range
//){
//return {_range};
//}

} //----------------------------------------------range layer
#endif
#include "range.tcc"
