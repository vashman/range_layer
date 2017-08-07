//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_TYPELIST_HPP
#define RANGE_LAYER_TYPELIST_HPP

#include <tuple>

namespace range_layer {
namespace bits {

template <template <typename...> class Tuple, typename... Ts>
struct typelist {

using type = Tuple<Ts...>;

typelist () = delete;
typelist (typelist const &) = delete;
typelist (typelist &&) = delete;
typelist & operator = (typelist const &) = delete;
typelist & operator = (typelist &&) = delete;

}; /* type list */

template <template <typename...> class Tuple, typename T>
struct typelist<Tuple, T> {

using type = T;

typelist () = delete;
typelist (typelist const &) = delete;
typelist (typelist &&) = delete;
typelist & operator = (typelist const &) = delete;
typelist & operator = (typelist &&) = delete;

}; /* type list */

template <typename LHSTuple, typename RHSTuple>
struct tuple_join {

LHSTuple lhs_tuple;
RHSTuple rhs_tuple;

};

template <typename Lhs, typename Rhs>
struct typelist_cat {

using type = typelist <std::tuple, Lhs, Rhs>;

};

template
< template <typename...> class LhsTuple
, typename... Lhs
, template <typename...> class RhsTuple
, typename... Rhs
>
struct typelist_cat
< typelist<LhsTuple, Lhs...>
, typelist<RhsTuple, Rhs...>
> {

using type = typelist <std::tuple, Lhs..., Rhs...>;

};

template
< typename Lhs
, template <typename...> class RhsTuple
, typename... Rhs
>
struct typelist_cat<Lhs, typelist<RhsTuple, Rhs...>> {

using type = typelist <RhsTuple, Lhs, Rhs...>;

};

template
< template <typename...> class LhsTuple
, typename... Lhs
, typename Rhs
>
struct typelist_cat <typelist<LhsTuple, Lhs...>, Rhs> {

using type = typelist <LhsTuple, Lhs..., Rhs>;

};

} /* bits */

template <template <typename...> class Tuple, typename... Ts>
using typelist = bits::typelist<Tuple, Ts...>;

template <typename Lhs, typename Rhs>
using typelist_cat = bits::typelist_cat<Lhs, Rhs>;

template <typename Lhs, typename Rhs>
using typelist_cat_t = typename typelist_cat<Lhs, Rhs>::type;

} /* range layer */
#endif
