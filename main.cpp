#include <iostream>
#include "BinaryTree.h"
using namespace std;


int main()
{
  BinarySearchTreeType  bSTree1;
  BinarySearchTreeType  bSTree2;
  BinarySearchTreeType  bSTree3;

  int num;

  cout << "Enter integers ending with -999" << endl;
  cin >> num;
  
  while (num != -999)
  {
    bSTree1.insert(num);
    cin >> num;
  }


  cout << endl << "Tree nodes in postorder: ";
  bSTree1.postorderTraversal();
  bSTree1.postorderTraversal() = bSTree2;
  cout << endl;

  cout << endl << "Tree nodes in preorder: ";
  bSTree2.preorderTraversal();
  bSTree2.preorderTraversal() = bSTree3;

  cout << endl << "Tree nodes in inorder: ";
  bSTree3.inorderTraversal();

  cout << "\n\n1st Tree Height: " << bSTree1.treeHeight();
  cout << "\n\n2nd Tree Height: " << bSTree2.treeHeight();
  cout << "\n\n3rd Tree Height: " << bSTree3.treeHeight();

  cout << "\n\nNumber of Leaves (tree 1): " << bSTree1.treeLeavesCount();
  cout << "\n\nNumber of Leaves (tree 2): " << bSTree2.treeLeavesCount();
  cout << "\n\nNumber of Leaves (tree 3): " << bSTree3.treeLeavesCount();

  cout << endl << endl;
  return 0;
}
