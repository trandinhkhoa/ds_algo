#include "minimalTree.h"
#include <iostream>

namespace {

int build(cracking::treesAndGraphs::BinaryTreeNode& iGraph, std::vector<int>& array, size_t iBegin, size_t iEnd) {
  size_t middleIndex = iBegin + (iEnd-iBegin+1)/2;
  int aRoot = array[middleIndex];
  if (iEnd == iBegin) {
    iGraph.insert({aRoot, {}});
    return aRoot;
  }

  std::vector<int> aChildList;
  if (iBegin <= middleIndex - 1) {
    int aLeftChild = build(iGraph, array, iBegin, middleIndex - 1);
    aChildList.push_back(aLeftChild);
  }
  if (middleIndex + 1 <= iEnd) {
    int aRightChild = build(iGraph, array, middleIndex+1, iEnd);
    aChildList.push_back(aRightChild);
  }

  iGraph.insert({aRoot, aChildList});
  return aRoot;
}

void printGraph(cracking::treesAndGraphs::BinaryTreeNode& iGraph) {
  std::unordered_map<int, cracking::treesAndGraphs::BinaryTreeNode::Node>::iterator aIter = iGraph._graph.begin();
  for ( auto aIter : iGraph._graph) {
    std::cout << "node " << aIter.first;
    std::cout << " child: ";
    for (int aChildIter : aIter.second.adjacentList) {
      std::cout <<  aChildIter << " ";
    }
    std::cout << std::endl;
  }
}

}

namespace cracking {
namespace treesAndGraphs {

BinaryTreeNode minimalTree(std::vector<int>& array) {
  cracking::treesAndGraphs::BinaryTreeNode aGraph;
  build(aGraph, array, 0, array.size() - 1);

  return aGraph;
}

}
}