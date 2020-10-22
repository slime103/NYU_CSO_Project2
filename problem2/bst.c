#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char * word ) {
    if (*root == NULL)
    {
       *root = newNode(word);
        return;
    }
    if (AchargtrB(word, (*root)->data))
        add(&(*root)->right,word);
    else
        add(&(*root)->left,word);
}


void inorder ( bst_node * root ) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}


char * removeSmallest (  bst_node ** root ){
    if ((*root) == NULL)
        return NULL;
    else if ((*root)->left != NULL && (*root)->left->left != NULL)
        return removeSmallest(&(*root)->left);
    else if ((*root)->left != NULL)
    {
        bst_node* tempRight;
        if ((*root)->left->right != NULL)
            tempRight = (*root)->left->right;
        else
            tempRight = NULL;
        char* temp = ((*root)->left)->data;
        free((*root)->left);
        (*root)->left = tempRight;
        return temp;
    }
    else //The root is the smallest
    {
        char* temp = (*root)->data;

        if ((*root)->right != NULL)
        {
            bst_node* tempRight = (*root)->right;
            (*root)->data = (*root)->right->data;
            (*root)->left = (*root)->right->left;
            (*root)->right = (*root)->right->right;
            free(tempRight);
        }
        else
            (*root) = NULL;

        return temp;
    }
}


char * removeLargest (  bst_node ** root ){
    if ((*root) == NULL)
        return NULL;
    else if ((*root)->right != NULL && (*root)->right->right != NULL)
        return removeLargest(&(*root)->right);
    else if ((*root)->right != NULL)
    {
        bst_node* tempRight;
        if ((*root)->right->left != NULL)
            tempRight = (*root)->right->left;
        else
            tempRight = NULL;
        char* temp = ((*root)->right)->data;
        free((*root)->right);
        (*root)->right = tempRight;
        return temp;
    }
    else //The root is the largest
    {
        char* temp = (*root)->data;

        if ((*root)->left != NULL)
        {
            bst_node* tempLeft = (*root)->left;
            (*root)->data = (*root)->left->data;
            (*root)->left = (*root)->left->left;
            (*root)->right = (*root)->left->right;
            free(tempLeft);
        }
        else
            (*root) = NULL;

        return temp;
    }
}


bst_node* newNode(char* word)
{
    bst_node *n;
    n = malloc(sizeof(bst_node));
    n->data = word;
    n->left = NULL;
    n->right = NULL;
    return n;
}


void freeTree(bst_node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
    }
}

int AchargtrB(char* a, char* b)
{
   /* int valA = 0;
    for(int i = 0; i < strlen(a); i++)
    {
        valA += *(a + i);
        //printf("%c",*(a + i));
    }
    //printf(" comapred with ");
    int valB = 0;
    for(int i = 0; i < strlen(b); i++)
    {
        valB += *(b + i);
        //printf("%c",*(b+i));
    }
    //printf("\nA: %d B: %d\n", valA, valB);
    if (valA > valB)
        return 1;
    else
        return 0;*/
    int i = 0;
    while (i < strlen(a) && i < strlen(b))
    {
        if (*(a + i) > *(b + i))
            return 1;
        else if (*(a + i) < *(b + i))
            return 0;
        i++;
    }
    if (strlen(a) > strlen(b))
        return 1;
    else
        return 0;
}
