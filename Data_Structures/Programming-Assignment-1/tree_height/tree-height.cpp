#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
    
};

int HeightTreeSimple(Node *NodeHT) {
  int max = 0;
  //if(NodeHT == NULL) return 0;
  /*if(NodeHT->children.size() == 0) {
    return 0;
  }*/
 // std::cout<<" For node children size is " <<NodeHT->children.size() << "\n";
  //std::cout<<" Key is " << (*NodeHT).key << "\n";
  for(int i=0; i < NodeHT->children.size(); i++) {
    int height_this_node = HeightTreeSimple(NodeHT->children[i]);
    if(height_this_node > max)
      max = height_this_node;
  }
  return 1+max;

}

/*int HeightTree(std::vector<Node> nodes, int root_node_key) {
  //Node *Childnodes;
  std::vector<Node *> ChildNodes = nodes[root_node_key].children;
  std::cout << "root_node_key is " << root_node_key << " Children count is " << ChildNodes.size() << "\n";
  
  
  //int child1_node_key =  *(ChildNodes[0]);
  //std::cout << "ChildNode[0] address is " << ChildNodes[0];
  //std::cout << "ChildNode[0] is " << *(ChildNodes[0]).key;
  //Node Child0;
  //Child0 = &ChildNodes[0];
  //int child0_node_key;
  //child0_node_key = *Child0.key;
 
  for(int i = 0; i < 5; i++) {
    std::cout << "node key is " << i << " childrencount is " <<nodes[i].children.size() << "\n";
  } 
  if(ChildNodes.size() == 0) {
    return 0;
  }
  return 0;
  if(ChildNodes.size() == 1) {
    int child_node_key = ChildNodes.key;
  }
  if(nodes[root_node_key].children.size() == 0) {
    return 0;
  }
  if(nodes[root_node_key].children.size() == 1) {
    //std::vector<Node *> children_key;
    return (1 + HeightTree(nodes, nodes[root_node_key].children[0]));
    children_key = nodes[root_node_key].children;
    int child_key = children_key;
    return (1 + max(HeightTree(nodes, children_key[0]),0));
  }
  if(nodes[root_node_key].children.size() == 2) {
    std::vector<Node *> children_key;
    children_key = nodes[root_node_key].children;
    return (1 + max((HeightTree(nodes, children_key[1]), HeightTree(nodes, children_key[0]))));
  }
}*/


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  //std::vector<Node> root_node;
  int root_node_key;
  Node *root_node_key_pointer;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    else
      root_node_key = child_index;
    nodes[child_index].key = child_index;
  }
  root_node_key_pointer = &nodes[root_node_key];

  std::cout << HeightTreeSimple(root_node_key_pointer) << std::endl;
  return 0;
  //return HeightTreeSimple(nodes, root_node_key);
  //return HeightTreeSimple(root_node_key_pointer);
}


int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
