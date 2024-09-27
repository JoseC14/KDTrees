#ifndef KDTREE_H_INCLUDED
#define KDTREE_H_INCLUDED

struct knode{
    int x;
    int y;
    struct knode *parent;
    struct knode *left;
    struct knode *right;
};

struct knode* insert_knode(struct knode **root, int elem[2]);
struct knode* search_knode(struct knode *root, int elem[2]);

struct knode* min_x(struct knode *root);
struct knode* min_y(struct knode* root);

int check_depth(struct knode* root, struct knode* node);

void delete_knode(struct knode *root, struct knode *node);
void print_in_order_kdtree(struct knode *root);
#endif // KDTREE_H_INCLUDED
