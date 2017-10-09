#include <iostream>
#include "range.hpp"
#include "vector.hpp"

using namespace std;
using range_layer::range;
using range_layer::make_range;

struct A {

void func (){cout << "test";}

};

int main (){

auto srng = make_range(std::make_shared<vector<int>>());
auto urng = make_range(std::make_unique<vector<int>>());

vector<int> type;
auto rng = make_range(move(type));
auto rng2 = make_range(type);


return 0;
}
