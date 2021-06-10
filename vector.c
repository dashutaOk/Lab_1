#include "vector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


//I.Vector creating
struct VectorN* Create0(size_t size, size_t elementSize, void* zero, void* one, void* (*minus)(void*), void* (*sum)(void* x1, void* x2), void* (*mult)(void*, void*))
{
    struct VectorN* v = malloc(sizeof(struct VectorN));
    v->dimension = size;
    v-> elementSize = elementSize;
    v->coordinates = malloc(elementSize*size);
    v->zero = zero;
    v->sum = sum;
    v->one = one;
    v->minus = minus;
    v->mult = mult;

    for (size_t i = 0; i < size; i++)
    {
        int8_t* position = (int8_t*)v->coordinates + i*v->elementSize;
        memcpy((void*)position, v->zero, v->elementSize);
    }
    return v;
};

struct VectorN* Create1(size_t size, size_t elementSize, void* zero, void* one, void* (*minus)(void*), void* (*sum)(void* x1, void* x2), void* (*mult)(void*, void*))
{
    struct VectorN* v = malloc(sizeof(struct VectorN));
    v->dimension = size;
    v-> elementSize = elementSize;
    v->coordinates = malloc(elementSize*size);
    v->zero = zero;
    v->sum = sum;
    v->one = one;
    v->minus = minus;
    v->mult = mult;

    for (size_t i = 0; i < size; i++)
    {
        int8_t* position = (int8_t*)v->coordinates + i*v->elementSize;
        memcpy((void*)position, v->one, v->elementSize);
    }
    return v;
};

struct VectorN* CreateFromValues(size_t size, size_t elementSize, void* zero, void* one, void* values, void* (*minus)(void*), void* (*sum)(void* x1, void* x2), void* (*mult)(void*, void*))
{
    struct VectorN* v = malloc(sizeof(struct VectorN));
    v->dimension = size;
    v-> elementSize = elementSize;
    v->coordinates = malloc(elementSize*size);
    v->zero = zero;
    v->sum = sum;
    v->one = one;
    v->minus = minus;
    v->mult = mult;
    for (size_t i = 0; i < size; i++)
    {
        int8_t* position = (int8_t*)v->coordinates + i * v->elementSize;
        memcpy((void*)position, values+i*v->elementSize, v->elementSize);
    }
    return v;
};


//II.Decomposition
void* GetN(size_t coord, struct VectorN* v)
{
    return (void*)((int8_t*) v->coordinates + coord * (v->elementSize));
};

void* SetN(size_t coord, void* value, struct VectorN* v){
    void* position = (int8_t*)v->coordinates + coord * v->elementSize;
    memcpy(position, value, v->elementSize);
    return 0;
};


//III.Operations
struct VectorN* SumN(struct VectorN* v1, struct VectorN* v2){
    if (v1 && v2){
        if(v1->elementSize == v2->elementSize){
            if (v1->dimension == v2->dimension){
                struct VectorN* v3 = Create0(v1->dimension, v1->elementSize, v1->zero, v1->one, v1->minus, v1->sum, v1->mult);
                for (int i = 0; i < v1->dimension; i++){
                    void* el1 = GetN(i, v1);
                    void* el2 = GetN(i, v2);
                    void* el3 = v3->sum(el1, el2);
                    SetN(i, el3, v3);
                }
                return v3;
            } else{
                Error("Dimension error (Dimension(v1) != Dimension(v2))");
                return 0;
            }
        } else {
            Error("Type error (Type(v1) != Type(v2))");
            return 0;
        }
    } else{
        Error("Vector1 and Vector2 is NULL");
        return 0;
    }
};

struct VectorN* ScalarMultN(struct VectorN* v1, struct VectorN* v2)
{
    if (v1 && v2){
        if(v1->elementSize == v2->elementSize){
            if (v1->dimension == v2->dimension){
                struct VectorN* v3 = Create0(v1->dimension, v1->elementSize, v1->zero, v1->one, v1->minus, v1->sum, v1->mult);
                for (int i = 0; i < v1->dimension; i++){
                    void* el1 = GetN(i, v1);
                    void* el2 = GetN(i, v2);
                    void* el3 = v3->mult(el1, el2);
                    SetN(i, el3, v3);
                }
                return v3;
            } else{
                Error("Dimension error (Dimension(v1) != Dimension(v2))");
                return 0;
            }
        } else {
            Error("Type error (Type(v1) != Type(v2))");
            return 0;
        }
    } else{
        Error("Vector1 and Vector2 = 0");
        return 0;
    }
};

struct VectorN* MinusN(struct VectorN* v1, struct VectorN* v2){
    if (v1 && v2){
        if(v1->elementSize == v2->elementSize){
            if (v1->dimension == v2->dimension){
                struct VectorN* v3 = Create0(v1->dimension, v1->elementSize, v1->zero, v1->one, v1->minus, v1->sum, v1->mult);
                for (int i = 0; i < v1->dimension; i++){
                    void* el1 = GetN(i, v1);
                    void* el2 = v2->minus(GetN(i, v2));
                    void* el3 = v3->sum(el1, el2);
                    SetN(i, el3, v3);
                }
                return v3;
            } else{
                Error("Dimension error (Dimension(v1) != Dimension(v2))");
                return 0;
            }
        } else {
            Error("Type error (Type(v1) != Type(v2))");
            return 0;
        }
    } else{
        Error("Vector1 and Vector2 is NULL");
        return 0;
    }
};

//Output errors
void* Error(char* msg)
{
    printf("%s", msg);
    printf("\n");
    exit(0);
    return 0;
};
