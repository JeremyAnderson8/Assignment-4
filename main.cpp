#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char** argv)
{
    DoublyLinkedList *myList = new DoublyLinkedList();

    myList->insertFront(10);
    myList->insertFront(11);
    myList->insertFront(12);
    myList->printList();

return 0;
};
