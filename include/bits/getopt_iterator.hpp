//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef RANGE_LAYER_GETOPT_ITERATOR_HPP
#define RANGE_LAYER_GETOPT_ITERATOR_HPP

#include <unistd.h>
#include <string>

namespace range_layer {

class getopt_iterator {

public:

typedef int difference_type;
typedef program_option value_type;
typedef program_option * pointer;
typedef program_option & reference;
typedef std::input_iterator_tag iterator_category;

private:

int local_optind;
std::string local_opts;
int local_argc;
program_option option;
char *const * local_argv;
int rv;

void
get_opt (){
using std::get;

/* set getopt state to local state. */
int global_optind = optind;
optind = this->local_optind;

this->rv =  getopt (
  this->local_argc
, this->local_argv
, this->local_opts.c_str() );

  if (this->rv != -1){
  // if a '?' character, then an error is found.
  this->option.get_option() = static_cast<char>(rv);
    if (
       '?' != static_cast<char>(rv)
    && ':' != static_cast<char>(rv)
    && optarg != NULL
    ){
    this->option.get_arg() = optarg;
    }
  }
  
/* restore get opt state */
this->local_optind = optind;
optind = global_optind;
}

public:

getopt_iterator (
  char *const * _argv
, std::string _opts
, int _argc
)
: local_optind (optind)
, local_opts (":" + _opts)
, local_argc (_argc)
, option ()
, local_argv (_argv)
, rv (-1)
{
this->get_opt();
}

getopt_iterator (
  int _optind
, char *const * _argv
, std::string _opts
, int _argc
, int _rv
)
: local_optind (_optind)
, local_opts (":" + _opts)
, local_argc (_argc)
, option ()
, local_argv (_argv)
, rv (_rv)
{
this->get_opt();
}

getopt_iterator ()
: local_optind ()
, local_opts ()
, local_argc ()
, option ()
, local_argv (nullptr)
, rv (-1)
{}

getopt_iterator (getopt_iterator const &) = default;
getopt_iterator & operator = (getopt_iterator const &) = default;
getopt_iterator (getopt_iterator &&) = default;
getopt_iterator & operator =(getopt_iterator &&) = default;

getopt_iterator &
operator ++ (){
this->get_opt();
return *this;
}

getopt_iterator
operator ++ (int){
auto temp (*this);
this->get_opt();
return temp;
}

program_option &
operator * (){
return this->option;
}

program_option *
operator -> (){
return &this->option;
}

bool
operator == (
  getopt_iterator const & _rhs
) const {
return ((this->rv == -1) && (_rhs.rv == -1));
}

}; /* getopt iterator */

bool
operator != (
  getopt_iterator const & _lhs
, getopt_iterator const & _rhs
);

bool
operator != (
  getopt_iterator const & _lhs
, getopt_iterator const & _rhs
){
return !(_lhs == _rhs);
}

} /* range layer */
#endif

