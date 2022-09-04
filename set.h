#ifndef SET_H
#define SET_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Node
{
  public:
 
    int value;
    Node *next;
	
    Node(int initValue);
    Node(int initValue, Node *initNext);
};

class Set
{
  public:
	
    Set();                               // default constructor
    ~Set();                              // destructor

    void insert(int item);  
    void remove(int item);  
    int cardinality();
    bool empty();
    bool contains(int item);     

    string to_string();              // return a string representation of the set

    bool operator==(Set& other);
    bool operator<=(Set& other);
    Set operator+(Set& other);
    Set operator-(Set& other);
    Set operator&(Set& other);

	
 private:
 
    Node *head;                           // head of the linked list
    int count;                            // number of items in the list

    void deallocate();
};

#endif