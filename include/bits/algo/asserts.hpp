//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_ALGO_ASSERTS_HPP
#define RANGE_LAYER_ALGO_ASSERTS_HPP

namespace range_layer {
namespace bits {

template <typename Range>
constexpr int read_assert (){
static_assert (
  range_trait::is_range<Range>::value
, "Not a range."
);

static_assert (
  range_trait::is_input<Range>::value
, "Not a input range."
);
return 0;
}

template <typename Range>
constexpr int write_assert (){
static_assert (
  range_trait::is_range<Range>::value
, "Not a range."
);

static_assert (
  range_trait::is_output<Range>::value
, "Not a output range."
);
return 0;
}

} /* bits */ } /* range layer */
#endif
