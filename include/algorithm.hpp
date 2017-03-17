//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGORITHM_HPP
#define RANGE_LAYER_ALGORITHM_HPP

#include "range_traits.hpp"

namespace range_layer {

template <typename Range>
bool
is_readable (
  Range & _range
){
using trait = range_traits<Range>;
static_assert(trait::is_input, "Not a input range.");

return (trait::end != readable_size(_range)); 
}

template <typename Range>
bool
is_writable (
  Range & _range
){
using trait = range_traits<Range>;
static_assert(trait::is_output, "Not a output range.");

return (trait::end != writable_size(_range)); 
}

template <typename Range, typename T>
Range
fill (
  Range _range
, T const & _var
){
using trait = range_traits<Range>;
static_assert(trait::is_output, "Not a output range.");
static_assert (
  trait::is_size_infinate
, "Impossible to fill infinate range."
);

auto n = write_size(_range);
  do {
    while (trait::end != n){
    write(_range, _var);
    --n;
    }
  n = write_size(_range);
  } while (trait::end != n);
return _range;
}

template <typename Range, typename T>
Range
fill (
  Range _range
, T const & _var
, typename range_traits<Range>::difference_type _n
){
using trait = range_traits<Range>;
static_assert(trait::is_output, "Not a output range.");

  for (
    auto n = write_size(_range)
  , trait::end != n
  , n = write_size(_range)
  ){
    while (trait::end != _n){
    write(_range, _var);
    --n;
    }
  }
return _range;
}

template <typename Range>
Range
reset (
  Range & _range
){
using trait = range_traits<Range>;
static_assert (
  trait::is_reversable, "Range is not reversable." );
//static_assert ();

return _range;
}

} /* range layer */
#endif
//#include "bits/algo/read.hpp"
//#include "bits/algo/write.hpp"
//#include "bits/algo/sort.hpp"
//#include "bits/algo/search.hpp"
//#include "bits/algo/hash.hpp"

