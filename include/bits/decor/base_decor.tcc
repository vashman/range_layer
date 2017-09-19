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
template
  <typename Range, typename Decorator, typename... Traits>
base_decor<Range, Decorator, Traits...>::base_decor (
  Range _range
)
: rng {_range}
{}

/*===========================================================
  operator *
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template<typename, typename>
auto
base_decor<Range, Decorator, Traits...>::operator * (
) -> decltype(std::declval<Range&>().operator*()) {
return *this->rng;
}

/*===========================================================
  operator =
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename T, typename, typename>
void
base_decor<Range, Decorator, Traits...>::operator = (
  T const & _var
){
this->rng = _var;
}

/*===========================================================
  operator ++
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
Decorator &
base_decor<Range, Decorator, Traits...>::operator ++ (
){
++this->rng;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator +=
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename N, typename, typename>
Decorator &
base_decor<Range, Decorator, Traits...>::operator += (
  N _n
){
this->rng += _n;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator --
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
Decorator &
base_decor<Range, Decorator, Traits...>::operator -- (
){
--this->rng;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator -=
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename N, typename, typename>
Decorator &
base_decor<Range, Decorator, Traits...>::operator -= (
  N _n
){
this->rng -= _n;
return static_cast<Decorator&>(*this);
}

/*===========================================================
  operator ==
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
bool
base_decor<Range, Decorator, Traits...>::operator == (
  sentinel::readable const & _sen
) const {
return this->rng == _sen;
}

/*===========================================================
  operator ==
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
bool
base_decor<Range, Decorator, Traits...>::operator == (
  sentinel::writable const & _sen
) const {
return this->rng == _sen;
}

/*===========================================================
  size
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
typename range_trait::size_type<Range>::type
base_decor<Range, Decorator, Traits...>::size (
) const {
return this->rng.size();
}

/*===========================================================
  position
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
typename range_trait::size_type<Range>::type
base_decor<Range, Decorator, Traits...>::position (
) const {
return this->rng.position();
}

/*===========================================================
  save
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
Decorator
base_decor<Range, Decorator, Traits...>::save (
){
Decorator temp{static_cast<Decorator&>(*this)};
temp.rng = this->rng.save();
return temp;
}

/*===========================================================
  erase
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
void
base_decor<Range, Decorator, Traits...>::erase (
){
this->rng->erase();
}

/*===========================================================
  erase all
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
void
base_decor<Range, Decorator, Traits...>::erase_all (
){
this->rng->erase_all();
}

/*===========================================================
  shrink
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename N, typename, typename>
void
base_decor<Range, Decorator, Traits...>::shrink (
  N _n
){
this->rng->shrink(_n);
}

/*===========================================================
  insert
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename... Args, typename, typename>
void
base_decor<Range, Decorator, Traits...>::insert (
  Args &&... _args
){
this->rng->insert(std::forward<Args...>(_args...));
}

/*===========================================================
  expand
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename N, typename, typename>
void
base_decor<Range, Decorator, Traits...>::expand (
  N _n
){
this->rng->expand(_n);
}

/*===========================================================
  disable
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename, typename>
Range
base_decor<Range, Decorator, Traits...>::disable (
) const {
return this->rng;
}

} // bits----------------------------------------------------
} // range layer---------------------------------------------
#endif
