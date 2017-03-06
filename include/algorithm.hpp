//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGORITHM_HPP
#define RANGE_LAYER_ALGORITHM_HPP

template <typename Range, typename SearchAlgo>
auto
find (
  Range & _range
, SearchAlgo _algo
) -> decltype (read(_range)) {

}

#include "bits/algo/sort.hpp"
#include "bits/algo/search.hpp"
#include "bits/algo/hash.hpp"

#endif

