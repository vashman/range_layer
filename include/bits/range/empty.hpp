// Default empty spelization of range class.

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_EMPTY_HPP
#define RANGE_LAYER_BITS_RANGE_EMPTY_HPP

#include "empty.fwd"

namespace range_layer {

/*===========================================================
  empty range
===========================================================*/
template <>
class range<> {

public:

constexpr std::size_t size() const;
constexpr std::size_t position() const;
constexpr range<>     save() const;
void                  advance () const;

}; //---------------------------------------------empty range

} //----------------------------------------------range layer
#endif
#include "empty.tcc"