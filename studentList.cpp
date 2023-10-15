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
  int numStudents = 0;

  while (running) {
    cout << "What would you like to do? (ADD, DELETE, PRINT Students)" << endl;
    cin >> input;

    if (!strcmp(input, "QUIT")) { //if the character array spells out "QUIT"...
      cout << "quitting student list program" << endl;
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

  char firstN[20];
  char lastN[20];
  int ID;
  float GPA;
  Student* stuPnt = new Student; //create a new pointer to a new Struct
  
  //ask for new student details
  cout << "what is the first name of the student?" << endl;
  cin >> firstN;
  strcpy((*stuPnt).firstName, firstN); //need to dereference pointer to set variables in new Struct to inputs

  cout << "last name?" << endl;
  cin >> lastN;
  strcpy((*stuPnt).secondName, lastN);

  cout << "id?" << endl;
  cin >> ID;
  (*stuPnt).id = ID;

  cout << "GPA?" << endl;
  cin >> GPA;
  (*stuPnt).gpa = GPA;

  studVec.push_back(stuPnt); //puts new pointer in the vector of pointers
  cout << "added student" << endl;
  return;
}

void PRINT(vector<Student*> &studVec) {

  for (vector<Student*>::iterator student = studVec.begin(); student != studVec.end(); student++) { //iterate through each student in the vector

    cout << "Students:" << endl;

    cout << (*student) -> firstName << " "; //print out the first and last name of the student
    cout << (*student) -> secondName << ", ";

    cout << "ID: " << (*student) -> id << ", "; //print out the student's id
    cout << "GPA: " << (*student) -> gpa << endl; //print out the student's gpa
    
  }
  return;

}

void DELETE(vector<Student*> &studVec) {
  //referred to this source for how to delete objects in a vector (with the .erase() command:

  //https://www.geeksforgeeks.org/cpp-stl-cheat-sheet/#T3

  /*This source shows how the .erase() command takes the position of an object
    in a vector and deletes the object at that position.

    The source also shows how the beginning position (of the first element
    in the vector) can be accessed through vectorName.begin())
   */
  
  int rmID;
  int count = 0; //counts the distance each "student" is away from the beginning
  int position; //the position of the student needed to be deleted
 
  cout << "Which student do you want to remove from the student list? (Give ID)" << endl;
  cin >> rmID; //get the id of the student we want to remove


    for (vector<Student*>::iterator student = studVec.begin(); student != studVec.end(); student++) { //iterate through each student in the vector

    ++count; //increase the count (creates a "number" for each students position from studVec.begin()

    if (((*student) -> id) == rmID) { //if the student's id is equal to the id being searched for..
      position = count; //this is the position of the student we want removed!
    }
  }
  
  studVec.erase(studVec.begin() + position - 1); //delete student
  cout << "removed student" << endl;
  
  return;
}
