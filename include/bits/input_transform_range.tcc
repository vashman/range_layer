//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_INPUT_TRANSFORM_RANGE_TCC
#define RANGE_LAYER_INPUT_TRANSFORM_RANGE_TCC

namespace range_layer {

template <typename Range, typename Func>
input_transform_range<Func, Range>
make_input_transform_range (
  Range _range
, Func _func
){
return input_transform_range<Func, Range>{_range, _func};
}

template <typename Func, typename Range>
auto
input_transform_range<Func, Range>::operator * (
)
-> decltype (this->func(*this->range))
{
return this->func(*this->range);
}

template <typename Func, typename Range>
template <typename T>
void
input_transform_range<Func, Range>::operator = (
  T const & _var
){
write(this->range, this->func(_var));
}

} /* range layer */
#endif

