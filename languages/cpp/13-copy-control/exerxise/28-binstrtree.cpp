#include "28_BinStrTree.h"

TreeNode& TreeNode::operator=(const TreeNode & rhs) {
  ++(*rhs.count);
  if (--(*count) == 0) {
    delete count;
    delete left;
    delete right;
  }

  value = rhs.value;
  count = rhs.count;
  left = rhs.left;
  right = rhs.right;

  return *this;
}

TreeNode::~TreeNode() {
  if (--(*count) == 0) {
    delete count;
    delete left;
    delete right;
  }
}

BinStrTree& BinStrTree::operator=(const BinStrTree &rhs) {
  auto temp = new TreeNode(*rhs.root);
  delete root;
  root = temp;

  return *this;
}
