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

BST_Node *bst_create_node(int value);
void bst_traverse_preorder(BST_Node *root);
void bst_traverse_inorder(BST_Node *root);
void bst_traverse_postorder(BST_Node *root);
int bst_height(BST_Node *root);
BST_Node *bst_find_min(BST_Node *root);
BST_Node *bst_find_max(BST_Node *root);
BST_Node *bst_search(BST_Node *root, int value);
BST_Node *bst_insert(BST_Node *root, int value);
BST_Node *bst_delete(BST_Node *root, int value);
void bst_destroy(BST_Node *root);

//AVL
typedef struct AVL_Node {
    int data;
    int height;
    struct AVL_Node *left;
    struct AVL_Node *right;
}AVL_Node;

AVL_Node *avl_create_node(int value);
void avl_traverse_preorder(AVL_Node *root);
void avl_traverse_inorder(AVL_Node *root);
void avl_traverse_postorder(AVL_Node *root);
int avl_node_height(AVL_Node *node);
int avl_balance_factor(AVL_Node *node);
AVL_Node *avl_find_max(AVL_Node *root);
AVL_Node *avl_find_min(AVL_Node *root);
AVL_Node *avl_rotate_left(AVL_Node *node);
AVL_Node *avl_rotate_right(AVL_Node *node);
AVL_Node *avl_insert(AVL_Node *root, int value);
AVL_Node *avl_delete(AVL_Node *root, int value);
void avl_destroy(AVL_Node *root);








#ifdef __cplusplus
}
#endif

#endif