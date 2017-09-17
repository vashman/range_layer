//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_INPUT_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_INPUT_TRANSFORM_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  input_transform_range
===========================================================*/
template <typename Func, typename Range>
class input_transform_range
: public bits::base_decor
  < Range
  , input_transform_range<Func, Range>
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
  , input_transform_range<Func, Range>
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

Func func;

public:

//using read_type = decltype(func(*rng));
using write_type = typename range_trait::write_type_t<Range>;

/*===========================================================
  ctor
===========================================================*/
input_transform_range (
  Range _range
, Func _func
)
: base_t {_range}
, func (_func)
{}

/*===========================================================
  copy ctor
===========================================================*/
input_transform_range (
  input_transform_range const &
) = default;

/*===========================================================
  move ctor
===========================================================*/
input_transform_range (input_transform_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
input_transform_range &
operator = (input_transform_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
input_transform_range &
operator = (input_transform_range const &) = default;

/*===========================================================
  dtor
===========================================================*/
~input_transform_range () = default;

/*===========================================================
  read
===========================================================*/
auto
operator * (
) -> decltype(this->func(*this->rng)) {
return this->func(*this->rng);
}

}; //-----------------------------------input transform range
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif

