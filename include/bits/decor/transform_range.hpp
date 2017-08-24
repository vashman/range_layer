//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_BITS_TRANSFORM_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  transform_range
===========================================================*/
template <typename Func, typename Range>
class transform_range
: public
  bits::base_decor<Range, transform_range<Func, Range>>
{

using base_t
  = bits::base_decor<Range, transform_range<Func, Range>>;

Func func;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
transform_range (
  Range _range
, Func _func
)
: base_t {_range}
, func (_func)
{}

/*===========================================================
  copy ctor
===========================================================*/
transform_range (transform_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
transform_range (transform_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
transform_range &
operator = (
  transform_range &&
) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
transform_range &
operator = (
  transform_range const &
) = default;

/*===========================================================
  dtor
===========================================================*/
~transform_range () = default;

/*===========================================================
  operator *
===========================================================*/
auto
operator * (
) -> decltype(this->func(*this->range)) {
return this->func(*this->range);
}

using base_t::save;
using base_t::size;
using base_t::position;
using base_t::erase;
using base_t::erase_all;
using base_t::shrink;
using base_t::expand;
using base_t::insert;
using base_t::operator ++;
using base_t::operator --;
using base_t::operator +=;
using base_t::operator -=;
using base_t::operator ==;
using base_t::disable;

}; //transform range-----------------------------------------

} //bits-----------------------------------------------------
} //range layer----------------------------------------------
#endif

