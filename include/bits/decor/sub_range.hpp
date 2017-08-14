//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SUB_RANGE_HPP
#define RANGE_LAYER_SUB_RANGE_HPP

namespace range_layer {
namespace bits {

/*===========================================================
  sub_range
===========================================================*/
template <typename Range, typename Sentinel>
class sub_range {

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

private:

Range range;
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

/*===========================================================
  ctor
===========================================================*/
sub_range (
  Range _range
, Sentinel _sentinel
)
: range {_range}
, sen {_sentinel}
, temp {*_range}
{}

sub_range (sub_range const &) = default;
sub_range & operator = (sub_range const &) = default;
sub_range (sub_range &&) = default;
sub_range & operator = (sub_range &&) = default;
~sub_range() = default;

/*===========================================================
  operator *
===========================================================*/
template <typename U = Range>
auto
operator * (
) -> decltype(this->temp) {
return this->temp;
}

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
  save
===========================================================*/
template <typename U = Range>
sub_range
save (
){
return sub_range(*this).range = this->range.save();
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
  operator =
===========================================================*/
template <typename T>
void
operator = (
  T const & _var
){
this->range = _var;
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

/*===========================================================
  size
===========================================================*/
/*template <typename U = Range>
auto
size (
) const -> decltype(this->range.size()) {
return this->range.size();
}*/

/*===========================================================
  position
===========================================================*/
/*template <typename U = Range>
auto
position (
) const -> decltype(this->range.position()) {
return this->range.position();
}*/

/*===========================================================
  disable
===========================================================*/
Range
disable (
) const {
return this->range;
}

};
//sub_range--------------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif

