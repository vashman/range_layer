//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_UNIQUE_POINTER_HPP
#define RANGE_LAYER_BITS_RANGE_UNIQUE_POINTER_HPP

#include "unique_ptr.fwd"
#include "pointer.hpp"

namespace range_layer {

/*===========================================================
  unique_ptr_range
===========================================================*/
template <typename T, typename Deleter>
class range<std::unique_ptr<T, Deleter>>
: public bits::base_from_member<std::unique_ptr<T, Deleter>>
, public range<T * const> {

public:

explicit range(std::unique_ptr<T, Deleter>);

}; //----------------------------------------unique ptr range

/*===========================================================
  const unique_ptr_range
===========================================================*/
template <typename T, typename Deleter>
class range<std::unique_ptr<const T, Deleter>>
: public bits::base_from_member
  <std::unique_ptr<const T, Deleter>>
, public range<const T * const> {

public:

explicit range(std::unique_ptr<const T, Deleter>);

}; //----------------------------------const unique ptr range
} //----------------------------------------------range layer
#endif
#include "unique_ptr.tcc"
