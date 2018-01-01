// Default traits for non-ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_TRAITS_HPP
#define RANGE_LAYER_BITS_TRAITS_HPP

namespace range_layer {

template <typename R> struct value_type     {using type = void;};
template <typename R> struct size_type      {using type = void;};
template <typename R> struct is_range       {static constexpr bool value = false;};
template <typename R> struct is_synced      {static constexpr bool value = false;};
template <typename R> struct is_output      {static constexpr bool value = false;};
template <typename R> struct is_input       {static constexpr bool value = false;};
template <typename R> struct is_finite      {static constexpr bool value = false;};
template <typename R> struct is_next_linear {static constexpr bool value = false;};
template <typename R> struct is_prev_linear {static constexpr bool value = false;};
template <typename R> struct is_reversable  {static constexpr bool value = false;};
template <typename R> struct is_decorator   {static constexpr bool value = false;};

template <typename R> using                 value_type_t     = typename value_type<R>::type;
template <typename R> using                 size_type_t      = typename size_type<R>::type;
template <typename R> constexpr bool is_range_v       = is_range<R>::value;
template <typename R> constexpr bool is_synced_v      = is_synced<R>::value;
template <typename R> constexpr bool is_output_v      = is_output<R>::value;
template <typename R> constexpr bool is_input_v       = is_input<R>::value;
template <typename R> constexpr bool is_finite_v      = is_finite<R>::value;
template <typename R> constexpr bool is_next_linear_v = is_next_linear<R>::vlaue;
template <typename R> constexpr bool is_prev_linear_v = is_prev_linear<R>::vlaue;
template <typename R> constexpr bool is_reversable_v  = is_reversable<R>::value;
template <typename R> constexpr bool is_decorator_v   = is_decorator<R>::value;

} //-----------------------------------------------------------------range layer
#endif

