#ifndef SET_H
#define SET_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
  T value;
  Node *next;

  Node(T initValue);
  Node(T initValue, Node *initNext);
};

template <typename T>
class Set
{
public:
  Set();  // default constructor
  ~Set(); // destructor

  void insert(T item);
  void remove(T item);
  int cardinality();
  bool empty();
  bool contains(T item);

  string to_string();

  bool operator==(Set &other);
  bool operator<=(Set &other);
  Set operator+(Set &other);
  Set operator-(Set &other);
  Set operator&(Set &other);

private:
  Node<T> *head;
  int count;

  void deallocate(); // private method for destructor
};

#endif