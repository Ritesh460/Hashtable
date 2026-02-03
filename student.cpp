#include <iostream>
#include <cstring>
#include "student.h"
//all inputs
Student::Student(const char* first_input, const char* last_input, int ID_input, float GPA_input) {
  first = new char[strlen(first_input)+1];
  strcpy(first, first_input);
  last = new char[strlen(last_input)+1];
  strcpy(last, last_input);
  ID = ID_input;
  GPA = GPA_input;
}
//first name get and set
char* Student::getFirstName() {
  return first;
}

void Student::setFirstName(const char* firstname_New) {
  delete[] first;
  first = new char[strlen(firstname_New)+1];
  strcpy(first, firstname_New);
}
//last name get and set
char* Student::getLastName() {
  return last;
}

void Student::setLastName(const char* lastname_New) {
  delete[] last;
  last = new char[strlen(lastname_New)+1];
  strcpy(last, lastname_New);
}
//ID get and set
int Student::getID() {
  return ID;
}

void Student::setID(int ID_New) {
  ID = ID_New;
}
//GPA get and set
float Student::getGPA() {
  return GPA;
}

void Student::setGPA(float GPA_New) {
  GPA = GPA_New;
}
//destructor
Student::~Student() {
  delete[] first;
  delete[] last;
}


                        
