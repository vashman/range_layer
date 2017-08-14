//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SUB_RANGE_N_HPP
#define RANGE_LAYER_SUB_RANGE_N_HPP

namespace range_layer {
namespace bits {

/*===========================================================
  sub_range_n
===========================================================*/
template <typename Range, typename S>
class sub_range_n {

Range range;
S pos;
S count;

bool
is_end () const {
return (this->pos > this->count) || (this->pos == 0);
}

public:

using read_type
  = typename range_trait::read_type<Range>::type;

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
sub_range_n (
  Range _range
, S _count
)
: range {_range}
, pos {1}
, count {_count}
{}

sub_range_n (sub_range_n const &) = default;
sub_range_n & operator = (sub_range_n const &) = default;
sub_range_n (sub_range_n &&) = default;
sub_range_n& operator = (sub_range_n &&) = default;
~sub_range_n() = default;

/*===========================================================
  operator *
===========================================================*/
template <typename U = Range>
auto
operator * () -> decltype(*this->range){
return *this->range;
}

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
  operator save
===========================================================*/
template <typename U = Range>
sub_range_n
save (
){
return sub_range_n(*this).range = this->range.save();;
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
  operator =
===========================================================*/
template <typename T>
void
operator = (T const & _var){
this->range = _var;
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

/*===========================================================
  size
===========================================================*/
template <typename U = Range>
auto
size (
) const -> decltype(this->range.size()) {
return this->range.size();
}

/*===========================================================
  position
===========================================================*/
template <typename U = Range>
auto
position (
) const -> decltype(this->range.position()) {
return this->range.position();
}

/*===========================================================
  disable
===========================================================*/
Range
disable (
) const {
return this->range;
}

};
//sub_range_n------------------------------------------------

} /* bits */ } /* range layer */
#endif
