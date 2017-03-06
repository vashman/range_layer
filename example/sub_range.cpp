#include <iostream>
#include <array>
#include "../include/sub_range.hpp"
#include "../include/array_range.hpp"

using std::array;
using range_layer::array_range;
using range_layer::lower_bound;
using range_layer::upper_bound;

int main (){
array<int, 7> arr {{0, 1, 2, 3, 4, 5, 6}};

upper_bound <lower_bound<array_range<int>>> arr_rng {
lower_bound<array_range<int>> {
  next(array_range<int> {arr.data(), arr.data()+arr.size()})
, 1
, 1
}
, 3
, 0
};

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
