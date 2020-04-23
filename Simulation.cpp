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
          Student *s = new Student();
          student = s->getStudent();
          studentLine->insert(student);
        }

        cout << "" << endl;
        cout << "Students in Line: " << studentLine->getSize() << endl;
        cout << "Number of Windows Open: " << numWindowsOpen << endl;
        timePerStudent = getWaitTime(numStudents, lineNum);
        cout << "Time Needed For Each Student: " << timePerStudent << endl;

        if(numWindowsOpen >= numStudents){
          cout << "" << endl;
          //Students going to window
          for(int i = 1; i <= numStudents; i++){
             cout << "Student " << i << " Going To Window" << endl;
             numWindowsOpen--;
             cout << "Number of Windows Open: " << numWindowsOpen << endl;
             cout << "" << endl;
          }
          //ticks
          for(int i = timeArrived; i <= timePerStudent; i++){
            cout << "Time " << i << endl;
          }
          //students leaving window
          for(int i = 1; i <= numStudents; i++){
             cout << "" << endl;
             cout << "Student " << i << " Leaving Window" << endl;
             numWindowsOpen++;
             cout << "Number of Windows Open: " << numWindowsOpen << endl;
             studentLine->remove();
             cout << "" << endl;
             cout << "Students In Line: " << studentLine->getSize() << endl;
          }
        }
        else if(numWindowsOpen < numStudents){
          temp = numWindowsOpen;
          studentsRemaining = numStudents - temp;
          cout << "" << endl;
          //Students going to window
          for(int i = 1; i <= numStudents; i++){
             cout << "Student " << i << " Going To Window" << endl;
             numWindowsOpen--;
             cout << "Number of Windows Open: " << numWindowsOpen << endl;
             cout << "" << endl;
             if(i == temp){
               cout << "All Windows Occupied" << endl;
               cout << "Number Of Students Waiting: " << studentsRemaining << endl;
               cout << "" << endl;
               break;
             }
          }
          for(int i = timeArrived; i <= timePerStudent; i++){
            cout << "Time " << i << endl;
          }

          for(int i = 1; i <= temp; i++){
            cout << "" << endl;
            cout << "Student " << i << " Leaving Window" << endl;
            numWindowsOpen++;
            studentLine->remove();
          }
          cout << "" << endl;
          cout << "Number Of Windows Open: " << numWindowsOpen << endl;

          for(int i = 1; i <= studentsRemaining; i++){
            cout << "" << endl;
            cout << "Student " << i + temp << " Going To Window" << endl;
            numWindowsOpen--;
          }

          cout << "" << endl;
          cout << "Number Of Windows Open: " << numWindowsOpen << endl;
          cout << "" << endl;

          for(int i = timeArrived; i <= timePerStudent; i++){
            cout << "Time " << i << endl;
          }

          for(int i = 1; i <= studentsRemaining; i++){
            cout << "" << endl;
            cout << "Student " << i + temp << " Leaving Window " << endl;
            numWindowsOpen++;
            studentLine->remove();
          }

          cout << "" << endl;
          cout << "Number Of Windows Open: " << numWindowsOpen << endl;
          cout << "Students In Line: " << studentLine->getSize() << endl;

        }

        cout << "" << endl;
        cout << "Simulation Completed" << endl;
        calculateMetrics();

        lineNum++;
        continue;
      }
    }
  }
}

int Simulation::getWaitTime(int numberOfStudents, int lineNumber){
  counter = 1;
  lineStop = numberOfStudents;
  while(getline(inFile, fileLine)){
    if(counter = lineStop){
      waitTime = stoi(fileLine);
      break;
    }
    else{
      counter++;
    }
  }
  return waitTime;
}

void Simulation::calculateMetrics(){
  cout << "" << endl;
  cout << "Calclated Metrics: " << endl;
  avgWaitTime = numStudents / timePerStudent;
  cout << "Average Wait Time: " << avgWaitTime << endl;
}
