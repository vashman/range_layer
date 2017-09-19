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
  remove_range
===========================================================*/
template <typename Range, typename Pred>
class remove_range
: public bits::base_decor
  < Range
  , remove_range<Range, Pred>
  , range_trait::is_linear<Range>
  , range_trait::is_reversable<Range>
  , range_trait::is_input<Range>
  , range_trait::is_output<Range>
  , range_trait::has_position<Range>
  , range_trait::is_singleton<Range>
  , range_trait::is_finite<Range>
  , range_trait::is_erasable<Range>
  , range_trait::is_all_erasable<Range>
  , range_trait::is_shrinkable<Range>
  , range_trait::is_expandable<Range>
  , range_trait::is_insertable<Range>
  >
{

Pred pred;

typename  std::remove_cv
< typename std::remove_reference
  <range_trait::read_type_t<Range>
>::type>::type temp;

bool fetched;

using base_t = bits::base_decor
  < Range
  , remove_range<Range, Pred>
  , range_trait::is_linear<Range>
  , range_trait::is_reversable<Range>
  , range_trait::is_input<Range>
  , range_trait::is_output<Range>
  , range_trait::has_position<Range>
  , range_trait::is_singleton<Range>
  , range_trait::is_finite<Range>
  , range_trait::is_erasable<Range>
  , range_trait::is_all_erasable<Range>
  , range_trait::is_shrinkable<Range>
  , range_trait::is_expandable<Range>
  , range_trait::is_insertable<Range>
  >;

/*===========================================================
  get var
===========================================================*/
void
get_next (
){
  while (
     (this->rng == sentinel::readable{})
  && ! this->fetched
  ){
  this->temp = *this->rng;
    if (! this->pred(this->temp)) this->fetched = true;
  ++this->rng;
  }
}

public:

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
, pred (_pred)
, temp {}
, fetched {false}
{}

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

/*===========================================================
  operator ++
===========================================================*/
//template <typename U = Range>
remove_range &
operator ++ (){
this->fetched = false;
this->get_next();
return *this;
}

/*===========================================================
  operator --
===========================================================*/
/*template <typename U = Range>
remove_range &
operator -- (){
--this->range;
  while (this->range == sentinel::readable{}){
  this->temp = *this->range;
    if (! this->pred(this->temp)) break;
  --this->range;
  }
return *this;
}*/

/*===========================================================
  operator *
===========================================================*/
range_trait::read_type_t<Range>
operator * (
){
get_next();
return this->temp;
}

}; //--------------------------------------------remove range

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

}; //---------------------------------------------remove pred
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif

