#include <iostream>
using namespace std;

class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode *previous;

    ListNode();
    ListNode(int d);
    ~ListNode();

};
