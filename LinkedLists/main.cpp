#include <iostream>
//#include "Node.h"
#include "linkedList.h"

using namespace std;

int main() {
  //Node<int> test = Node<int>(45);
  //cout << test.getNext() << endl;
  //cout << test.getData() << endl;

  linkedList<int> list = linkedList<int>(45);
  cout << list.getData() << endl;
  return 0;
}
