#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
class Student{
  public:
   //functions regarding inputs
   Student(const char* first_input, const char* last_input, int ID_input, float GPA_input);
   char* getFirstName();
   void setFirstName(const char* firstname_New);
   char* getLastName();
   void setLastName(const char* lastname_New);
   int getID();
   void setID(int ID_New);
   float getGPA();
   void setGPA(float GPA_New);
   ~Student();
  private:
   //variables for inputs
   float GPA;
   int ID;
   char* first;
   char* last;
};
#endif

