//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <memory>
#include <cassert>
#include "../include/range.hpp"

using range_layer::range;
using range_layer::make_range;
using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using std::shared_ptr;

template <typename Range>
void
read_test (
  Range &&
);

template <typename Range>
void
write_test (
  Range &&
);

int main (){
int       var {1};
const int cvar{2};

//range empty_range {};
//range rng         {var};
//range crng        {var};
//range rng_ptr     {&var};
//range crng_ptr    {&var};
//range unqiue_rng  {make_unique<int>(var)};
//range cunqiue_rng {make_unique<const int>(cvar)};
//range shared_rng  {make_shared<int>(var)};
//range cshared_rng {make_shared<const int>(cvar)};
auto empty_range = make_range();
auto rng         = make_range(var);
auto crng        = make_range(cvar);
auto rng_ptr     = make_range<int * const>(&var);
auto crng_ptr    = make_range<const int * const>(&cvar);
auto unqiue_rng  = make_range(make_unique<int>(var));
auto cunqiue_rng = make_range(make_unique<const int>(cvar));
auto shared_rng  = make_range(make_shared<int>(var));
auto cshared_rng = make_range(make_shared<const int>(cvar));

read_test (rng);
write_test(rng);
read_test (crng);

read_test (rng_ptr);
write_test(rng_ptr);
read_test (crng_ptr);

read_test (unqiue_rng);
write_test(unqiue_rng);
read_test (cunqiue_rng);

read_test (shared_rng);
write_test(shared_rng);
read_test (cshared_rng);

return 0;
}

template <typename Range>
void
read_test (
  Range && _range
){
  if (has_readable(_range)){
  int i = read(_range);
  }
}

template <typename Range>
void
write_test (
  Range && _range
){
bool written = false;

  if (has_writable(_range)) write(_range, 44);
}
