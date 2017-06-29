// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_TRAITS_HPP
#define RANGE_LAYER_RANGE_TRAITS_HPP

#include "bits/is_detected.hpp"

namespace range_layer {

namespace sentinel {

class readable {};
class writable {};

} /* sentinel */

template <template <typename...> class Tuple, typename... Ts>
struct type_list {

using tuple_type = Tuple<Ts...>;

type_list () = delete;
type_list (type_list const &) = delete;
type_list (type_list &&) = delete;
type_list & operator = (type_list const &) = delete;
type_list & operator = (type_list &&) = delete;

}; /* type list */

enum class validation_type {
  // Only a single instance may be transversed.
  single
  // All instances transverse at the same time. 
, synced
  // All instances maintain there postion indepent of others.
, unsynced
};

enum class range_size {
  finite // count <= size_type
, countable // count > size_type {N1, N2, N3...}
, uncountable // count unknown to size_type; 0, 1, infinity
};

namespace bits {
namespace trait_bits {

template <typename T>
using rtype = typename T::read_type;

template <typename T>
using diff_type = typename T::difference_type;

template <typename T>
using wtype = typename T::write_type;

template<class T>
using copy_assign_t
  = decltype(std::declval<T&>() = std::declval<const T&>());

template<class T>
using move_assign_t
  = decltype(std::declval<T&>() = std::declval<T&&>());

template <typename T>
using read_t = decltype(std::declval<T&>().operator *());

template <typename T>
using advance_t = decltype(std::declval<T&>().operator ++());

template <typename T>
using reverse_t = decltype(std::declval<T&>().operator --());

template <typename T>
using subscript_t = decltype (
  std::declval<T&>().operator [](std::declval<int>()) );

template <typename T>
using read_sen_t = decltype (
     std::declval<T&>()
  == std::declval<const sentinel::readable>()
);

template <typename T>
using write_t = decltype (
  std::declval<T&>().operator =(std::declval<int>()));

template <typename T>
using write_sen_t = decltype (
   std::declval<T&>()
== std::declval<const sentinel::writable>()
);

template <typename T>
using linear_fwd_t = decltype (
  std::declval<T&>().operator +=(std::declval<int>()) );

template <typename T>
using linear_bck_t = decltype (
  std::declval<T&>().operator -=(std::declval<int>()) );

template <typename T>
using expand_t = decltype (
  std::declval<T&>().expand(std::declval<int>()) );

template <typename T>
using shrink_t = decltype (
  std::declval<T&>().shrink(std::declval<int>()) );

} /* trait bits */ } /* bits */

namespace range_trait {

template <typename Range>
struct is_range {

static constexpr bool const value
   = bits::is_detected<bits::trait_bits::advance_t, Range>::value
  && bits::is_detected<bits::trait_bits::copy_assign_t, Range>::value
  && bits::is_detected<bits::trait_bits::move_assign_t, Range>::value;
};

template <typename Range>
struct read_type {
using type
  = typename bits::detected_or<void, bits::trait_bits::rtype, Range>::type;
};

template <typename Range>
struct write_type {
using type = typename bits::detected_or<void, bits::trait_bits::wtype, Range>::type;
};

template <typename Range>
struct is_output {
static constexpr bool const value
   = bits::is_detected<bits::trait_bits::write_t, Range>::value
  && bits::is_detected<bits::trait_bits::write_sen_t, Range>::value;
};

template <typename Range>
struct is_input {
static constexpr bool const value
   = bits::is_detected<bits::trait_bits::read_t, Range>::value
  && bits::is_detected<bits::trait_bits::read_sen_t, Range>::value;
};

template <typename Range>
struct is_reversable {
static constexpr bool const value
  = bits::is_detected<bits::trait_bits::reverse_t, Range>::value;
};

template <typename Range>
struct is_linear {
static constexpr bool const value
   = !( bits::is_detected<bits::trait_bits::linear_fwd_t, Range>::value
  && (( bits::is_detected<bits::trait_bits::linear_bck_t, Range>::value
      && is_reversable<Range>::value )
    || ! is_reversable<Range>::value ) );
};

/* if true; erase, shrink */
template <typename Range>
struct is_erasable {
static constexpr bool const value
  = bits::is_detected<bits::trait_bits::shrink_t, Range>::value;
};

/* if true; insert, expand */
template <typename Range>
struct is_insertable {
static constexpr bool const value
  = bits::is_detected<bits::trait_bits::expand_t, Range>::value;
};

template <typename Range>
struct validation {
static constexpr validation_type const value = Range::validation;
};

/* if true; read and write are mutually exclusive */
template <typename Range>
struct is_io_synced {
static constexpr bool const value = Range::is_io_synced;
};

namespace input {

/* input_size */
template <typename Range>
struct size_type {
static constexpr range_size const value = Range::input_size_type;
};

// if true, the read function performs UB when reading to
// the same postion more than once.
template <typename Range>
struct is_temporary {
static constexpr bool const value = Range::is_input_temporary;
};

} /* input */

namespace output {

/* output_size */
template <typename Range>
struct size_type {
static constexpr range_size const value = Range::output_size_type;
};

// if true, the write function performs UB when writing to
// the same postion more than once.
template <typename Range>
struct is_temporary {
static constexpr bool value = Range::is_output_temporary;
};

} /* output */

/* if true; T& range[n] */
template <typename Range>
struct is_subscriptable {
static constexpr bool const value
   = is_reversable<Range>::value
  && is_input<Range>::value
  && is_output<Range>::value
  && is_io_synced<Range>::value
  && (is_linear<Range>::value == false)
  && (input::size_type<Range>::value == range_size::finite)
  && (output::size_type<Range>::value == range_size::finite)
  && bits::is_detected<bits::trait_bits::subscript_t, Range>::value;
};

} /* range  trait */

} /* range layer */
#endif

