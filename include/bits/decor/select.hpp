//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_SELECT_RANGE_HPP
#define RANGE_LAYER_SELECT_RANGE_HPP

#include <tuple>
#include "base_decor.hpp"

namespace range_layer {
namespace bits {

template <typename T, std::size_t I>
struct range_element_type {
using type = typename std::tuple_element<I, T>::type;
};

template <std::size_t I>
struct range_element_type <void, I> {
using type = void;
};

/*===========================================================
  select
===========================================================*/
template <typename Range, std::size_t I>
class select
: public bits::base_decor<Range, select<Range, I>>
{

using base_t = bits::base_decor<Range, select<Range, I>>;

public:

using read_type
  = typename range_element_type
  < typename range_trait::read_type<Range>::type
  , I
  >::type;

using write_type
  = typename range_element_type
  < typename range_trait::write_type<Range>::type
  , I
  >::type;

/*===========================================================
  ctor
===========================================================*/
select (
  Range _range
)
: base_t {_range}
{}

/*===========================================================
  copy ctor
===========================================================*/
select (select const &) = default;

/*===========================================================
  move ctor
===========================================================*/
select (select &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
select & operator = (select &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
select & operator = (select const &) = default;

/*===========================================================
  dtor
===========================================================*/
~select () = default;

/*===========================================================
  operator *
===========================================================*/
auto
operator * (
) -> decltype(std::get<I>(*this->range)) {
using std::get;
return get<I>(*this->range);
}

/*===========================================================
  operator =
===========================================================*/
template <typename T>
void
operator = (
  T const & _var
){
using std::get;
get<I>(this->range) = _var;
}

using base_t::size;
using base_t::position;
using base_t::save;
using base_t::operator ==;
using base_t::erase;
using base_t::erase_all;
using base_t::shrink;
using base_t::insert;
using base_t::expand;

};
//select-----------------------------------------------------

}
//bits-------------------------------------------------------
}
//range layer------------------------------------------------
#endif

