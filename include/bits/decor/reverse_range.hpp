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
: public bits::base_decor<Range, reverse_range<Range>>
{

using base_t = bits::base_decor<Range, reverse_range<Range>>;

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

using base_t::size;
using base_t::position;
using base_t::save;
using base_t::operator *;
using base_t::operator =;
using base_t::operator ==;
using base_t::erase;
using base_t::erase_all;
using base_t::shrink;
using base_t::insert;
using base_t::expand;

};
// reverse range---------------------------------------------

}
// bits------------------------------------------------------
}
//range layer------------------------------------------------
#endif

