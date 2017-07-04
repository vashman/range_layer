// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_RANGE_TRAITS_HPP
#define RANGE_LAYER_RANGE_TRAITS_HPP

#include "bits/is_detected.hpp"
#include <limits>
#include <type_traits>

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

namespace bits {
namespace trait_bits {

template <typename T>
using rtype = typename T::read_type;

template <typename T>
using wtype = typename T::write_type;

template <typename T>
using stype = decltype(T::max_size);

template <typename T>
using sing_t = decltype(T::is_singleton);

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

template <typename T>
using disable_t = decltype (std::declval<T&>().disable());

template <typename T>
using save_t = decltype(std::declval<T&>().save());

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

} /* trait bits */ } /* bits */

namespace range_trait {

template <typename Range>
struct is_range {

static constexpr bool value
  = bits
    ::is_detected<bits::trait_bits::advance_t, Range>::value
  && std::is_copy_constructible<Range>::value
  && std::is_copy_assignable<Range>::value
  && std::is_move_constructible<Range>::value
  && std::is_move_assignable<Range>::value;

};

template <typename Range>
struct read_type {
using type
  = typename bits
    ::detected_or<void, bits::trait_bits::rtype, Range>
    ::type;
};

template <typename Range>
struct write_type {
using type
  = typename bits
    ::detected_or<void, bits::trait_bits::wtype, Range>
    ::type;
};

template <typename Range>
struct max_size {

using type
  = typename bits
    ::detected_or <
        std::size_t, bits::trait_bits::stype, Range
      >
    ::type;

static constexpr type value
  = std::numeric_limits<std::size_t>::max();

static_assert (
  std::is_unsigned<type>::value
, "Size must be a unsigned type."
);

static_assert (
  std::numeric_limits<type>::is_integer
, "Size must be a interger type."
);

};

template <typename Range>
struct is_singleton {
static constexpr bool value
  = ! bits
      ::is_detected<bits::trait_bits::save_t, Range>::value;
};

template <typename Range>
struct is_output {
static constexpr bool value
   = bits
     ::is_detected<bits::trait_bits::write_t, Range>::value
  && bits
     ::is_detected<bits::trait_bits::write_sen_t, Range>
     ::value;
};

template <typename Range>
struct is_input {
static constexpr bool value
   = bits
     ::is_detected<bits::trait_bits::read_t, Range>
     ::value
  && bits
     ::is_detected<bits::trait_bits::read_sen_t, Range>
     ::value;
};

template <typename Range>
struct is_reversable {
static constexpr bool value
  = bits
    ::is_detected<bits::trait_bits::reverse_t, Range>::value;
};

template <typename Range>
struct is_linear {
static constexpr bool value
   = !( bits
        ::is_detected<bits::trait_bits::linear_fwd_t, Range>
        ::value
  && (( bits
        ::is_detected<bits::trait_bits::linear_bck_t, Range>
        ::value
      && is_reversable<Range>::value )
    || ! is_reversable<Range>::value
       )
      );
};

/* if true; erase, shrink */
template <typename Range>
struct is_erasable {
static constexpr bool value
   = bits
  ::is_detected<bits::trait_bits::shrink_t, Range>::value;
};

/* if true; insert, expand */
template <typename Range>
struct is_insertable {
static constexpr bool value
   = bits
  ::is_detected<bits::trait_bits::expand_t, Range>::value;
};

template <typename Range>
struct is_finite {
static constexpr bool value
  = max_size<Range>::value
  < std::numeric_limits
      <typename max_size<Range>::type>::max();
};

namespace input {

// if true, the read function performs UB when reading to
// the same postion more than once.
template <typename Range>
struct is_temporary {

static constexpr bool value
   = ( std::is_reference
       <decltype(std::declval<Range&>().operator *())>::value
    && std::is_const
       <decltype(std::declval<Range&>().operator *())>::value
     )
  || ! std::is_reference <
         decltype(std::declval<Range&>().operator *())>
      ::value;

};

} /* input */

namespace output {

} /* output */

/* if true; T& range[n] */
template <typename Range>
struct is_subscriptable {
static constexpr bool value
   = is_reversable<Range>::value
  && is_input<Range>::value
  && is_output<Range>::value
  && (is_linear<Range>::value == false)
  && is_finite<Range>::value
  && bits
  ::is_detected<bits::trait_bits::subscript_t, Range>::value;
};

template <typename Range>
struct is_decorator {
static constexpr bool value
   = bits
  ::is_detected<bits::trait_bits::disable_t, Range>::value;
};

} /* range  trait */

} /* range layer */
#endif

