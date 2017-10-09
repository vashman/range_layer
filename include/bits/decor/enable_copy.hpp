// Add a copy ctor and assignment operator.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ENABLE_COPY_HPP
#define RANGE_LAYER_ENABLE_COPY_HPP

#inlcude <memory>

namespace range_layer {
namespace bits {

template <typename Range>
struct enable_copy {

std::shared_ptr<Range> rng_ptr;

/*===========================================================
  ctor
===========================================================*/
enable_copy (
  Range &&
);

/*===========================================================
  copy ctor
===========================================================*/
enable_copy (
  enable_copy const &
) = default

/*===========================================================
  move ctor
===========================================================*/
enable_copy (
  enable_copy &&
) = default

/*===========================================================
  move assignment operator
===========================================================*/
enable_copy & operator = (enable_copy &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
enable_copy & operator = (enable_copy const &) = default;

/*===========================================================
  dtor
===========================================================*/
~enable_copy() = default;

/*===========================================================
  read
===========================================================*/
template
< typename R = Range
, typename = std::enable_if
  <range_trait::is_input<R>::value, void>
>
delete(auto)
read (
){
return range_layer::read(*this->rng_ptr);
}

/*===========================================================
  operator ++
===========================================================*/
enable_copy<Range> &
operator ++ (
){
range_layer::advance(*this->rng_ptr);
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template
< typename R = Range
, typename = std::enable_if
  <range_trait::is_reversable<R>::value, void>::type
>
enable_copy<Range> &
operator -- (
){
range_layer::reverse(*this->rng_ptr);
return *this;
}

/*===========================================================
  operator +=
===========================================================*/
template
< typename N
, typename R = Range
, typename = std::enable_if
  <! range_trait::is_linear<R>::value, void>::type
>
enable_copy<Range> &
operator += (
  N const _n
){
range_layer::advance_n(_n, *this->rng_ptr);
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template
< typename N
, typename R = Range
, typename = std::enable_if
  <! range_trait::is_linear<R>::value 
  && range_trait::is_reversable<R>::value, void>::type
>
enable_copy<Range> &
operator -= (
  N const _n
){
range_layer::reverse_n(_n, *this->rng_ptr);
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
template
< typename R = Range
, typename = std::enable_if
  <range_trait::is_input<R>::value, void>::type
>
bool
operator == (
  sentinel::readable const & _sen
) const {
return *this->rng_ptr == _sen;
}

/*===========================================================
  size
===========================================================*/
template
< typename R = Range
, typename = std::enable_if
  <range_trait::is_finite<R>::value, void>::type
>
typename range_trait::size_type<R>::type
size (
) const {
return this->rng_ptr->size();
}

/*===========================================================
  position
===========================================================*/
template
< typename R = Range
, typename = std::enable_if
  <range_trait::has_position<R>::value, void>::type
>
typename range_trait::size_type<R>::type
position (
) const {
return this->rng_ptr->position();
}

/*===========================================================
  save
===========================================================*/
template
< typename R = Range
, typename = std::enable_if
  <! range_trait::is_singleton<R>::value, void>::type
>
enable_copy<Range>
save (
) const {
return enable_copy<Range> {this->rng_ptr->save()};
}

/*===========================================================
  disable
===========================================================*/
Range
disable (
){
return this->rng_ptr.release();
}

}; //---------------------------------------------enable copy
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif