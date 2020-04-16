#include "GenQueue.h"
#include "DoublyLinkedList.h"

GenQueue::GenQueue(){

}

GenQueue::~GenQueue(){

}

DoublyLinkedList *myList = new DoublyLinkedList();

void GenQueue::insert(int d){
  if(myList->isEmpty()){
    myList->insertFront(d);
  }
  else{
    myList->insertBack(d);
  }
}

void GenQueue::printQueue(){
  myList->printList();
}

int GenQueue::remove(){
  myList->removeFront();
}

int GenQueue::peek(){
  myList->returnFront();
}

bool GenQueue::isEmpty(){
  myList->isEmpty();
}

int GenQueue::getSize(){
  myList->getSize();
}
