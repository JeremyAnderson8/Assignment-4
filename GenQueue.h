#include <iostream>

using namespace std;

class GenQueue{
  public:
    GenQueue();
    GenQueue(int maxSize);
    ~GenQueue();

    void insert(int d);
    int remove();

    int peek();
    bool isEmpty();
    int getSize();
    void printQueue();

    int front;
    int rear;
    int mSize;
    int numElements;

    int* myQueue;
};
