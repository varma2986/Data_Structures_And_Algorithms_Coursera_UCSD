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

void isBSTUtil(const vector<Node>& tree, int i, bool& flag, long min, long max)
{
	if (i == -1)
	{
		return;
	}
	if (tree[i].key < min || tree[i].key >= max)
	{
		flag = false;
		return;
	}

	isBSTUtil(tree, tree[i].left, flag, min, tree[i].key);

	isBSTUtil(tree, tree[i].right, flag, tree[i].key, max);
}
bool IsBinarySearchTree(const vector<Node>& tree) {
	// Implement correct algorithm here
	bool flag = true;
	long min = LONG_MIN, max = LONG_MAX;
	if (tree.size() <= 1)
		return flag;
	isBSTUtil(tree, 0, flag, min, max);
	return flag;
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
