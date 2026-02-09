#include <iostream> //my code is using Linked Lists p2 from last project
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <random>
#include "node.h"
#include "student.h"
using namespace std;
const int OGsize = 100;

Node** table;
int tableSize = OGsize;
int nextID = 100000;

//function prototypes(modify later to remove)
int hashFunction(int ID);                  
void addStudent(Student* s);
void addNode(Node* &head, Student* s, int &count);
void printAll();
void printChain(Node* head);
void deleteStudent(int ID);
bool deleteNode(Node* &head, int ID);
void averageGPA();
float averageHelper(Node* head, int &count);
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
    cout << "What is your input(ADD,RANDOM,PRINT,DELETE,AVERAGE,QUIT): ";
    cin >> command;
    if (strcmp(command,"ADD")) {
      char first[50], last[50];
      int ID;
      float GPA;
      cin >> first >> last >> ID >> GPA;
      Student* s = new Student(first, last, ID, GPA);
      addStudent(s);
    }
    else if (strcmp(command,"RANDOM") == 0) {
      int n;
      cout << "How many students would you like to add?" << endl;
      cin >> n;
      for (int i = 0; i < n; i++) {
        addStudent(randomStudent());
      }
    }
    else if (strcmp(command,"PRINT") == 0) {
      printAll();		    
    }
    else if (strcmp(command,"DELETE")) {
      int ID;
      deleteStudent(ID);
    }
    else if (strcmp(command,"AVERAGE")) {
      averageGPA();
    }
    else if (strcmp(command,"QUIT")) {
      cout << "Quitting the program...";
      running = false;
    }
    //delete memory code over here(will do later, def after all other functions are done)
  }
  return 0;
}
//create hashtable
int hashFunction(int ID) {
  return ID % tableSize;
}
//add functions
void addStudent(Student* s) {
  int index = hashFunction(s->getID());
  int count = 0;

  addNode(table[index], s, count);

  if (count > 3) {
    rehash();
  }
}

void addNode(Node* &head, Student* s, int &count) {
  if (head == NULL) {
    head = new Node(s);
    count++;
    return;
  }
  count++;
  Node* next = head->getNext();
  addNode(next, s, count);
  head->setNext(next);
}

//print functions
void printAll() {
  for (int i = 0; i < tableSize; i++) {
    printChain(table[i]);
  }
}

void printChain(Node* head) {
  if (head == NULL) {
    return;
  }
  Student* s = head->getStudent();
  cout << s->getFirstName() << " "
       << s->getLastName() << ", "
       << s->getID() << ", "
       << fixed << setprecision(2) 
       << s->getGPA() << endl;
  printChain(head->getNext());
}

//delete functions
void deleteStudent(int ID) {
  int index = hashFunction(ID);
  deleteNode(table[index], ID);
}

bool deleteNode(Node* &head, int ID) {
 if (head = NULL) {
   return false;
 }

 if (head->getStudent()->getID() == ID) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return true;
  }

 Node* next = head->getNext();
 bool removed = deleteNode(next, ID);
 head->setNext(next);
 return removed;
}

//average functions
void averageGPA() {
  int count = 0;
  float sum = 0;

  for (int i = 0; i < tableSize; i++) {
    sum += averageHelper(table[i], count);
  }

  if (count == 0) {
    cout << "0.00" << endl;
  } else {
    cout << fixed << setprecision(2) << sum / count << endl;
  }
}

float averageHelper(Node* head, int& count) {
  if (head == NULL) {
    return 0;
  }
  count++;
  return head->getStudent()->getGPA() + averageHelper(head->getNext(), count);
}

void rehash() {
  Node** oldTable = table;
  int oldSize = tableSize;

  tableSize *= 2;
  table = new Node*[tableSize];

  for (int i = 0; i < tableSize; i++) {
    table[i] = NULL;
  }

  for (int i = 0; i < oldSize; i++) {
    while (oldTable[i] != NULL) {
      Node* temp = oldTable[i];
      oldTable[i] = oldTable[i]->getNext();
      addStudent(temp->getStudent());
      delete temp;
    }
  }

  delete[] oldTable;
}


//randomizer for selecting students
Student* randomStudent() {
  ifstream firstFile("firstnames.txt"); //use ifstream in order to read data from files, searched up command
  ifstream lastFile("lastnames.txt");
  char first[50], last[50];
  int r1 = rand() % 100;
  int r2 = rand() % 100;
  
  int i = 0;
  while (i <= r1) {
    firstFile >> first;  
    i++;
  }
 
  int j = 0;
  while (j <= r2) {
    lastFile >> last;    
    i++;
  }

  float GPA = (rand() % 401) / 100.0;
  return new Student(first, last, nextID++, GPA);
}
