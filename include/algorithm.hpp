//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGORITHM_HPP
#define RANGE_LAYER_ALGORITHM_HPP

namespace range_layer {
namespace execution_policy {

class sequenced {};
class parallel {};
class parallel_unsequenced {};

template <typename Policy> class gpu {};
template <typename Policy> class cpu {};
template <typename Policy> class remote {};
} /* execution policy */ } /* range layer */

#include "range_traits.hpp"
#include "range.hpp"
#include "bits/algo/read.hpp"
#include "bits/algo/write.hpp"
//#include "bits/algo/sort.hpp"
//#include "bits/algo/search.hpp"
//#include "bits/algo/hash.hpp"

#endif

