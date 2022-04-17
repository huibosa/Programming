#pragma once

#include <initializer_list>
#include <string>

class TreeNode {
public:
  TreeNode()
      : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
  TreeNode(const TreeNode &rhs)
      : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
  TreeNode &operator=(const TreeNode &);
  ~TreeNode();
private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};

class BinStrTree {
public:
  BinStrTree(): root(nullptr) {}
  BinStrTree(BinStrTree &rhs) : root(rhs.root) {}
  BinStrTree &operator=(const BinStrTree &rhs);
  ~BinStrTree() { delete root; }
private:
  TreeNode *root;
};
