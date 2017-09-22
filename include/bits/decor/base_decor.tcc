// used as base class to implement un-used functions.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_BASE_DECOR_TCC
#define RANGE_LAYER_BITS_BASE_DECOR_TCC

#include "../range.hpp"

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
  read
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template<typename, typename>
auto
base_decor<Range, Decorator, Traits...>::read (
){
return range_layer::read(this->rng);
}

/*===========================================================
  write
===========================================================*/
template
  <typename Range, typename Decorator, typename... Traits>
template <typename T, typename, typename>
void
base_decor<Range, Decorator, Traits...>::write (
  T const & _var
){
range_layer::write(this->rng, _var);
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
range_layer::advance(this->rng);
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
range_layer::advance_n(this->rng, _n);
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
range_layer::reverse(this->rng);
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
range_layer::reverse_n(this->rng, _n);
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
return range_layer::size(this->rng);
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
return range_layer::position(this->rng);
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
range_layer::erase (this->rng);
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
range_layer::erase_all(this->rng);
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
range_layer::shrink(this->rng, _n);
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
  range_layer
::insert(this->rng, std::forward<Args...>(_args...));
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
range_layer::expand(this->rng, _n);
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

} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif
