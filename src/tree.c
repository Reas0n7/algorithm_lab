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
    Tree_Node *found = tree_search(root->left, value);
    if (found != NULL) return found;
    return tree_search(root->right, value);
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
    tree_destroy(root->left);
    tree_destroy(root->right);
    free(root);
}

//BST
BST_Node *bst_create_node(int value)
{
    BST_Node *node = (BST_Node*)malloc(sizeof(BST_Node));
    if (node == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bst_traverse_preorder(BST_Node *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    bst_traverse_preorder(root->left);
    bst_traverse_preorder(root->right);
}

void bst_traverse_inorder(BST_Node *root)
{
    if (root == NULL) return;
    bst_traverse_inorder(root->left);
    printf("%d ", root->data);
    bst_traverse_inorder(root->right);
}

void bst_traverse_postorder(BST_Node *root)
{
    if (root == NULL) return;
    bst_traverse_postorder(root->left);
    bst_traverse_postorder(root->right);
    printf("%d ", root->data);
}

int bst_height(BST_Node *root)
{
    if (root == NULL) return 0;
    int left_height = bst_height(root->left);
    int right_height = bst_height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1; 
}

BST_Node *bst_find_min(BST_Node *root)
{
    if (root == NULL) return NULL;
    BST_Node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

BST_Node *bst_find_max(BST_Node *root)
{
    if (root == NULL) return NULL;
    BST_Node *current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

BST_Node *bst_search(BST_Node *root, int value)
{
    if (root == NULL) return NULL;
    if (root->data == value) return root;
    if (root->data > value) return bst_search(root->left, value);
    return bst_search(root->right, value);
}

BST_Node *bst_insert(BST_Node *root, int value)
{
    if (root == NULL) return bst_create_node(value);
    if (root->data > value) {
        root->left = bst_insert(root->left, value);
    } else if (root->data < value) {
        root->right = bst_insert(root->right, value);
    }
    return root;
}

BST_Node *bst_delete(BST_Node *root, int value)
{
    if (root == NULL) return NULL;
    if (root->data > value) {
        root->left = bst_delete(root->left, value);
    } else if (root->data < value) {
        root->right = bst_delete(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            BST_Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BST_Node *temp = root->left;
            free(root);
            return temp;
        } else {
            BST_Node *successor = bst_find_min(root->right);
            root->data = successor->data;
            root->right = bst_delete(root->right, successor->data);
        }
    }
    return root;
}

void bst_destroy(BST_Node *root)
{
    if (root == NULL) return;
    bst_destroy(root->left);
    bst_destroy(root->right);
    free(root);
}


//AVL
AVL_Node *avl_create_node(int value)
{
    AVL_Node *node = (AVL_Node*)malloc(sizeof(AVL_Node));
    if (node == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    node->data = value;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void avl_traverse_preorder(AVL_Node *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    avl_traverse_preorder(root->left);
    avl_traverse_preorder(root->right);
}

void avl_traverse_inorder(AVL_Node *root)
{
    if (root == NULL) return;
    avl_traverse_inorder(root->left);
    printf("%d ", root->data);
    avl_traverse_inorder(root->right);
}

void avl_traverse_postorder(AVL_Node *root)
{
    if (root == NULL) return;
    avl_traverse_postorder(root->left);
    avl_traverse_postorder(root->right);
    printf("%d ", root->data);
}

int avl_node_height(AVL_Node *node)
{
    return node ? node->height : 0;
}

int avl_balance_factor(AVL_Node *node)
{
    if (node == NULL) return 0;
    return avl_node_height(node->left) - avl_node_height(node->right);
}

AVL_Node *avl_find_max(AVL_Node *root)
{
    if (root == NULL) return NULL;
    AVL_Node *current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

AVL_Node *avl_find_min(AVL_Node *root)
{
    if (root == NULL) return NULL;
    AVL_Node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}


AVL_Node *avl_rotate_left(AVL_Node *node)
{
    AVL_Node *new_node = node->right;
    node->right = new_node->left;
    new_node->left = node;
    node->height = (avl_node_height(node->right) > avl_node_height(node->left) ? avl_node_height(node->right) : avl_node_height(node->left)) + 1;
    new_node->height = (avl_node_height(new_node->right) > avl_node_height(new_node->left) ? avl_node_height(new_node->right) : avl_node_height(new_node->left)) + 1;
    return new_node;
}

AVL_Node *avl_rotate_right(AVL_Node *node)
{
    AVL_Node *new_node = node->left;
    node->left = new_node->right;
    new_node->right = node;
    node->height = (avl_node_height(node->right) > avl_node_height(node->left) ? avl_node_height(node->right) : avl_node_height(node->left)) + 1;
    new_node->height = (avl_node_height(new_node->right) > avl_node_height(new_node->left) ? avl_node_height(new_node->right) : avl_node_height(new_node->left)) + 1;
    return new_node;
}

AVL_Node *avl_insert(AVL_Node *root, int value)
{
    if (root == NULL) return avl_create_node(value);
    if (value < root->data) {
        root->left = avl_insert(root->left, value);
    } else if (value > root->data) {
        root->right = avl_insert(root->right, value);
    } else {
        return root;
    }
    root->height = (avl_node_height(root->right) > avl_node_height(root->left) ? avl_node_height(root->right) : avl_node_height(root->left)) + 1;
    int balance_factor = avl_balance_factor(root);
    if (balance_factor > 1 && value < root->left->data) {
        //LL
        return avl_rotate_right(root);
    } else if (balance_factor < -1 && value > root->right->data) {
        //RR
        return avl_rotate_left(root);
    } else if (balance_factor > 1 && value > root->left->data) {
        //LR
        root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);
    } else if (balance_factor < -1 && value < root->right->data) {
        //RL
        root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);
    }
    return root;
}

AVL_Node *avl_delete(AVL_Node *root, int value)
{
    if (root == NULL) return NULL;
    if (value < root->data) {
        root->left = avl_delete(root->left, value);
    } else if (value > root->data) {
        root->right = avl_delete(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            AVL_Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            AVL_Node *temp = root->right;
            free(root);
            return temp;
        } else {
            AVL_Node *successor = avl_find_min(root->right);
            root->data = successor->data;
            root->right = avl_delete(root->right, successor->data);
        }
    }
    if (root == NULL) return NULL;
    root->height = (avl_node_height(root->right) > avl_node_height(root->left) ? avl_node_height(root->right) : avl_node_height(root->left)) + 1;
    int balance_factor = avl_balance_factor(root);
    if (balance_factor > 1 && value < root->left->data) {
        //LL
        return avl_rotate_right(root);
    } else if (balance_factor < -1 && value > root->right->data) {
        //RR
        return avl_rotate_left(root);
    } else if (balance_factor > 1 && value > root->left->data) {
        //LR
        root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);
    } else if (balance_factor < -1 && value < root->right->data) {
        //RL
        root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);
    }
    return root;
    
}

void avl_destroy(AVL_Node *root)
{
    if (root == NULL) return;
    avl_destroy(root->left);
    avl_destroy(root->right);
    free(root);
}

/* 横向旋转 90° 的树：根在最左，越往下越缩进 */
void tree_print(AVL_Node *root, int depth)
{
    if (root == NULL) {
        return;
    }
    tree_print(root->right, depth + 1);          /* 先画右子树（上面） */
    for (int i = 0; i < depth; i++) {
        printf("    ");                          /* 深度越深，缩进越多 */
    }
    printf("(%d)\n", root->data);                /* 画当前节点 */
    tree_print(root->left, depth + 1);           /* 再画左子树（下面） */
}