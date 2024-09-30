#ifndef KDTREE_H_INCLUDED
#define KDTREE_H_INCLUDED

struct knode{
    double x;
    double y;
    struct knode *parent;
    struct knode *left;
    struct knode *right;
};

// Estrutura para armazenar o resultado do vizinho mais próximo
struct nearest_neighbor_result {
    struct knode* node;
    double distance;
};
struct knode* insert_knode(struct knode **root, double elem[2]);
struct knode* search_knode(struct knode *root, double elem[2]);

struct knode* min_x(struct knode *root);
struct knode* min_y(struct knode* root);

int check_depth(struct knode* root, struct knode* node);

void delete_knode(struct knode *root, struct knode *node);
void print_in_order_kdtree(struct knode *root);

double euclidean_distance(double* point1, double* point2, int k);

struct nearest_neighbor_result nearest_neighbor(struct knode* root, double* target, int depth, int k);
struct knode* find_nearest_neighbor(struct knode* root, double* target, int k);
void print_2d(struct knode* root, struct knode* node);
#endif // KDTREE_H_INCLUDED
