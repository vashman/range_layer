//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_VARIABLE_TCC
#define RANGE_LAYER_BITS_RANGE_VARIABLE_TCC

namespace range_layer {
namespace range_class {

/*==============================================================================
  ctor range
==============================================================================*/
template <typename H, typename S>
variable<H, S>::variable (
  S _handle
)
: variable<const H, S> {_handle}
{}

/*==============================================================================
  ctor const varaible
==============================================================================*/
template <typename H, typename S>
variable<const H, S>::variable (
  S _handle
)
: handle {_handle}
, last   {false}
{}

/*==============================================================================
  has_io
==============================================================================*/
template <typename H, typename S>
constexpr bool
variable<const H, S>::has_io (
) const {
return this->last;
}

/*==============================================================================
  rw_size
==============================================================================*/
template <typename H, typename S>
constexpr std::size_t
variable<const H, S>::rw_size (
) const {
return 1;
}

/*==============================================================================
  size
==============================================================================*/
template <typename H, typename S>
constexpr std::size_t
variable<const H, S>::size (
) const {
return 1;
}

/*==============================================================================
  position
==============================================================================*/
template <typename H, typename S>
constexpr std::size_t
variable<const H, S>::position (
) const {
return 0;
}

/*==============================================================================
  read
==============================================================================*/
template <typename H, typename S>
const H &
variable<const H, S>::read (
  const std::size_t //unused
) const {
return bits::to_ref(this->handle);
}

/*==============================================================================
  write
==============================================================================*/
template <typename H, typename S>
void
variable<H, S>::write (
  const std::size_t //unused
, H _var
){
bits::to_ref(this->handle) = _var;
}

/*==============================================================================
  swap
==============================================================================*/
template <typename H, typename S>
void
variable<H, S>::swap (
  H & _other
){
swap(_other, bits::to_ref(this->handle));
}

/*==============================================================================
  drain
==============================================================================*/
template <typename H, typename S>
H
variable<H, S>::drain (
){
return std::move(bits::to_ref(this->handle));
}

/*==============================================================================
  next
==============================================================================*/
template <typename H, typename S>
void
variable<const H, S>::next (
){
this->last = true;
}

} //-----------------------------------------------------------------range class
} //-----------------------------------------------------------------range layer
#endif

