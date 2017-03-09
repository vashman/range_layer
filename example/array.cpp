#include <iostream>
#include <array>
#include "../include/array_range.hpp"

using std::array;
using range_layer::array_range;

int main (){
array<int, 5> arr {{0, 1, 2, 3, 4}};
array_range<int> arr_rng
  {arr.data(), arr.data()+arr.size()};
std::cout << "\nsize is: " << input_size(arr_rng);

if (!is_readable(arr_rng)) std::cout << "unable to read";

int temp = read(arr_rng);
std::cout << "\ntemp is: " << temp;
temp = read(arr_rng);
std::cout << "\ntemp is: " << temp;

arr_rng = prev (arr_rng);

  if (!is_writable(arr_rng)) std::cout << "unable to write";
write (arr_rng, 9);
temp = read(arr_rng);
std::cout << "\ntemp is: " << temp;

  if (2 > output_size(arr_rng))
  std::cout << "no room to write";
arr_rng = prev(arr_rng, 2);
temp = read(arr_rng);
std::cout << "\ntemp is: " << temp;

return 0;
}