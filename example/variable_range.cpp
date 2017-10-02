//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/range.hpp"

using range_layer::range;

int main (){
int var {1};
range<int> rng {var};

  if (has_writable(rng)) write(rng, 44);
  if (has_readable(rng)) int i = read(rng);

return 0;
}
