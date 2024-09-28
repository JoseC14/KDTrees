#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "kdtree.h"

struct knode *insert_knode(struct knode **root, int elem[])
{

    //Inicializa a dimensão como 0
    int dim = 0;

    //Aloca espaço na memória para armazenar um nó e cria um ponteiro que aponta para esse espaco
    struct knode *new_node = (struct knode*) malloc(sizeof(struct knode));

    //Atribuindo os valores no novo nó
    new_node->x = elem[0];
    new_node->y = elem[1];
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;


    //Se a kd tree estiver vazia
    if(*root == NULL)
    {
        //o Novo no vai ser a raiz
        *root = new_node;

    }
    else
    {
        //Cria dois ponteiros que apontam para a raiz
        //Um vai ser usado para armazenar o no folha(temp) e o outro para traversar a arvore(aux)
        struct knode *aux = *root;
        struct knode *temp = aux;

        //Enquanto não chegar ao fim da arvore
        while(aux != NULL)
        {

            //Armazena o ultimo no que foi percorrido, caso chegue ao final da arvore
            //nao perdemos o controle de quem e o ultimo no
            temp = aux;

            //Se a dimensao for x
            if(dim % 2 == 0)
            {
                //Se o valor de x for maior que o valor de x do no que esta sendo percorrido
                if(new_node->x > aux->x)
                {
                    //ira para a direita
                    aux = aux->right;
                }
                else
                {
                    //ira para a esquerda
                    aux = aux->left;
                }
            }
            else
            {
                //Se o valor de y for maior que o valor de y do no que esta sendo percorrido
                if(new_node->y > aux->y)
                {

                    //Vai oara a direita
                    aux = aux->right;
                }
                else
                {
                    //Vai para a esquerda
                    aux = aux->left;
                }
            }

            //Muda a dimensao
            dim++;
        }
        //Decrementamos pois queremos saber qual a ultima dimensao que percorremos
        dim--;
        
        new_node->parent = temp;
        //Se a dimensao for x
        if(dim % 2 == 0)
        {
            //Se o valor de x for maior que o valor de x do no folha
            if(new_node->x > temp->x)
            {
                //Novo no sera o filho da direita do antigo no folha
                temp->right = new_node;
            }
            else
            {
                //Novo no sera o filho da esquerda do antigo no folha
                temp->left = new_node;
            }
        }
        else
        {
            //Se o y do novo no for maior que o valor y do no folha
            if (new_node->y > temp->y)
            {
                //Novo no sera o filho da direita do antigo no folha
                temp->right = new_node;
            }
            else
            {
                //Novo no sera o filho da esquerda do antigo no folha
                temp->left = new_node;
            }
        }
    }

    //Retorna o novo no para futuros usos
    return new_node;
};

struct knode* search_knode(struct knode* root, int elem[])
{
    //aux e a raiz
    struct knode *aux = root;

