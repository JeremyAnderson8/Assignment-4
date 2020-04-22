#include <iostream>
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv)
{
  string fileName = "";
  cout << "Enter File Name: " << endl;
  cin >> fileName;

  Simulation *newSimulation = new Simulation();
  newSimulation->getValues(fileName);
  return 0;
};
