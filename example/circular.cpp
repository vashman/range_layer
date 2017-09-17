//

#include <iostream>
#include <cassert>
#include "../include/range.hpp"
#include "../include/array.hpp"

using std::array;
using range_layer::range;
using range_layer::circular_range;
using range_layer::read;

int main (){


array<int, 6> arr = {{5,6,7,8,9,0}};

auto rng = circular_range (range(arr));

advance_n (3, rng);
assert(read(rng) == 8);

advance_n (2, rng);
std::cout << read(rng);
/*assert(read(rng) == 8);

advance (rng);
assert(read(rng) == 9);

reverse_n(2, rng);
assert(read(rng) == 7);
*/
return 0;
}