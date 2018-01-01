// Range, function and trait definitions.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_HPP
#define RANGE_LAYER_BITS_RANGE_HPP

#include "range.fwd"

// for traits
#include <limits>
#include <type_traits>
#include "traits.hpp"
#include "is_detected.hpp"

namespace range_layer {
namespace range_class {

template <> struct spec <int> {using type = range_class::variable<int>;};
template <> struct spec <char> {using type = range_class::iota<char>;};
template <> struct spec <float> {using type = range_class::iota<float>;};
template <> struct spec <double> {using type = range_class::iota<double>;};
} //-----------------------------------------------------------------range class

namespace bits {

/*==============================================================================
  to_ref
==============================================================================*/
template <typename T>
T &
to_ref (
  T & _ref
){
return _ref;
}

template <typename T>
T &
to_ref (
  T * _ptr
){
return *_ptr;
}

} //------------------------------------------------------------------------bits

/*==============================================================================
  empty range
==============================================================================*/
template <> class range <> {}; //------------------------------------empty range

/*==============================================================================
  range
==============================================================================*/
template <typename H>
class range <H> : public range_class::spec<H>::type {

public:

explicit range      (H);
        ~range      ()              = default;
         range      (const range &) = default;
         range      (range &&)      = default;
range &  operator = (const range &) = default;
range &  operator = (range &&)      = default;

}; //----------------------------------------------------------------------range

/*==============================================================================
  decorator builder range
==============================================================================*/
template <typename R, typename D1, typename D2, typename... Ds>
class range <R, D1, D2, Ds...> : public range <range<R, D1>, D2, Ds...> {

public:

explicit range      (R, D1, D2, Ds...);
        ~range      ()              = default;
         range      (const range &) = default;
         range      (range &&)      = default;
range &  operator = (const range &) = default;
range &  operator = (range &&)      = default;

}; //----------------------------------------------------decorator builder range

/*==============================================================================
  Traits
==============================================================================*/
template <typename... Ts> struct value_type<range<Ts...>>
{using type = typename range<Ts...>::value_type;};

template <typename... Ts> struct size_type<range<Ts...>>
{using type = typename range<Ts...>::size_type;};

/*==============================================================================
  is_range
==============================================================================*/
template <typename... Ts>
struct is_range<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using func_t  = decltype(std::declval<T&>().next());
static constexpr bool has_next      = bits::is_detected<func_t, R>::value;
static constexpr bool has_move_ctor = std::is_move_constructible<R>::value;
static constexpr bool has_copy_ctor = std::is_copy_constructible<R>::value;

public:

static constexpr bool value = has_next && (has_move_ctor || has_copy_ctor);
};

/*==============================================================================
  is_synced
==============================================================================*/
template <typename... Ts>
struct is_synced<range<Ts...>> {

using R = range<Ts...>;
template <typename T> using comp_t = decltype (std::declval<const T&>().has_io());
static constexpr bool has_has_io = bits::is_detected<comp_t, R>::value;

public:

static constexpr bool value = has_has_io && is_input_v<R> && is_output_v<R>;
using type = std::integral_constant<bool, value>;

};

/*==============================================================================
  is_output
==============================================================================*/
template <typename... Ts>
struct is_output<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using func_t = decltype(std::declval<T&>().write(std::declval<value_type_t<R> const &>()));
template <typename T> using insert_func_t = decltype(std::declval<T&>().insert(std::declval<value_type_t<R> const &>()));
template <typename T> using comp_t = decltype (std::declval<const T&>().has_writable());
template <typename T> using io_t = decltype (std::declval<const T&>().has_io());

static constexpr bool has_write = bits::is_detected<func_t, R>::value;
static constexpr bool has_insert = bits::is_detected<insert_func_t, R>::value;
static constexpr bool has_has_writable = bits::is_detected<comp_t, R>::value;
static constexpr bool has_has_io = bits::is_detected<io_t, R>::value;

public:

static constexpr bool value
  = (has_write || has_insert) && (has_has_io || has_has_writable);
};

/*==============================================================================
  is_input
==============================================================================*/
template <typename... Ts>
struct is_input<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using read_t = decltype (std::declval<const T&>().read());
template <typename T> using drain_t = decltype (std::declval<const T&>().drain(std::declval<value_type_t<R> &>()));
template <typename T> using comp_t = decltype (std::declval<const T&>().has_readable());
template <typename T> using io_t = decltype (std::declval<const T&>().has_io());

static constexpr bool has_read = bits::is_detected<read_t, R>::value;
static constexpr bool has_drain = bits::is_detected<drain_t, R>::value;
static constexpr bool has_has_readable = bits::is_detected<comp_t, R>::value;
static constexpr bool has_has_io = bits::is_detected<io_t, R>::value;

public:

static constexpr bool value
  = (has_read || has_drain) && (has_has_readable || has_has_io);
};

/*==============================================================================
  is_finite
==============================================================================*/
template <typename... Ts>
struct is_finite<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using func_t = decltype(std::declval<T&>().size());
template <typename T> using pos_t = decltype(std::declval<T&>().position());

static constexpr bool has_size     = bits::is_detected<func_t, R>::value;
static constexpr bool has_position = bits::is_detected<pos_t, R>::value;

public:

static constexpr bool value = has_size && has_position;
};

/*==============================================================================
  is_reversable
==============================================================================*/
template <typename... Ts>
struct is_reversable<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using func_t = decltype(std::declval<T&>().prev());

public:

static constexpr bool value = bits::is_detected<func_t, R>::value;
};

/*==============================================================================
  is_next_linear
==============================================================================*/
template <typename... Ts>
struct is_next_linear<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using fwdfunc_t = decltype(std::declval<T&>().next(std::declval<int>()));

public:

static constexpr bool value = ! bits::is_detected<fwdfunc_t, R>::value;
};

/*==============================================================================
  is_decorator
==============================================================================*/
template <typename... Ts>
struct is_decorator<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using func_t = decltype (std::declval<T&>().disable());

public:

static constexpr bool value = bits::is_detected<func_t, R>::value;
};

/*==============================================================================
  is_prev_linear
==============================================================================*/
template <typename... Ts>
struct is_prev_linear<range<Ts...>> {

private:

using R = range<Ts...>;
template <typename T> using func_t = decltype(std::declval<T&>().prev(std::declval<int>()));

public:

static constexpr bool value = !(bits::is_detected<func_t, R>::value);
};

/*==============================================================================
  Range operations
==============================================================================*/
constexpr std::size_t
size (
 const range<> &
){
return 0;
}

constexpr std::size_t
position (
  const range<> &
){
return 0;
}

constexpr range<>
next (
  const range<> _rng
){
return _rng;
}

} //-----------------------------------------------------------------range layer
#endif
#include "range.tcc"

