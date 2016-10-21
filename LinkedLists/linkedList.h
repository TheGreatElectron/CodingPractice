#include "Node.h"

template <class T> class linkedList{
  private:
    Node<T>* head;
    Node<T>* active;
  public:
    linkedList(T data) { head = new Node<T>(data); active = head; }
    Node<T>* getHead() { return head; }
    T getData() { return active->getData(); }


};
