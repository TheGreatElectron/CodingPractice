template <class T>
class Node {
private:
  Node* next;
  Node* prv;
  T data;
public:
  Node(T value, Node* p = NULL, Node* n = NULL);

  // Define setter functions
  void setNext(Node* n) { next = n; }
  void setPrv(Node* p) { prv = p; }
  void setData(T d) { data = d; }

  // Define Gertter functions
  const Node* getNext() { return this->next; }
  const Node* getPrv() { return this->prv; }
  const T getData() { return this->data; }

};

template <class T>
Node<T>::Node(T value, Node* p, Node* n){
  data = value;
  prv = p;
  next = n;
}
