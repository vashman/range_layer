// Attempts to tie the life time of varaibles with ranges.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_EXTEND_LIFE_RANGE_HPP
#define RANGE_LAYER_EXTEND_LIFE_RANGE_HPP

#include <tuple>
#include <memory>
#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  extend life
===========================================================*/
template <typename Range, template <typename> class Ptr, typename... Ts>
class extend_life
: public bits::base_decor
  < Range
  , extend_life<Range, Ptr, Ts...>
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
  , extend_life<Range, Ptr, Ts...>
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

std::tuple<Ptr<Ts>...> variable;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
explicit
extend_life (
  Range
, std::tuple<Ptr<Ts>...>
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

/*===========================================================
  set_range
 * used internally to reset the range, after the container
 * has moved or been copied to inside the range.
===========================================================*/
void
set_range (
  Range _range
){
this->rng = _range;
}

}; //---------------------------------------------extend_life

/*===========================================================
  ctor
===========================================================*/
template <typename Range, template <typename> class Ptr, typename... Ts>
extend_life<Range, Ptr, Ts...>::extend_life (
  Range _range
, std::tuple<Ptr<Ts>...> _variable
)
: extend_life<Range, Ptr, Ts...>::base_t {_range}
, variable {_variable}
{}

} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif

