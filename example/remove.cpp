//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include "../include/iota_range.hpp"
#include "../include/range.hpp"

using range_layer::iota_range;
using range_layer::remove;
using range_layer::remove_if;

struct pred {

pred () = default;
pred (pred const &) = default;
pred (pred &&) = default;
pred & operator = (pred const &) = default;
pred & operator = (pred &&) = default;
~pred() = default;

bool
operator ()(int const _var){
return ((_var % 2) == 0);
}

};

int main (){

auto rng = remove_if (iota_range<int>{2}, pred{});

assert (has_readable(rng));
assert (read(rng) == 3);
advance(rng);

assert (has_readable(rng));
assert (read(rng) == 5);
advance(rng);

assert (has_readable(rng));
assert (read(rng) == 7);

return 0;
}