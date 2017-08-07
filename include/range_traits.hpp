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
#include "bits/typelist.hpp"

namespace range_layer {

namespace sentinel {

class readable {};
class writable {};

} /* sentinel */

namespace bits {
namespace trait_bits {

template <typename T>
using rtype = typename T::read_type;

template <typename T>
using wtype = typename T::write_type;

template <typename T>
using sing_t = decltype(T::is_singleton);

template <typename T>
using read_t = decltype(std::declval<T&>().operator *());

template <typename T>
using rsize_t = decltype(std::declval<T&>().size());

template <typename T>
using rpos = decltype(std::declval<T&>().position());

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

template <typename T>
struct is_typelist {
using type = T;
static constexpr bool value = false;
};

template <template <typename...> class Tuple, typename... Ts>
struct is_typelist <typelist<Tuple, Ts...>> {
static constexpr bool value = true;
using type = typename typelist<Tuple, Ts...>::type;
};

template <template <typename...> class Tuple, typename T>
struct is_typelist <typelist<Tuple, T>> {
static constexpr bool value = false;
using type = typename typelist<Tuple, T>::type;
};

template <typename Range, bool HasSize>
struct size_type;

template <typename Range>
struct size_type<Range, false> {
using type = std::size_t;
};

template <typename Range>
struct size_type<Range, true> {

using type = decltype(std::declval<Range&>().size());

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
  = typename bits::trait_bits::is_typelist
  <
    typename bits
  ::detected_or<void, bits::trait_bits::rtype, Range>
  ::type
  >::type;
};

template <typename Range>
struct write_type {
using type
  = typename bits::trait_bits::is_typelist
  < typename bits
    ::detected_or<void, bits::trait_bits::wtype, Range>
    ::type
  >
  ::type;
};

template <typename Range>
struct size_type {
using type
  = typename bits
  ::trait_bits
  ::size_type
  < Range
  , bits::is_detected<bits::trait_bits::rsize_t, Range>
    ::value
  >
  ::type;

static_assert (
  std::is_unsigned<type>::value
, "Range size must be a unsigned type."
);

static_assert (
  std::numeric_limits<type>::is_integer
, "Range size must be a interger type."
);

};

template <typename Range>
struct has_position {
static constexpr bool value
  = bits
  ::is_detected<bits::trait_bits::rpos, Range>
  ::value;

static_assert (
  std::is_same
  < typename size_type<Range>::type
  , decltype(std::declval<Range&>().position())
  >
  ::value
, "Range postion and Size must return same type."
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
&&  bits
  ::is_detected<bits::trait_bits::write_sen_t, Range>
  ::value;
};

template <typename Range>
struct is_input {
static constexpr bool value
  = bits
  ::is_detected<bits::trait_bits::read_t, Range>
  ::value
&&
    bits
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
  = !(bits
  ::is_detected<bits::trait_bits::linear_fwd_t, Range>
  ::value
&& ((
        bits
      ::is_detected <bits::trait_bits::linear_bck_t, Range>
      ::value

   && is_reversable<Range>::value
   )
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
   = bits::is_detected<bits::trait_bits::expand_t, Range>
  ::value;
};

template <typename Range>
struct is_finite {
static constexpr bool value
  = bits::is_detected<bits::trait_bits::rsize_t, Range>
  ::value;
};

namespace input {

// if true, the read function performs UB when reading to
// the same postion more than once.
template <typename Range>
struct is_temporary {

static constexpr bool value
   = (
       std::is_reference
      <decltype(std::declval<Range&>().operator *())>::value
  && std::is_const
       <decltype(std::declval<Range&>().operator *())>::value
  )
  || ! std::is_reference <
         decltype(std::declval<Range&>().operator *())>
       ::value;

};

template <typename Range>
struct is_heterogeneous {
static constexpr bool value
  = bits
    ::trait_bits
    ::is_typelist <
      typename bits
      ::detected_or<void, bits::trait_bits::rtype, Range>
      ::type
      >
    ::value;
}; 

} /* input */

namespace output {

template <typename Range>
struct is_heterogeneous {
static constexpr bool value
  = bits
  ::trait_bits
  ::is_typelist
  <   typename bits
    ::detected_or<void, bits::trait_bits::wtype, Range>
    ::type
  >
  ::value;
}; 

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
&&  bits
  ::is_detected<bits::trait_bits::subscript_t, Range>
  ::value;
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

