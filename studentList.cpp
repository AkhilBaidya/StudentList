//C++ Programming: Student List Project
//by Akhil Baidya

#include <iostream>
using namespace std;

//DEFINING STRUCTS:

struct Student {

  char firstName[20]; //Struct code based on Mr. Galbraith's video on Structs in Canvas
  char secondName[20];
  int id;
  float gpa; //a Student has a first name, last name, id, and gpa 
}


//FUNCTION PROTOTYPES:

void ADD(&vector<Student*> newStudVec);
void PRINT(&vector<Student*> newStudVec);
void DELETE(&vector<Student*> newStudVec);
  

//MAIN FUNCTION:

int main() {
  bool running = true;
  
  vector<Student*> studVec;


  while (running) {


  }
  

  return 0;
}

//OTHER FUNCTIONS IMPLEMENTED IN MAIN FUNCTION:

void ADD(&vector<Student*> newStudVec) {

}

void PRINT(&vector<Student*> newStudVec) {

}

void DELETE(&vector<Student*> newStudVec) {

}
