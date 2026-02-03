#include "node.h"
Node::Node(Student* s){
  stu = s;
  next = nullptr;
}
Student* Node::getStudent() const {
  return stu;
}
Node* Node::getNext() const {
  return next;
}
Node::~Node(){
  delete stu;
  next = nullptr;
}
void Node::setNext(Node* nextNode){
  next = nextNode;
}
