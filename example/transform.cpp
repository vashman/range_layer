//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cassert>
#include <string>
#include "../include/range.hpp"
#include "../include/array.hpp"

using std::string;
using std::array;
using range_layer::iota;
using range_layer::range;
using range_layer::xrange;
using range_layer::make_transform_read;
using range_layer::make_transform_write;
using range_layer::has_readable;
using range_layer::has_writable;
using range_layer::read;
using range_layer::write;
using range_layer::next;

char
func1 (string _str);

string
func2 (char _c);

char
func1 (string _str){return _str[0];}

string
func2 (char _c){
string temp("\nchar is: ");
return temp += _c;
}

int main (){

auto rng = xrange (
  range(iota<char>{'a'})
, make_transform_read(func2)
);

while (has_readable(rng)){
assert((read(rng)).compare("a"));
rng = next(rng);
}

array<char, 5> arr {{'5', 'b' , 'c', 'd', 'e'}};
auto rng2 = xrange (
  range(arr)
, make_transform_write(func1)
);

string ss {"FGHKI"};
  while (has_writable(rng2)){
  write (rng2, ss);
  assert(read(rng2) == ss[0]);
  rng2 = next(rng2);
  ss.erase(0,1);
  }

return 0;
}
