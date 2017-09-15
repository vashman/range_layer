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
template <typename Range, typename Func>
class as_range {

Range outer_rng;
range_trait::read_type_t<Range> temp;

using range_type = decltype(range(temp));
range_type inner_rng;
Func func;

public:

as_range (
  Range _range
, Func _func
)
: outer_rng {_range}
, temp {_func(outer_rng)}
, inner_rng {range(temp)}
, func (_func)
{}

as_range (as_range &&) = default;
as_range (as_range const &) = default;
as_range & operator = (as_range const &) = default;
as_range & operator = (as_range &&) = default;
~as_range() = default;

range_trait::read_type_t<range_type>
operator * (
){
return read(this->inner_rng);
}

void
operator = (
  range_trait::write_type_t<range_type> & _var
){
write(this->inner_rng);
}

as_range &
operator ++ (
){
advance(this->inner_rng);
  if (! has_readable(this->inner_rng)){
  advance(this->outer_rng);
    if (has_readable(this->outer_rng)){
    this->temp = read(this->outer_rng);
    this->inner_rng = this->func(this->temp);
    }
  }
return *this;
}

bool
operator == (
  sentinel::readable const & _sen
) const {
return has_readable(this->inner_rng);
}

bool
operator == (
  sentinel::writable const & _sen
) const {
return has_writable(this->inner_rng);
}

}; // as_range-----------------------------------------------

} // bits----------------------------------------------------
} //range layer----------------------------------------------
#endif