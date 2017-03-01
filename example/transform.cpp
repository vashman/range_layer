#include <string>
#include <array>
#include <iostream>
#include "../include/array_range.hpp"
#include "../include/transform_range.hpp"
#include "../include/iota_range.hpp"

using std::string;
using std::cout;
using std::array;
using range_layer::iota_range;
using range_layer::array_range;
using range_layer::input_transform_range;
using range_layer::output_transform_range;

template <typename Range, typename Func>
input_transform_range<Range, Func>
make_itransform_range (
  Range _range
, Func _func
){
return input_transform_range<Range, Func>{_range, _func};
}

template <typename Range, typename Func>
output_transform_range<Range, Func>
make_otransform_range (
  Range _range
, Func _func
){
return output_transform_range<Range, Func>{_range, _func};
}

int main (){

auto range = make_itransform_range (
  iota_range<char>{'a'}
, [](char _c){
  string temp("\nchar is: ");
  return temp += _c;
  }
);

while (is_readable(range)){
cout << read(range);
}

array<char, 5> arr {{'r', 't' , '1', '2', 'k'}};

auto range2 = make_otransform_range (
  array_range<char> {arr.data(), arr.data()+arr.size()}
, [](string _str){return _str[0];}
);

string ss {"rt17k"};
while (is_writable(range2)){
write (range2, ss);
ss.erase(0,1);
}

for (auto ch : arr){
std::cout << ch;
}

return 0;
}
