// used as base class to implement un-used functions.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_BASE_DECOR_HPP
#define RANGE_LAYER_BITS_BASE_DECOR_HPP

namespace range_layer {
namespace bits {

/*===========================================================
  base decor
===========================================================*/
template <typename Range, typename Decorator>
class base_decor {

protected:

Range range;

/*===========================================================
  ctor
===========================================================*/
base_decor (
  Range _range
);

/*===========================================================
  copy ctor
===========================================================*/
base_decor (base_decor const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
base_decor & operator = (base_decor const &) = default;

/*===========================================================
  move ctor
===========================================================*/
base_decor (base_decor &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
base_decor & operator = (base_decor &&) = default;

/*===========================================================
  dtor
===========================================================*/
~base_decor() = default;

/*===========================================================
  operator *
===========================================================*/
template <typename U = Range>
auto
operator * () -> decltype(*this->range);

/*===========================================================
  operator =
===========================================================*/
template <typename T>
void
operator = (
  T const &
);

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
Decorator &
operator ++ ();

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
Decorator &
operator += (
  N
);

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
Decorator &
operator -- ();

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
Decorator &
operator -= (
  N
);

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::readable const &
) const;

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::writable const &
) const;

/*===========================================================
  size
===========================================================*/
template <typename U = Range>
auto
size () const -> decltype(this->range.size());

/*===========================================================
  position
===========================================================*/
template <typename U = Range>
auto
position () const -> decltype(this->range.position());

/*===========================================================
  save
===========================================================*/
template <typename U = Range>
Decorator
save ();

/*===========================================================
  erase
===========================================================*/
template <typename U = Range>
void
erase ();

/*===========================================================
  erase all
===========================================================*/
template <typename U = Range>
void
erase_all ();

/*===========================================================
  shrink
===========================================================*/
template <typename N>
void
shrink (
  N
);

/*===========================================================
  insert
===========================================================*/
template <typename... Args>
void
insert (
  Args &&...
);

/*===========================================================
  expand
===========================================================*/
template <typename N>
void
expand (
  N
);

public:

/*===========================================================
  disable
===========================================================*/
Range
disable () const;

};
//base decor-------------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#include "base_decor.tcc"
#endif

