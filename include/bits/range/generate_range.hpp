//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GENERATE_RANGE_TCC
#define RANGE_LAYER_GENERATE_RANGE_TCC

#include "../../range_traits.hpp"

namespace range_layer {

/*===========================================================
  generate
===========================================================*/
template <typename Generator>
struct generate {

Generator generate;

}; //----------------------------------------------------bits

namespace bits {

/*===========================================================
  generate_range
===========================================================*/
template <typename Gen, typename... Ts>
class generate_range {

Gen gen;

using rtype = decltype(gen());

rtype temp;

public:

/*===========================================================
  ctor
===========================================================*/
generate_range (
  generate<Gen> _gen
)
: gen (_gen.generate)
, temp (gen())
{}

/*===========================================================
  copy ctor
===========================================================*/
generate_range (generate_range const &) = default;

/*===========================================================
  move ctor
===========================================================*/
generate_range (generate_range &&) = default;

/*===========================================================
  dtor
===========================================================*/
~generate_range () = default;

/*===========================================================
  move assignment operator
===========================================================*/
generate_range & operator = (generate_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
generate_range &
operator = (generate_range const &) = default;

/*===========================================================
  read
===========================================================*/
rtype
read (
){
return this->temp;
}

/*===========================================================
  operator ++
===========================================================*/
generate_range<Gen, Ts...> &
operator ++ (){
this->temp = this->gen();
return *this;
}

/*===========================================================
  operator ==
===========================================================*/
bool
operator == (
  sentinel::readable const &
) const;

}; //------------------------------------------generate range

/*===========================================================
  operator ==
===========================================================*/
template <typename Gen, typename... Ts>
bool
generate_range<Gen, Ts...>::operator == (
  sentinel::readable const &
) const {
return true;
}

} //-----------------------------------------------------bits

template <typename Gen>
generate<Gen>
make_generator (
  Gen _gen
);

template <typename Gen>
generate<Gen>
make_generator (
  Gen _gen
){
return generate<Gen>{_gen};
}

/*===========================================================
  range
===========================================================*/
template <typename Generator>
bits::generate_range<Generator>
range (
  generate<Generator> _con
){
return bits::generate_range<Generator>{_con};
}

} //----------------------------------------------range layer
#endif

