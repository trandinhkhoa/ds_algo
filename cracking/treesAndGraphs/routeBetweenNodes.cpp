#include <iostream>
#include <deque>
#include "routeBetweenNodes.h"


namespace cracking {
namespace treesAndGraphs {

void printGraph(Graph& iGraph) {
  std::unordered_map<std::string, Graph::Node>::iterator aIter = iGraph._graph.begin();
  for ( auto aIter : iGraph._graph) {
    std::cout << "node " << aIter.first;
    std::cout << " child: ";
    for (std::string aChildIter : aIter.second.adjacentList) {
      std::cout <<  aChildIter << " ";
    }
    std::cout << std::endl;
  }
}

bool depthFirstSearch(Graph& iGraph, std::string& iNodeA, std::string& iNodeB, std::vector<std::string>& iPath) {
  iGraph._graph.at(iNodeA).visited = true;
  if (iNodeA == iNodeB) {
    return true;
  }

  std::vector<std::string>& aListOfChilds = iGraph._graph.at(iNodeA).adjacentList;
  for (auto iter : aListOfChilds) {
    if (!iGraph._graph.at(iter).visited && depthFirstSearch(iGraph, iter, iNodeB, iPath)) {
      iPath.push_back(iter);
      return true;
    }
  }
  return false;
}

void backTrace(Graph& iGraph, std::string& iSource, std::string& iNode, std::vector<std::string>& iPath) {
  while (iNode != iSource) {
    iPath.push_back(iNode);
    iNode = iGraph._graph.at(iNode).parent;
  }
}

bool breadthFirstSearch(Graph& iGraph, std::string& iSource, std::string& iDestination, std::vector<std::string>& iPath) {
  bool found = false;
  std::deque<std::string> aQueue;
  aQueue.push_back(iSource);
  while (!aQueue.empty()) {
    std::string node = aQueue.front();
    aQueue.pop_front();

    if (node == iDestination) {
      found = true;
      backTrace(iGraph, iSource, node, iPath);
      break;
    } else {
      std::vector<std::string>& aListOfChilds = iGraph._graph.at(node).adjacentList;
      for (std::string child : aListOfChilds) {
        if (!iGraph._graph.at(child).visited) {
          iGraph._graph.at(child).visited = true;
          iGraph._graph.at(child).parent = node;
          aQueue.push_back(child);
        }
      }
    }
  }

  return found;
}

std::vector<std::string> routeBetweenNodes(const Graph& iGraph, std::string& iSourceNode, std::string& iDestinationNode, traversalStrategy strategy ) {
  std::vector<std::string> aPath;
  Graph workGraph;
  workGraph._graph = iGraph._graph;

  bool aFound = false;

  switch (strategy) {
    case depthFirst:
      aFound = depthFirstSearch(workGraph, iSourceNode, iDestinationNode, aPath);
      break;
    case breadthFirst:
      aFound = breadthFirstSearch(workGraph, iSourceNode, iDestinationNode, aPath);
      break;
  }

  if (aFound) {
    aPath.push_back(iSourceNode);
  }

  return aPath;
}

}
}