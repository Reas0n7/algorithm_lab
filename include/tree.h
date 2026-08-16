#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Tree_Node {
    int data;
    struct Tree_Node *left;
    struct Tree_Node *right;
}Tree_Node;

Tree_Node *tree_create_node(int value);
Tree_Node *tree_search(Tree_Node *root, int value);
void tree_traverse_preorder(Tree_Node *root);
void tree_traverse_inorder(Tree_Node *root);
void tree_traverse_postorder(Tree_Node *root);
int tree_find_max(Tree_Node *root);
int tree_find_min(Tree_Node *root);
int tree_height(Tree_Node *root);
void tree_destroy(Tree_Node *root);






//BST
typedef struct BST_Node {
    int data;
    struct BST_Node *left;
    struct BST_Node *right;
}BST_Node;







//AVL
typedef struct AVL_Node {
    int data;
    int height;
    struct AVL_Node *left;
    struct AVL_Node *right;
}AVL_Node;










#ifdef __cplusplus
}
#endif

#endif