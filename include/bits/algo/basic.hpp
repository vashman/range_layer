// Basic range operations.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ALGO_BASIC_HPP
#define RANGE_LAYER_BITS_ALGO_BASIC_HPP

#include "basic.fwd"

namespace range_layer {
namespace bits {

template <typename R>
struct has_next {
static constexpr bool value = (is_range<R>::value && !is_next_linear<R>::value);
using type = std::integral_constant<bool, value>;
};

template <typename R>
struct has_prev {
static constexpr bool value = (is_range<R>::value && is_reversable<R>::value && !is_prev_linear<R>::value);
using type = std::integral_constant<bool, value>;
};

} //------------------------------------------------------------------------bits
} //-----------------------------------------------------------------range layer
#include "basic.tcc"
#endif
