#include <stdio.h>
#include "kdtree.h"

int main()
{

    int elem1[2] = { 7,2 };
    int elem2[2] = { 3,1 };
    int elem3[2] = { 9,5 };
    int elem4[2] = { 2,0 };
    int elem5[2] = { 4,3 };
    int elem6[2] = { 8,4 };
    int elem7[2] = { 10,6 };

    struct knode *root = NULL;
    struct knode *n1 = insert_knode(&root, elem1);
    struct knode* n2 = insert_knode(&root, elem2);
    struct knode* n3 = insert_knode(&root, elem3);
    struct knode* n4 = insert_knode(&root, elem4);
    struct knode* n5 = insert_knode(&root, elem5);
    struct knode* n6 = insert_knode(&root, elem6);
    struct knode* n7 = insert_knode(&root, elem7);
    struct knode* node_find = search_knode(root, elem3);
   // printf("Node inserted with %d in x axis and %d in y axis\n", n1->x, n1->y);
   // printf("Node inserted with %d in x axis and %d in y axis\n", n2->x, n2->y);
    print_in_order_kdtree(root);

    delete_knode(root, node_find);
    printf("\n");
    print_in_order_kdtree(root);

    return 0;
}
