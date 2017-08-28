//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DISABLE_INPUT_HPP
#define RANGE_LAYER_DISABLE_INPUT_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  disable input
===========================================================*/
template <typename Range>
class disable_input
: public bits::base_decor
  < Range
  , disable_input<Range>
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
  , disable_input<Range>
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

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
disable_input (
  Range _range
)
: base_t {_range}
{}

/*===========================================================
  copy ctor
===========================================================*/
disable_input (disable_input const &) = default;

/*===========================================================
  move ctor
===========================================================*/
disable_input (disable_input &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
disable_input & operator = (disable_input &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
disable_input & operator = (disable_input const &) = default;

/*===========================================================
  dtor
===========================================================*/
~disable_input () = default;

using base_t::size;
using base_t::position;
using base_t::save;
using base_t::operator =;
using base_t::operator ++;
using base_t::operator +=;
using base_t::operator --;
using base_t::operator -=;
using base_t::operator ==;
using base_t::erase;
using base_t::erase_all;
using base_t::shrink;
using base_t::insert;
using base_t::expand;
using base_t::disable;

}; //disable input-------------------------------------------

} //bits-----------------------------------------------------
} //range layer----------------------------------------------
#endif

