Copyright Sundeep S. Sangha 2017.

Distributed under the Boost Software License, Version 1.0.
 (See accompanying file `../LICENSE_1_0.txt` or copy at
       `http://www.boost.org/LICENSE_1_0.txt`)

1 Table of Contents
============================================================

2 Introduction
============================================================

3 Motivation and Scope
============================================================
Reresent the device / container in a more 1 to 1
relationship. ie: the range should not try to adapt the
device / containers access model.

1. constexpr range
2. Move sems, and temporay data
3. concurrancy
4. lazy iteration
5. adapt when needed, pass through when not

4 Impact on the Standard
============================================================
none, pure extenstion. / Addtional headers

5 Desgin Descions
============================================================
No transversal on construction
------------------------------------------------------------
1. When constructing a range type, no obervable transversal
   should take place.
2. The ctor should not eat any part of the range.

X Automatic transversal
X ------------------------------------------------------------
X 1. Reading or Writing to a range should transverse once,
X    when the operation completes.

X Non-const observation
X ------------------------------------------------------------
X 1. Observing the class does not gurantee constness and the
X   object may change.

Non-blocking calls
------------------------------------------------------------
The following calls shall be implemented as non-blocking;
1. `read_size`
2. `write_size`

Allow move / copy / refrence passing
------------------------------------------------------------
1. The range object can be passed around by moving,
   refrencing or coping to the same API.

Allow move / copy / refrence return
------------------------------------------------------------
1. Reading from a range may return a refrence, move or copy.
2. Reading will consistently return the same type using the
   same operation.

No size
------------------------------------------------------------

No position
------------------------------------------------------------

Traits
------------------------------------------------------------
The basic trait type is `static constexpr bool const`.
1. `is_output`: output interface supported.
2. `is_input`: input interface supported.
3. `is_reversable`: reverse transversal and supporting
    interface supported.
4. `is_erasable`: Data can be erased from the range.
5. `static constexpr validation_type validation const`: Type
   used to hold the validation gurantee for the range.
6. `using size_type`: Type used to represent the readable
   / writable size.
7. `static constexpr size_type const zero`: The equivlent of
   zero on none of the above type.

### Data traits
Duplicate traits for both input and output.

1. `is_contiguous`:
2. `is_temporary`:

Interface
------------------------------------------------------------
Below `Range` may refer to value `Range` or a pair of
overloads for `range &&` and `Range&`.

### Basic
1. `Range next (Range);`
2. `Range next (Range, size_type);`
3. `bool is_last (Range);`

### If reverseable
1. `Range prev (Range);`
2. `Range prev (Range, size_type);`
3. `bool is_first (Range);`

### Read
1. `T read (Range);`
2. `size_type read_size (Range);`

### write
1. `void write (Range, T const &);`
2. `size_type write_size (Range);`

### If erasable
1. `void erase (Range);`
2. `void erase (Range, size_type)`

Invalidation
------------------------------------------------------------
All copies of valid ranges are equal and therefore valid.
Invalidation occurs for all ranges when:
1. The pointed to device / contianer is destroyed.
2. The position goes out of bounds.

When the container / device is modified from inseration or
erasure, the above rules still hold.

The following operations cannot invalidate a range;
1. `is_last`
2. `is_first`
3. `read_size`
4. `write_size`

Ranges are catgorized with 3 validation tags; single, synced
, unsynced,These provide gurantess under which operations
the range will be valid / invalid under.

### Single
1. The range will become invalid after any read or write.
   Transvering the range while in bounds, will revalidate
   the range.

2. When the range is transvered, Only the transversed range
   will be valid. All copies will become invalid.

#### Concurrancy

### Synced
1. All ranges for the instance are equal, regular
   invalidation occurs for the group at once.

#### Concurrancy

### Unsynced
1. All ranges instances are seperate and can only themselves
   become invalid through regular invalidation.

#### Concurrancy

6 Technical Specifications
============================================================
