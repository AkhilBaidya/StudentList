//C++ Programming: Student List Project
//by Akhil Baidya

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//DEFINING STRUCTS:

struct Student {

  char firstName[20]; //Struct code based on Mr. Galbraith's video on Structs in Canvas
  char secondName[20];
  int id;
  float gpa; //a Student has a first name, last name, id, and gpa 
};


//FUNCTION PROTOTYPES: referred to Mr. Galbraith's videos for understanding how to write vectors and pass them by reference

void ADD(vector<Student*> &);
void PRINT(vector<Student*> &);
void DELETE(vector<Student*> &);
  

//MAIN FUNCTION:

int main() {
  bool running = true;
  vector<Student*> studVec;
  char input[7];

  while (running) {
    cin >> input;
    if (!strcmp(input, "QUIT")) { //if the character array spells out "QUIT"...
      cout << "quitting" << endl;
      running = false; //quit the program!
     }
  }
  
  return 0;
}

//OTHER FUNCTIONS IMPLEMENTED IN MAIN FUNCTION:

void ADD(vector<Student*> &studVec) {

}

void PRINT(vector<Student*> &studVec) {

}

void DELETE(vector<Student*> &studVec) {

}
