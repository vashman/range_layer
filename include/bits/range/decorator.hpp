//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_DECORATOR_HPP
#define RANGE_LAYER_BITS_RANGE_DECORATOR_HPP

#include "range.hpp"

namespace range_layer {

/*===========================================================
  decorator builder range

* A range with more then 2 types means multiple decorators
  are being used.
===========================================================*/
template
< typename Range
, typename Decorator
, typename T
, typename... Ts
>
class range<Range, Decorator, T, Ts...>
: public range<range<Range, Decorator>, T, Ts...>
{};

} //----------------------------------------------range layer
#endif
