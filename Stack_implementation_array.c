// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int capacity;
    int *arr;
};
struct Stack* createstack(int n){
    struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->capacity=n;
    stack->arr=(int*)malloc(stack->capacity*sizeof(int));
    return stack;
}
void pop(struct Stack*stack){
    if(stack->top==-1)
    printf("stack underflow");
    else
    stack->arr[stack->top--];
}
void push(struct Stack*stack,int n){
    if(stack->top==stack->capacity-1)
    printf("Stack Overflow");
    else{
    stack->arr[++stack->top]=n;
    printf("added %d",n);
    printf("\n");}
}
int main(){
    struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
    printf("Enter the size of stack\n");
    int n;
    scanf("%d",&n);
    stack=createstack(n);
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
}
