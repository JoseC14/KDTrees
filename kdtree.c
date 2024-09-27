#include <stdlib.h>
#include <stdio.h>
#include "kdtree.h"

struct knode *insert_knode(struct knode **root, int elem[])
{
    int dim = 0;

    struct knode *new_node = (struct knode*) malloc(sizeof(struct knode));

    new_node->x = elem[0];
    new_node->y = elem[1];
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    if(*root == NULL)
    {
        *root = new_node;

    }
    else
    {
        struct knode *aux = *root;
        struct knode *temp = aux;

        while(aux != NULL)
        {
            temp = aux;
            if(dim % 2 == 0)
            {
                if(new_node->x > aux->x)
                {
                    aux = aux->right;
                }
                else
                {
                    aux = aux->left;
                }
            }
            else
            {
                if(new_node->y > aux->y)
                {
                    aux = aux->right;
                }
                else
                {
                    aux = aux->left;
                }
            }
            dim++;
        }
        dim--;
        new_node->parent = temp;
        if(dim % 2 == 0)
        {
            if(new_node->x > temp->x)
            {
                temp->right = new_node;
            }
            else
            {
                temp->left = new_node;
            }
        }
        else
        {
            if (new_node->y > temp->y)
            {
                temp->right = new_node;
            }
            else
            {
                temp->left = new_node;
            }
        }
    }

    return new_node;
};

struct knode* search_knode(struct knode* root, int elem[])
{
    struct knode *aux = root;
    int dim = 0;
    while (aux != NULL)
    {
        if (aux->x == elem[0] && aux->y == elem[1])
        {
            return aux;
        }

        if (dim % 2 == 0)
        {
            if (elem[0] > aux->x)
            {
                aux = aux->right;
            }
            else
            {
                aux = aux->left;
            }
        }
        else
        {
            if (elem[1] > aux->y)
            {
                aux = aux->right;
            }
            else
            {
                aux = aux->left;
            }
        }
        dim++;
    }
}

struct knode* min_x(struct knode* root) {
    if (root == NULL) {
        return NULL; // Se a árvore estiver vazia
    }

    struct knode* min_node = root; // Inicialmente, o mínimo é o nó atual

    // Busca o mínimo na subárvore esquerda
    struct knode* left_min = min_y(root->left);
    struct knode* right_min = min_y(root->right);

    // Verifica o mínimo na subárvore esquerda
    if (left_min != NULL && left_min->x < min_node->x) {
        min_node = left_min;
    }

    // Verifica o mínimo na subárvore direita
    if (right_min != NULL && right_min->x < min_node->x) {
        min_node = right_min;
    }

    return min_node; // Retorna o nó com o menor valor em y
}


struct knode* min_y(struct knode* root) {
    if (root == NULL) {
        return NULL; // Se a árvore estiver vazia
    }

    struct knode* min_node = root; // Inicialmente, o mínimo é o nó atual

    // Busca o mínimo na subárvore esquerda
    struct knode* left_min = min_y(root->left);
    struct knode* right_min = min_y(root->right);

    // Verifica o mínimo na subárvore esquerda
    if (left_min != NULL && left_min->y < min_node->y) {
        min_node = left_min;
    }

    // Verifica o mínimo na subárvore direita
    if (right_min != NULL && right_min->y < min_node->y) {
        min_node = right_min;
    }

    return min_node; // Retorna o nó com o menor valor em y
}


int check_depth(struct knode* root, struct knode* node)
{
    struct knode* aux = root;
    int depth = 0;
    while (aux != NULL)
    {
        if (aux == node)
        {
            break;
        }

        if (depth % 2 == 0)
        {
            if (node->x > aux->x)
            {
                aux = aux->right;
            }
            else
            {
                aux = aux->left;
            }
        }
        else
        {
            if (node->y > aux->y)
            {
                aux = aux->right;
            }
            else
            {
                aux = aux->left;
            }
        }
        depth++;
    }

    return depth;
}

void delete_knode(struct knode* root, struct knode* node)
{
    if (node->left == NULL && node->right == NULL)
    {

        if (node->parent->left == node)
        {
            node->parent->left = NULL;
        }
        else
        {
            node->parent->right= NULL;
        }
        free(node);
        return;
    }
    else if (node->left != NULL && node->right == NULL)
    {
        node->parent->left = node->left;
        free(node);
    }
    else if (node->left != NULL && node->right != NULL)
    {
        int depth = check_depth(root, node);
        struct knode* sucessor;
        if (depth % 2 == 0)
        {
           sucessor = min_x(node);
            
        }
        else
        {
           sucessor = min_y(node);
        }

        node->x = sucessor->x;
        node->y = sucessor->y;

        delete_knode(root, sucessor);
    }
    
}


void print_in_order_kdtree(struct knode *root)
{
    if (root == NULL)
    {
        return;
    }
    
    print_in_order_kdtree(root->left);
    printf("(%d, %d) ", root->x, root->y);
    print_in_order_kdtree(root->right);
}