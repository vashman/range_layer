//

#include <cassert>
#include "../include/bits/chrono.hpp"

using range_layer::range;
using range_layer::read;
using range_layer::has_readable;

int main (){

auto rng = range(std::chrono::steady_clock::now());

assert(has_readable(rng));
auto tmp = read(rng);

return 0;
}
