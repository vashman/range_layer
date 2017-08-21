//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_JOIN_RANGE_HPP
#define RANGE_LAYER_JOIN_RANGE_HPP

namespace range_layer {
namespace bits {

/*===========================================================
  join
===========================================================*/
template <typename LhsRange, typename RhsRange>
class join {

LhsRange lhs_range;
RhsRange rhs_range;

public:

using read_type = typelist_cat_t
<   typename bits
  ::detected_or<void, bits::trait_bits::rtype, LhsRange>
  ::type
,   typename bits
  ::detected_or<void, bits::trait_bits::rtype, RhsRange>
  ::type
>;

using write_type = typelist_cat_t
<   typename bits
  ::detected_or<void, bits::trait_bits::wtype, LhsRange>
  ::type
,   typename bits
  ::detected_or<void, bits::trait_bits::wtype, RhsRange>
  ::type
>;

/*===========================================================
  ctor
===========================================================*/
join (
  LhsRange _lhs_range
, RhsRange _rhs_range
)
: lhs_range {_lhs_range}
, rhs_range {_rhs_range}
{}

join (join const &) = default;
join (join &&) = default;
join & operator = (join &&) = default;
join & operator = (join const &) = default;

/*===========================================================
  dtor
===========================================================*/
~join () = default;

template <typename U = LhsRange>
typename read_type::type
operator * (
){
return std::make_tuple(*this->lhs_range, *this->rhs_range);
}

template <typename U = LhsRange>
join
save (
){
join temp{*this};
temp.lhs_range = this->lhsrange.save();
temp.rhs_range = this->rhsrange.save();
return temp;
}

template <typename U = LhsRange>
join &
operator ++ (
){
++this->lhs_range;
++this->rhs_range;
return *this;
}

template <typename U = LhsRange>
join &
operator -- (){
--this->lhs_range;
--this->rhs_range;
return *this;
}

template <typename T>
void
operator = (
  T const & _var
){
this->lhs_range = std::get<0>(_var);
this->rhs_range = std::get<1>(_var);
}

template <typename N>
join &
operator += (
  N _n
){
this->lhs_range += _n;
this->rhs_range += _n;
return *this;
}

template <typename N>
join &
operator -= (
  N _n
){
this->lhs_range -= _n;
this->rhs_range -= _n;
return *this;
}

bool
operator == (
  sentinel::readable const & _sen
) const {
return
   (this->lhs_range == _sen)
&& (this->rhs_range == _sen);
}

template <typename U = LhsRange>
bool
operator == (
  sentinel::writable const & _sen
) const {
return
   (this->lhs_range == _sen)
&& (this->rhs_range == _sen);
}

/*auto
size (
) const -> decltype(size(this->range)) {
return size(this->range);
}

auto
position (
) const -> decltype(this->range.position()) {
return this->range.position();
}*/

}; /* join range */

} /* bits */

template <typename LhsRange, typename RhsRange>
bits::join<LhsRange, RhsRange>
join (
  LhsRange _lhs_range
, RhsRange _rhs_range
){
return
bits::join<LhsRange, RhsRange> {_lhs_range, _rhs_range};
}

} /* range layer */
#endif

