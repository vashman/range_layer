//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_RANGE_GENERATE_HPP
#define RANGE_LAYER_BITS_RANGE_GENERATE_HPP

#include "../../range_traits.hpp"
#include "generate.fwd"

namespace range_layer {

/*===========================================================
  generator
===========================================================*/
template <typename Generator>
struct generator {

Generator gen;

auto operator ()();

}; //-----------------------------------------------generator

/*===========================================================
  range
===========================================================*/
template <typename Generator>
class range<generator<Generator> * const>
: public range<const generator<Generator> * const>
{

public:

explicit range (generator<Generator> * const);
void     advance ();

private:

generator<Generator> * const handle;

}; //-----------------------------------------generator range

/*===========================================================
  const range
===========================================================*/
template <typename Generator>
class range<const generator<Generator> * const> {

using read_type = decltype(std::declval<Generator&>()());

public:

explicit          range (const generator<Generator> * const);
read_type const & read () const;
bool              has_readable () const;

protected:

const generator<Generator> * const const_handle;
read_type temp;

}; //-----------------------------------const generator range
} //----------------------------------------------range layer
#endif
#include "generate.tcc"

