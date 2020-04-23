#include <iostream>
#include <fstream>
using namespace std;

class Simulation{
  public:
    Simulation();
    ~Simulation();

    void getValues(string fileName);
    int getWaitTime(int numberOfStudents, int lineNumber);
    void calculateMetrics();

    int numWindowsOpen;
    int timeArrived;
    int numStudents;
    int timePerStudent;

    fstream inFile;
    string fileLine;
    int lineNum;
    int student;
    int windowsOpen;
    int windowsOccupied;
    int waitTime;
    int counter;
    int lineStop;
    int temp;
    int studentsRemaining;

    int avgWaitTime;

};
