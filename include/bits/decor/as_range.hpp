//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_AS_RANGE_TCC
#define RANGE_LAYER_AS_RANGE_TCC

namespace range_layer {
namespace bits {

/*===========================================================
  as_range
===========================================================*/
template <typename Range, typename Func, typename Range2>
class as_range {

Range outer_rng;
range_trait::read_type_t<Range> temp;
Func func;
Range2 inner_rng;

public:

as_range (
  Range _range
, Func _func
)
: outer_rng {_range}
, temp {_func(outer_rng)}
, func (_func)
, inner_rng {this->func(temp)}
{}

as_range (as_range &&) = default;
as_range (as_range const &) = default;
as_range & operator = (as_range const &) = default;
as_range & operator = (as_range &&) = default;
~as_range() = default;

range_trait::read_type_t<Range2>
read (
){
return range_layer::read(this->inner_rng);
}

void
write (
  range_trait::write_type_t<Range2> & _var
){
range_layer::write(this->inner_rng);
}

as_range &
operator ++ (
){
range_layer::advance(this->inner_rng);

  if (! range_layer::has_readable(this->inner_rng)){
  range_layer::advance(this->outer_rng);

    if (range_layer::has_readable(this->outer_rng)){
    this->temp = range_layer::read(this->outer_rng);
    this->inner_rng = this->func(this->temp);
    }
  }
return *this;
}

bool
operator == (
  sentinel::readable const & _sen
) const {
return range_layer::has_readable(this->inner_rng);
}

bool
operator == (
  sentinel::writable const & _sen
) const {
return range_layer::has_writable(this->inner_rng);
}

}; //------------------------------------------------as_range
} //-----------------------------------------------------bits
} //----------------------------------------------range layer
#endif