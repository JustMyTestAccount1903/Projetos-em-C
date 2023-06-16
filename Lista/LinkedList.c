#include <stdlib.h>
#include <stdio.h>
#include "footballer.h"

typedef struct node
{
    Footballer fb;
    struct node* next;
} Node;

typedef struct linkedlist
{
    struct node *head;
    int size;
} List;

void createList(List *list)
{
    list->head = NULL;
    list->size = 0;
}

// Insert at the beginning of the list
void insertFirst(List *list)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node)
    {
        setFootballer(&new_node->fb);
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;
}

// Insert at the end of the list
void insertEnd(List *list)
{
    Node *aux, *new_node = (Node*) malloc(sizeof(Node));
    if(new_node)
    {
        setFootballer(&new_node->fb);
        new_node->next = NULL;
        if(list->head == NULL) // is it the first?
            list->head = new_node;
        else
        {
            aux = list->head;
            while(aux->next)
                aux = aux->next;
            aux->next = new_node;
        }
        list->size++;
    }
}

// Insert at the middle of the list
void insertMiddle(List *list, int previous)
{
    Node *aux, *new_node = (Node*) malloc(sizeof(Node));
    if(new_node)
    {
        setFootballer(&new_node->fb);
        new_node->next = NULL;
        if(list->head == NULL) // empty list
            list->head = new_node;
        else
        {
            aux = list->head;
            while(aux->fb.id != previous && aux->next)
                aux = aux->next;
            new_node->next = aux->next;
            aux->next = new_node;
        }
        list->size++;
    }
}

// Show the list on the screen
void printList(List *list)
{
    Node *aux = list->head;

    printf("\n\t------- LIST SIZE: %d ------\n", list->size);
    while(aux)
    {
        printf("\t%s\n", aux->fb.name);
        aux = aux->next;
    }
    printf("\n\t------- END LIST ---------\n");
}

// Remove a node from the list
Node* listRemove(List *list, int id)
{
    Node *aux, *prior;
    Node *remove = NULL;
    aux = prior = list->head;
    if(aux)
    {
        while(aux != NULL)
        {
            if(id == aux->fb.id)
            {
                if(aux == list->head) // 1st of the list
                {
                    remove = list->head;
                    list->head = aux->next;
                    list->size--;
                    break;
                }
                else
                {
                    remove = aux;
                    prior->next = aux->next;
                    list->size--;
                    break;
                }
            }
            else
            {
                prior = aux;
                aux = aux->next;
            }
        }
    }
    return remove;
}

// Search a node on the list
Node* listSearch(List *list, int id)
{
    Node *aux, *node;
    aux = list->head;
    node = NULL;
    while(aux && aux->fb.id != id)
        aux = aux->next;
    if(aux)
        node = aux;
    return node;
}

int main()
{
    List list;
    createList(&list);
    Node *removed, *found;
    int choice, previous, find_id, remove_id;

    do{
        printf("\nPerform operations on the list:\n");
        printf("\n\t1 - Insert beginning\n\t2 - Insert middle\n\t3 - Insert end\n\t4 - Show the list\n\t5 - Remove from the list\n\t6 - Search on the list\n\t0 - Exit\n");
        printf("\nEnter the choice: \n");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            insertFirst(&list);
            break;
        case 2:
            printf("Type the ID of the previous footballer: ");
            scanf("%d", &previous);
            insertMiddle(&list, previous);
            break;
        case 3:
            insertEnd(&list);
            break;
        case 4:
            printList(&list);
            break;
        case 5:
            printf("Type the ID of the footballer to be removed: ");
            scanf("%d", &remove_id);
            removed = listRemove(&list, remove_id);
            if(removed)
            {
                printf("Removed element:\n");
                showFootballer(&removed->fb);
            }
            else
                printf("\nThe ID was not found.\n");
            free(removed);
            break;
        case 6:
            printf("Type the ID to be searched: ");
            scanf("%d", &find_id);
            found = listSearch(&list, find_id);
            if(found)
            {
                printf("\nElement found!\n");
                showFootballer(&found->fb);
            }
            else
                printf("\nThe ID was not found.\n");
            free(found);
            break;
        default:
            if (choice != 0)
                printf("Invalid choice! Choose another.\n");
        }
    }while(choice != 0);

    printf("Program Finished.\n");

    return 0;
}

