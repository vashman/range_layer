// Traits for ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_TRAITS_HPP
#define RANGE_LAYER_BITS_RANGE_TRAITS_HPP

#include <limits>
#include <type_traits>
#include "range_traits.fwd"
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

namespace range_trait {

/*===========================================================
  is range
===========================================================*/
template <typename Range>
struct is_range {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().advance());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value
&& std::is_move_constructible<bits::r_type<Range>>::value;
};

/*===========================================================
  write_type

* When the range is not an output type, write type is void.
===========================================================*/
template <typename Range>
struct write_type {
using type = typename bits::detected_or
< bits::void_t
, bits::trait_bits::wtype
, bits::r_type<Range>
>::type;
};

/*===========================================================
  write_type_t
===========================================================*/
template <typename Range>
using write_type_t = typename write_type<Range>::type;

/*===========================================================
  is_output
===========================================================*/
template <typename Range>
struct is_output {

private:

template <typename T>
using func_t = decltype (
  std::declval<T&>().write (
    std::declval<write_type_t<bits::r_type<Range>> const &>()
  )
);

template <typename T>
using comp_t = decltype (
   std::declval<const T&>().has_writable()
);

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value
&&  bits::is_detected<comp_t, bits::r_type<Range>>::value;
};

/*===========================================================
  is_input
===========================================================*/
template <typename Range>
struct is_input {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().read());

template <typename T>
using comp_t = decltype (
     std::declval<const T&>().has_readable()
);

public:

static constexpr bool value
  =  bits::is_detected<func_t, bits::r_type<Range>>::value
  && bits::is_detected<comp_t, bits::r_type<Range>>::value;
};

/*===========================================================
  read_type

* When not input type is void.
===========================================================*/
template <typename Range>
struct read_type {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().read());

public:

using type = typename bits::detected_or
  <bits::void_t, func_t, bits::r_type<Range>>::type;
};

/*===========================================================
  read_type_t
===========================================================*/
template <typename Range>
using read_type_t = typename read_type<Range>::type;

/*===========================================================
  is_finite
===========================================================*/
template <typename Range>
struct is_finite {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().size());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*===========================================================
  size type
===========================================================*/
template <typename Range>
struct size_type {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().size());

public:

using type
  = typename bits::detected_or
  <bits::void_t, func_t, bits::r_type<Range>>::type;

static_assert (
   std::is_same<type, void>::value
|| std::is_unsigned<bits::r_type<Range>>::value
, "Range size must be a unsigned type."
);

static_assert (
   std::is_same<type, void>::value
|| std::numeric_limits<bits::r_type<Range>>::is_integer
, "Range size must be a interger type."
);

};

/*===========================================================
  size_type_t
===========================================================*/
template <typename Range>
using size_type_t = typename size_type<Range>::type;

/*===========================================================
  has_position
===========================================================*/
template <typename Range>
struct has_position {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().position());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;

static_assert (
 ! value || (value && is_finite<Range>::value)
, "Range with position also must have size."
);

static_assert (
  std::is_same
  < typename bits::trait_bits::pos_type<Range, value>::type
  , typename size_type<Range>::type
  >::value
, "Size and Position type must be the same."
);

};

/*===========================================================
  is_singleton
===========================================================*/
template <typename Range>
struct is_singleton {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().save());

public:

static constexpr bool value
  = ! bits::is_detected<func_t, bits::r_type<Range>>::value;
};


/*===========================================================
  is_reversable
===========================================================*/
template <typename Range>
struct is_reversable {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().reverse());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*===========================================================
  is_linear
===========================================================*/
template <typename Range>
struct is_linear {

private:

template <typename T>
using fwdfunc_t = decltype (
  std::declval<T&>().advance_n(std::declval<int>()) );

template <typename T>
using bckfunc_t = decltype (
  std::declval<T&>().reverse_n(std::declval<int>()) );

public:

static constexpr bool value
  = !(bits::is_detected<fwdfunc_t, bits::r_type<Range>>::value
&& (! is_reversable<Range>::value
  || (bits::is_detected <bckfunc_t, bits::r_type<Range>>::value
    && is_reversable<Range>::value
    )
  )
);
};

