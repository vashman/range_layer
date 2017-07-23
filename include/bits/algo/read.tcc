//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_READ_TCC
#define RANGE_LAYER_ALGO_READ_TCC

#include "asserts.hpp"

namespace range_layer {

template <typename Range, typename Pred>
bool
all_of (
  execution_policy::sequenced
, Range _range
, Pred _pred
){
bits::read_assert<Range>();

  for (; has_readable(_range); advance(_range))
    if (! _pred(read(_range))) return false;
return true;
}

template <typename Range, typename Pred>
bool
none_of (
  execution_policy::sequenced
, Range _range
, Pred _pred
){
bits::read_assert<Range>();

  for (; has_readable(_range); advance(_range))
    if (_pred(read(_range))) return false;
return true;
}

template <typename Range, typename Pred>
bool
any_of (
  execution_policy::sequenced
, Range _range
, Pred _pred
){
bits::read_assert<Range>();

  for (; has_readable(_range); advance(_range))
    if (_pred(read(_range))) return true;
return false;
}

template <typename Range, typename T>
bool
any_is (
  execution_policy::sequenced
, Range _range
, T const _value
){
bits::read_assert<Range>();

  for (; has_readable(_range); advance(_range))
    if (_value == read(_range)) return true;
return false;
}

template <typename Range, typename T>
bool
any_is_not (
  execution_policy::sequenced
, Range _range
, T const _value
){
bits::read_assert<Range>();

  for (; has_readable(_range); advance(_range))
    if (_value != read(_range)) return true;
return false;
}

template <typename Range1, typename Range2>
bool
equal (
  execution_policy::sequenced
, Range1 _range1
, Range2 _range2
){
bits::read_assert<Range1>();
bits::read_assert<Range2>();

  for (
  ; has_readable(_range1) && has_readable(_range2)
  ; advance(_range1, _range2)
  )
    if (read(_range1) != read(_range2)) return false;
return true;
}

template <typename Range, typename Pred>
typename range_trait::size_type<Range>::type
count_if (
  execution_policy::sequenced
, Range _range
, Pred _pred
){
bits::read_assert<Range>();

static_assert (
  range_trait::is_finite<Range>::value
, "Cannot count a infinite range."
);

typename range_trait::size_type<Range>::type n = 0;

  while (has_readable(_range)){
    if (_pred(read(_range))) ++n;
  advance(_range);
  }
return n;
}

template <typename Range, typename T, typename Policy>
typename range_trait::size_type<Range>::type
count (
  Policy _policy
, Range _range
, T _value
){
bits::read_assert<Range>();

return count_if (
  _policy
, _range
, [=](decltype(read(_range)) _var){return _var == _value;}
);
}

template <typename Range, typename Operation>
Range
for_each (
  execution_policy::sequenced
, Range _range
, Operation _op
){
bits::read_assert<Range>();

  while (has_readable(_range)){
  _op(read(_range));
  advance(_range);
  }
return _range;
}

} /* range layer */
#endif

