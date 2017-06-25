//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_BITS_TRANSFORM_RANGE_TCC
#define RANGE_LAYER_BITS_TRANSFORM_RANGE_TCC

namespace range_layer {
namespace bits {

template <typename Func, typename Range>
auto
transform_range<Func, Range>::operator * (
)
-> decltype (this->func(*this->range))
{
return this->func(*this->range);
}

template <typename Func, typename Range>
template <typename T>
void
transform_range<Func, Range>::operator = (
  T const & _var
){
this->range = this->func(_var);
}

} /* bits */ } /* range layer */
#endif

