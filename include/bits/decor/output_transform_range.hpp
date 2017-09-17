//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP
#define RANGE_LAYER_OUTPUT_TRANSFORM_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  output_transform_range
===========================================================*/
template <typename Func, typename Range>
class output_transform_range
: public bits::base_decor
  < Range
  , output_transform_range<Func, Range>
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
  , output_transform_range<Func, Range>
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

using read_type = typename range_trait::read_type_t<Range>;
using write_type = typename range_trait::write_type_t<Range>;

/*===========================================================
  ctor
===========================================================*/
output_transform_range (
  Range _range
, Func _func
)
: base_t {_range}
, func (_func)
{}

/*===========================================================
  copy ctor
===========================================================*/
output_transform_range (
  output_transform_range const &
) = default;

/*===========================================================
  move ctor
===========================================================*/
output_transform_range (output_transform_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
output_transform_range &
operator = (output_transform_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
output_transform_range &
operator = (output_transform_range const &) = default;

/*===========================================================
  dtor
===========================================================*/
~output_transform_range () = default;

/*===========================================================
  operator =
===========================================================*/
template <typename T>
void
operator = (
  T const & _var
){
this->rng = this->func(_var);
}

}; //----------------------------------output transform range
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif

