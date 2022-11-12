#include <iostream>
#include "routeBetweenNodes.h"


namespace cracking {
namespace treesAndGraphs {

void printGraph(Graph& iGraph) {
  std::unordered_map<std::string, std::vector<Graph::Node>>::iterator aIter = iGraph._graph.begin();
  for ( ;aIter != iGraph._graph.end(); aIter++) {
    std::cout << "node " << aIter->first;
    std::vector<Graph::Node>& aListOfChilds = aIter->second;
    std::vector<Graph::Node>::iterator aChildIter = aListOfChilds.begin();
    std::cout << " child: ";
    for (; aChildIter != aListOfChilds.end(); aChildIter++) {
      std::cout <<  aChildIter->value << " ";
    }
    std::cout << std::endl;
  }
}

bool depthFirstSearch(Graph& iGraph, Graph::Node& iNodeA, Graph::Node& iNodeB, std::vector<std::string>& iPath) {
  iNodeA.visited = true;
  if (iNodeA.value == iNodeB.value) {
    return true;
  }

  std::vector<Graph::Node>& aListOfChilds = iGraph._graph.at(iNodeA.value);
  for (auto iter = aListOfChilds.begin(); iter != aListOfChilds.end(); iter++) {
    if (!iter->visited && depthFirstSearch(iGraph, *iter, iNodeB, iPath)) {
      iPath.push_back(iter->value);
      return true;
    }
  }
  return false;
}

std::vector<std::string> routeBetweenNodes(Graph& iGraph, std::string& iNodeA, std::string& iNodeB) {
  std::vector<std::string> aPath;
  Graph::Node sourceNode(iNodeA);
  Graph::Node destinationNode(iNodeB);
  bool aFound = depthFirstSearch(iGraph, sourceNode, destinationNode, aPath);

  if (aFound) {
    aPath.push_back(iNodeA);
  }

  return aPath;
}

}
}