//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_VARIABLE_TCC
#define RANGE_LAYER_BITS_RANGE_VARIABLE_TCC

namespace range_layer {

/*==============================================================================
  ctor range <T *>
==============================================================================*/
template <typename T>
range<T *, range_class::variable>::range (
  T * _ptr
)
: range <const T *, range_class::variable> {_ptr}
, handle {_ptr}
{}

/*==============================================================================
  ctor range <const T *>
==============================================================================*/
template <typename T>
range<const T *, range_class::variable>::range (
  const T * _ptr
)
: const_handle {_ptr}
{
  if (_ptr == nullptr) throw;
}

/*==============================================================================
  has_io
==============================================================================*/
template <typename T>
constexpr bool
range<const T *, range_class::variable>::has_io (
) const {
return (this->const_handle != nullptr);
}

/*==============================================================================
  rw_size
==============================================================================*/
template <typename T>
constexpr std::size_t
range<const T *, range_class::variable>::rw_size (
) const {
return 1;
}

/*==============================================================================
  size
==============================================================================*/
template <typename T>
constexpr std::size_t
range<const T *, range_class::variable>::size (
) const {
return 1;
}

/*==============================================================================
  position
==============================================================================*/
template <typename T>
constexpr std::size_t
range<const T *, range_class::variable>::position (
) const {
return 0;
}

/*==============================================================================
  read
==============================================================================*/
template <typename T>
const T &
range<const T *, range_class::variable>::read (
  const std::size_t //unused
) const {
return *this->const_handle;
}

/*==============================================================================
  write
==============================================================================*/
template <typename T>
void
range<T *, range_class::variable>::write (
  const std::size_t //unused
, T _var
){
*this->handle = _var;
}

/*==============================================================================
  swap
==============================================================================*/
template <typename T>
void
range<T *, range_class::variable>::swap (
  T & _other
){
swap(_other, *this->handle);
}

/*==============================================================================
  drain
==============================================================================*/
template <typename T>
T
range<T *, range_class::variable>::drain (
){
return std::move(*this->handle);
}

/*==============================================================================
  next
==============================================================================*/
template <typename T>
void
range<const T *, range_class::variable>::next (
){
this->const_handle = nullptr;
}

} //-----------------------------------------------------------------range layer
#endif

