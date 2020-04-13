#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

DoublyLinkedList::~DoublyLinkedList(){
  delete front;
  delete back;
}

unsigned int DoublyLinkedList::getSize(){
  return size;
}

bool DoublyLinkedList::isEmpty(){
  if(size == 0)
    return true;
  else
    return false;
}

void DoublyLinkedList::printList(){
  ListNode *current = front;

  while(current != NULL){
    cout << current->data << endl;
    current = current->next;
  }
}

void DoublyLinkedList::insertFront(int d){
   ListNode *node = new ListNode(d);

   if(isEmpty()){
     back = node;
   }
   else{
     front->previous = node;
     front->next = back;
   }
   front = node;
   size++;
 }

 void DoublyLinkedList::insertBack(int d){
   ListNode *node = new ListNode(d);

   if(isEmpty()){
     front = node;
   }
   else{
     back->next = node;
     node->previous = front;
   }
   back = node;
   size++;
 }

 int DoublyLinkedList::search(int val){
   int position = -1;
   ListNode *curr = front;

   while(curr != NULL)
   {
     //iterate and attempt to find the value
     position++;
     if(curr->data == val){
       break;
     }
     else{
       curr = curr->next;
     }
   }

   if(curr == NULL){
     position = -1;
   }

   return position;
 }

 int DoublyLinkedList::removeAtPos(int pos){
   int idx = 0;
   ListNode *curr = front;
   ListNode *prev = front;

   //loop until position
   while(idx != pos){
       prev = curr;
       curr = curr->next;
       idx++;
   }

   // found the position of the node to be deleted
   prev->next = curr->next;
   curr->next = NULL;
   int temp = curr->data;
   delete curr;
   size--;
   return temp;
 }
