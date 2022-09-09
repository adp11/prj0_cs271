#include <sstream>
#include "set.h"

// Implementations for Node class
template <typename T>
Node<T>::Node(T initValue) {
  /*
  pre-conditions: param initValue must be of type T
  post-conditions: an object of type Node<T> is initialized
  */
  value = initValue;
  next = NULL;
}

template <typename T>
Node<T>::Node(T initValue, Node *initNext) {
  /*
  pre-conditions: param initValue must be of type T and param initNext must be pointer of type Node
  post-conditions: an object of type Node<T> is initialized
  */
  value = initValue;
  next = initNext;
}

// -------------------------------------------------------------------------------
// Implementations for Set class
template <typename T>
Set<T>::Set() {
  /*
  pre-conditions: no param
  post-conditions: an object of type Set<T> is initialized
  */
  head = NULL;
  count = 0;
}

template <typename T>
Set<T>::~Set() {
  /*
  pre-conditions: no param
  post-conditions: the object of type Node<T> is destroyed
  */
  deallocate();
}

template <typename T>
void Set<T>::insert(T item) {
  /*
  pre-conditions: param item must be of type T
  post-conditions: param item is at the head of Set<T> and return nothing
  */
  if (!this->contains(item)) {
    if (head == NULL) { // set is empty
        Node<T> *newNode = new Node<T> (item);
        head = newNode;
      } else {
        Node<T> *newNode = new Node<T> (item, head);
        head = newNode;
      }
    count++;
  }
}

template <typename T>
void Set<T>::remove(T item) {
  /*
  pre-conditions: param item must be of type T
  post-conditions: param item is removed of Set<T> if any and return nothing
  */
  Node<T> *current = head;
  Node<T> *prev = NULL;

  if (current != NULL && current->value == item) { // delete at the head
    head = current->next;
    delete current;
    count--;
    return;
  } else {
    while (current != NULL && current->value != item) {
      prev = current;
      current = current->next;
    }

    if (current == NULL) { // item not in set
      return;
    }
    prev->next = current->next; // delete by changing pointers 
    delete current;
    count--;
  }
}

template <typename T>
int Set<T>::cardinality() {
  /*
  pre-conditions: no param
  post-conditions: return the size of Set<T>
  */
  return count;
}

template <typename T>
bool Set<T>::empty() {
  /*
  pre-conditions: no param
  post-conditions: return whether or not Set<T> is empty
  */
  return count == 0;
}

template <typename T>
bool Set<T>::contains(T item) {
  /*
  pre-conditions: param item must be of type T
  post-conditions: return whether or not param item is a memeber of Set<T>
  */
  Node<T> *current = head;
  while (current != NULL) {
    if (current->value == item) {
      return true;
    }
    current = current->next;
  }
  return false;
}

template <typename T>
string Set<T>::to_string()
/*
  pre-conditions: no param
  post-conditions: return Set<T> in string format
  */
{
  if (head == NULL)
    return "";

  std::stringstream ss;

  Node<T> *current = head;
  while (current != NULL)
  {
    if (current->next == NULL) {
      ss << current->value;
    } else {
      ss << current->value << " ";
    }
    current = current->next;
  }

  return ss.str();
}

template <typename T>
void Set<T>::deallocate()
/*
  pre-conditions: no param
  post-conditions: Set<T> was destroyed and return nothing
  */
{
  Node<T> *nodeToDelete;
  Node<T> *current = head;

  while (current != NULL)
  {
    nodeToDelete = current;
    current = current->next;
    delete nodeToDelete;
  }
}

template <typename T>
bool Set<T>::operator==(Set& other) {
  /*
  pre-conditions: param other of type Set&
  post-conditions: return whether or not set "this" = set "other"
  */
  if (count == other.count) {
    Node<T> *current = other.head;
    while (current != NULL) {
      if (this->contains(current->value)) {
        current = current->next;
      } else {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <typename T>
bool Set<T>::operator<=(Set& other) {
  /*
  pre-conditions: param other of type Set&
  post-conditions: return whether or not set "this" is a subset of set "other"
  */
  Node<T> *current = head;
  while (current != NULL) {
    if (other.contains(current->value)) {
      current = current->next;
    } else {
      return false;
    }
  }
  return true;
}

template <typename T>
Set<T> Set<T>::operator+(Set& other) {
  /*
  pre-conditions: param other of type Set&
  post-conditions: return the union of set "this" and set "other"
  */
  Set newSet;
  
  Node<T> *current = other.head; // get all elements in set B
  while (current != NULL) {
    if (!newSet.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }

  current = head; // get all elements in set A
  while (current != NULL) {
    if (!newSet.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }

  return newSet;
}

template <typename T>
Set<T> Set<T>::operator&(Set& other) {
  /*
  pre-conditions: param other of type Set&
  post-conditions: return the intersection of set "this" and set "other"
  */
  Set newSet;
  
  Node<T> *current = head;
  while (current != NULL) {
    if (other.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }
  return newSet;
}

template <typename T>
Set<T> Set<T>::operator-(Set& other) {
  /*
  pre-conditions: param other of type Set&
  post-conditions: return the difference of set "this" and set "other"
  */
  Set newSet;
  
  Node<T> *current = head;
  while (current != NULL) {
    if (!other.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }
  return newSet;
}