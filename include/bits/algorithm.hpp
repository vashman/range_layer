//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ALGORITHM_HPP
#define RANGE_LAYER_BITS_ALGORITHM_HPP

namespace range_layer {
namespace execution_policy {

class sequenced {};
class parallel {};
class parallel_unsequenced {};

template <typename Policy> class gpu {};
template <typename Policy> class cpu {};
template <typename Policy> class remote {};

using default_policy = sequenced;
} //-----------------------------------------execution policy
} //----------------------------------------------range layer

#include "algo/read.hpp"
#include "algo/write.hpp"
//#include "algo/sort.hpp"
#include "algo/search.hpp"
//#include "algo/hash.hpp"

#endif

