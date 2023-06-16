#include <stdio.h>
#include <stdlib.h>
#include "footballer.h"

typedef struct node
{
    Footballer fb;
    struct node *next;
} Node;

typedef struct queue
{
    Node *head;
    Node *tail;
} Queue;

void createQueue(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

void enqueue(Queue *queue)
{
    Node *node = (Node*) malloc(sizeof(Node));

    if(node)
    {
        setFootballer(&node->fb);
        node->next = NULL;
        if(queue->head == NULL)
        {
            queue->head = node;
            queue->tail = node;
        }
        else
        {
            queue->tail->next = node;
            queue->tail = node;
        }
    }
    else
        printf("Memory not allocated.\n");
}

Node* dequeue(Queue *queue)
{
    Node *remove;

    if(queue->head)
    {
        remove = queue->head;
        queue->head = remove->next;
    }
    else
        printf("\nThe queue is empty.\n");
    return remove;
}

// Show the queue on the screen
void printQueue(Queue *queue)
{
    Node *aux = queue->head;

    printf("\n\t--------- QUEUE ---------\n");
    while(aux)
    {
        printf("\t%d ", aux->fb.id);
        aux = aux->next;
    }
    printf("\n\t--------- END QUEUE ----------\n");
}

int main()
{
    Node *removed;
    Queue queue;
    int choice;

    createQueue(&queue);

    do{
        printf("\nPerform operations on the queue:\n");
        printf("\n\t1 - Enqueue\n\t2 - Dequeue\n\t3 - Show the queue\n\t0 - Exit\n");
        printf("\nEnter the choice: \n");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            enqueue(&queue);
            break;
        case 2:
            removed = dequeue(&queue);
            if(removed)
            {
                printf("\nThe dequeued element is: \n");
                showFootballer(&removed->fb);
            }
            free(removed);
            break;
        case 3:
            printQueue(&queue);
            break;
        default:
            if (choice != 0)
                printf("Invalid choice! Choose another.\n");
        }
    }while(choice != 0);

    printf("Program Finished.\n");

    return 0;
}
