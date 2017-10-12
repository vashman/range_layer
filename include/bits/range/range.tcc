//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_RANGE_TCC
#define RANGE_LAYER_BITS_RANGE_RANGE_TCC

#include <memory>

namespace range_layer {

/*===========================================================
  make_range

* Does not deduce pointer ranges correctly.
===========================================================*/
template <typename... Ts>
range<Ts...>
make_range (
  Ts... _args
){
return range<Ts...>{std::move(_args)...};
}

} //----------------------------------------------range layer
#endif