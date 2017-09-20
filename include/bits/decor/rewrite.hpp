//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_REWRITE_RANGE_HPP
#define RANGE_LAYER_REWRITE_RANGE_HPP

#include "base_decor.hpp"

namespace range_layer {
namespace bits {

/*===========================================================
  rewrite_range
===========================================================*/
template <typename Func, typename Range>
class rewrite_range
: public bits::base_decor
  < Range
  , rewrite_range<Func, Range>
  , range_trait::is_linear<Range>
  , range_trait::is_reversable<Range>
  , range_trait::is_input<Range>
  , range_trait::is_output<Range>
  , range_trait::has_position<Range>
  , range_trait::is_singleton<Range>
  , range_trait::is_finite<Range>
  , range_trait::is_erasable<Range>
  , range_trait::is_all_erasable<Range>
  , range_trait::is_shrinkable<Range>
  , range_trait::is_expandable<Range>
  , range_trait::is_insertable<Range>
  , range_trait::is_subscriptable<Range>
  , range_trait::is_decorator<Range>
  >
{

using base_t = bits::base_decor
  < Range
  , rewrite_range<Func, Range>
  , range_trait::is_linear<Range>
  , range_trait::is_reversable<Range>
  , range_trait::is_input<Range>
  , range_trait::is_output<Range>
  , range_trait::has_position<Range>
  , range_trait::is_singleton<Range>
  , range_trait::is_finite<Range>
  , range_trait::is_erasable<Range>
  , range_trait::is_all_erasable<Range>
  , range_trait::is_shrinkable<Range>
  , range_trait::is_expandable<Range>
  , range_trait::is_insertable<Range>
  , range_trait::is_subscriptable<Range>
  , range_trait::is_decorator<Range>
  >;

Func func;

public:

using write_type = typename range_trait::write_type_t<Range>;

/*===========================================================
  ctor
===========================================================*/
rewrite_range (
  Range _range
, Func _func
)
: base_t {_range}
, func {_func}
{}

/*===========================================================
  copy ctor
===========================================================*/
rewrite_range (
  rewrite_range const &
) = default;

/*===========================================================
  move ctor
===========================================================*/
rewrite_range (rewrite_range &&) = default;

/*===========================================================
  move assignment operator
===========================================================*/
rewrite_range &
operator = (rewrite_range &&) = default;

/*===========================================================
  copy assignment operator
===========================================================*/
rewrite_range &
operator = (rewrite_range const &) = default;

/*===========================================================
  dtor
===========================================================*/
~rewrite_range () = default;

/*===========================================================
  write
===========================================================*/
template <typename T>
void
write (
  T const & _var
){
auto rng = this->func(_var);
  while (range_layer::has_readable(rng)){
  range_layer::write(this->rng, range_layer::read(rng));
  }
}

}; //-------------------------------------------rewrite_range
} //-----------------------------------------------------bits

/*===========================================================
  rewrite
===========================================================*/
template <typename Func>
struct rewrite {

Func func;

template <typename Range>
bits::rewrite_range<Func, Range>
range (
  Range _range
){
return bits::rewrite_range<Func, Range>{_range, this->func};
}

}; //-------------------------------------------------rewrite

template <typename Func>
rewrite<Func>
make_rewrite (
  Func _func
){
return rewrite<Func>{_func};
}

} //----------------------------------------------range layer
#endif

