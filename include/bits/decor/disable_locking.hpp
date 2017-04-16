//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

template <typename Range>
class disable_locking {
Range range;
};

template <typename Range>
auto
read (
  disable_locking<Range> & _range
)
-> decltype (read(_range.range))
{
return read(_range.range);
}

template <typename Range>
auto
read (
  disable_locking<Range> && _range
)
-> decltype (read(std::move(_range.range)))
{
return read(std::move(_range.range));
}

template <typename Range>
auto
read_count (
  disable_locking<Range> & _range
)
-> decltype (read_count(_range.range))
{
return read_count(_range.range);
}

template <typename Range>
auto
read_count (
  disable_locking<Range> && _range
)
-> decltype (read_count(std::move(_range.range)))
{
return read_count(std::move(_range.range));
}

template <typename Range, typename T>
void
write (
  Range && _range
, T const & _var
){
return write(std::forward<Range>(_range), _var);
}

template <typename Range>
auto
write_count (
  Range && _range
)
-> decltype (write_count(std::forward<Range>(_range)))
{
return write_count(std::forward<Range>(_range));
}

template <typename Range>
disable_locking<Range>
next (
  disable_locking<Range> &
)