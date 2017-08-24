// Skips over range elements that match the predicate.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REMOVE_RANGE_HPP
#define RANGE_LAYER_REMOVE_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  remove range
===========================================================*/
template <typename Range, typename Pred>
class remove_range
: public bits::base_decor<Range, remove_range<Range, Pred>>
{

Pred pred;
typename range_trait::read_type<Range>::type temp;

using base_t
  = bits::base_decor<Range, remove_range<Range, Pred>>;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
remove_range (
  Range _range
, Pred _pred
)
: base_t {_range}
, pred {_pred}
, temp ()
{
// Should not transverse the range in the ctor!
  while (this->range == sentinel::readable{}){
  this->temp = *this->range;
    if (! this->pred(this->temp)) break;
  ++this->range;
  }
}

/*===========================================================
  copy ctor
===========================================================*/
remove_range (remove_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
remove_range (remove_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
remove_range & operator = (remove_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
remove_range & operator = (remove_range const &) = default;

/*===========================================================
  dtor
===========================================================*/
~remove_range () = default;

using base_t::save;
using base_t::size;
using base_t::position;
using base_t::erase;
using base_t::erase_all;
using base_t::shrink;
using base_t::expand;
using base_t::insert;
using base_t::operator *;
using base_t::operator =;
using base_t::operator ==;
using base_t::disable;

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
remove_range &
operator ++ (){
++this->range;
  while (this->range == sentinel::readable{}){
  this->temp = *this->range;
    if (! this->pred(this->temp)) break;
  ++this->range;
  }
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
remove_range &
operator -- (){
--this->range;
  while (this->range == sentinel::readable{}){
  this->temp = *this->range;
    if (! this->pred(this->temp)) break;
  --this->range;
  }
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
remove_range &
operator += (
  N _n
){
++this->range;
  while ((0 != _n) && (this->range == sentinel::readable{})){
  this->temp = *this->range;
    if (! this->pred(this->temp)) --_n;
  ++this->range;
  }
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
remove_range &
operator -= (
  N _n
){
--this->range;
  while ((0 != _n) && (this->range == sentinel::readable{})){
  this->temp = *this->range;
    if (! this->pred(this->temp)) --_n;
  --this->range;
  }
return *this;
}

}; //remove range--------------------------------------------

/*===========================================================
  remove_pred
===========================================================*/
template <typename T>
struct remove_pred {

T value;

/*===========================================================
  operator ()
===========================================================*/
template <typename U>
bool
operator () (
  U _lhs
) const {
return this->value == _lhs;
}

};
//remove pred------------------------------------------------

} //bits-----------------------------------------------------
} //range layer----------------------------------------------
#endif

