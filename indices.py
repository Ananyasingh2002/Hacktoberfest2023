from libcpp.vector cimport vector
cimport numpy as np
import numpy as np
import cython

@cython.boundscheck(False)
@cython.wraparound(False)
def bool2indices(np.ndarray[np.uint8_t, cast=True] boolvalues):
    cdef int i, size
    cdef vector[int] indices
    size = len(boolvalues)

    for i in range(size):
        if boolvalues[i]:
            indices.push_back(i)

    return np.asarray(indices)
