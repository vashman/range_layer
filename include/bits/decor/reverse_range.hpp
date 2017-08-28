//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REVERSE_RANGE_HPP
#define RANGE_LAYER_REVERSE_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  reverse range
===========================================================*/
template <typename Range>
class reverse_range
: public bits::base_decor
  < Range
  , reverse_range<Range>
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
  , range_trait::is_subscriptable<Range>
  , range_trait::is_decorator<Range>
  >
{

using base_t = bits::base_decor
  < Range
  , reverse_range<Range>
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
  , range_trait::is_subscriptable<Range>
  , range_trait::is_decorator<Range>
  >;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
reverse_range (
  Range _range
)
: base_t {_range}
{}

/*===========================================================
  copy ctor
===========================================================*/
reverse_range (reverse_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
reverse_range (reverse_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
reverse_range &
operator = (reverse_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
reverse_range &
operator = (reverse_range const &) = default;

/*===========================================================
  dtor
===========================================================*/
~reverse_range () = default;

/*===========================================================
  operator ++
===========================================================*/
reverse_range &
operator ++ (){
--this->range;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
reverse_range &
operator -- (){
++this->range;
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
reverse_range &
operator += (
  N _n
){
this->range -= _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
reverse_range &
operator -= (
  N _n
){
this->range += _n;
return *this;
}

}; // reverse range------------------------------------------

} // bits----------------------------------------------------
} //range layer----------------------------------------------
#endif

