//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DECOR_BUILDER_HPP
#define RANGE_LAYER_BITS_RANGE_DECOR_BUILDER_HPP

namespace range_layer {

/*===========================================================
  builder range
===========================================================*/
template
< typename Range
, typename Decorator
, typename T
, typename... Ts
>
class range<Range, Decorator, T, Ts...> {

range (Range, Decorator);

}; //-------------------------------------------builder range
} //----------------------------------------------range layer
#endif
