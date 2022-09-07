#include <iostream>
#include "set.cpp"

void test_insert() {
  try {
    Set<int> s;
    string set_str = s.to_string();
    if (s.to_string() != "") {
      cout << "Incorrect insert result. Expected nothing but got : " << set_str << endl;
    }

    s.insert(0);
    set_str = s.to_string();
    
    if (s.to_string() != "0") {
      cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
    }
    s.insert(2);
    s.insert(-1);
    set_str = s.to_string();
    if (s.to_string() != "-1 2 0") {
      cout << "Incorrect insert result. Expected -1 2 0 but got : " << set_str << endl;
    }
  } catch (exception& e) {
    cerr << "Error inserting into set : " << e.what() << endl;
  }
}

void test_remove() {
  try {
    Set<string> s;
    s.remove("hello");
    string set_str = s.to_string();
    if (s.to_string() != "") {
      cout << "Incorrect remove result. Expected nothing but got : " << set_str << endl;
    }

    s.insert("hello");
    s.insert("world");
    s.remove("hello");
    set_str = s.to_string();
    if (s.to_string() != "world") {
      cout << "Incorrect remove result. Expected \"world\" but got : " << set_str << endl;
    }
    
    s.insert("hi");
    s.insert("hii");
    s.remove("hi");
    set_str = s.to_string();
    if (s.to_string() != "hii world") {
      cout << "Incorrect remove result. Expected \"hii world\" but got : " << set_str << endl;
    }
    s.remove("world");
    set_str = s.to_string();
    if(s.to_string() != "hii") {
      cout << "Incorrect remove result. Expected \"hii\" but got : " << set_str << endl;
    }
  } catch (exception &e) {
    cerr << "Error removing from set : " << e.what() << endl;
  }
}

void test_cardinality() {
  try {
    Set<int> s;
    int c = s.cardinality();
    if(c != 0) {
      cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
    }
    s.insert(6);
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    c = s.cardinality();
    if(c != 5) {
      cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
    }
    s.remove(4);
    s.remove(2);
    c = s.cardinality();
    if(c != 3) {
      cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
    }
  } catch (exception &e) {
    cerr << "Error in determining set cardinality : " << e.what() << endl;
  }
}

void test_empty() {
  try {
    Set<int> s;
    if(!s.empty()){
      cout << "Empty set identified as non-empty" << endl;
    }
    s.insert(1);
    s.insert(2);
    if(s.empty()) {
      cout << "Non-empty set identified as empty" << endl;
    }
    s.remove(2);
    if(s.empty()) {
      cout << "Non-empty set identified as empty" << endl;
    }
    s.remove(1);
    if(!s.empty()) {
      cout << "Empty set identified as non-empty" << endl;
    }
  } catch (exception &e) {
    cerr << "Error in determining if set is the empty set : " << e.what() << endl;
  }
}

void test_contains() {
  try {
    Set<char> s;
    if(s.contains('a')) {
      cout << "Incorrectly identified \'a\' as in the set " << s.to_string() << endl;
    }
    s.insert('a');
    s.insert('b');
    s.insert('c');
    if(s.contains('z')) {
      cout << "Incorrectly identified \'z\' as in the set " << s.to_string() << endl;
    }
    if(!s.contains('c')) {
      cout << "Incorrectly identified \'c\' as NOT in the set " << s.to_string() << endl;
    }
  } catch (exception &e) {
    cerr << "Error in determining if value contained in se : " << e.what() << endl;
  }
}

// BREAKPOINT OF ADDING/FIXING MORE TESTS
void test_equality() {
  try {
    Set<int> s;
    Set<int> t;
    if(!(s==t)) {
      cout << "Empty sets should be considered equal" << endl;
    }
    s.insert(1);
    s.insert(2);
    s.insert(3);
    if(s==t) {
      cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
    }
    t.insert(1);
    t.insert(2);
    t.insert(3);
    if(!(s==t)) {
      cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
    }
    s.remove(3);
    if(s==t) {
      cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
    }
  } catch (exception &e) {
    cerr << "Error in determining set equality : " << e.what() << endl;
  }
}

void test_subset() {
  try {
    Set<int> s;
    Set<int> t;
    if(!(s<=t)) {
      cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
    }
    t.insert(3);
    t.insert(7);
    if(!(s<=t)) {
      cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
    }
    s.insert(7);
    s.insert(3);
    if(!(s<=t)) {
      cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
    }
    t.insert(10);
    if(!(s<=t)) {
      cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
    }
    s.insert(11);
    if(s<=t) {
    cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
    }
  } catch (exception& e) {
    cerr << "Error in determining subset : " << e.what() << endl;
  }
}

void test_union() {
  try {
    Set<int> s;
    Set<int> t;
    string set_str = (s+t).to_string();
    if(set_str != "") {
      cout << "Union of the empty sets should be the empty set. Instead got :" << set_str << endl;
    }
    s.insert(1);
    s.insert(2);
    t.insert(2);
    t.insert(1);
    set_str = (s+t).to_string();
    if(set_str != "2 1") {
      cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
    }
    t.insert(6);
    set_str = (s+t).to_string();
    if(set_str != "2 1 6") {
      cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << set_str << endl;
    }
  } catch (exception& e) {
    cerr << "Error in generating the union set : " << e.what() << endl;
  }
}

void test_intersection() {
  try {
    Set<int> s;
    Set<int> t;
    string set_str = (s&t).to_string();
    if(set_str != "") {
      cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
    }
    s.insert(1);
    s.insert(2);
    t.insert(6);
    set_str = (s&t).to_string();
    if(set_str != "") {
      cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
    }
    t.insert(2);
    t.insert(1);
    set_str = (s&t).to_string();
    if(set_str != "1 2") {
      cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << set_str << endl;
    }
  } catch (exception& e) {
    cerr << "Error in generating the intersection set : " << e.what() << endl;
  }
}

void test_diff() {
  try {
    Set<int> s;
    Set<int> t;
    string set_str = (s-t).to_string();
    if(set_str != "") {
      cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
    }
    s.insert(1);
    s.insert(2);
    t.insert(6);
    set_str = (s-t).to_string();
    if(set_str != "1 2") {
      cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 1 2 set but instead got : " << set_str << endl;
    }
    t.insert(2);
    t.insert(1);
    set_str = (s-t).to_string();
    if(set_str != "") {
      cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set set but instead got : " << set_str << endl;
    }
  } catch (exception& e) {
    cerr << "Error in generating the intersection set : " << e.what() << endl;
  }
}

int main() {
    test_insert();
    test_remove();
    test_cardinality();
    test_empty();
    test_contains();
    test_equality();
    test_subset();
    test_union();
    test_intersection();
    test_diff();
    
    cout << "Testing completed" << endl;
    
    return 0;
}