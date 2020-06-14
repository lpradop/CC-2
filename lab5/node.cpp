#include "node.hpp"
Node::Node(int elem, Node *next) : elem_(elem), next_(next) {}
Node::~Node() {}