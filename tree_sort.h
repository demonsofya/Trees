#ifndef TREE_SORT_H_INCLUDED
#define TREE_SORT_H_INCLUDED

typedef int TreeElem_t;

struct TreeNode_t {
    TreeElem_t data;
    TreeNode_t *left;
    TreeNode_t *right;
    TreeNode_t *parent;
};

struct Tree_t {
    TreeNode_t *root;
};

void PrintTreeNode(TreeNode_t *node);
void PrintTreeElements(Tree_t *tree);

#endif // TREE_SORT_H_INCLUDED
