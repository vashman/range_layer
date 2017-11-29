//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_EMPTY_TCC
#define RANGE_LAYER_BITS_EMPTY_TCC

namespace range_layer {

/*===========================================================
  size
===========================================================*/
constexpr std::size_t
range<>::size (
) const {
return 0;
}

/*===========================================================
  position
===========================================================*/
constexpr std::size_t
range<>::position (
) const {
return 0;
}

/*===========================================================
  next
===========================================================*/
void
range<>::next (
) const {
throw;
}

} //----------------------------------------------range layer
#endif
