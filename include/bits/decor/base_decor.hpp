// used as base class to implement un-used functions.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_BASE_DECOR_HPP
#define RANGE_LAYER_BITS_BASE_DECOR_HPP

namespace range_layer {
namespace bits {

template <typename Range, typename Decorator>
class base_decor {

protected:

Range range;

/*===========================================================
  ctor
===========================================================*/
base_decor (
  Range _range
)
: range {_range}
{}

/*===========================================================
  copy ctor
===========================================================*/
base_decor (base_decor const &) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
base_decor & operator = (base_decor const &) = default;

/*===========================================================
  move ctor
===========================================================*/
base_decor (base_decor &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
base_decor & operator = (base_decor &&) = default;

/*===========================================================
  dtor
===========================================================*/
~base_decor() = default;

/*===========================================================
  operator *
===========================================================*/
template <typename U = Range>
auto
operator * (
) -> decltype(*this->range) {
return *this->range;
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
  operator ++
===========================================================*/
template <typename U = Range>
Decorator &
operator ++ (
){
++this->range;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator +=
===========================================================*/
template <typename N>
Decorator &
operator += (
  N _n
){
this->range += _n;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator --
===========================================================*/
template <typename U = Range>
Decorator &
operator -- (
){
--this->range;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator -=
===========================================================*/
template <typename N>
Decorator &
operator -= (
  N _n
){
this->range -= _n;
return static_cast<Decorator&>(*this);
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
  save
===========================================================*/
template <typename U = Range>
Decorator
save (
){
Decorator temp{static_cast<Decorator&>(*this)};
temp.range = this->range.save();
return temp;
}

/*===========================================================
  erase
===========================================================*/
template <typename U = Range>
void
erase (
){
this->range->erase();
}

/*===========================================================
  erase all
===========================================================*/
template <typename U = Range>
void
erase_all (
){
this->range->erase_all();
}

/*===========================================================
  shrink
===========================================================*/
template <typename N>
void
shrink (
  N _n
){
this->range->shrink(_n);
}

/*===========================================================
  insert
===========================================================*/
template <typename... Args>
void
insert (
  Args &&... _args
){
this->range->insert(std::forward<Args...>(_args...));
}

/*===========================================================
  expand
===========================================================*/
template <typename N>
void
expand (
  N _n
){
this->range->expand(_n);
}

public:

/*===========================================================
  disable
===========================================================*/
Range
disable (
) const {
return this->range;
}

};
//base decor-------------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif
