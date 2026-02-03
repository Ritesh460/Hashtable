#include <iostream>
#include <iomanip>
#include <cstring>
#include <random>
#include "student.h"
using namespace std;

const int OGsize = 100;

Node** table;
int tableSize = OGsize;
int nextID = 100000;

//function prototypes(modify later to remove)
int hashFunction(int ID);
void addStudent(Student* s);
void addNode(Node*& head, Student* s, int& count);
void printAll();
void printChain(Node* head);
void deleteStudent(int ID);
bool deleteNode(Node*& head, int ID);
void averageGPA();
float averageHelper(Node* head, int& count);
void rehash();
Student* randomStudent();

int main () {
  srand(time(NULL));
  table = new Node*[tableSize];
  for (int i = 0; i < tableSize; i++) {
    table[i] = NULL;
  }
  char command[20];
  bool running = true;
  while (running) {
    if (strcmp(command,"ADD")) {
     //addStudent and addNode functions called
    }
    else if (strcmp(command,"PRINT") {
     //printALL and printChain functions called		    
    }
    else if (strcmp(command,"DELETE") {
     //deleteStudent and deleteNode functions called
    }
    else if (strcmp(command,"AVERAGE") {
     //averageGPA and averageHelper functions called
    }
    else if(strcmp(command,"QUIT") {
      cout << "Quitting the program...";
      running = false;
    }
    //delete memory code over here(will do later, def after all other functions are done)
  }
  return 0;
}
//randomizer for selecting students
Student* randomStudent() {
  ifstream firstFile("firstnames.txt");
  ifstream lastFile("lastnames.txt");
  char first[50], last[50];
  int r1 = rand() % 100;
  int r2 = rand() % 100;
  
  int i = 0;
  while (i <= r1) {
    firstFile >> first;  
    i++;
  }

  i = 0;
  while (i <= r2) {
    lastFile >> last;    
    i++;
  }

  float GPA = (rand() % 401) / 100.0;
  return new Student(first, last, nextID++, GPA);
}
