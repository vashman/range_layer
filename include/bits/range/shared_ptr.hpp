//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_SHARED_PTR_HPP
#define RANGE_LAYER_BITS_SHARED_PTR_HPP

#include "shared_ptr.fwd"
#include "pointer.hpp"

namespace range_layer {

/*===========================================================
  shared_ptr_range
===========================================================*/
template <typename T>
class range<std::shared_ptr<T>>
: public bits::base_from_member<std::shared_ptr<T>>
, public range<T * const> {

public:

explicit range(std::shared_ptr<T>);

}; //----------------------------------------shared ptr range

/*===========================================================
  const shared_ptr_range
===========================================================*/
template <typename T>
class range<std::shared_ptr<const T>>
: public bits::base_from_member<std::shared_ptr<const T>>
, public range<const T * const> {

public:

explicit range(std::shared_ptr<const T>);

}; //----------------------------------const shared ptr range
} //----------------------------------------------range layer
#endif
#include "shared_ptr.tcc"

