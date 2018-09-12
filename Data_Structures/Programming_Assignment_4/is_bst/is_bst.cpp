#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};


bool isBSTUtil(vector<Node> &tree, int i, long min, long max)
{
	/* an empty tree is BST */
	if (i == -1)
		return true;

	/* false if this node violates the min/max constraint */
	if (tree[i].key <= min || tree[i].key >= max)
		return false;

	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return
		isBSTUtil(tree, tree[i].left, min, tree[i].key) &&  // Allow only distinct values
		isBSTUtil(tree, tree[i].right, tree[i].key, max);  // Allow only distinct values
}


bool IsBinarySearchTree(vector<Node>& tree)
{
	long min = LONG_MIN;
	long max = LONG_MAX;
	if (tree.size() == 0)
		return true;
	return isBSTUtil(tree, 0, min, max);
}



int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
