#include <iostream>
#include "../include/iota_range.hpp"

using range_layer::iota_range;

int main (int arc, char** argv){
iota_range<int> rng {10};

std::cout << "\nsize is: " << input_size(rng);
if (! is_readable(rng)) std::cout << "unable to read";

int temp = read(rng);
std::cout << "\ntemp is: " << temp;
temp = read(rng);
std::cout << "\ntemp is: " << temp;

rng = next(rng, 100);
temp = read(rng);
std::cout << "\ntemp is: " << temp;

rng = prev (rng);
temp = read(rng);
std::cout << "\ntemp is: " << temp;

return 0;
}
