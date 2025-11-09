#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree_sort.h"
#include "tree_dump.h"

void PrintTreeNode(TreeNode_t *node) {

    assert(node);

    fprintf(OUTPUT_FILE, " ( ");

    if (node->left != NULL)
        PrintTreeNode(node->left);

    fprintf(OUTPUT_FILE, " "TREE_TYPE_OUTPUT" ", node->data);

    if (node->right != NULL)
        PrintTreeNode(node->right);

    fprintf(OUTPUT_FILE, " ) ");
}

int PrintTreeElements(Tree_t *tree) {

    Return_If_Tree_Error(tree)

    PrintTreeNode(tree->root);

    Return_Tree_Error(tree);
}

Tree_t *TreeCtor(TreeElem_t root_value) {

    Tree_t *tree = (Tree_t *) calloc(1, sizeof(Tree_t));
    if (tree == NULL)
        return NULL;

    TreeNode_t *root = (TreeNode_t *) calloc(1, sizeof(TreeNode_t));
    if (root == NULL)
        return tree;

    root->data = root_value;

    tree->root = root;
    tree->nodes_count = 0;

    return tree;
}

void DeleteNode(Tree_t *tree, TreeNode_t *node) {

    assert(node);
    assert(tree);

    if (node->left != NULL)
        DeleteNode(node->left);

    if (node->right != NULL)
        DeleteNode(node->right);

    free(node);
    tree->nodes_count--;
}

void TreeNodeDtor(Tree_t *tree, TreeNode_t *node) {

    if (tree == NULL || node == NULL)
        return;

    DeleteNode(tree, node);
}

int InsertTreeElement(Tree_t *tree, TreeElem_t new_value) {

    Return_If_Tree_Error(tree)

    TreeNode_t *new_node = (TreeNode_t *) calloc(1, sizeof(TreeNode_t));
    if (new_node == NULL)
        return NodePtrError;

    new_node->data = new_value;

    TreeNode_t *curr_parent_node = tree->root;

    while (true) {
        if (new_value <= curr_parent_node->data) {

            if (curr_parent_node->left != NULL)
                curr_parent_node = curr_parent_node->left;

            else {
                curr_parent_node->left = new_node;
                break;
            }

        } else {

            if (curr_parent_node->right != NULL)
                curr_parent_node = curr_parent_node->right;

            else {
                curr_parent_node->right = new_node;
                break;
            }

        }

    }

    new_node->parent = curr_parent_node;
    (tree->nodes_count)++;

    Return_Tree_Error(tree);
}


