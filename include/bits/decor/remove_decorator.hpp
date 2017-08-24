// Removes disable member function from range.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REMOVE_DECORATOR_HPP
#define RANGE_LAYER_REMOVE_DECORATOR_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  remove_decorator
===========================================================*/
template <typename Range>
class remove_decorator
: public bits::base_decor<Range, remove_decorator<Range>>
{

using base_t
  = bits::base_decor<Range, remove_decorator<Range>>;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
remove_decorator (
  Range _range
)
: base_t {_range}
{}

/*===========================================================
  copy ctor
===========================================================*/
remove_decorator (remove_decorator const &) = default;

/*===========================================================
  move ctor
===========================================================*/
remove_decorator (remove_decorator &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
remove_decorator &
operator = (
  remove_decorator &&
) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
remove_decorator &
operator = (
  remove_decorator const &
) = default;

using base_t::save;
using base_t::size;
using base_t::position;
using base_t::shrink;
using base_t::erase;
using base_t::erase_all;
using base_t::expand;
using base_t::insert;
using base_t::operator *;
using base_t::operator =;
using base_t::operator ++;
using base_t::operator --;
using base_t::operator +=;
using base_t::operator -=;
using base_t::operator ==;

}; //remove decorator----------------------------------------

} //bits-----------------------------------------------------
} //range layer----------------------------------------------
#endif
