#include <stdio.h>
#include <stdlib.h>
#include "footballer.h"

typedef struct node
{
    Footballer fb;
    struct node *next;
} Node;

typedef struct stack
{
    struct node *top;
    int size;
} Stack;

void createStack(Stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

void push(Stack *stack)
{
    Node *newNode = (Node*) malloc(sizeof(Node));

    if(newNode)
    {
        setFootballer(&newNode->fb);
        newNode->next = stack->top;
        stack->top = newNode;
        stack->size++;
    }
    else
        printf("\nMemory not allocated.\n");
}

Node* pop(Stack *stack)
{
    if(stack->top)
    {
        Node *remove = stack->top;
        stack->top = remove->next;
        stack->size--;
        return remove;
    }
    else
        printf("\nThe stack is empty.\n");
    return NULL;
}

// Show the stack on the screen
void printStack(Stack *stack)
{
    Node *aux = stack->top;
    printf("\n--------- STACK SIZE: %d ---------\n", stack->size);
    while(aux)
    {
        printf("\n");
        showFootballer(&aux->fb);
        printf("\n");
        aux = aux->next;
    }
    printf("\n--------- THE END ---------\n");
}

int main(){

    Stack stack;
    Node *removed = NULL;
    int choice;

    createStack(&stack);

    do{
        printf("\nPerform operations on the stack:\n");
        printf("\n\t1 - Push\n\t2 - Pop\n\t3 - Show the stack\n\t0 - Exit\n");
        printf("\nEnter the choice: \n");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            push(&stack);
            break;
        case 2:
            removed = pop(&stack);
            if (removed)
            {
                printf("\nThe popped element is: \n");
                showFootballer(&removed->fb);
                free(removed);
            }
            break;
        case 3:
            printStack(&stack);
            break;
        default:
            if (choice != 0)
                printf("Invalid choice! Choose another.\n");
        }
    }while (choice != 0);

    printf("Program Finished.\n");
    return 0;
}
