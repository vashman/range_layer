//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BACK_INSERT_HPP
#define RANGE_LAYER_BACK_INSERT_HPP

namespace range_layer {
namespace bits {

/*===========================================================
  back insert
===========================================================*/
template <typename Range>
class back_insert {

Range range;

public:

using write_type
  = typename range_trait::write_type<Range>::type;

/*===========================================================
  ctor
===========================================================*/
back_insert (
  Range _range
)
: range {end_of_output(_range)}
{
expand(this->range, 1);
}

/*===========================================================
  copy ctor
===========================================================*/
back_insert (back_insert const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
back_insert & operator = (back_insert const &) = default;

/*===========================================================
  move ctor
===========================================================*/
back_insert (back_insert &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
back_insert & operator = (back_insert &&) = default;

/*===========================================================
  dtor
===========================================================*/
~back_insert() = default;

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
back_insert &
operator ++ (
){
expand(this->range, 1);
++this->range;
return *this;
}

/*===========================================================
  save
===========================================================*/
template <typename U = Range>
back_insert
save (
){
return back_insert(*this).range = this->range.save();
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
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::readable const & _sen
) const {
return this->range == _sen;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename U = Range>
bool
operator == (
  sentinel::writable const & _sen
) const {
return this->range == _sen;
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
//back insert------------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif

