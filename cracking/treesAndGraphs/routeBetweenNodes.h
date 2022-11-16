#include <unordered_map>
#include <vector>
#include <string>

namespace cracking {
namespace treesAndGraphs {

enum traversalStrategy {depthFirst, breadthFirst};

class Graph {
public:
  class Node {
  public:
    std::string value;
    std::vector<std::string> adjacentList;

    bool visited = false;
    std::string parent;

    Node(std::string& iValue) : value(iValue), visited(false) {};
  };

  std::unordered_map<std::string, Node> _graph;

  void insert(std::pair<std::string, std::vector<std::string>> iPair) {
    Node aNode(iPair.first);
    for (auto iter : iPair.second) {
      aNode.adjacentList.push_back(iter);
    }
    _graph.insert({aNode.value, aNode});

  }

};

std::vector<std::string> routeBetweenNodes(const Graph& iGraph, std::string& iSourceNode, std::string& iDestinationNode, traversalStrategy strategy);

}
}