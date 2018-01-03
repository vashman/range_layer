//

//          Copyright Sundeep S. Sangha 2015 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_TAG_HPP
#define RANGE_LAYER_BITS_TAG_HPP

#include <type_traits>

namespace range_layer {
/*==============================================================================
  Tag

* Creates a type for both version of the tag.
* True tag exits, false tag does not exist.
* For the tag to not exist it has to be known, and thus must exist.
* Tags cannot have "cv"

# Tag types
1. T  = Truthness
2. Ts = Type list
==============================================================================*/
namespace bits {
template <typename T, typename... Ts> struct tag;
template <typename... Ts>             struct tag <std::true_type, Ts...>;
template <typename... Ts>             struct tag <std::false_type, Ts...>;

template <typename T, typename... Ts> struct tag {
using type = T;
};

template <typename... Ts> struct tag <std::true_type, Ts...> {
using type = bool;
};

template <typename... Ts> struct tag <std::false_type, Ts...> {
using type = bool;
};

}
//---------------------------------------------------------------------------bits

template <typename... Ts>             using tag       = const bits::tag<Ts...>;
template <typename... Ts>             using true_tag  = const tag<std::true_type, Ts...>;
template <typename... Ts>             using false_tag = const tag<std::false_type, Ts...>;
template <typename T, typename... Ts> using trait_tag = const tag<std::integral_constant<bool, T::value>, T, Ts...>;

//template <typename... Ts> constexpr std::string to_string (tag<Ts...>){return _tag.str;}
//template <typename... Ts> constexpr bool measure (tag<Ts...>, tag<Ts...>::type){return true;}
//template <typename... Ts> constexpr bool measure (true_tag<Ts...>, bool){return true;}
//template <typename... Ts> constexpr bool measure (false_tag<Ts...>, bool){return false;}

}
//-------------------------------------------------------------------range_layer
#endif

