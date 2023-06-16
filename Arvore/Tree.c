#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

int main()
{
    TreeNode *root = initTree();
    Player *j;
    int choice;

    do{
        printf("\n\t0 - Exit\n\t1 - Insert into tree\n\t2 - Show the tree\n\t3 - Search in tree\n\t4 - Remove a node\n");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            j = (Player*) malloc(sizeof(Player));
            j = setJogador(j);
            root = insertTree(root, j);
            break;
        case 2:
            imprimeJogador(j);
            printTree(root, 1);
            printf("\n");
            break;
        case 3: ;
            int id;
            printf("Digite o ID a ser buscado: \n");
            scanf("%d", &id);
            TreeNode *tmp = treeSearch(root, id);
            if (tmp == NULL)
            {
                printf("Elemento nao encontrado\n");
            }else
                printf("Elemento %i encontrado!\n", tmp->player->id);
            break;
        case 4: ;
            int id_remove;
            printf("Digite o ID que quer remover: \n");
            scanf("%d", &id_remove);
            printf("Antes de remover: \n");
            printTree(root, 1);

            printf("\nDepois de remover: \n");
            root = treeRemove(root, id);
            printTree(root, 1);
            break;
        default:
            if (choice != 0)
                printf("Opcao invalida!\n");
        }
    }while(choice != 0);

    printf("Program finished.");
    freeTree(root);

    return 0;
}
