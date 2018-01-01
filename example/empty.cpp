//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/range.hpp"

using range_layer::range;

int main(){

range<> nothing {};
assert(0 == size(nothing));
assert(0 == position(nothing));
nothing = next(std::move(nothing));

return 0;
}
