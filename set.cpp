#include <sstream>
#include "set.h"

template <typename T>
Node<T>::Node(T initValue) {
  value = initValue;
  next = NULL;
}

template <typename T>
Node<T>::Node(T initValue, Node *initNext) {
  value = initValue;
  next = initNext;
}

template <typename T>
Set<T>::Set() {
  head = NULL;
  count = 0;
}

template <typename T>
Set<T>::~Set() {
  deallocate();
}

template <typename T>
void Set<T>::insert(T item) {
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
  return count;
}

template <typename T>
bool Set<T>::empty() {
  return count == 0;
}

template <typename T>
bool Set<T>::contains(T item) {
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