#include <iostream>
#include "ListNode.h"
using namespace std;


class DoublyLinkedList{
  private:
    ListNode *front;
    ListNode *back;
    unsigned int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(int data);
    void insertBack(int data);
    int removeFront();
    int removeBack();
    int search (int val);
    int removeAtPos(int post);

    unsigned int getSize();
    bool isEmpty();
    void printList();
};
