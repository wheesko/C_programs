#ifndef _STACK_H
#define _STACK_H

typedef int defStackElement;

typedef struct {
  defStackElement *contents;
  int maxSize;
  int elementCount;
  int top;
} stackStruct;

void Create(stackStruct *stackIn);
void Destroy(stackStruct *stackIn);
void Push(stackStruct *stackIn, defStackElement element);
defStackElement Pop(stackStruct *stackIn);
defStackElement PopLast(stackStruct *stackIn);
defStackElement Peek(stackStruct *stackIn);
int IsEmpty(stackStruct *stackIn);
int IsFull(stackStruct *stackIn);
void Create(stackStruct *stackIn){

    int maxSize = 2000;
    defStackElement *newContents;

    //printf ("Enter stack length: \n");
    //scanf    ("%d", &maxSize);
    stackIn->contents = (defStackElement *)malloc(maxSize * sizeof(defStackElement));
    stackIn->maxSize = maxSize;
    stackIn->top = -1;

   // printf ("Length = %d\n", stackIn->maxSize);
}

void Destroy(stackStruct *stackIn){

    free(stackIn->contents);
    stackIn->elementCount = 0;
    stackIn->contents = NULL;
    stackIn->maxSize = 0;
    stackIn->top = -1;
}

void Push(stackStruct *stackIn, defStackElement element){

    if (IsFull(stackIn))
        printf("Can't push element on stack: stack is full.\n");
    else{
	(stackIn->elementCount)++;
	for (int i = stackIn -> elementCount - 1; i > 0 ; i--){
        	stackIn->contents[i] = stackIn -> contents[i-1];	
	}
	stackIn -> contents[0] = element;
    }
}

defStackElement Pop(stackStruct *stackIn){

    if (IsEmpty(stackIn)){
        printf("Can't pop element from stack: stack is empty.\n");
        exit(0);
    }
    int a = stackIn -> contents[0];
    for (int i = 1; i < stackIn -> elementCount;i++){
	stackIn -> contents[i-1] = stackIn -> contents[i];
    }	
    (stackIn->elementCount)--;	
    return a;
}

defStackElement Peek(stackStruct *stackIn){

    if (IsEmpty(stackIn))
        printf("Can't peek element from stack: stack is empty.\n");

    return stackIn->contents[stackIn->top];
}

int IsEmpty(stackStruct *stackIn){
    return stackIn -> elementCount == 0;
}

int IsFull(stackStruct *stackIn){
    return stackIn -> elementCount + 1 == stackIn -> maxSize;
}
defStackElement PopLast(stackStruct *stackIn){

    if (IsEmpty(stackIn)){
        printf("Can't pop element from stack: stack is empty.\n");
        exit(0);
    }
    defStackElement  a;
    a = stackIn -> contents[(stackIn -> elementCount) - 1];
    stackIn -> elementCount --;
    return a;
}


#endif
