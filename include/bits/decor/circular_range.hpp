//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_CIRCULAR_RANGE_HPP
#define RANGE_LAYER_CIRCULAR_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  circular range
===========================================================*/
template <typename Range>
class circular_range
: public bits::base_decor<Range, circular_range<Range>>
{

using base_t
  = bits::base_decor<Range, circular_range<Range>>;

/*===========================================================
  is_end
===========================================================*/
bool
is_end (
) const {
// Return true if either end is reached.
return (
   ! (this->range == sentinel::writable{})
|| ! (this->range == sentinel::readable{})
);
}

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
circular_range (
  Range _range
)
: base_t {_range}
{}

/*===========================================================
  copy ctor
===========================================================*/
circular_range (circular_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
circular_range (circular_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
circular_range & operator = (circular_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
circular_range &
operator = (
  circular_range const &
) = default;

/*===========================================================
  dtor
===========================================================*/
~circular_range () = default;

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
circular_range &
operator ++ (){
++this->range;
  if (this->is_end())
  this->range = start_of(this->range);
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
circular_range &
operator -- (){
--this->range;
  if (this->is_end())
  this->range = end_of(this->range);
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
circular_range &
operator += (
  N _n
){
  while (_n > 0){
  this->operator ++();
  --_n;
  }
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
circular_range &
operator -= (
  N _n
){
  while (_n > 0){
  this->operator --();
  --_n;
  }
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
constexpr bool
operator == (
  sentinel::readable const & _sen
) const {
return true;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
constexpr bool
operator == (
  sentinel::writable const & _sen
) const {
return true;
}

using base_t::save;
using base_t::position;
using base_t::expand;
using base_t::shrink;
using base_t::erase;
using base_t::erase_all;
using base_t::operator =;
using base_t::operator *;

};
//circular range---------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif

