//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SPEC_VECTOR_HPP
#define RANGE_LAYER_SPEC_VECTOR_HPP

#include <vector>
#include "bits/range/vector.hpp"

namespace range_layer {

template <typename T, typename Alloc>
class range<std::vector<T, Alloc> * const>
: public range<>
{};

} //----------------------------------------------range layer
#endif
