#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree_sort.h"

#define OUTPUT_FILE stderr

void PrintTreeNode(TreeNode_t *node) {

    assert(node);

    fprintf(OUTPUT_FILE, " ( ");

    if (node->left != NULL)
        PrintTreeNode(node->left);

    fprintf(OUTPUT_FILE, " %d ", node->data);

    if (node->right != NULL)
        PrintTreeNode(node->right);

    fprintf(OUTPUT_FILE, " ) ");
}

void PrintTreeElements(Tree_t *tree) {

    assert(tree);

    PrintTreeNode(tree->root);
}
