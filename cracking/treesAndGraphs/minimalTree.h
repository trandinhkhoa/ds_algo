#include <vector>
#include <unordered_map>

namespace cracking {
namespace treesAndGraphs {

class BinaryTreeNode {
public:
  class Node {
  public:
    int value;
    std::vector<int> adjacentList;

    bool visited = false;
    int parent;

    Node(int iValue) : value(iValue), visited(false) {};
  };

  std::unordered_map<int, Node> _graph;

  void insert(std::pair<int, std::vector<int>> iPair) {
    Node aNode(iPair.first);
    for (auto iter : iPair.second) {
      aNode.adjacentList.push_back(iter);
    }
    _graph.insert({aNode.value, aNode});

  }

};

BinaryTreeNode minimalTree(std::vector<int>& array);

}
}