    //inicializa a dimensao
    int dim = 0;
    while (aux != NULL)
    {
        //Se o valor do x e y do no forem iguais aos pontos x, y que estao sendo procurados
        if (aux->x == elem[0] && aux->y == elem[1])
        {
            //retorne o no
            return aux;
        }

        //Se a dimensao for x
        if (dim % 2 == 0)
        {

            //Se x maior que x do no atual
            if (elem[0] > aux->x)
            {
                //vai para a direita
                aux = aux->right;
            }
            else
            {
                //Vai para a esquerda
                aux = aux->left;
            }
        }
        else
        {
            //Se y mmaior que o y do no atual
            if (elem[1] > aux->y)
            {

                //Vai para a direita
                aux = aux->right;
            }
            else
            {
                // Vai para a esquerda
                aux = aux->left;
            }
        }
        //muda a dimensao incremntado-a
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
    //aux e a raiz
    struct knode* aux = root;
    //Inicializa a profundidade como zero
    int depth = 0;
    //Enquanto aux for dirferente de nulo
    while (aux != NULL)
    {
        //Se aux for igual ao o no que estamos procurando
        if (aux == node)
        {
            //Quebra o ciclo
            break;
        }

        //Se a dimensao for x
        if (depth % 2 == 0)
        {
            //Se o valor de x for maior que o valor de x atual
            if (node->x > aux->x)
            {
                //Vai para a direita
                aux = aux->right;
            }
            else
            {
                //Vai para a esquerda
                aux = aux->left;
            }
        }
        else
        {
            //Se o valor de y for maior que valor de y do no atual
            if (node->y > aux->y)
            {
                //vai para a direita
                aux = aux->right;
            }
            else
            {
                //Vai para a esquerda
                aux = aux->left;
            }
        }
        //Incrementa a profundidade
        depth++;
    }

    //Retorna a profundidade
    return depth;
}

void delete_knode(struct knode* root, struct knode* node)
{
    //Se for um no folha
    if (node->left == NULL && node->right == NULL)
    {

        //Se o no folha for o filho esquerdo
        if (node->parent->left == node)
        {
            //desaloja a esquerda do pai com o no folha
            node->parent->left = NULL;
        }
        else
        {
            //desaloja a direita do pai com o no folha
            node->parent->right= NULL;
        }
        //desaloca a memoria
        free(node);
        //FIm da funcao
        return;
    }
    //Se ele tiver um filho a esquerda
    else if (node->left != NULL && node->right == NULL)
    {
        //o filho dele vai se tornar o filho do pai dele no lugar do no que vai ser deletado
        node->parent->left = node->left;
        node->left->parent = node->parent;
        //desaloca a memoria
        free(node);
    }
    else if (node->left == NULL && node->right != NULL)
    {
        //o filho dele vai se tornar o filho do pai dele no lugar do que vai ser deletado
        node->parent->right = node->right;
        node->right->parent = node->parent;
        free(node);
    }
    else if (node->left != NULL && node->right != NULL)
    {
        //Pega a profundidade do no
        int depth = check_depth(root, node);
        //Cria um ponteiro para o sucessor
        struct knode* sucessor;

        //Se ele estiver na dimensao x
        if (depth % 2 == 0)
        {

            //Procura o minimo no x
           sucessor = min_x(node);
            
        }
        else
        {
            //Procura o minimo no y
           sucessor = min_y(node);
        }

        //Copia os valores do no para
        node->x = sucessor->x;
        node->y = sucessor->y;

        //Deleta o sucessor recursivamente
        delete_knode(root, sucessor);
    }
    
}


void print_in_order_kdtree(struct knode *root)
{
    //Caso base, no e nulo
    if (root == NULL)
    {
        return;
    }
    
    //Chama recursivamente com o filho esquerdo
    print_in_order_kdtree(root->left);
    //Imprime o valor do no atual
    printf("(%d, %d) ", root->x, root->y);
    //Chama recursivamente com o filho direito
    print_in_order_kdtree(root->right);
}



double euclidean_distance(double* point1, double* point2, int k) {
    double distance = 0;

    //Formula da distancia euclidiana
    for (int i = 0; i < k; i++) {
        distance += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return sqrt(distance);
}

struct knode* nearest_neighbor(struct knode* root, int point[2])
{
    //Se a arvore for vazia
    if (root == NULL)
    {
        return NULL;
    }

    //Armazena os pontos em mnemonicos
    int x = point[0];
    int y = point[1];
    //inicializa a dimensão como zero
    int dim = 0;
    //Inicializa o melhor ponto como a raiz
    struct knode* best = root;
    //Melhor ponto é inicializado como a raiz
    struct knode* aux = root;

    //Enquanto não chegar em um nó folha
    while (aux != NULL)
    {
        double aux_point[2] = { aux->x, aux->y };
        double best_point[2] = { best->x, best->y };

        // Calcula a distância euclidiana
        double nearest_current = euclidean_distance(point, aux_point, 2);
        double best_distance = euclidean_distance(point, best_point, 2);

        //Se o nó atual for mais perto que o melhor nó até agora
        if (nearest_current < best_distance)
        {
            //Melhor e o no atual
            best = aux;
        }

        //Dimensao x
        if (dim % 2 == 0)
        {
            //Traversa  a kd tree
            if (x > aux->x)
            {
                aux = aux->right;
            }
            else
            {
                aux = aux->left;
            }
        }
        //Dimensao y
        else
        {
            //traversa a kd tree
            if (y > aux->y)
            {
                aux = aux->right;
            }
            else
            {
                aux = aux->left;
            }
        }
        //muda de dimensao
        dim++;
    }
    //Retorna o no mais proximo
    return best;
}
