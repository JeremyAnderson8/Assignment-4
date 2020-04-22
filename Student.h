#include <iostream>
using namespace std;

class Student{
  public:
    Student();
    ~Student();

    //returns an integer for each student created
    //essentially each student is tracked as a number
    //every time a student occurs in the sim
    //number inserted into the queue
    int getStudent();

    int student;

};
