//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DISABLE_INPUT_HPP
#define RANGE_LAYER_DISABLE_INPUT_HPP

#include "base_decor.hpp"
#include "../range/range.hpp"

namespace range_layer {

/*===========================================================
  disable_input
===========================================================*/
struct disable_input {};

/*===========================================================
  disable_input range
===========================================================*/
template <typename Range>
class range<Range, disable_input>
: public bits::base_decor
  < Range
  , disable_input
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

public:

using write_type
  = typename range_trait::write_type<Range>::type;

range (Range);

}; //-------------------------------------disable input range

/*===========================================================
  ctor ::range<Range, disable_input>
===========================================================*/
template <typename Range>
range<Range, disable_input>::range (
  Range _range
)
: range::base_decor {_range}
{}

} //----------------------------------------------range layer
#endif

