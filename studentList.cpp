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

    else if (!strcmp(input, "ADD")) { //if the character array spells out "ADD"...
      ADD(studVec);
    }

    else if (!strcmp(input, "DELETE")) { //if the character array spells out "DELETE"...
      DELETE(studVec);
    }
    
    else if (!strcmp(input, "PRINT")) { //if the character array spells out "PRINT"...
      PRINT(studVec);
    }    
  }
  
  return 0;
}

//OTHER FUNCTIONS IMPLEMENTED IN MAIN FUNCTION:

void ADD(vector<Student*> &studVec) {

  //ask for new student details
  cout << "what is the first name of the student?" << endl;
  cin >> new char firstN[20];

  cout << "last name?" << endl;
  cin >> new char lastN[20];

  cout << "id?" << endl;
  cin >> new int ID;

  cout << "GPA?" << endl;
  cin >> new float GPA;

  //make new struct of that student with those specific details
  Student newStudent;
  newStudent.firstName = firstN;
  newStudent.lastName = lastN;
  newStudent.id = ID;
  newStudent.gpa = GPA;

  
  
}

void PRINT(vector<Student*> &studVec) {

}

void DELETE(vector<Student*> &studVec) {

}
