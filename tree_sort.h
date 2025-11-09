#ifndef TREE_SORT_H_INCLUDED
#define TREE_SORT_H_INCLUDED

//=============================================================================

typedef int TreeElem_t;
#define TREE_TYPE_OUTPUT "%d"

#define OUTPUT_FILE stderr

//-----------------------------------------------------------------------------

#define DEBUG

#ifdef DEBUG
    #define ON_DEBUG(...) __VA_ARGS__
#else
    #define ON_DEBUG(...)
#endif

//-----------------------------------------------------------------------------


struct TreeNode_t {
    TreeElem_t data;
    TreeNode_t *left;
    TreeNode_t *right;
    TreeNode_t *parent;
};

struct Tree_t {
    TreeNode_t *root;
    int nodes_count;
};

void PrintTreeNode(TreeNode_t *node);
void PrintTreeElements(Tree_t *tree);

int InsertTreeElement(Tree_t *tree, TreeElem_t new_value);

#endif // TREE_SORT_H_INCLUDED
