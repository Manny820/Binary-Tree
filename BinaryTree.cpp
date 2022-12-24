  
//Constructor
BinaryTreeType::BinaryTreeType()
{
  root = NULL;
}

// Check if tree is empty
bool BinaryTreeType::isEmpty() const
{
return (root == NULL);
}

//Helper method for the inorder Traversal
void BinaryTreeType::inorderTraversal() const
{
  inorder(root);
}

//Helper method for the preorder Traversal
void BinaryTreeType::preorderTraversal() const
{
  preorder(root);
}

//Helper method for the postorder Traversal
void BinaryTreeType::postorderTraversal() const
{
  postorder(root);
}

//Helper method for the finding height of a tree
int BinaryTreeType::treeHeight() const
{
  return height(root);
}

//Helper method for the counting all nodes in a tree
int BinaryTreeType::treeNodeCount() const
{
  return nodeCount(root);
}

//Helper method for counting leaf nodes
int BinaryTreeType::treeLeavesCount() const
{
  return leavesCount(root);
}

//Helper method for swapping subtrees
int BinaryTreeType::treeSwapTrees() const
{
  return swapTrees(root);
}

//Helper method for finding single parents
int BinaryTreeType::treeSingleParent() const
{
  return singleParent(root);
}

void  BinaryTreeType::copyTree(NodeType* &copiedTreeRoot,NodeType* otherTreeRoot)
{
  if (otherTreeRoot == NULL)
    copiedTreeRoot = NULL;

  else
  {
    copiedTreeRoot = new NodeType;
    copiedTreeRoot->info = otherTreeRoot->info;
    copyTree(copiedTreeRoot->leftLink, otherTreeRoot->leftLink);
    copyTree(copiedTreeRoot->rightLink, otherTreeRoot->rightLink);
  }
} //end copyTree

//Recursive method for inorder traversal
void BinaryTreeType::inorder(NodeType *p) const
{
  if (p != NULL)
  {
    inorder(p->leftLink);
    cout << p->info << " ";
    inorder(p->rightLink);
  }
}

//Recursive method for preorder traversal
void BinaryTreeType::preorder(NodeType *p) const
{
  if (p != NULL)
  {
    cout << p->info << " ";
    preorder(p->leftLink);
    preorder(p->rightLink);
  }
}

//Recursive method for post order traversal
void BinaryTreeType::postorder(NodeType *p) const
{
  if (p != NULL)
  {
    postorder(p->leftLink);
    postorder(p->rightLink);
    cout << p->info << " ";
  }
}

void  BinaryTreeType::destroy(NodeType* &p)
{
  if (p != NULL)
  {
    destroy(p->leftLink);
    destroy(p->rightLink);
    delete p;p = NULL;
  }
}

void  BinaryTreeType::destroyTree()
{
  destroy(root);
}

//copy constructor
BinaryTreeType::BinaryTreeType(const BinaryTreeType& otherTree)
{
  if (otherTree.root == NULL) //otherTree is empty
    root = NULL;
  else
    copyTree(root, otherTree.root);
}

//Destructor
BinaryTreeType::~BinaryTreeType()
{
  destroy(root);
}

int BinaryTreeType::height(NodeType *p) const
{
  if (p == NULL)
    return 0;
  else
    return 1 + max(height(p->leftLink), height(p->rightLink));
}

int BinaryTreeType::max(int x, int y) const
{
  if (x >= y)
    return x;
  else
    return y;
}

int count = 1;

int BinaryTreeType::nodeCount(NodeType *p) const
{
  //int count = 1; // global variable

  if (p == NULL)
  {
    return 0;
  }

  if (p->leftLink != NULL )
  {
    count = count + 1;
    count = nodeCount(p->leftLink);
  }
  
  if (p->rightLink != NULL )
  {
    count = count + 1;
    count = nodeCount(p->rightLink);
  }
    
  return count;
}

int BinaryTreeType::leavesCount(NodeType *p) const
{
  if(p == NULL)      
    return 0;  

  if(p->leftLink == NULL && p->rightLink == NULL)  
    return 1;  

  else
    return leavesCount(p->leftLink) + leavesCount(p->rightLink); 

  return 0;
}

// recursive method to swap subtrees
int BinaryTreeType::swapTrees(NodeType *p) const
{
  if(p == NULL)
    return 0;

  NodeType *temp = p->leftLink;
  p->leftLink = p->rightLink;
  p->rightLink = temp;
  swapTrees(p->leftLink);
  swapTrees(p->rightLink);

  return 0;
}



