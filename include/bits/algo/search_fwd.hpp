//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_ALGO_SEARCH_FWD_HPP
#define RANGE_LAYER_BITS_ALGO_SEARCH_FWD_HPP

namespace range_layer {

/*===========================================================
  find #4

* sequenced
* Returns the range at the position of the found element.
* If the range has temporary input, the element cannot be
  read again.
===========================================================*/
template<typename Range, typename T>
Range
find (
  execution_policy::sequenced
, Range
, T const &
);

/*===========================================================
  find #3

* parallel
===========================================================*/
template<typename Range, typename T>
Range
find (
  execution_policy::parallel
, Range
, T const &
);

/*===========================================================
  find #2

* parallel_unsequenced
===========================================================*/
template<typename Range, typename T>
Range
find (
  execution_policy::parallel_unsequenced
, Range
, T const &
);

/*===========================================================
  find #1

* Use the default policy.
===========================================================*/
template<typename Range, typename T>
Range
find (
  Range
, T const &
);

/*===========================================================
  find if #4

* sequenced
===========================================================*/
template <typename Range, typename Pred>
Range
find_if (
  execution_policy::sequenced
, Range
, Pred
);

/*===========================================================
  find if #3

* parallel
===========================================================*/
template <typename Range, typename Pred>
Range
find_if (
  execution_policy::parallel
, Range
, Pred
);

/*===========================================================
  find if #2

* parallel_unsequenced
===========================================================*/
template <typename Range, typename Pred>
Range
find_if (
  execution_policy::parallel_unsequenced
, Range
, Pred
);

/*===========================================================
  find if #1
===========================================================*/
template <typename Range, typename Pred>
Range
find_if (
  Range
, Pred
);

/*===========================================================
  find if not #4

* parallel_unsequenced
===========================================================*/
template <typename Range, typename Pred>
Range
find_if_not (
  execution_policy::parallel_unsequenced
, Range
, Pred
);

/*===========================================================
  find if not #3

* parallel
===========================================================*/
template <typename Range, typename Pred>
Range
find_if_not (
  execution_policy::parallel
, Range
, Pred
);

/*===========================================================
  find if not #2
===========================================================*/
template <typename Range, typename Pred>
Range
find_if_not (
  Range
, Pred
);

/*===========================================================
  find if not #1

* sequenced
===========================================================*/
template <typename Range, typename Pred>
Range
find_if_not (
  execution_policy::sequenced
, Range
, Pred
);

} // range layer---------------------------------------------
#endif
