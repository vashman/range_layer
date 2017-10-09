//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_RANGE_HPP
#define RANGE_LAYER_BITS_RANGE_RANGE_HPP

#include "../range_traits.hpp"

namespace range_layer {

namespace bits {

/*===========================================================
  base_from_member
===========================================================*/
template <typename T>
struct base_from_member;

/*===========================================================
  base_from_member
===========================================================*/
template <typename T>
struct base_from_member {

T member;

};

} //-----------------------------------------------------bits

/*===========================================================
  range
===========================================================*/
template <typename... Ts>
class range;

/*===========================================================
  decorator builder range

* A range with more then 2 types means multiple decorators
  are being used.
===========================================================*/
template
< typename Range
, typename Decorator
, typename T
, typename... Ts
>
class range<Range, Decorator, T, Ts...>
: public range<range<Range, Decorator>, T, Ts...>
{};

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

/*===========================================================
  make_range

* Does not deduce pointer ranges correctly.
===========================================================*/
template <typename... Ts>
range<Ts...>
make_range (
  Ts... _args
){
return range<Ts...>{std::move(_args)...};
}

} //----------------------------------------------range layer
#include "default_range.hpp"
#include "empty_range.hpp"
#include "smart_pointer_range.hpp"
#endif
