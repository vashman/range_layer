//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BACK_INSERT_HPP
#define RANGE_LAYER_BACK_INSERT_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  back insert
===========================================================*/
template <typename Range>
class back_insert
: public bits::base_decor
  < Range
  , back_insert<Range>
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
  , back_insert<Range>
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
back_insert (
  Range _range
)
: base_t {end_of_output(_range)}
{
expand(this->range, 1);
}

/*===========================================================
  copy ctor
===========================================================*/
back_insert (back_insert const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
back_insert & operator = (back_insert const &) = default;

/*===========================================================
  move ctor
===========================================================*/
back_insert (back_insert &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
back_insert & operator = (back_insert &&) = default;

/*===========================================================
  dtor
===========================================================*/
~back_insert() = default;

/*===========================================================
  operator ++
===========================================================*/
back_insert &
operator ++ (
){
expand(this->range, 1);
++this->range;
return *this;
}

using base_t::operator =;

}; //back insert---------------------------------------------

} //bits-----------------------------------------------------
} //range layer----------------------------------------------
#endif

