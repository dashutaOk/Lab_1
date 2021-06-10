#ifndef float_vector_h
#define float_vector_h
#include "vector.h"
#include <stdio.h>


void* minus_float(void* x);
void* sum_float(void* x, void* y);
void* mult_float(void* x, void* y);
void* init_zero_one_float(void);

struct VectorN* create0Float(size_t size);
struct VectorN* create1Float(size_t size);
struct VectorN* createFromValuesFloat(size_t size, void* values);

struct VectorN* printVectorFloat(struct VectorN* v);
struct VectorN* scanVectorFloat(void);

#endif /* float_vector_h */
