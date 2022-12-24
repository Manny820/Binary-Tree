#include <iostream>
#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

//A node in the tree
struct NodeType
{
  int info;
  NodeType *leftLink;
  NodeType *rightLink;
};

  //BinaryTree class
class BinaryTreeType
{
  public:
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    int treeSwapTrees() const;
    int treeSingleParent() const;
    void destroyTree();
    virtual bool search(const int &searchItem) const = 0;
    virtual void insert(const int &insertItem) = 0;
    virtual void deleteNode(const int &deleteItem) = 0;
    BinaryTreeType(const BinaryTreeType &otherTree);
    BinaryTreeType();
    ~BinaryTreeType();
  
  protected:
    NodeType  *root;
  
  private:
    void copyTree(NodeType* &copiedTreeRoot,NodeType* otherTreeRoot);
    void destroy(NodeType* &p);
    void inorder(NodeType *p) const;
    void preorder(NodeType *p) const;
    void postorder(NodeType *p) const;
    int height(NodeType *p) const;
    int max(int x, int y) const;
    int nodeCount(NodeType *p) const;
    int leavesCount(NodeType *p) const;
    int swapTrees(NodeType *p) const;
    int singleParent(NodeType *p) const;
  };
