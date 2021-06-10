#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "float_vector.h"
#include "complex_vector.h"
#include "tests.h"


void* floatVectorsUI()
{
    int command;
    printf("Choose an operation: 1 - vectors sum, 2 - subtraction of vectors, 3 - scalar multiplication, 4 - tests, 5 - Error test, 0 - exit: ");
    scanf("%d", &command);
    if (command == 1)
    {
        struct VectorN* v1 = scanVectorFloat();
        struct VectorN* v2 = scanVectorFloat();
        printf("\nv1 = ");
        printVectorFloat(v1);
        printf("v2 = ");
        printVectorFloat(v2);
        struct VectorN* v3 = SumN(v1, v2);
        printf("Result: ");
        printVectorFloat(v3);
    }
    else if (command == 2)
    {
        struct VectorN* v1 = scanVectorFloat();
        struct VectorN* v2 = scanVectorFloat();
        printf("\nv1 = ");
        printVectorFloat(v1);
        printf("v2 = ");
        printVectorFloat(v2);
        struct VectorN* v3 = MinusN(v1, v2);
        printf("Result: ");
        printVectorFloat(v3);
    }
    else if (command == 3)
    {
        struct VectorN* v1 = scanVectorFloat();
        struct VectorN* v2 = scanVectorFloat();
        printf("\nv1 = ");
        printVectorFloat(v1);
        printf("v2 = ");
        printVectorFloat(v2);
        struct VectorN* v3 = ScalarMultN(v1, v2);
        printf("Result: ");
        printVectorFloat(v3);
    }
    else if (command == 4)
    {
        floatVectorTests();
    }
    else if (command == 5)
    {
        floatVectorTestsError();
    }
    else if (command == 0)
    {
        exit(0);
    }
    else
    {
        printf("Incorrect value!\n");
    };
        
    return 0;
};

void* complexVetorsUI()
{
    int command;
    printf("Choose an operation: 1 - vectors sum, 2 - subtraction of vectors, 3 - scalar multiplication, 4 - tests, 5 - Error test, 0 - exit: ");
    scanf("%d", &command);
    if (command == 1)
    {
        struct VectorN* v1 = scanVectorComplex();
        struct VectorN* v2 = scanVectorComplex();
        printf("\nv1 = ");
        printVectorComplex(v1);
        printf("v2 = ");
        printVectorComplex(v2);
        struct VectorN* v3 = SumN(v1, v2);
        printf("Result: ");
        printVectorComplex(v3);
    }
    else if (command == 2)
    {
        struct VectorN* v1 = scanVectorComplex();
        struct VectorN* v2 = scanVectorComplex();
        printf("\nv1 = ");
        printVectorComplex(v1);
        printf("v2 = ");
        printVectorComplex(v2);
        struct VectorN* v3 = MinusN(v1, v2);
        printf("Result: ");
        printVectorComplex(v3);
    }
    else if (command == 3)
    {
        struct VectorN* v1 = scanVectorComplex();
        struct VectorN* v2 = scanVectorComplex();
        printf("\nv1 = ");
        printVectorComplex(v1);
        printf("v2 = ");
        printVectorComplex(v2);
        struct VectorN* v3 = ScalarMultN(v1, v2);
        printf("Result: ");
        printVectorComplex(v3);
    }
    else if (command == 4)
    {
        complexVectorTests();
    }
    else if (command == 5)
    {
        complexVectorTestsError();
    }
    else if (command == 0)
    {
        exit(0);
    }
    else
    {
        printf("Incorrect value!\n");
    };
        
    return 0;
};
