//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SUB_RANGE_HPP
#define RANGE_LAYER_SUB_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  sub_range
===========================================================*/
template <typename Range, typename Sentinel>
class sub_range
: public bits::base_decor
  < Range
  , sub_range<Range, Sentinel>
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
  , sub_range<Range, Sentinel>
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

using write_type
  = typename range_trait::write_type<Range>::type;

private:

Sentinel sen;
  typename std::remove_cv<range_trait::read_type_t<Range>>
::type temp;

/*===========================================================
  is_end
===========================================================*/
bool
is_end (
) const {
return (this->sen == this->temp);
}

public:

/*===========================================================
  ctor
===========================================================*/
sub_range (
  Range _range
, Sentinel _sentinel
)
: base_t {_range}
, sen {_sentinel}
, temp {*_range}
{}

/*===========================================================
  copy assignment operator
===========================================================*/
sub_range (sub_range const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
sub_range & operator = (sub_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
sub_range (sub_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
sub_range & operator = (sub_range &&) = default;

/*===========================================================
  dtor
===========================================================*/
~sub_range() = default;

using base_t::operator =;

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
sub_range &
operator ++ (
){
++this->rng;
this->temp = *this->rng;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
sub_range &
operator -- (
){
--this->range;
this->temp = *this->range;
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::readable const & _sen
) const {
return this->rng == _sen && !this->is_end();
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::writable const & _sen
) const {
return this->rng == _sen && !this->is_end();
}

}; //-----------------------------------------------sub_range
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif

