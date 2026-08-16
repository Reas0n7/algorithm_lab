#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//Tree
Tree_Node *tree_create_node(int value)
{
    Tree_Node *node = (Tree_Node*)malloc(sizeof(Tree_Node));
    if (node == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void tree_traverse_preorder(Tree_Node *root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    tree_traverse_preorder(root->left);
    tree_traverse_preorder(root->right);
}

void tree_traverse_inorder(Tree_Node *root)
{
    if (root == NULL) {
        return;
    }
    tree_traverse_inorder(root->left);
    printf("%d ", root->data);
    tree_traverse_inorder(root->right);
}

void tree_traverse_postorder(Tree_Node *root)
{
    if (root == NULL) {
        return;
    }
    tree_traverse_postorder(root->left);
    tree_traverse_postorder(root->right);
    printf("%d ", root->data);
}

Tree_Node *tree_search(Tree_Node *root, int value)
{
    if (root == NULL) return NULL;
    if (root->data == value) return root;
    tree_search(root->right, value);
    tree_search(root->left, value);
}

int tree_find_max(Tree_Node *root)
{
    if (root == NULL) return INT_MIN;
    int left = tree_find_max(root->left);
    int right = tree_find_max(root->right);
    int mid = root->data;
    return ((left < right) ? ((mid > right) ? mid : right) : ((mid > left) ? mid : left));
}

int tree_find_min(Tree_Node *root)
{
    if (root == NULL) return INT_MAX;
    int left = tree_find_min(root->left);
    int right = tree_find_min(root->right);
    int mid = root->data;
    return ((left < right) ? ((mid > left) ? left : mid) : ((mid > right) ? right : mid));
}

int tree_height(Tree_Node *root)
{
    if (root == NULL) return 0;
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

void tree_destroy(Tree_Node *root)
{
    if (root == NULL) return;
    free(root->left);
    free(root->right);
}

//BST
BST_Node *bst_create_node(int value)
{

}

void bst_traverse_preorder(BST_Node *root)
{

}

void bst_traverse_inorder(BST_Node *root)
{
    
}

void bst_traverse_postorder(BST_Node *root)
{
    
}

int bst_height(BST_Node *root)
{

}

BST_Node *bst_find_min(BST_Node *root)
{

}

BST_Node *bst_find_max(BST_Node *root)
{

}

BST_Node *bst_search(BST_Node *root, int value)
{
    
}

BST_Node *bst_insert(BST_Node *root, int value)
{

}

BST_Node *bst_delete(BST_Node *root, int value)
{

}

void bst_destroy(BST_Node *root)
{

}











//AVL
int avl_node_height(Tree_Node *node)
{

}

int avl_balance_factor(Tree_Node *node)
{

}

Tree_Node *avl_rotate_left(Tree_Node *node)
{

}

Tree_Node *avl_rotate_right(Tree_Node *node)
{
    
}

Tree_Node *avl_insert(Tree_Node *root, int value)
{

}

Tree_Node *avl_delete(Tree_Node *root, int value)
{
    
}