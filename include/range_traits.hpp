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

template <typename Range>
struct range_traits {

/*
  Tuple for multiple types, but must support io for the
  group / tuple as well.
*/
template <typename T>
using rtype = typename T::read_type;

template <typename T>
using wtype = typename T::write_type;

using read_type
  = typename bits::detected_or<void, rtype, Range>::type;

using write_type
  = typename bits::detected_or<void, wtype, Range>::type;

template<class T>
using copy_assign_t
  = decltype(std::declval<T&>() = std::declval<const T&>());

template<class T>
using move_assign_t
  = decltype(std::declval<T&>() = std::declval<T&&>());

template <typename T>
using read_t = decltype(std::declval<T&>().operator *());

template <typename T>
using read_sen_t = decltype (
     std::declval<T&>()
  == std::declval<const sentinel::readable>()
);

template <typename T>
using advance_t = decltype(std::declval<T&>().operator ++());

template <typename T>
using reverse_t = decltype(std::declval<T&>().operator --());

template <typename T>
using subscript_t = decltype (
  std::declval<T&>().operator [](std::declval<int>()) );

template <typename T>
using write_t = decltype (
  std::declval<T&>().operator =(std::declval<write_type>()));

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

static_assert (
  bits::is_detected<advance_t, Range>::value
, "Range's must be advanceable (++)." );

static_assert (
  bits::is_detected<copy_assign_t, Range>::value
, "Ranges's must be copy assignable.");

static_assert (
  bits::is_detected<move_assign_t, Range>::value
, "Ranges's must be move assignable.");

/* interface traits */
static constexpr bool const is_output
   = bits::is_detected<write_t, Range>::value
  && bits::is_detected<write_sen_t, Range>::value;

static constexpr bool const is_input
   = bits::is_detected<read_t, Range>::value
  && bits::is_detected<read_sen_t, Range>::value;

static constexpr bool const is_reversable
  = bits::is_detected<reverse_t, Range>::value;

static constexpr bool const is_linear
   = !( bits::is_detected<linear_fwd_t, Range>::value
  && (( bits::is_detected<linear_bck_t, Range>::value
      && is_reversable )
    || ! is_reversable ) );

/* if true; erase, shrink */
static constexpr bool const is_erasable
  = bits::is_detected<shrink_t, Range>::value;

/* if true; insert, expand */
static constexpr bool const is_insertable
  = bits::is_detected<expand_t, Range>::value;

static constexpr validation_type const
  validation = Range::validation;

/* if true; read and write are mutually exclusive */
static constexpr bool const
  is_io_synced = Range::is_io_synced;

/* data traits */
struct input {
  /* input_size */
  static constexpr range_size const
    size_type = Range::input_size_type;

  // if true, the read function performs UB when reading to
  // the same postion more than once.
  static constexpr bool const
    is_temporary = Range::is_input_temporary;
};

struct output {
  /* output_size */
  static constexpr range_size const
    size_type = Range::output_size_type;

  // if true, the write function performs UB when writing to
  // the same postion more than once.
  static constexpr bool const
    is_temporary = Range::is_output_temporary;
};

/* if true; T& range[n] */
static constexpr bool const is_subscriptable
   = is_reversable
  && is_input
  && is_output
  && is_io_synced
  && (is_linear == false)
  && (input::size_type == range_size::finite)
  && (output::size_type == range_size::finite)
  && bits::is_detected<subscript_t, Range>::value;

}; /* range traits */

} /* range layer */
#endif

