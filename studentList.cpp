//C++ Programming: Student List Project
//by Akhil Baidya

//Date of Submission (mm/dd/yy): 10/16/23

/* Notes: In this program, the user will be able to edit a list of students.
The user can input the commands "ADD," "DELETE," "PRINT" and "QUIT." QUIT
exits the program.

   1. ADD registers a new student in the list. The user inputs the student's names,
   id, and gpa (the id and gpa must be inputted as numbers).

   2. DELETE removes a student from the student list. The user must input a student
   id to identify this student to be removed.

   3. PRINT displays all the students currently registered in the student list and their info.
 */


/* Credits: 

1. In order to understand the syntax of creating vectors and passing them in by reference in function prototypes and functions, Mr. Galbraith's video on Vectors in Canvas was observed: https://www.youtube.com/watch?v=KD_pItB8Ygg&t=1s (video url).

The same video was also referred to in order to understand how to deference pointers (with (*pointerName)) and access aspects of the object the pointer is pointed towards using "->."

The same video was also used to write the iterator when printing out the students in the student vector in the PRINT function.


2. Referred to cplusplus.com (https://cplusplus.com/reference/cctype/toupper/) to find toupper() command which was used to standardize user command inputs (such as "PRINT" or "pRinT") to upper case.


3.Referred to GeeksforGeeks website for learning how to delete objects in a vector (with the .erase() command):https://www.geeksforgeeks.org/cpp-stl-cheat-sheet/#T3

This source shows how the .erase() command takes the position of an object in a vector and deletes the object at that position. The source also shows how the beginning position (of the first element in the vector) can be accessed through vectorName.begin())
 */


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

    for (int i = 0; i < strlen(input); i++) {
      input[i] = toupper(input[i]); //referred to https://cplusplus.com/reference/cctype/toupper/ for toupper() command
    }
    
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

    cout.setf(ios::showpoint); //want trailing zeroes in gpa (5 as 5.00)
    cout.precision(3); //(restrict precision to three, allowing two decimal places fo gpa)
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
  int position = -1; //the position of the student needed to be deleted
 
  cout << "Which student do you want to remove from the student list? (Give ID)" << endl;
  cin >> rmID; //get the id of the student we want to remove


    for (vector<Student*>::iterator student = studVec.begin(); student != studVec.end(); student++) { //iterate through each student in the vector

    ++count; //increase the count (creates a "number" for each students position from studVec.begin()

    if (((*student) -> id) == rmID) { //if the student's id is equal to the id being searched for..
      position = count; //this is the position of the student we want removed!
    }
  }

    if (position != -1) { //if there is a student (position) with that id
      studVec.erase(studVec.begin() + position - 1); //delete student
      cout << "removed student" << endl;
    }

    else {
      cout << "student not found" << endl;
    }
  
  return;
}
