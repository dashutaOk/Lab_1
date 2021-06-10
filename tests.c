#include "tests.h"
#include "float_vector.h"
#include "complex_vector.h"
#include <stdlib.h>


void* floatVectorTests()
{
    float* coord1 = (float*)malloc(sizeof(float)*3);
        for(int i = 0; i < 3; i++)
        {
            *(coord1+i) = 1.5f + i;
        };
    struct VectorN* v1 = createFromValuesFloat(3, coord1);
    float* coord2 = (float*)malloc(sizeof(float)*3);
        for(int i = 0; i < 3; i++)
        {
            *(coord2+i) = 2.2f + i;
        };
    struct VectorN* v2 = createFromValuesFloat(3, coord2);
    printf("============================================================\n");
    printf("Two vectors with coordinates:\n");
    printf("v1 = ");
    printVectorFloat(v1);
    printf("v2 = ");
    printVectorFloat(v2);
    
    printf("\nFirst test. Summ of vectors.\n");
    struct VectorN* v_summ = SumN(v1, v2);
    printf("Expected result: [3.70, 5.70, 7.70]\n");
    printf("Result of function SumN: ");
    printVectorFloat(v_summ);
    printf("Third coordinate of the resulting vector: %.2f\n", *(float*)GetN(2, v_summ));
    
    printf("\nSecond test. Subtraction of vectors.\n");
    struct VectorN* v_subt = MinusN(v1, v2);
    printf("Expected result: [-0.70, -0.70, -0.70]\n");
    printf("Result of function minusN: ");
    printVectorFloat(v_subt);
    printf("First coordinate of the resulting vector: %.2f\n", *(float*)GetN(0, v_subt));
    
    printf("\nThird test. Scalar multiplication of vectors.\n");
    struct VectorN* v_mult = ScalarMultN(v1, v2);
    printf("Expected result: [3.30, 8.00, 14.70]\n");
    printf("Result of function scalarMultN: ");
    printVectorFloat(v_mult);
    printf("Second coordinate of the resulting vector: %.2f", *(float*)GetN(1, v_mult));
    printf("\n============================================================\n");
    return 0;
};

void* complexVectorTests()
{
    float cord1[2][3] = {1.5, 2.2, 3, 4, 5.8, 6};
    float cord2[2][3] = {6, 5.8, 4, 3, 2.2, 1.5};
    struct VectorN* v1 = createFromValuesComplex(3, cord1);
    struct VectorN* v2 = createFromValuesComplex(3, cord2);
    printf("============================================================\n");
    printf("Two vectors with coordinates:\n");
    printf("v1 = ");
    printVectorComplex(v1);
    printf("v2 = ");
    printVectorComplex(v2);
    
    printf("\nFirst test. Summ of vectors.\n");
    struct VectorN* v_summ = SumN(v1, v2);
    printf("Expected result: [(7.50; 8.00i), (7.00; 7.00i), (8.00; 7.50i)]\n");
    printf("Result of function SumN: ");
    printVectorComplex(v_summ);
    printf("Third coordinate of the resulting vector: ");
    printComplexCoord(GetN(2, v_summ));
    
    printf("\n\nSecond test. Subtraction of vectors.\n");
    struct VectorN* v_subt = MinusN(v1, v2);
    printf("Expected result: [(-4.50; -3.60i), (-1.00; 1.00i), (3.60; 4.50i)]\n");
    printf("Result of function minusN: ");
    printVectorComplex(v_subt);
    printf("Second coordinate of the resulting vector: ");
    printComplexCoord(GetN(1, v_subt));
    
    printf("\n\nThird test. Scalar multiplication of vectors.\n");
    struct VectorN* v_mult = ScalarMultN(v1, v2);
    printf("Expected result: [(-3.76; 21.90i), (0.00; 25.00i), (3.76; 21.90i)]\n");
    printf("Result of function scalarMultN: ");
    printVectorComplex(v_mult);
    printf("First coordinate of the resulting vector: ");
    printComplexCoord(GetN(0, v_mult));
    printf("\n============================================================\n");
    return 0;
};

void* floatVectorTestsError()
{
    float* coord1 = (float*)malloc(sizeof(float)*3);
        for(int i = 0; i < 3; i++)
        {
            *(coord1+i) = 1.5f + i;
        };
    struct VectorN* v1 = createFromValuesFloat(3, coord1);
    float* coord2 = (float*)malloc(sizeof(float)*3);
        for(int i = 0; i < 3; i++)
        {
            *(coord2+i) = 2.2f + i;
        };
    struct VectorN* v2 = createFromValuesFloat(4, coord2);
    printf("2 vectors created:\n");
    printVectorFloat(v1);
    printVectorFloat(v2);
    printf("When trying to scalar multiplication of 2 vectors with different dimensions, an error pops up:\n");
    struct VectorN* v_mult = ScalarMultN(v1, v2);
    return v_mult;
};

void* complexVectorTestsError()
{
    float cord1[2][3] = {1.5, 2.2, 3, 4, 5.8, 6};
    float cord2[2][4] = {6, 5.8, 4, 3, 2.2, 1.5, 2.4, 1};
    struct VectorN* v1 = createFromValuesComplex(3, cord1);
    struct VectorN* v2 = createFromValuesComplex(4, cord2);
    printf("2 vectors created:\n");
    printVectorComplex(v1);
    printVectorComplex(v2);
    printf("When trying to scalar multiplication of 2 vectors with different dimensions, an error pops up:\n");
    struct VectorN* v_mult = ScalarMultN(v1, v2);
    return v_mult;
};
