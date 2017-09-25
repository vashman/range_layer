//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_READ_TCC
#define RANGE_LAYER_ALGO_READ_TCC

#include "asserts.hpp"

namespace range_layer {

/*===========================================================
  all_of
===========================================================*/
template <typename Range, typename Pred>
bool
all_of (
  execution_policy::sequenced
, Range && _range
, Pred _pred
){
bits::read_assert<Range>();

  while (range_layer::has_readable(_range)){
    if (! _pred(range_layer::read(_range)))
    return false;
  range_layer::advance(_range);
  }
return true;
}

/*===========================================================
  none_of
===========================================================*/
template <typename Range, typename Pred>
bool
none_of (
  execution_policy::sequenced
, Range && _range
, Pred _pred
){
bits::read_assert<Range>();

  while (has_readable(_range)){
    if (_pred(range_layer::read(_range)))
    return false;
  range_layer::advance(_range);
  }
return true;
}

/*===========================================================
  any_of
===========================================================*/
template <typename Range, typename Pred>
bool
any_of (
  execution_policy::sequenced
, Range && _range
, Pred _pred
){
bits::read_assert<Range>();

  while (range_layer::has_readable(_range)){
    if (_pred(range_layer::read(_range)))
    return true;
  range_layer::advance(_range);
  }
return false;
}

/*===========================================================
  any_is
===========================================================*/
template <typename Range, typename T>
bool
any_is (
  execution_policy::sequenced
, Range && _range
, T const _value
){
bits::read_assert<Range>();

  while (range_layer::has_readable(_range)){
    if (_value == range_layer::read(_range))
    return true;
  range_layer::advance(_range);
  }
return false;
}

/*===========================================================
  any_is_not
===========================================================*/
template <typename Range, typename T>
bool
any_is_not (
  execution_policy::sequenced
, Range && _range
, T const _value
){
bits::read_assert<Range>();

  while (range_layer::has_readable(_range)){
    if (_value != range_layer::read(_range))
    return true;
  range_layer::advance(_range);
  }
return false;
}

/*===========================================================
  equal
===========================================================*/
template <typename Range1, typename Range2>
bool
equal (
  execution_policy::sequenced
, Range1 && _range1
, Range2 && _range2
){
bits::read_assert<Range1>();
bits::read_assert<Range2>();

  while (
     range_layer::has_readable(_range1)
  && range_layer::has_readable(_range2)
  ){
    if (
       range_layer::read(_range1)
    != range_layer::read(_range2)
    ){
    return false;
    }
  range_layer::advance(_range1, _range2);
  }
return true;
}

/*===========================================================
  count_if
===========================================================*/
template <typename Range, typename Pred>
typename range_trait::size_type<Range>::type
count_if (
  execution_policy::sequenced
, Range && _range
, Pred _pred
){
bits::read_assert<Range>();
bits::finite_assert<Range>();

typename range_trait::size_type<Range>::type n = 0;

  while (range_layer::has_readable(_range)){
    if (_pred(range_layer::read(_range)))
    ++n;
  range_layer::advance(_range);
  }
return n;
}

/*===========================================================
  count
===========================================================*/
template <typename Range, typename T, typename Policy>
typename range_trait::size_type<Range>::type
count (
  Policy _policy
, Range && _range
, T _value
){
bits::read_assert<Range>();

return count_if (
  _policy
, _range
, [=](auto const & _var){return _var == _value;}
);
}

/*===========================================================
  count_if_until
===========================================================*/
template <typename Range, typename Pred>
typename range_trait::size_type<Range>::type
count_if_until (
  execution_policy::sequenced
, Range && _range
, Pred _pred
){
bits::read_assert<Range>();
bits::finite_assert<Range>();

typename range_trait::size_type<Range>::type n = 0;

  while (range_layer::has_readable(_range)){
    if (_pred(read(_range)))
    ++n;

    else
    break;
  range_layer::advance(_range);
  }
return n;
}

/*===========================================================
  count_until
===========================================================*/
template <typename Range, typename T, typename Policy>
typename range_trait::size_type<Range>::type
count_until (
  Policy _policy
, Range && _range
, T _value
){
bits::read_assert<Range>();

return count_if_until (
  _policy
, _range
, [=](auto const & _var){return _var == _value;}
);
}

/*===========================================================
  for_each
===========================================================*/
template <typename Range, typename Operation>
void
for_each (
  execution_policy::sequenced
, Range _range
, Operation _op
){
bits::range_assert<Range>();
bits::read_assert<Range>();

  while (range_layer::has_readable(_range)){
  _op(range_layer::read(_range));
  range_layer::advance(_range);
  }
}

} //----------------------------------------------range layer
#endif

