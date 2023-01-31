#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr first;

  first.push_front("738");
  cout << first.get(0) << endl;
  cout << "SIZE: " << first.size() << endl;
  cout << "NODES: " << first.numNodes() << endl;

  first.pop_back();
  //cout << first.get(0) << endl;
  cout << "SIZE: " << first.size() << endl;
  cout << "NODES: " << first.numNodes() << endl;
}
