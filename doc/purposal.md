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

4 Impact on the Standard
============================================================
none, pure extenstion. / Addtional headers

5 Desgin Descions
============================================================
No transversal on construction
------------------------------------------------------------
1. When constructing a range type, no obervable transversal
   should take place.

Automatic transversal
------------------------------------------------------------
1. Reading or Writing to a range should transvese once,
   when the operation completes.

Non-const observation
------------------------------------------------------------
1. Observing the class does not gurantee constness and the
   object may change.
2. An exception is that observing the postion does gurantee
   constness.

Allow move / copy / refrence passing
------------------------------------------------------------
1. The range object can be passed around by moving,
   refrencing or coping to the same API.

Allow move / copy / refrence return
------------------------------------------------------------
1. Reading from a range may return a refrence, move or copy.
2. Reading will consistently return the same type using the
   same operation.

Transversal traits
------------------------------------------------------------

Data traits
------------------------------------------------------------
------------------------------------------------------------


6 Technical Specifications
============================================================