//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_GENERATE_TCC
#define RANGE_LAYER_BITS_RANGE_GENERATE_TCC

namespace range_layer {

template <typename Generator>
auto
generator<Generator>::operator ()(
){
return this->gen();
}

/*===========================================================
  make_generator
===========================================================*/
template <typename Gen>
generator<Gen>
make_generator (
  Gen _gen
){
return generator<Gen>{_gen};
}

/*===========================================================
  ctor
===========================================================*/
template <typename Generator>
range<generator<Generator> * const>::range (
  generator<Generator> * const _ptr
) : range<const generator<Generator> * const> {_ptr}
, handle {_ptr}
{
this->temp = this->handle->gen();
}

/*===========================================================
  ctor
===========================================================*/
template <typename Generator>
range<const generator<Generator> * const>::range (
  const generator<Generator> * const _ptr
) : const_handle {_ptr}
, temp {}
{}

/*===========================================================
  read
===========================================================*/
template <typename Generator>
  typename range<const generator<Generator> * const>
::read_type const & 
range<const generator<Generator> * const>::read (
) const {
return this->temp;
}

/*===========================================================
  has_readable
===========================================================*/
template <typename Generator>
bool
range<const generator<Generator> * const>::has_readable (
) const {
return true;
}

/*===========================================================
  advance
===========================================================*/
template <typename Generator>
void
range<generator<Generator> * const>::advance (
){
this->temp = this->handle->gen();
}

} //----------------------------------------------range layer
#endif
