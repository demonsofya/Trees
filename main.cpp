#include <stdio.h>

#include "tree_sort.h"

int main()
{
    TreeNode_t root = {};
    TreeNode_t vertex_5 = {};
    TreeNode_t vertex_7 = {7, NULL, NULL, &vertex_5};
    TreeNode_t vertex_3 = {3, NULL, NULL, &vertex_5};
    TreeNode_t vertex_20 = {20, NULL, NULL, &root};
    vertex_5 = {5, &vertex_3, &vertex_7, &root};
    root = {10, &vertex_5, &vertex_20, NULL};

    Tree_t tree = {&root};

    PrintTreeElements(&tree);

    return 0;
}
