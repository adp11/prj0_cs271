#include <sstream>
#include "set.h"

Node::Node(int initValue) {
  value = initValue;
  next = NULL;
}

Node::Node(int initValue, Node *initNext) {
  value = initValue;
  next = initNext;
}

Set::Set() {
  head = NULL;
  count = 0;
}

Set::~Set() {
  deallocate();
}

void Set::insert(int item) {
  if (!this->contains(item)) {
    if (head == NULL) { // set is empty
        Node *newNode = new Node(item);
        head = newNode;
      } else {
        Node *newNode = new Node(item, head);
        head = newNode;
      }
    count++;
  }
}

void Set::remove(int item) {
  Node *current = head;
  Node *prev = NULL;

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

int Set::cardinality() {
  return count;
}

bool Set::empty() {
  return count == 0;
}

bool Set::contains(int item) {
  Node *current = head;
  while (current != NULL) {
    if (current->value == item) {
      return true;
    }
    current = current->next;
  }
  return false;
}

string Set::to_string()
{
  if (head == NULL)
    return "";

  std::stringstream ss;

  Node *current = head;
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

void Set::deallocate()
{
  Node *nodeToDelete;
  Node *current = head;

  while (current != NULL)
  {
    nodeToDelete = current;
    current = current->next;
    delete nodeToDelete;
  }
}

bool Set::operator==(Set& other) {
  if (count == other.count) {
    Node *current = other.head;
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

bool Set::operator<=(Set& other) {
  Node *current = head;
  while (current != NULL) {
    if (other.contains(current->value)) {
      current = current->next;
    } else {
      return false;
    }
  }
  return true;
}

Set Set::operator+(Set& other) {
  Set newSet;
  
  Node *current = head; // get all elements in set A
  while (current != NULL) {
    if (!newSet.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }

  current = other.head; // get all elements in set B
  while (current != NULL) {
    if (!newSet.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }

  return newSet;
}

Set Set::operator&(Set& other) {
  Set newSet;
  
  Node *current = head;
  while (current != NULL) {
    if (other.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }
  return newSet;
}

Set Set::operator-(Set& other) {
  Set newSet;
  
  Node *current = head;
  while (current != NULL) {
    if (!other.contains(current->value)) {
      newSet.insert(current->value);
    }
    current = current->next;
  }
  return newSet;
}