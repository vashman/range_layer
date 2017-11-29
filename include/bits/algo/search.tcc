//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_SEARCH_TCC
#define RANGE_LAYER_ALGO_SEARCH_TCC

namespace range_layer {

/*===========================================================
  find if #4
===========================================================*/
template <typename R, typename P>
bool
find_if (
  execution_policy::sequenced
, const R & _range
, P _pred
){
  while (has_readable(_range)){
    if ( _pred(read(_range)) )
    return true;
  }
return false;
}

/*===========================================================
  find if #3
===========================================================*/
template <typename Range, typename Pred>
Range
find_if (
  execution_policy::parallel
, Range _range
, Pred _pred
){
}

/*===========================================================
  find if #2
===========================================================*/
template <typename Range, typename Pred>
Range
find_if (
  execution_policy::parallel_unsequenced
, Range _range
, Pred _pred
){
}

/*===========================================================
  find if #1
===========================================================*/
template <typename Range, typename Pred>
Range
find_if (
  Range _range
, Pred _pred
){
return find_if
(execution_policy::default_policy{}, _range, _pred);
}

/*===========================================================
  find if not #4
===========================================================*/
template <typename Range, typename Pred>
Range
find_if_not (
  execution_policy::parallel_unsequenced
, Range
, Pred
){

}

/*===========================================================
  find if not #3
===========================================================*/
template <typename Range, typename Pred>
Range
find_if_not (
  execution_policy::parallel
, Range _range
, Pred _pred
){

}

/*===========================================================
  find if not #2
===========================================================*/
template <typename Range, typename Pred>
Range
find_if_not (
  Range _range
, Pred _pred
){

}

/*===========================================================
  find if not #1
===========================================================*/
template <typename R, typename P>
bool
find_if_not (
  execution_policy::sequenced
, const R & _range
, P _pred
){
  while (has_readable(_range))
    if ( !_pred(read(_range)) ) return true;
return false;
}

/*===========================================================
  find #4
===========================================================*/
template <typename Range, typename T>
Range
find (
  execution_policy::sequenced _policy
, Range _range
, T const & _value
){
using type = decltype(read(_range));

return find_if
(_policy, _range, [=](type _v){return _v == _value;});
}

/*===========================================================
  find #3
===========================================================*/
template <typename Range, typename T>
Range
find (
  execution_policy::parallel _policy
, Range _range
, T const & _value
){
using type = decltype(read(_range));

return find_if
(_policy, _range, [=](type _v){return _v == _value;});
}

/*===========================================================
  find #2
===========================================================*/
template <typename Range, typename T>
Range
find (
  execution_policy::parallel_unsequenced _policy
, Range _range
, T const & _value
){
using type = decltype(read(_range));

return find_if
(_policy, _range, [=](type _v){return _v == _value;});
}

/*===========================================================
  find #1
===========================================================*/
template <typename Range, typename T>
Range
find (
  Range _range
, T const & _value
){
using type = decltype(read(_range));

return find_if (
  execution_policy::default_policy{}
, _range
, [=](type _v){return _v == _value;}
);
}

} //range layer----------------------------------------------
#endif
