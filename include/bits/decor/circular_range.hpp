//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_CIRCULAR_RANGE_HPP
#define RANGE_LAYER_CIRCULAR_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  circular range
===========================================================*/
template <typename Range>
class circular_range
: public bits::base_decor
  < Range
  , circular_range<Range>
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
  , circular_range<Range>
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

/*===========================================================
  is_end
===========================================================*/
bool
is_end (
) const {
// Return true if either end is reached.
return (
   ! (this->range == sentinel::writable{})
|| ! (this->range == sentinel::readable{})
);
}

public:

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
circular_range (
  Range _range
)
: base_t {_range}
{}

/*===========================================================
  copy ctor
===========================================================*/
circular_range (circular_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
circular_range (circular_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
circular_range & operator = (circular_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
circular_range &
operator = (
  circular_range const &
) = default;

/*===========================================================
  dtor
===========================================================*/
~circular_range () = default;

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
circular_range &
operator ++ (
){
++this->range;
  if (this->is_end())
  this->range = start_of(this->range);
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
circular_range &
operator -- (
){
--this->range;
  if (this->is_end())
  this->range = end_of(this->range);
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
constexpr bool
operator == (
  sentinel::readable const & _sen
) const {
return true;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
constexpr bool
operator == (
  sentinel::writable const & _sen
) const {
return true;
}

}; //------------------------------------------circular range
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif

