//

#include <iostream>
#include <cassert>
#include <array>
#include "../include/range.hpp"
#include "../include/array_range.hpp"

using std::array;
using range_layer::array_range;
using range_layer::circular_range;

int main (){


array<int, 6> arr = {{5,6,7,8,9,0}};

auto rng = circular_range (
  array_range<int>(arr.data(), arr.data()+arr.size())
);

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