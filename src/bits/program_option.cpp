//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_PROGRAM_OPTION_CPP
#define RANGE_LAYER_PROGRAM_OPTION_CPP

namespace range_layer {

bool
program_option::has_arg () const {
using std::get;

return ! get<1>(this->option).empty();
}

char &
program_option::get_option (){
using std::get;

return get<0>(this->option);
}

std::string &
program_option::get_arg (){
using std::get;

return get<1>(this->option);
}

program_option::program_option (
  char _opt
)
: option (_opt, "")
{}

program_option::program_option (
  char _opt
, std::string _str
)
: option (_opt, _str)
{}

} /* range layer */
#endif

