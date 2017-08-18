// used as base class to implement un-used functions.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_BASE_DECOR_TCC
#define RANGE_LAYER_BITS_BASE_DECOR_TCC

namespace range_layer {
namespace bits {

/*===========================================================
  ctor
===========================================================*/
template <typename Range, typename Decorator>
base_decor<Range, Decorator>::base_decor (
  Range _range
)
: range {_range}
{}

/*===========================================================
  operator *
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
auto
base_decor<Range, Decorator>::operator * (
) -> decltype(*this->range) {
return *this->range;
}

/*===========================================================
  operator =
===========================================================*/
template <typename Range, typename Decorator>
template <typename T>
void
base_decor<Range, Decorator>::operator = (
  T const & _var
){
this->range = _var;
}

/*===========================================================
  operator ++
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
Decorator &
base_decor<Range, Decorator>::operator ++ (
){
++this->range;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator +=
===========================================================*/
template <typename Range, typename Decorator>
template <typename N>
Decorator &
base_decor<Range, Decorator>::operator += (
  N _n
){
this->range += _n;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator --
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
Decorator &
base_decor<Range, Decorator>::operator -- (
){
--this->range;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator -=
===========================================================*/
template <typename Range, typename Decorator>
template <typename N>
Decorator &
base_decor<Range, Decorator>::operator -= (
  N _n
){
this->range -= _n;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator ==
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
bool
base_decor<Range, Decorator>::operator == (
  sentinel::readable const & _sen
) const {
return this->range == _sen;
}

/*===========================================================
  operator ==
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
bool
base_decor<Range, Decorator>::operator == (
  sentinel::writable const & _sen
) const {
return this->range == _sen;
}

/*===========================================================
  size
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
auto
base_decor<Range, Decorator>::size (
) const -> decltype(this->range.size()) {
return this->range.size();
}

/*===========================================================
  position
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
auto
base_decor<Range, Decorator>::position (
) const -> decltype(this->range.position()) {
return this->range.position();
}

/*===========================================================
  save
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
Decorator
base_decor<Range, Decorator>::save (
){
Decorator temp{static_cast<Decorator&>(*this)};
temp.range = this->range.save();
return temp;
}

/*===========================================================
  erase
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
void
base_decor<Range, Decorator>::erase (
){
this->range->erase();
}

/*===========================================================
  erase all
===========================================================*/
template <typename Range, typename Decorator>
template <typename U = Range>
void
base_decor<Range, Decorator>::erase_all (
){
this->range->erase_all();
}

/*===========================================================
  shrink
===========================================================*/
template <typename Range, typename Decorator>
template <typename N>
void
base_decor<Range, Decorator>::shrink (
  N _n
){
this->range->shrink(_n);
}

/*===========================================================
  insert
===========================================================*/
template <typename Range, typename Decorator>
template <typename... Args>
void
base_decor<Range, Decorator>::insert (
  Args &&... _args
){
this->range->insert(std::forward<Args...>(_args...));
}

/*===========================================================
  expand
===========================================================*/
template <typename Range, typename Decorator>
template <typename N>
void
base_decor<Range, Decorator>::expand (
  N _n
){
this->range->expand(_n);
}

/*===========================================================
  disable
===========================================================*/
template <typename Range, typename Decorator>
Range
base_decor<Range, Decorator>::disable (
) const {
return this->range;
}

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif
