#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Create(stackStruct *stackIn){

    int maxSize;
    defStackElement *newContents;

    printf ("Enter stack length: \n");
    scanf    ("%d", &maxSize);

    newContents = (defStackElement *)malloc(maxSize * sizeof(defStackElement));

    if (newContents == NULL)
        printf("Insufficient memory to initialize stack.\n");

    stackIn->contents = newContents;
    stackIn->maxSize = maxSize;
    stackIn->top = -1;

    printf ("Length = %d\n", stackIn->maxSize);
}

void Destroy(stackStruct *stackIn){

    free(stackIn->contents);

    stackIn->contents = NULL;
    stackIn->maxSize = 0;
    stackIn->top = -1;
}

void Push(stackStruct *stackIn, defStackElement element){

    if (IsFull(stackIn))
        printf("Can't push element on stack: stack is full.\n");
    else{
        stackIn->contents[++stackIn->top] = element;
	(stackIn->elementCount)++;
        printf("Element pushed = %d\n", element);
    }
}

defStackElement Pop(stackStruct *stackIn){

    if (IsEmpty(stackIn)){
        printf("Can't pop element from stack: stack is empty.\n");
        exit(0);
    }
    (stackIn->elementCount)--;	
    return stackIn->contents[stackIn->top--];
}

defStackElement Peek(stackStruct *stackIn){

    if (IsEmpty(stackIn))
        printf("Can't peek element from stack: stack is empty.\n");

    return stackIn->contents[stackIn->top];
}

int IsEmpty(stackStruct *stackIn){
    return stackIn->top < 0;
}

int IsFull(stackStruct *stackIn){
    return stackIn->top >= stackIn->maxSize - 1;
}

