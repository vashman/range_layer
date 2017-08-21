// Attempts to tie the life time of varaibles with ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_EXTEND_LIFE_RANGE_HPP
#define RANGE_LAYER_EXTEND_LIFE_RANGE_HPP

#include <tuple>
#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  extend life
===========================================================*/
template <typename Range, typename... Ts>
class extend_life
: public bits::base_decor<Range, extend_life<Range, Ts...>>
{

using base_t
  = bits::base_decor<Range, extend_life<Range, Ts...>>;

public:

// variables will need to be stored as pointers.
std::tuple<Ts...> variables;

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
extend_life (
  Range
, Ts...
);

/*===========================================================
  copy ctor
===========================================================*/
extend_life (extend_life const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
extend_life & operator = (extend_life const &) = default;

/*===========================================================
  move ctor
===========================================================*/
extend_life (extend_life &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
extend_life & operator = (extend_life &&) = default;

/*===========================================================
  dtor
===========================================================*/
~extend_life() = default;

using base_t::operator *;
using base_t::operator =;
using base_t::operator ++;
using base_t::operator +=;
using base_t::operator --;
using base_t::operator -=;
using base_t::operator ==;
using base_t::save;
using base_t::size;
using base_t::position;
using base_t::insert;
using base_t::expand;
using base_t::shrink;
using base_t::erase;
using base_t::erase_all;

/* used internally to reset the range, after the container
 * has moved or been copied to inside the range.
 */
void
set_range (
  Range _range
){
this->range = _range;
}

};
//extend_life------------------------------------------------

/*===========================================================
  ctor
===========================================================*/
template <typename Range, typename... Ts>
extend_life<Range, Ts...>::extend_life (
  Range _range
, Ts... _ts
)
: extend_life<Range, Ts...>::base_t {_range}
, variables {_ts...}
{}

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif

