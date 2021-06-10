#include "interface.h"
#include <stdlib.h>


int main()
{
    int typeOfVector;
    printf("Select type of vectors: 1 - Real, 2 - Complex, 0 - exit: ");
    scanf("%d", &typeOfVector);
    if (typeOfVector == 1)
    {
        floatVectorsUI();
    }
    else if (typeOfVector == 2)
    {
        complexVetorsUI();
    }
    else if (typeOfVector == 0)
    {
        exit(0);
    }
    else
    {
        printf("Incorrect value!\n");
    };
};
