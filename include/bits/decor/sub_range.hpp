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
: public bits::base_decor<Range, sub_range<Range, Sentinel>>
{

using base_t
  = bits::base_decor<Range, sub_range<Range, Sentinel>>;

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

private:

Sentinel sen;
read_type temp;

/*===========================================================
  is_end
===========================================================*/
bool
is_end (
) const {
return (this->sen == this->temp);
}

public:

using base_t::operator =;
using base_t::operator *;
using base_t::size;
using base_t::position;

/*===========================================================
  ctor
===========================================================*/
sub_range (
  Range _range
, Sentinel _sentinel
)
: bits::base_decor<Range, sub_range<Range, Sentinel>>{_range}
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

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
sub_range &
operator ++ (
){
++this->range;
this->temp = *this->range;
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
  operator +=
===========================================================*/
template <typename N>
sub_range &
operator += (
  N _n
){
  while (_n-- > 0) this->operator ++<Range>();
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
sub_range &
operator -= (
  N _n
){
  while (_n-- > 0) this->operator --<Range>();
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

};
//sub_range--------------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif

