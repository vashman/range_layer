Copyright Sundeep S. Sangha 2017.

Distributed under the Boost Software License, Version 1.0.
 (See accompanying file `../LICENSE_1_0.txt` or copy at
       `http://www.boost.org/LICENSE_1_0.txt`)

1 Table of Contents
=============================================================

2 Introduction
=============================================================

3 Motivation and Scope
=============================================================
1. constexpr range
2. Move sems, and temporay data
3. concurrancy
4. lazy iteration
5. adapt when needed, pass through when not

4 Impact on the Standard
=============================================================
none, pure extenstion. / Addtional headers

5 Desgin Descions
=============================================================

# Handle
* A handle is owned by the range.
* A handle maybe shared between mutliple ranges.
* The range should attempt to provide the same set of functions as the handle.
* The hadle used in the range should be accessible.
  * The deference operators should provide access to the range handle.
  
Construction
-------------------------------------------------------------
1. When constructing a range type, no observable transversal
   should take place.
2. A constructed range must be movable.
3. A saved range must have the same postion, size, 
4. A copied range will refer to the same handle as the
   orgianl range.
5. A saved range will not refer to the same handle as the
   orginal range.

Transversal
-------------------------------------------------------------
1. A range must be advanceable.
2. Transversal operations must perform in constant time.
3. Transversal functions perform in best time.

Size
-------------------------------------------------------------
1. A range that has postion must also have a size.
2. The size must be reresented by whole numbers.
3. A range that has a size is finite.
4. The number of readable elements may not be the same as the
   number of writable elements.

Range
-------------------------------------------------------------
1. Represent the device / container in a more 1 to 1
   relationship. ie: the range should not try to adapt the
   device / containers access model.

Element
-------------------------------------------------------------
1. A element is a type that is written too or read from a
   range.
2. Element qualiffiers share extra information about how the
   element works with the range.
3. Element qulaiffiers should not be removed.

Algorithm
-------------------------------------------------------------
1. When returning a range, will return the same type of range
   that was passed to it.
2. [Construction 2][Algorithm 1]
   ∴ Algorithms which return a range cannot take a refrence
   to the same range as a argument.
3. Should provide the same set of capabilits that the range
   handle posesses.
4. Ranges should be movable into algorithms.
5. [Algorithm 2]
   ∴ Algorithms that do not return a range sould take r-value
   or l-value refrences.

Ownership
-------------------------------------------------------------
1. [Construction 2]
   ∴ Algorithms should only transfer ownership of ranges.

Input / Output
-------------------------------------------------------------
1. The number of readable elements may not be the same as the
   number of writable elements.

Seperate input & output postions
-------------------------------------------------------------
The postions of intput and output may be differnt at the
time of construction. Their postions / transversal will be
synced after that point, but either or may go on when the
other ends.

Allow move / copy / refrence return
-------------------------------------------------------------
1. Reading from a range may return a refrence, move or copy.
2. Reading will consistently return the same type using the
   same operation.

Types
-------------------------------------------------------------
1. `range_traits`:
2. `range_size_type`:

Traits
-------------------------------------------------------------
The basic trait type is `static constexpr bool const`.
1. `is_output`: output interface supported.
2. `is_input`: input interface supported.
3. `is_reversable`: reverse transversal and supporting
    interface supported.
4. `is_erasable`: Data can be erased from the range.
5. `static constexpr validation_type validation const`: Type
   used to hold the validation gurantee for the range.

### Data traits
Duplicate traits for both input and output.

1. `is_contiguous`:
2. `is_temporary`:

Interface
-------------------------------------------------------------
Below `Range` may refer to value `Range` or a pair of
overloads for `range &&` and `Range&`.

### Basic
1. `Range next (Range);`
2. `Range next (Range, size_type);`

### Read
1. `T read (Range);`
2. `size_type read_size (Range);`

### write
1. `void write (Range, T const &);`
2. `size_type write_size (Range);`

### If reverseable
1. `Range prev (Range);`
2. `Range prev (Range, size_type);`
3. `S rwrite_size (Range);`
3. `S rread_size (Range);`

### If erasable
1. `void erase (Range);`
2. `void erase (Range, size_type)`

Invalidation
-------------------------------------------------------------
All copies of valid ranges are equal and therefore valid.
Invalidation occurs for all ranges when:
1. The pointed to device / contianer is destroyed.
2. The position goes out of bounds.

When the container / device is modified from inseration or
erasure, the above rules still hold.

The following operations cannot invalidate a range;
1. `rread_size`
2. `rwrite_size`
3. `read_size`
4. `write_size`

### Tempory data
When the input / output has `is_tempeary` set to `true`, the
read / write functions cannot only be called once per
postion in the range.

### Validation gurantees for multiple instances.
Ranges are catgorized with 3 validation tags; single, synced
, unsynced,These provide gurantess under which operations
the range will be valid / invalid under.

1. Single: When the range is transvered, Only the
   transversed range will be valid. All copies will become
   invalid.

2. Synced: All ranges for the instance are equal, regular
   invalidation occurs for the group at once.

3. Unsynced: All ranges instances are seperate and can only
   themselves become invalid through regular invalidation.

6 Technical Specifications
=============================================================
