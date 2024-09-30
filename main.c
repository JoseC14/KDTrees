#include <stdio.h>
#include "kdtree.h"

int main()
{

    
    double elem1[2] = {4.9, 5.5};
    double elem2[2] = { 2.3, 3.5 };
    double elem3[2] = { 6.3, 2.4 };
    double elem4[2] = { 1.2, 4.6 };
    double elem5[2] = { 3.6, 6.2 };
    double elem6[2] = { 5.1, 2.8 };
    double elem7[2] = { 7.4, 1.9 };
    double elem8[2] = { 0.8, 0.6 };
    double elem9[2] = { 3.3, 1.2 };


    double pos[2] = { 4.0, 3.0 };


    struct knode *root = NULL;
    struct knode *n1 = insert_knode(&root, elem1);
    struct knode* n2 = insert_knode(&root, elem2);
    struct knode* n3 = insert_knode(&root, elem3);
    struct knode* n4 = insert_knode(&root, elem4);
    struct knode* n5 = insert_knode(&root, elem5);
    struct knode* n6 = insert_knode(&root, elem6);
    struct knode* n8 = insert_knode(&root, elem7);
    struct knode* n9 = insert_knode(&root, elem8);
    struct knode* n10 = insert_knode(&root, elem9);
    struct knode* node_find = search_knode(root, elem3);
    


    //print_in_order_kdtree(root);

   // delete_knode(root, node_find);
    printf("\n");
    //print_in_order_kdtree(root);
    print_2d(root,root);
    //printf("Node nearest to the point(%.1lf, %.1f) is (%.1lf, %.1lf)", pos[0], pos[1], find_nearest_neighbor(root, pos, 2)->x, find_nearest_neighbor(root, pos, 2)->y);
    return 0;
}
