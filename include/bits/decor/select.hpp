//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SELECT_RANGE_HPP
#define RANGE_LAYER_SELECT_RANGE_HPP

#include <tuple>

namespace range_layer {
namespace bits {

template <typename T, std::size_t I>
struct range_element_type {
using type = typename std::tuple_element<I, T>::type;
};

template <std::size_t I>
struct range_element_type <void, I> {
using type = void;
};

/*===========================================================
  select
===========================================================*/
template <typename Range, std::size_t I>
class select {

Range range;

public:

using read_type
  = typename range_element_type
  < typename range_trait::read_type<Range>::type
  , I
  >::type;

using write_type
  = typename range_element_type
  < typename range_trait::write_type<Range>::type
  , I
  >::type;

/*===========================================================
  ctor
===========================================================*/
select (
  Range _range
)
: range {_range}
{}

select (select const &) = default;
select (select &&) = default;
select & operator = (select &&) = default;
select & operator = (select const &) = default;
~select () = default;

/*===========================================================
  operator *
===========================================================*/
auto
operator * (
) -> decltype(std::get<I>(*this->range)) {
using std::get;
return get<I>(*this->range);
}

/*===========================================================
  save
===========================================================*/
template <typename U = Range>
select &
save (
){
return select(*this).range = this->range.save();
}

/*===========================================================
  operator ++
===========================================================*/
template <typename U = Range>
select &
operator ++ (){
++this->range;
return *this;
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
select &
operator -- (){
--this->range;
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
using std::get;
get<I>(this->range) = _var;
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
select &
operator += (
  N _n
){
this->range += _n;
return *this;
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
select &
operator -= (
  N _n
){
this->range -= _n;
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
//select-----------------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif

