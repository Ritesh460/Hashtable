#ifndef NODE_H
#define NODE_H
#include "student.h"
class Node{
 private:
  Node* next;//pointer to next node in list
  Student* stu;//pointer to data aka the student
 public:
  Node(Student* s);
  Student* getStudent() const;
  Node* getNext() const;
  ~Node();
  void setNext(Node* nextNode);
};
#endif

