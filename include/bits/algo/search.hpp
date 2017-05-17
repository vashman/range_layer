//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_SEARCH_HPP
#define RANGE_LAYER_ALGO_SEARCH_HPP

namespace range_layer {

template <typename Range, typename T, typename Policy>
Range
find (
  Policy
, Range
, T const
);

template <typename Range, typename pred>
Range
find_if (
  execution_policy::sequenced
, Range
, Pred
);

template <typename Range, typename Pred>
Range
find_if_not (
  execution_policy::sequenced
, Range
, Pred
);

} /* range layer */
#endif
#include "search.tcc"
