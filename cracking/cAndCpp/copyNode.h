

namespace cracking {

namespace cAndCpp {

// Note: dont use anonymous namespace in header file
// https://stackoverflow.com/questions/357564/uses-for-anonymous-namespaces-in-header-files
namespace copyNodeHelper {
class Node {
public:
  Node* _ptr1;
  Node* _ptr2;
  int value;
  // https://stackoverflow.com/questions/50379663/why-i-get-null-is-undefined-error
  Node(int x, Node* ptr1 = nullptr, Node* ptr2 = nullptr);
};
}

copyNodeHelper::Node* copyNode(copyNodeHelper::Node* root);

}

}
