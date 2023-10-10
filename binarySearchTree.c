#include <stdio.h>
#include <malloc.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
};

struct BinarySearchTree {
    struct TreeNode *root;
};

struct TreeNode* treeSearch(struct TreeNode *treeNode, int find);
struct TreeNode* findTreeNode(struct BinarySearchTree *binarySearchTree, int find);
void insertTreeNode(struct BinarySearchTree *binarySearchTree, int add);
void insertNode(struct TreeNode *treeNode, int add);
void removeTreeNode(struct BinarySearchTree *tree, struct TreeNode *node);


int main() {
    return 0;
}

struct TreeNode* treeSearch(struct TreeNode *current, int find) {
    if (current == NULL) {
        return NULL;
    }
    if (current->value == find) {
        return current;
    }

    if (find < current->value && current->left != NULL) {
        return treeSearch(current->left, find);
    }

    if (find > current->value && current->right != NULL) {
        return treeSearch(current->right, find);
    }

    return NULL;
}

struct TreeNode* findTreeNode(struct BinarySearchTree *binarySearchTree, int find) {
    if (binarySearchTree->root == NULL) {
        return NULL;
    }
    return treeSearch(binarySearchTree->root, find);
}

void insertTreeNode(struct BinarySearchTree *binarySearchTree, int add) {
    if (binarySearchTree->root == NULL) {
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        root->value = add;
    } else {
        insertTreeNode(binarySearchTree->root, add);
    }
}

void insertNode(struct TreeNode *treeNode, int add) {
    if (add == treeNode->value) {
    }
    if (add < treeNode->value) {
        if (treeNode->left != NULL) {
            insertTreeNode(treeNode, add);
        } else {
            struct TreeNode *node = malloc(sizeof(struct TreeNode));
            node->value = add;
            treeNode->left = node;
            treeNode->left->parent = treeNode;
        }
    } else {
        if (treeNode->right != NULL) {
            insertTreeNode(treeNode, add);
        } else {
            struct TreeNode *node = malloc(sizeof(struct TreeNode));
            node->value = add;
            treeNode->right = node;
            treeNode->right->parent = treeNode;
        }
    }
}

void removeTreeNode(struct BinarySearchTree *tree, struct TreeNode *node) {
    if (tree->root == NULL || node == NULL) {
        exit(1);
    }

    // Deleting a leaf node
    if (node->left == NULL && node->right == NULL) {
        if (node->parent == NULL) {
            tree->root = NULL;
        } else if (node->parent->left == node) {
            node->parent->left = NULL;
        } else {
            node->parent->right = NULL;
        }
        return;
    }
    // Deleting a node with one child
    if (node->left == NULL || node->right == NULL) {
        struct TreeNode *child;
        child = node->left;
        if (node->left == NULL) {
            child = node->right;
        }

        child->parent = node->parent;
        if (node->parent == NULL) {
            tree->root = child;
        } else if (node->parent->left == node) {
            node->parent->left = child;
        } else {
            node->parent->right = child;
        }
        return;
    }
    // Deleting a node with two children.

    struct TreeNode *successor = node->right;
    while(successor->left != NULL) {
        successor = successor->left;
        removeTreeNode(tree, successor);
    }

    if (node->parent == NULL) {
        tree->root = successor;
    } else if (node->parent->left == node) {
        node->parent->left = successor;
    } else {
        node->parent->right = successor;
    }

    successor->parent = node->parent;

    successor->left = node->left;
    node->left->parent = successor;

    successor->right = node->right;
    if (node->right != NULL) {
        node->right->parent = successor;
    }
}
