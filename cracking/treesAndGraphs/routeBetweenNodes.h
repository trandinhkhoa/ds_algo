#include <unordered_map>
#include <vector>
#include <string>

namespace cracking {
namespace treesAndGraphs {

class Graph {
public:
  class Node {
  public:
    std::string value;
    bool visited = false;
    Node(std::string& iValue) : value(iValue), visited(false) {};
  };
  std::unordered_map<std::string, std::vector<Node>> _graph;

  void insert(std::pair<std::string, std::vector<std::string>> iPair) {
    std::vector<Node> aListOfChildNodes;
    for (auto iter = iPair.second.begin(); iter != iPair.second.end(); iter++) {
      aListOfChildNodes.push_back(*iter);
      // aListOfChildNodes.push_back(Graph::Node(*iter));
    }
    _graph.insert({iPair.first, aListOfChildNodes});
    // _graph.insert(std::make_pair<std::string, std::vector<Node>>(iPair.first, aListOfChildNodes));
    // _graph.insert(std::make_pair(iPair.first, aListOfChildNodes));

  }

};

std::vector<std::string> routeBetweenNodes(Graph& iGraph, std::string& iNodeA, std::string& iNodeB);

}
}