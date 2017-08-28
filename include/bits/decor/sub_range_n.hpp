//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SUB_RANGE_N_HPP
#define RANGE_LAYER_SUB_RANGE_N_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  sub_range_n
===========================================================*/
template <typename Range>
class sub_range_n
: public bits::base_decor
  < Range
  , sub_range_n<Range>
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
  , sub_range_n<Range>
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

typename range_trait::size_type<Range>::type pos;
typename range_trait::size_type<Range>::type count;

bool
is_end (
) const {
return (this->pos > this->count) || (this->pos == 0);
}

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

using base_t::operator =;

/*===========================================================
  size
===========================================================*/
typename range_trait::size_type<Range>::type
size (
) const {
return this->count;
}

/*===========================================================
  ctor
===========================================================*/
sub_range_n (
  Range _range
, typename range_trait::size_type<Range>::type _count
)
: base_t {_range}
, pos {1}
, count {_count}
{}

/*===========================================================
  copy ctor
===========================================================*/
sub_range_n (sub_range_n const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
sub_range_n & operator = (sub_range_n const &) = default;

/*===========================================================
  move ctor
===========================================================*/
sub_range_n (sub_range_n &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
sub_range_n & operator = (sub_range_n &&) = default;

/*===========================================================
  dtor
===========================================================*/
~sub_range_n() = default;

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
sub_range_n &
operator ++ (){
++this->pos;
++this->range;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
sub_range_n &
operator -- (){
--this->pos;
--this->range;
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
sub_range_n &
operator += (
  N _n
){
this->pos += _n;
this->range += _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
sub_range_n &
operator -= (
  N _n
){
this->pos -= _n;
this->range -= _n;
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const & _sen
) const {
return this->range == _sen && !this->is_end();
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::writable const & _sen
) const {
return this->range == _sen && !this->is_end();
}

}; //sub_range_n---------------------------------------------

} //bits-----------------------------------------------------
} //range layer----------------------------------------------
#endif

