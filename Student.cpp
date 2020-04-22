#include "Student.h"

Student::Student(){
  student = 1;
}


Student::~Student(){

}

//returns an integer for each student created
//essentially each student is tracked as a number
//every time a student occurs in the sim
//number inserted into the queue
int Student::getStudent(){
  return student;
}
