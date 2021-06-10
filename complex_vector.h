#ifndef complex_vector_h
#define complex_vector_h
#include <stdio.h>
#include "vector.h"


typedef struct ComplexCoord {
    float Real;
    float Image;
}complex;

void* getReal(complex* coordinates);
void* getImage(complex* coordinates);
void* minus_complex(void* z);
void* sum_complex(void* z1, void* z2);
void* mult_complex(void* z1, void* z2);

struct VectorN* create0complex(size_t size);
struct VectorN* create1complex(size_t size);
struct VectorN* createFromValuesComplex(size_t size, void* coordinates);

void* printComplexCoord(complex* z);
struct VectorN* printVectorComplex(struct VectorN* v);
struct VectorN* scanVectorComplex(void);


#endif /* complex_vector_h */
