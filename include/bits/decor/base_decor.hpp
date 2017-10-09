// used as base class to implement un-used functions.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_BASE_DECOR_HPP
#define RANGE_LAYER_BITS_BASE_DECOR_HPP

#include "../range_traits.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  has_type

* True if T is in the list.
===========================================================*/
template <typename...>
struct has_type {
static constexpr bool value = false;
};

template <typename T, typename U, typename... Ts>
struct has_type <T, U, Ts...> {
static constexpr bool value
  = std::is_same<T, U>::value || has_type<T, Ts...>::value;
};

/*===========================================================
  enable_range_if
===========================================================*/
template
  <template <typename> class T, typename R, typename... Ts>
using enable_range_if = std::enable_if
<has_type<T<R>, Ts...>::value && T<R>::value, void>;

/*===========================================================
  enable_range_if_not
===========================================================*/
template
  < template <typename> class T, typename R, typename... Ts>
using enable_range_if_not = std::enable_if
<has_type<T<R>, Ts...>::value && (!T<R>::value), void>;

/*===========================================================
  enable_range_if_t
===========================================================*/
template
  <template <typename> class T, typename R, typename... Ts>
using enable_range_if_t = typename enable_range_if
  <T, R, range_trait::is_range<R>, Ts...>::type;

/*===========================================================
  enable_range_if_not_t
===========================================================*/
template
  <template <typename> class T, typename R, typename... Ts>
using enable_range_if_not_t = typename enable_range_if_not
  <T, R, range_trait::is_range<R>, Ts...>::type;

/*===========================================================
  base_decor
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
class base_decor {

protected:

Range rng;

base_decor (Range);

public:

/*===========================================================
  read
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_input, R, Traits...>
>
auto read ();

/*===========================================================
  write
===========================================================*/
template
< typename T
, typename R = Range
, typename = enable_range_if_t
    <range_trait::is_output, R, Traits...>
>
void write (T const &);

/*===========================================================
  operator ++
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_range, R, Traits...>
>
range<Range, Decorator> & operator ++ ();

/*===========================================================
  operator +=
===========================================================*/
template
< typename N
, typename R = Range
, typename = enable_range_if_not_t
    <range_trait::is_linear, R, Traits...>
>
range<Range, Decorator> & operator += (N);

/*===========================================================
  operator --
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_reversable, R, Traits...> // checks is linear?
>
range<Range, Decorator> & operator -- ();

/*===========================================================
  operator -=
===========================================================*/
template
< typename N
, typename R = Range
, typename = enable_range_if_not_t
    <range_trait::is_linear, R, Traits...>
>
range<Range, Decorator> & operator -= (N);

/*===========================================================
  operator ==
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_input, R, Traits...>
>
bool operator == (sentinel::readable const &) const;

/*===========================================================
  operator ==
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_output, R, Traits...>
>
bool operator == (sentinel::writable const &) const;

/*===========================================================
  size
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_finite, R, Traits...>
>
typename range_trait::size_type<Range>::type
size () const;

/*===========================================================
  position
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::has_position, R, Traits...>
>
typename range_trait::size_type<Range>::type
position () const;

/*===========================================================
  save
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_not_t
    <range_trait::is_singleton, R, Traits...> //! singleton?
>
range<Range, Decorator> save () const;

/*===========================================================
  erase
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_erasable, R, Traits...>
>
void erase ();

/*===========================================================
  erase all
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_all_erasable, R, Traits...>
>
void erase_all ();

/*===========================================================
  shrink
===========================================================*/
template
< typename N
, typename R = Range
, typename = enable_range_if_t
    <range_trait::is_shrinkable, R, Traits...>
>
void shrink (N);

/*===========================================================
  insert
===========================================================*/
template
< typename... Args
, typename R = Range
, typename = enable_range_if_t
    <range_trait::is_insertable, R, Traits...>
>
void insert (Args &&...);

/*===========================================================
  expand
===========================================================*/
template
< typename N
, typename R = Range
, typename = enable_range_if_t
    <range_trait::is_expandable, R, Traits...>
>
void expand (N);

/*===========================================================
  disable
===========================================================*/
template
< typename R = Range
, typename = enable_range_if_t
    <range_trait::is_decorator, R, Traits...>
>
Range disable () const;

}; //----------------------------------------------base decor
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif

