#ifndef SET_H
#define SET_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class Node
{
  public:
 
    T value;
    Node *next;
	
    Node(T initValue);
    Node(T initValue, Node *initNext);
};

template <class T>
class Set
{
  public:
	
    Set();                               // default constructor
    ~Set();                              // destructor

    void insert(T item);  
    void remove(T item);  
    int cardinality();
    bool empty();
    bool contains(T item);     

    string to_string();              // return a string representation of the set

    bool operator==(Set& other);
    bool operator<=(Set& other);
    Set operator+(Set& other);
    Set operator-(Set& other);
    Set operator&(Set& other);

	
 private:
 
    Node<T> *head;                           // head of the linked list
    int count;                            // number of items in the list

    void deallocate();
};

#endif