/*===========================================================
  is_shrinkable

* When true, calling advance_shrink shrinks the size of the
  range by removing elements from the beggining.
* The removed elements are destroyed.
* The ranges postion remains the same, until the element at
  the position is removed, then the postion advances by 1.

  pre:  | 0| 1|*2| 3| 4
  n = 1
  post: | 0| 1|*2| 3
  n = 3
  post: | 0| 1|*
===========================================================*/
template <typename Range>
struct is_shrinkable {

private:

template <typename T>
using func_t = decltype (
  std::declval<T&>().shrink
  (std::declval<size_type_t<Range>>())
);

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*===========================================================
  is_erasable

* When true, calling erase shrinks the size of the range by
  removing the current element.
* The removed elements are destroyed.
* The postion does not change.

  pre:  | 0| 1|*2| 3| 4
  post: | 0| 1|*3| 4

  pre:  | 0| 1| 2| 3|*4
  post: | 0| 1| 2| 3|*
===========================================================*/
template <typename Range>
struct is_erasable {

private:

template <typename T>
using func_t = decltype (std::declval<T&>().erase());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*===========================================================
  is_all_erasable

* When true, calling erase shrinks the size of the range by
  removing the current element.
* The removed elements are destroyed.
* The postion advacnes by 1.

  pre:  | 0| 1|*2| 3| 4
  post: *
===========================================================*/
template <typename Range>
struct is_all_erasable {

private:

template <typename T>
using func_t = decltype(std::declval<T&>().erase_all());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*===========================================================
  is_expandable

* When true, calling reverse_expand expands the size of the
  range by adding to the end.
* The postion does not change.

  pre:  | 0| 1|*2| 3| 4
  n = 1
  post: | 0| 1|*2| 3| 4| #
===========================================================*/
template <typename Range>
struct is_expandable {

private:

template <typename T>
using func_t = decltype (
  std::declval<T&>().expand
  (std::declval<size_type_t<Range>>())
);

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*===========================================================
  is_insertable

* When true, calling insert expands the size of the range by
  adding to the current postion with a write_type.
* The postion changes to the inserted element.

  pre:  | 0| 1|*2| 3| 4
  post: | 0| 1|*#| 2| 3| 4
===========================================================*/
template <typename Range>
struct is_insertable {

private:

template <typename T>
using func_t = decltype (
  std::declval<T&>().insert(std::declval<int>()) );

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

namespace input {

/*===========================================================
  is_temporary

* if true, the read function performs UB when reading to
  the same postion more than once.
===========================================================*/
template <typename Range>
struct is_temporary {

static constexpr bool value
   = (
       std::is_reference
      <decltype(std::declval<bits::r_type<Range>&>().operator *())>::value
  && std::is_const
       <decltype(std::declval<bits::r_type<Range>&>().operator *())>::value
  )
  || ! std::is_reference <
         decltype(std::declval<bits::r_type<Range>&>().operator *())>
       ::value;

};

/*===========================================================
  is_heterogeneous
===========================================================*/
/*template <typename Range>
struct is_heterogeneous {
static constexpr bool value
  = bits
    ::trait_bits
    ::is_typelist <
      typename bits
      ::detected_or<bits::void_t, bits::trait_bits::rtype, Range>
      ::type
      >
    ::value;
};*/ 

} //----------------------------------------------------input

namespace output {

/*===========================================================
  is_heterogeneous
===========================================================*/
/*template <typename Range>
struct is_heterogeneous {
static constexpr bool value
  = bits
  ::trait_bits
  ::is_typelist
  <   typename bits
    ::detected_or<bits::void_t, bits::trait_bits::wtype, Range>
    ::type
  >
  ::value;
};*/ 

} //---------------------------------------------------output

/*===========================================================
  is_subscriptable

* if true; T& range[n]
===========================================================*/
template <typename Range>
struct is_subscriptable {

private:

template <typename T>
using func_t = decltype (
  std::declval<T&>().operator []
  (std::declval<size_type_t<Range>>())
);

public:

static constexpr bool value
  = is_reversable<Range>::value
&& is_input<Range>::value
&& is_output<Range>::value
&& (is_linear<Range>::value == false)
&& is_finite<Range>::value
&& bits::is_detected<func_t, bits::r_type<Range>>::value;
};

/*===========================================================
  is_decorator
===========================================================*/
template <typename Range>
struct is_decorator {

private:

template <typename T>
using func_t = decltype (std::declval<T&>().disable());

public:

static constexpr bool value
  = bits::is_detected<func_t, bits::r_type<Range>>::value;
};

} //----------------------------------------------range trait
} //----------------------------------------------range layer
#endif

