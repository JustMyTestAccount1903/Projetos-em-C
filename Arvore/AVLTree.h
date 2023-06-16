#include <stdio.h>
#include <stdlib.h>
#include "player.h"

typedef struct treeNode
{
    Player *player;
    struct treeNode *left;
    struct treeNode *right;
    int height;
} TreeNode;

TreeNode* initTree()
{
    return NULL;
}

TreeNode* createNode(Player *p)
{
    TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
    if (node)
    {
        node->player = p;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else
        printf("Memory not allocated.");
    return NULL;
}

int maxValue(int num, int num2)
{
    return (num>num2)? num: num2;
}

int nodeHeight(TreeNode *node)
{
    if (node==NULL)
        return -1;
    else
        return node->height;
}

int balanceFactor(TreeNode *node)
{
    if(node)
        return (nodeHeight(node->left) - nodeHeight(node->right));
    else
        return 0;
}

TreeNode* leftRotation(TreeNode *root)
{
    TreeNode *aux, *aux2;

    aux = root->right;
    aux2 = aux->left;

    aux->left = root;
    root->right = aux2;

    root->height = maxValue(nodeHeight(root->left), nodeHeight(root->right))+1;
    aux->height = maxValue(nodeHeight(aux->left), nodeHeight(aux->right))+1;

    return aux;
}

TreeNode* rightRotation(TreeNode *root)
{
    TreeNode *aux, *aux2;

    aux = root->left;
    aux2 = aux->right;

    aux->right = root;
    root->left = aux2;

    root->height = maxValue(nodeHeight(root->left), nodeHeight(root->right))+1;
    aux->height = maxValue(nodeHeight(aux->left), nodeHeight(aux->right))+1;

    return aux;
}

TreeNode* leftRightRotation(TreeNode *root)
{
    root->right = leftRotation(root->left);
    return rightRotation(root);
}

TreeNode* rightLeftRotation(TreeNode *root)
{
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

TreeNode* BalanceTree(TreeNode *root)
{
    int bf = balanceFactor(root);

    //left rotation
    if (bf < -1 && balanceFactor(root->right) <= 0)
        root = leftRotation(root);

    //right rotation
    else if (bf > 1 && balanceFactor(root->left) >= 0)
        root = rightRotation(root);

    //left right
    else if (bf > 1 && balanceFactor(root->left) < 0)
        root = leftRightRotation(root);

    //right left
    else if (bf < -1 && balanceFactor(root->right) > 0)
        root = rightLeftRotation(root);

    return root;
}

TreeNode* insertTree(TreeNode *node, Player *p)
{
    if (node == NULL)
        node = createNode(p);
    else
    {
        if (p->id > node->player->id)
            node->right = insertTree(node->right, p);
        else if (p->id < node->player->id)
            node->left = insertTree(node->left, p);
    }

    node->height = maxValue(nodeHeight(node->left), nodeHeight(node->right))+1;

    node = BalanceTree(node);

    return node;
}

void printTree(TreeNode *root, int depth)
{
    if (root)
    {
        printTree(root->right, depth+1);
        printf("\n\n");
        for(int i=0; i<depth; i++)
            printf("\t");
        printf("%d", root->player->id);
        printTree(root->left, depth+1);
    }
}

TreeNode* treeSearch(TreeNode *node, int id)
{
    if(node != NULL)
    {
        if (node->player->id == id)
        {
            return node;
        } else {
            if (node->player->id < id)
            {
                return treeSearch(node->right, id);
            } else{
                return treeSearch(node->left, id);
            }
        }
    }
    return NULL;
}

//to Search the max value on the left of the tree
TreeNode* treeMaxLeft(TreeNode *node)
{
    if (node != NULL)
    {
        TreeNode *aux = node->left;
        while (aux->right != NULL)
        {
            aux = aux->right;
        }
        return aux;
    }
    return NULL;
}

TreeNode* treeRemove(TreeNode *root, int id)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (root->player->id < id)
        {
            root->right = treeRemove(root->right, id);
        }
        else if(root->player->id > id)
        {
            root->left = treeRemove(root->left, id);
        }
        else //encontrou elemento a ser removido
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if(root->left == NULL && root->right != NULL) //um filho pela direita
            {
                TreeNode *aux = root->right;
                free(root);
                return aux;
            }
            else if (root->left != NULL && root->right == NULL) //um filho pela esquerda
            {
                TreeNode *aux = root->left;
                free(root);
                return aux;
            }
            else //dois filhos
            {
                TreeNode *aux = treeMaxLeft(root);
                Player *pAux = root->player;
                root->player = aux->player;
                aux->player = pAux;
                root->left = treeRemove(root->left, id);
                return root;
            }
        }
    }

    root->height = maxValue(nodeHeight(root->left), nodeHeight(root->right)) + 1;

    root = BalanceTree(root);

    return root;
}

void freeTree(TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
