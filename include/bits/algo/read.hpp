//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_READ_HPP
#define RANGE_LAYER_ALGO_READ_HPP

#include "assert.hpp"

namespace range_layer {

template <typename Range, typename Pred>
bool
all_of (
  execution_policy::sequenced
, Range _range
, Pred _pred
);

template <typename Range, typename Pred>
bool
none_of (
  execution_policy::sequenced
, Range _range
, Pred _pred
);

template <typename Range, typename Pred>
bool
any_of (
  execution_policy::sequenced
, Range _range
, Pred _pred
);

} /* range layer */
#endif
#include "read.tcc"

