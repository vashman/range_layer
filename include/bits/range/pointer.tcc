//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_POINTER_TCC
#define RANGE_LAYER_BITS_RANGE_POINTER_TCC

namespace range_layer {

/*===========================================================
  ctor ::default pointer range
===========================================================*/
template <typename T>
range<T * const>::range (
  T * const _ptr
)
: range<const T * const> {_ptr}
, handle {_ptr}
{}

/*===========================================================
  ctor ::default const pointer range
===========================================================*/
template <typename T>
range<const T * const>::range (
  const T * const _ptr
)
: c_handle {_ptr}
{
  if(_ptr == nullptr) throw;
}

/*===========================================================
  read
===========================================================*/
template <typename T>
typename std::remove_pointer<T>::type const &
range<const T * const>::read (
) const {
return *this->c_handle;
}

/*===========================================================
  write
===========================================================*/
template <typename T>
void
range<T * const>::write (
  typename std::remove_pointer<T>::type const & _var
){
*this->handle = _var;
}

/*===========================================================
  size
===========================================================*/
template <typename T>
constexpr std::size_t
range<const T * const>::size (
) const {
return 1;
}

/*===========================================================
  position
===========================================================*/
template <typename T>
constexpr std::size_t
range<const T * const>::position (
) const {
return 0;
}

/*===========================================================
  advance
===========================================================*/
template <typename T>
void
range<const T * const>::advance (
){
this->is_end = !this->is_end;
}

/*===========================================================
  reverse
===========================================================*/
template <typename T>
void
range<const T * const>::reverse (
){
this->is_end = !this->is_end;
}

/*===========================================================
  has_readable
===========================================================*/
template <typename T>
bool
range<const T * const>::has_readable (
) const {
return this->is_end;
}

/*===========================================================
  has_writable
===========================================================*/
template <typename T>
bool
range<T * const>::has_writable (
) const {
return this->has_readable();
}

} //----------------------------------------------range layer
#endif