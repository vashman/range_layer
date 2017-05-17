//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_SEARCH_TCC
#define RANGE_LAYER_ALGO_SEARCH_TCC

namespace range_layer {

template <typename Range, typename Pred>
Range
find_if (
  execution_policy::sequenced
, Range _range
, Pred _pred
){
  while (has_readable(_range))
    if (_pred(read(_range))) break;
return _range;
}

template <typename Range, typename Pred>
Range
find_if_not (
  execution_policy::sequenced
, Range _range
, Pred _pred
){
  while (has_readable(_range))
    if (! _pred(read(_range))) break;
return _range;
}

template <typename Range, typename T, typename Policy>
Range
find (
  Policy _policy
, Range _range
, T const & _value
){
return find_if (
  _policy, _range, [=](auto _v){return _v == _value});
}

} /* range layer */
#endif