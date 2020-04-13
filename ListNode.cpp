#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode::ListNode(){
  data = 0;
  next = NULL;
  previous = NULL;
}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
  previous = NULL;
}

ListNode::~ListNode(){
  delete next;
  delete previous;
}
