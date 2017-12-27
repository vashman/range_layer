//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/range.hpp"

using range_layer::make_range;

template <typename Range> Range read_test  (Range);
template <typename Range> Range write_test (Range);

int main (){
int       var  {1};
const int cvar {2};

//range rng         {var};
//range crng        {var};
//range rng_ptr     {&var};
//range crng_ptr    {&var};
auto rng         = make_range(var);
auto crng        = make_range(cvar);
auto rng_ptr     = make_range<int *>(&var);
auto crng_ptr    = make_range<const int *>(&cvar);

rng      = write_test(read_test (std::move(rng)));
//crng     = read_test (std::move(crng));
//rng_ptr  = write_test(read_test (std::move(rng_ptr)));
//crng_ptr = read_test (std::move(crng_ptr));

return 0;
}

template <typename Range>
Range
read_test (
  Range _range
){
  if (read_size(_range) > 0){
  int i = read(_range, 0);
  }
return _range;
}

template <typename Range>
Range
write_test (
  Range _range
){
  if (write_size(_range) > 0) write(_range, 0, 44);
return _range;
}