// recursive method to find single parent nodes in tree
int BinaryTreeType::singleParent(NodeType *p) const
{
  if(p == NULL)
    return 0;
  else
  {
    if(p->leftLink == NULL && p->rightLink != NULL)
      return 1 + singleParent(p->rightLink);
    else if(p->leftLink != NULL && p->rightLink == NULL)
      return 1 + singleParent(p->leftLink);
    else  
      return singleParent(p->leftLink);
  }

  return 0;
}



//Inheritance to implement virtual methods
// defined in BinaryTreeType
class BinarySearchTreeType : public BinaryTreeType
{
  public:
    bool search(const int &searchItem) const;
    void insert(const int &insertItem);
    void deleteNode(const int &deleteItem);
  
  private:
    void deleteFromTree(NodeType * &p);
};

bool BinarySearchTreeType::search(const int &searchItem) const
{
  NodeType *current;
  bool found = false;

  if (root == NULL)
    cout << "Cannot search an empty tree." << endl;
  else    
  {
    current = root;  //set current to root node
    while (current != NULL && !found)
    {
      if (current->info == searchItem)
        found = true;
      else if (current->info > searchItem)
        current = current->leftLink;
      else 
        current = current->rightLink;
    }//end while
  }//end else
  return found;
}//end search


void BinarySearchTreeType::insert(const int &insertItem)
{
  NodeType *current; //pointer to traverse the tree
  NodeType *parent = NULL; //pointer behind current
  NodeType *newNode;  //pointer to create the node

  newNode = new NodeType;
  newNode->info = insertItem;
  newNode->leftLink = NULL;
  newNode->rightLink = NULL;

  if (root == NULL)
    root = newNode;
  else 
  {
    current = root;
    while (current != NULL)  
    {
      parent = current;
      if (current->info == insertItem) 
      {
        cout << "Item already exist - no duplicates\n\n";
        return;
      }
      else if (current->info > insertItem)
        current = current->leftLink;
      else
        current = current->rightLink;
    }//end while
    if (parent->info > insertItem)
      parent->leftLink = newNode;
    else
      parent->rightLink = newNode;
  }
}//end insert

void BinarySearchTreeType::deleteNode(const int &deleteItem)
{
  NodeType *current; //pointer to traverse the tree
  NodeType *parent; //pointer behind current
  bool found = false;

  if (root == NULL)
    cout << "Cannot delete from an empty tree.\n";
  else   
  {
    current = root;
    parent = root;

    while (current != NULL && !found)  
    {
      if (current->info == deleteItem)
        found = true;
      else   
      {
        parent = current;
        if (current->info > deleteItem)
          current = current->leftLink;
        else 
          current = current->rightLink;
      } //end if-else
    }//end while

    if (current == NULL)
    cout << "The item to be deleted is not in the tree.\n";
    else if (found)
    {
      if (current == root)
        deleteFromTree(root);
      else if (parent->info > deleteItem)
        deleteFromTree(parent->leftLink);
      else 
        deleteFromTree(parent->rightLink);
    }
    else 
      cout << "The item to be deleted is not in the tree."<< endl;
  }
} //end deleteNode


void BinarySearchTreeType::deleteFromTree(NodeType* &p)
{
  NodeType *current; //pointer to traverse the tree
  NodeType *parent;  //pointer behind current
  NodeType *temp;    //pointer to delete the node

  if (p == NULL)
    cout << "Error: The node to be deleted does not exist.\n";
  else if (p->leftLink == NULL && p->rightLink == NULL)
  {  //Leaf node
    temp = p;
    p = NULL;
    delete temp;
  }
  else if (p->leftLink == NULL)   
  {  //Has no left sub-tree
    temp = p;
    p = temp->rightLink;
    delete temp;
  }
  else if (p->rightLink == NULL)  
  { //Has no right sub-tree
    temp = p;
    p = temp->leftLink;
    delete temp;
  }
  else   
  {  //Node has both left and right subtree
    current = p->leftLink;  // go left sub-tree
    parent = NULL;

    while (current->rightLink != NULL) 
    { //then get right most node
      parent = current;
      current = current->rightLink;
    }//end while

    p->info = current->info;  //make copy
    if (parent == NULL) //current did not move;
                          //current == p->lLink; adjust p
      p->leftLink = current->leftLink;
    else
      parent->rightLink = current->leftLink;

    delete current;  //remove this node copied above
  }//end else
} //end deleteFromTree
