//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_DISABLE_OUTPUT_HPP
#define RANGE_LAYER_DISABLE_OUTPUT_HPP

#include "base_decor.hpp"
#include "../range/range.hpp"

namespace range_layer {

/*===========================================================
  disable_output
===========================================================*/
struct disable_output {};

/*===========================================================
  disable_output range
===========================================================*/
template <typename Range>
class range<Range, disable_output>
: public bits::base_decor
  < Range
  , disable_output
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

range (Range);

}; //------------------------------------disable output range

/*===========================================================
  ctor ::range<Range, disable_output>
===========================================================*/
template <typename Range>
range<Range, disable_output>::range (
  Range _range
)
: range::base_decor {_range}
{}

} //----------------------------------------------range layer
#endif

