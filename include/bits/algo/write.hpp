//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_WRITE_HPP
#define RANGE_LAYER_ALGO_WRITE_HPP

namespace range_layer {

template <typename Range, typename T>
Range
fill (
  execution_policy::sequenced
, Range
, T const &
);

template <typename Range, typename T, typename Count>
Range
fill (
  execution_policy::sequenced
, Range
, T const &
, Count
);

template<typename Range, typename Generator>
Range
generate (
  execution_policy::sequenced
, Range
, Generator
);

} /* range layer */
#include "write.tcc"
#endif
