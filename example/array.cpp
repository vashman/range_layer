#include <iostream>
#include <array>
#include "../include/array_range.hpp"
#include "../include/algorithm.hpp"

using std::array;
using range_layer::array_range;
using range_layer::range_traits;

int main (){
array<int, 5> arr {{0, 1, 2, 3, 4}};
array_range<int> rng {arr.data(), arr.data()+arr.size()};

auto isize = readable_size(rng);
std::cout << "\nsize is: " << isize;
  if (! range_traits<array_range<int>>::max >= isize){
  std::cout << "unable to read: "
    << range_traits<array_range<int>>::max;
  }

int temp = read(rng); std::cout << "\ntemp is: " << temp;
temp = read(rng); std::cout << "\ntemp is: " << temp;

rng = prev (rng);

  if (!is_writable(rng)) std::cout << "unable to write";
write (rng, 9);
temp = read(rng);
std::cout << "\ntemp is: " << temp;

//  if (2 > output_size(arr_rng)) std::cout << "no room to write";
temp = read(prev(rng, 2));
std::cout << "\ntemp is: " << temp;

return 0;
}
