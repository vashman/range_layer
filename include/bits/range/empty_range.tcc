//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_EMPTY_RANGE_TCC
#define RANGE_LAYER_BITS_EMPTY_RANGE_TCC

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
  save
===========================================================*/
constexpr range<>
range<>::save (
) const {
return *this;
}

/*===========================================================
  advance

* Cannot be called since the range is always empty, there can
  have zero effect.
* Throws to catch bugs.
===========================================================*/
void
range<>::advance (
) const {
throw;
}

} //----------------------------------------------range layer
#endif
