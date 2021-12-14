#include <cstddef>
  template<typename T>
  class Node
  {
  private:
    
  public:
    T value;
    Node* next;  
    Node(T _value): value(_value), next(nullptr){}
  };