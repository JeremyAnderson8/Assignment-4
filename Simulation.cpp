#include "Simulation.h"
#include "Student.h"
#include "GenQueue.h"
using namespace std;

Simulation::Simulation(){

}

Simulation::~Simulation(){

}

//tracks students in registrar line
GenQueue *studentLine = new GenQueue();

void Simulation::getValues(string fileName){
  inFile.open(fileName);

  lineNum = 1;

  if(inFile.fail())
  {
    cerr << "Error Opening File" << endl;
    exit(1);
  }

  else{
    while(getline(inFile, fileLine)){
      //gets the number of windows open
      if(lineNum == 1){
        numWindowsOpen = stoi(fileLine);
        lineNum++;
        continue;
      }
      //gets the time
      else if(lineNum == 2){
        timeArrived = stoi(fileLine);
        lineNum++;
        continue;
      }
      //gets the number of students
      else if(lineNum == 3){
        numStudents = stoi(fileLine);
        for(int i = 1; i <= numStudents; i++){
          lineNum = 3;
          lineNum += i;
          Student *s = new Student();
          student = s->getStudent();
          studentLine->insert(student);
        }

        cout << "" << endl;
        cout << "Time " << timeArrived << endl;
        cout << "Number of Students Getting in Line: " << studentLine->getSize() << endl;

        if(numWindowsOpen >= numStudents){
          cout << "Number of Windows Open: " << numWindowsOpen << endl;
          cout << "" << endl;
          for(int i = 1; i <= numStudents; i++){
             cout << "Student " << i << " Going To Window" << endl;
             numWindowsOpen--;
             cout << "Number of Windows Open: " << numWindowsOpen << endl;
             cout << "" << endl;
          }
        }
        break;
      }
    }
  }
}
