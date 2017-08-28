# numlabAPI details
-----------

  * naming conventions:
    namespaces, class, methods: lowercases with potention underscore for
    seperation when necessary. However use namespace or struct seperations whenever
    possible.

  * root namespace: nl::

Architecture specifics
----------------------

Definition of
  * data: move only
  * view: const T1
  * mut: T&

Any class in numlab MyDataSet, we impose the following restrictions:
  * a nested class OR a nested struct named "data" regroups ONLY the required
    data necessary. If "data" is defined as a class, then its members are private
    and the structure "tools" is defined as friend.

  * a nested struct named "tools" made of static function ONLY.

Favor structs with consecutive "using"-s for regrouping types and enums for
switching implementation using tag dispatch pattern.

Functionality groups
--------------------

Core / nl::core

Linear algebra / nl::alg2D, nl::alg3D, nl::algND

Geometry / nl::geom

Numerical integration / nl::num_int

Signal processing / nl::sig_proc

Functionality levels
--------------------

L0:
  * nl::core
      - nl::real, nl::complex
      - Generic parallel loops ?,

  * nl::alg2D, nl::alg3D, nl::algND
      - Level1 blas operations on arrays and vectors,
      - Outputs of (long) vectors & arrays into stream.

  * nl::geom
      - Data definition of coordinates, points, vectors and directions in 2D & 3D,
      - mesh1D

  * nl::num_int
      - Data definition of 1D quadrature rules

L1:
  * nl::sig_proc
      - Data definition of temporal signals (-> needs nl::algND::vector, nl::geom::mesh1D)
