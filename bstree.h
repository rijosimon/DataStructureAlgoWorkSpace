/* bstree.h
   CS311 Fall 2013
   Header file for HW7
   Group project members:
     Christopher Howard
     Rijo Simon
*/

#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <iostream>
#include <cstdlib>
using std::size_t;
#include <iterator>
using std::iterator;
using std::output_iterator_tag;
#include <vector>
/* #include <algorithm> */
/* using std::copy; */
/* using std::for_each; */
/* #include <functional> */
/* using std::function; */

/* TODO: type requirements */
template <typename T>

/* TODO: class invariants
 */
class BSTree
{
 public:
  BSTree();
  BSTree(const BSTree<T> & original);
  BSTree<T> & operator=(BSTree<T> rhs);
  void insertHead(T const& value);
  ~BSTree();
  int numNodes() const;
  size_t size() const;
  bool empty() const;
  void clear();
  bool retrieve(const T & key) const;
  bool insert(const T & key);
  void preorderTraverse(typename std::vector<T>::iterator output_iterator) const;
  void inorderTraverse(typename std::vector<T>::iterator output_iterator) const;
  void postorderTraverse(typename std::vector<T>::iterator output_iterator) const;

  class Node
  {
	public:
    T key;
    Node * left;
    Node * right;
    Node(const T & key);
	std::size_t numNodes() const;
    ~Node();
  };
  
  private:
  Node * _head;
  size_t _size;
};

/* Node constructor
   Will set the new node key to the key provided, and set the left and right
   pointers to null value.
 */
 
template <typename T>
BSTree<T>::Node::Node(const T & key) : key(key), left(NULL), right(NULL)
{}

/* Node destructor
   Recursively deletes itself and any child Nodes. You will first need to
   disconnect child nodes if you do not want them deleted.
*/
template <typename T>
BSTree<T>::Node::~Node()
{
  if(left)
    (*left).~Node();
  if(right)
    (*right).~Node();
}

/*
  Default constructor
  Pre-conditions: None.
  Post-conditions: Constructs an empty BSTree.
 */
template <typename T>
BSTree<T>::BSTree() : _head(0), _size(0) {}

template <typename T>
void BSTree<T>::insertHead(T const& value)
{
	Node* newHead = new Node(value);
	newHead->left = _head;
	_head = newHead;
}

/* Copy constructor
   Pre-conditions: None.
   Post-conditions: Performs deep copy (completely separate data).
*/
template <typename T>
BSTree<T>::BSTree(const BSTree<T> & original): _head(0)
{
  std::vector<Node const*> remaining;
  Node const* cur = original._head;
  while(cur)
  {
	insertHead(cur->key);
	if(cur->right){
		remaining.push_back(cur->right);
	}
	if(cur->left){
		cur = cur->left;
	}
	else if(remaining.empty()){
		break;
	}
	else{
		cur = remaining.back();
		remaining.pop_back();
	}
  }
}

/* Copy assignment operator
   Pre-conditions: None.
   Post-conditions: Turns lhs into a deep copy of rhs.
*/
template <typename T>
BSTree<T> & BSTree<T>::operator=(BSTree<T> rhs)
{
  /* TODO: create swap function and uncomment below */
  /* swap(rhs); */
  return *this;
}

/* Class destructor */
template <typename T>
BSTree<T>::~BSTree()
{
  std::vector<Node*> remaining;
  Node* cur = _head;
  while(cur){
	Node* left = cur->left;
	if (cur->right) {
        remaining.push_back(cur->right);
      }
      delete cur;
      if (left) {
        cur = left;
      }
      else if (remaining.empty()) {
        break;
      }
      else {
        cur = remaining.back();
        remaining.pop_back();
      }
  }
}

template <typename T>
std::size_t BSTree<T>::Node::numNodes() const {
   std::size_t size = 1;

   if (left != NULL) size += left->numNodes();
   if (right != NULL) size += right->numNodes();

   return size;
}


/* Pre-conditions: None.
   Post-conditions: Returns number of keys stored in the tree.
*/
template <typename T>
size_t BSTree<T>::size() const
{
	if(_head!=NULL)
	{
		return _head->numNodes();
	}
	else{
		return 0;
	}
}

/* Pre-conditions: None.
   Post-conditions:
   - Returns true iff the size of the tree is zero.
   - Is constant time.
*/
template <typename T>
bool BSTree<T>::empty() const
{
  return (_head == NULL);
}

/* Pre-conditions: None.
   Post-conditions: Removes all keys from the tree, resulting in an empty tree.
*/
template <typename T>
void BSTree<T>::clear()
{
  /* TODO: implement this */
}

/* Pre-conditions: None.
   Post-conditions:
   Returns true iff a key equivalent to the given key is in tree.
*/
template <typename T>
bool BSTree<T>::retrieve(const T & key) const
{
  /* TODO: implement this */
  return false;
}

/* Pre-conditions: None.
   Post-conditions:
   - If key equivalent to the given key is in the tree already, returns false,
     leaving the tree unchanged.
   - Otherwise, inserts the key into the tree and return true.
*/
template <typename T>
bool BSTree<T>::insert(const T & key)
{
  /* TODO: implement this */
  return false;
}

/* Pre-conditions: Provide a valid output iterator.
   Post-conditions:
   - Does “ *output_iterator++ = key;” for each key in the tree
   - Performs preorder traversal of the tree
*/
template <typename T>
void BSTree<T>::preorderTraverse(typename std::vector<T>::iterator output_iterator) const
{
  /* TODO: implement this */
}

/* Pre-conditions: Provide a valid output iterator.
   Post-conditions:
   - Does “ *output_iterator++ = key;” for each key in the tree
   - Performs inorder traversal of the tree
*/
template <typename T>
void BSTree<T>::inorderTraverse(typename std::vector<T>::iterator output_iterator) const
{
  /* TODO: implement this */
}

/* Pre-conditions: Provide a valid output iterator.
   Post-conditions:
   - Does “ *output_iterator++ = key;” for each key in the tree
   - Performs postorder traversal of the tree
*/
template <typename T>
void BSTree<T>::postorderTraverse(typename std::vector<T>::iterator output_iterator) const
{
  /* TODO: implement this */
}

#endif /* _BSTREE_H_ */
