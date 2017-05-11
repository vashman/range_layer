//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <string>
#include <array>
#include "../include/range.hpp"
#include "../include/transform_range.hpp"
#include "../include/iota_range.hpp"
#include "../include/array_range.hpp"

using std::string;
using std::array;
using range_layer::iota_range;
using range_layer::array_range;
using range_layer::input_transform_range;
using range_layer::output_transform_range;

int main (){

auto range = input_transform_range (
  iota_range<char>{'a'}

, [](char _c){
  string temp("\nchar is: ");
  return temp += _c;
  }
);

while (has_readable(range)){
assert((read(range)).compare("a"));
range = next(range);
}

array<char, 5> arr {{'5', 'b' , 'c', 'd', 'e'}};

auto range2 = output_transform_range (
  array_range<char> {arr.data(), arr.data()+arr.size()}
, [](string _str){return _str[0];}
);

string ss {"FGHKI"};
  while (has_writable(range2)){
  write (range2, ss);
  assert(read(range2) == ss[0]);
  range2 = next(range2);
  ss.erase(0,1);
  }

return 0;
}
