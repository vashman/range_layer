//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GENERATE_RANGE_TCC
#define RANGE_LAYER_GENERATE_RANGE_TCC

#include "range_traits.hpp"
#include <tuple>

namespace range_layer {
namespace bits {

template<template <typename...> class Tuple, typename... Ts>
struct typelist_base {

using type = range_layer::typelist<Tuple, Ts...>;

};

template <template <typename...> class Tuple, typename T>
struct typelist_base<Tuple, T> {

using type = T;

};

} /* bits */

template <typename Gen, typename... Ts>
class generate_range {

Gen gen;

using rtype = decltype(gen());

rtype temp;

public:

using read_type
  = typename bits::typelist_base<std::tuple, Ts...>::type;

static constexpr std::size_t max_size
  = std::numeric_limits<std::size_t>::max();

generate_range (
  Gen _gen
)
: gen (_gen)
, temp (gen())
{}

generate_range (generate_range const &) = default;
generate_range (generate_range &&) = default;
~generate_range () = default;
generate_range & operator = (generate_range &&) = default;

generate_range &
operator = (generate_range const &) = default;

rtype
operator * (
){
return this->temp;
}

generate_range<Gen, Ts...> &
operator ++ (){
this->temp = this->gen();
return *this;
}

bool operator == (sentinel::readable const &) const;

}; /* generate range */

template <typename Gen, typename... Ts>
bool
generate_range<Gen, Ts...>::operator == (
  sentinel::readable const &
) const {
return true;
}

template <typename Gen, typename... Ts>
generate_range<Gen, Ts...>
make_generate_range (
  Gen _gen
);

template <typename... Ts, typename Gen>
generate_range<Gen, Ts...>
make_generate_range (
  Gen _gen
){
return generate_range<Gen, Ts...>(_gen);
}

} /* range layer */
#endif

