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
==============================================================================*/
template <typename... Ts> struct tag;
template <typename... Ts> struct tag <std::true_type, Ts...>;
template <typename... Ts> struct tag <std::false_type, Ts...>;
template <typename... Ts> using  true_tag  = const tag<std::true_type, Ts...>;
template <typename... Ts> using  false_tag = const tag<std::false_type, Ts...>;

template <typename... Ts> constexpr std::string to_string (const tag<Ts...> ){return _tag.str;}
template <typename... Ts> constexpr bool        tag_truth (true_tag<Ts...>){return true;}
template <typename... Ts> constexpr bool        tag_truth (false_tag<Ts...>){return false;}

template <typename... Ts> struct tag {};
template <typename... Ts> struct tag <std::true_type, Ts...>{};
template <typename... Ts> struct tag <std::false_type, Ts...>{};
}
//-------------------------------------------------------------------range_layer
#endif

