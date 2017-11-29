// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_TRAITS_HPP
#define RANGE_LAYER_BITS_TRAITS_HPP

#include <limits>
#include <type_traits>
#include "traits.fwd"
#include "is_detected.hpp"

namespace range_layer {

namespace bits {

using void_t = void*;

template <typename Range>
using r_type = typename std::remove_cv
  <typename std::remove_reference<Range>::type>::type;

namespace trait_bits {

template <typename T>
using wtype = typename T::write_type;

template <typename Range, bool flag>
struct single_value;

template <typename Range>
struct single_value <Range, false> {
static constexpr bool value = true;
};

template <typename Range>
struct single_value <Range, true> {
static constexpr bool value = Range::is_singleton;
};

template <typename Range, bool HasSize>
struct size_type {
using type = void_t;
};

template <typename Range>
struct size_type<Range, true> {
using type = decltype(std::declval<Range&>().size());
};

template <typename Range, bool>
struct pos_type {
using type = typename std::result_of
<decltype(&Range::position)()>::type;

};

template <typename Range>
struct pos_type<Range, false> {
using type = void_t;
};

template <typename Range, bool>
struct if_read_type {
using type = void_t;
};

template <typename Range>
struct if_read_type<Range, true> {
using type = decltype(std::declval<Range&>().operator*());
};

} //-----------------------------------------------trait bits
} //-----------------------------------------------------bits

/*==============================================================================
  range_type
==============================================================================*/
template <typename Range>
struct range_type {

using type = typename bits::r_type<Range>::type::type;

};

/*==============================================================================
  range_type_t
==============================================================================*/
template <typename Range>
using range_type_t = typename range_type<Range>::type;

/*==============================================================================
  is range
==============================================================================*/
template <typename Range>
struct is_range {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().next());

static constexpr bool has_next
  = bits::is_detected<func_t, bits::r_type<Range>>::value;

static constexpr bool has_move_ctor
  = std::is_move_constructible<bits::r_type<Range>>::value;

static constexpr bool has_copy_ctor
  = std::is_copy_constructible<bits::r_type<Range>>::value;

public:

static constexpr bool value = has_next && (has_move_ctor || has_copy_ctor);
};

/*==============================================================================
  is_synced
==============================================================================*/
template <typename Range>
struct is_synced {

template <typename T>
using comp_t = decltype (std::declval<const T&>().has_io());

static constexpr bool has_has_io
  = bits::is_detected<comp_t, bits::r_type<Range>>::value;

public:

static constexpr bool value
  = has_has_io && is_input<Range>::value && is_output<Range>::value;

using type = std::integral_constant<bool, value>;

};

/*==============================================================================
  is_output
==============================================================================*/
template <typename Range>
struct is_output {

private:

template <typename T>
using func_t = decltype
  (std::declval<T&>().write(std::declval<range_type_t<Range> const &>()));

template <typename T>
using insert_func_t = decltype
  (std::declval<T&>().insert(std::declval<range_type_t<Range> const &>()));

template <typename T>
using comp_t
  = decltype (std::declval<const T&>().has_writable());

template <typename T>
using io_t = decltype (std::declval<const T&>().has_io());

static constexpr bool has_write
  = bits::is_detected<func_t, bits::r_type<Range>>::value;

static constexpr bool has_insert
  = bits::is_detected<insert_func_t, bits::r_type<Range>>::value;

static constexpr bool has_has_writable
  = bits::is_detected<comp_t, bits::r_type<Range>>::value;

static constexpr bool has_has_io
  = bits::is_detected<io_t, bits::r_type<Range>>::value;

public:

static constexpr bool value
  = (has_write || has_insert) && (has_has_io || has_has_writable);
};

/*==============================================================================
  is_input
==============================================================================*/
template <typename Range>
struct is_input {

private:

template <typename T>
using read_t = decltype (std::declval<const T&>().read());

template <typename T>
using drain_t
  = decltype (std::declval<const T&>().drain(std::declval<range_type_t<Range> &>()));

template <typename T>
using comp_t = decltype (std::declval<const T&>().has_readable());

template <typename T>
using io_t = decltype (std::declval<const T&>().has_io());

static constexpr bool has_read = bits::is_detected<read_t, bits::r_type<Range>>::value;
static constexpr bool has_drain = bits::is_detected<drain_t, bits::r_type<Range>>::value;
static constexpr bool has_has_readable = bits::is_detected<comp_t, bits::r_type<Range>>::value;
static constexpr bool has_has_io = bits::is_detected<io_t, bits::r_type<Range>>::value;

public:

static constexpr bool value
  = (has_read || has_drain) && (has_has_readable || has_has_io);
};

/*==============================================================================
  is_finite
==============================================================================*/
template <typename Range>
struct is_finite {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().size());

template <typename T>
using pos_t = decltype(std::declval<T&>().position());

static constexpr bool has_size
  = bits::is_detected<func_t, bits::r_type<Range>>::value;

static constexpr bool has_position
  = bits::is_detected<pos_t, bits::r_type<Range>>::value;

public:

static constexpr bool value = has_size && has_position;
};

/*==============================================================================
  is_reversable
==============================================================================*/
template <typename Range>
struct is_reversable {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().prev());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*==============================================================================
  is_next_linear
==============================================================================*/
template <typename Range>
struct is_next_linear {

private:

template <typename T>
using fwdfunc_t = decltype (
  std::declval<T&>().next(std::declval<int>()) );

public:

static constexpr bool value
  = ! bits::is_detected<fwdfunc_t, bits::r_type<Range>>::value;
};

/*==============================================================================
  is_prev_linear
==============================================================================*/
template <typename Range>
struct is_prev_linear {

private:

template <typename T>
using func_t = decltype (
  std::declval<T&>().prev(std::declval<int>()) );

public:

static constexpr bool value
  = !(bits::is_detected<func_t, bits::r_type<Range>>::value);
};

/*==============================================================================
  is_shrinkable
==============================================================================*/
/*template <typename Range>
struct is_shrinkable {

private:

template <typename T>
using func_t = decltype (std::declval<T&>().erase());

template <typename T>
using drain_t
  = decltype (std::declval<const T&>().drain(std::declval<range_type_t<Range> &>()));

static constexpr bool has_erase
  = bits::is_detected<func_t, bits::r_type<Range>>::value;

static constexpr bool has_drain
  = bits::is_detected<drain_t, bits::r_type<Range>>::value;

public:

static constexpr bool value = has_erase || has_drain;
};*/

/*==============================================================================
  is_clearable
==============================================================================*/
/*template <typename Range>
struct is_clearable {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().clear());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};*/

/*==============================================================================
  is_expandable
==============================================================================*/
/*template <typename Range>
struct is_expandable {

private:

template <typename T>
using func_t = decltype (std::declval<T&>().expand(std::declval<int>()));

template <typename T>
using insert_func_t
  = decltype(std::declval<T&>().insert(std::declval<range_type_t<Range>>()));

static constexpr bool has_expand
  = bits::is_detected<func_t, bits::r_type<Range>>::value;

static constexpr bool has_insert
  = bits::is_detected<insert_func_t, bits::r_type<Range>>::value;

public:

static constexpr bool value = has_expand || has_insert;
  = 
};*/

/*==============================================================================
  is_decorator
==============================================================================*/
template <typename R>
struct is_decorator {

private:

template <typename T>
using func_t = decltype (std::declval<T&>().disable());

public:

static constexpr bool value = bits::is_detected<func_t, bits::r_type<R>>::value;
};

} //-----------------------------------------------------------------range layer
#endif

