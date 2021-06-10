#ifndef vector_h
#define vector_h

#include <stdio.h>
#include <stdlib.h>


struct VectorN
{
    size_t dimension;                   //Vector dimension
    size_t elementSize;                 //Size of 1 element
    void* zero;                         //∃(0): a + 0 = a
    void* one;                          //∃(1): a * 1 = a
    void* coordinates;                  //Array of coordinates
    void* (*minus)(void*);              //∃(a*): a + a* = 0
    void* (*sum)(void* x, void* y);     //Determination of the sum of 2 elements
    void* (*mult)(void* x, void* y);    //Determination of the multiplication of 2 elements
                                        //There should be an inverted item here 
};

//I.Vector creating
struct VectorN* Create0(size_t size, size_t elementSize, void* zero, void* one, void* (*minus)(void*), void* (*sum)(void* x1, void* x2), void* (*mult)(void*, void*));
struct VectorN* Create1(size_t size, size_t elementSize, void* zero, void* one, void* (*minus)(void*), void* (*sum)(void* x1, void* x2), void* (*mult)(void*, void*));
struct VectorN* CreateFromValues(size_t size, size_t elementSize, void* zero, void* one, void* values, void* (*minus)(void*), void* (*sum)(void* x1, void* x2), void* (*mult)(void*, void*));

//II.Decomposition
void* GetN(size_t coord, struct VectorN* v);
void* SetN(size_t coord, void* value, struct VectorN* v);

//III.Operations
struct VectorN* SumN(struct VectorN* v1, struct VectorN* v2);
struct VectorN* ScalarMultN(struct VectorN* v1, struct VectorN* v2);
struct VectorN* MinusN(struct VectorN* v1, struct VectorN* v2);

//Output errors
void* Error(char* msg);

#endif /* vector_c_h */
