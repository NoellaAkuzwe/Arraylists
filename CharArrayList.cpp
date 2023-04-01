/*
 *  CharArrayList.cpp
 *  Noella Akuzwe
 *  Jan 24, 2023
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  FILE PURPOSE: Implementation of CharArrayList class
 *
 */

#include "CharArrayList.h"
#include <sstream>
#include<iostream>
using namespace std;

/*
* name:      CharArrayList default constructor
* purpose:   initialize an empty CharArrayList
* arguments: none
* returns:   none
* effects:   numItems to 0 and also updates data and capacity
*/
CharArrayList::CharArrayList() {
    data = nullptr;
    numItems = 0;
    capacity = 0;
}

/*
* name:      CharArrayList second constructor
* purpose:   initialize a CharArrayList with one element
* arguments: character c, which is the element to be added to the arraylist
* returns:   none
* effects:   numItems and capacity to 1 and also updates data
*/
CharArrayList::CharArrayList(char c) {
    data = new char[1];
    data[0] = c;
    numItems = 1;
    capacity = 1;
}

/*
* name:      CharArrayList third constructor
* purpose:   creates an arraylist containing characters
* arguments: character arr, which has elements to be added to the arraylist
* returns:   none
* effects:   numItems, capacity, and data are updated.
*/
CharArrayList::CharArrayList(char arr[], int size) {
    capacity = size;
    numItems = size;
    char *new_data = new char[capacity];
    for(int i = 0; i < capacity; i++) {
        new_data[i] = arr[i];
    }
    data = new_data;
}

/*
* name:      CharArrayList fourth constructor
* purpose:   makes a deep copy of a given instance
* arguments: CharArrayList instance
* returns:   none
* effects:   numItems, capacity, and data are updated
*/
CharArrayList::CharArrayList(const CharArrayList &other) {
    char *new_arr = new char[other.size()];
    data = nullptr;
    for(int i = 0; i < other.size(); i++) {
        new_arr[i] = other.data[i];
    }
    numItems = other.size();
    delete [] data;
    data = new_arr;
}

/*
* name:      CharArrayList destructor
* purpose:   destroys/deletes/recycles heap-allocated data
* arguments: none
* returns:   none
* effects:   free memory allocated by CharArrayList instances
*/
CharArrayList::~CharArrayList() {
    delete [] data;
}

/*
* name:      CharArrayList Assignment operator?
* purpose:   recycles storage associated with he instance on the 
             left of the assignment and makes a deep copy of the 
             instance on the RHS into the instance on the LHS
* arguments: character c, which is the element to be added to the arraylist
* returns:   none
* effects:   numItems and capacity to 1 and also updates data
*/
CharArrayList &CharArrayList::operator=(const CharArrayList &other) {
    if(this == &other) {
        return *this;
    }
    for(int i = 0; i < size(); i++) {
        data[i] = other.data[i];
    }
    return *this;
}

/*
* name:      isEmpty
* purpose:   checks whether the CharArrayList is empty
* arguments: none
* returns:   bool true is arraylist is empty and false otherwise
* effects:   none 
*/
bool CharArrayList::isEmpty() const {
    return (numItems == 0);
}

/*
* name:      clear
* purpose:   makes the CharArrayList instance into an empty arraylist
* arguments: none
* returns:   none
* effects:   updates numItems to 0
*/
void CharArrayList::clear() {
    numItems = 0;
}

/*
* name:      size
* purpose:   returns the number of items in the arraylist
* arguments: none
* returns:   integer
* effects:   none
*/
int CharArrayList::size() const {
    return numItems;
}

/*
* name:      first
* purpose:   returns the first character in the arraylist
             throws runtime_error otherwise
* arguments: none
* returns:   character
* effects:   none
*/

char CharArrayList::first() const {
    if(isEmpty()) {
        string error_msg = "cannot get first of empty ArrayList";
        throw runtime_error(error_msg);
    }
    return data[0];
}

/*
* name:      last
* purpose:   returns the last character in the arraylist
             throws runtime_error otherwise
* arguments: none
* returns:   character
* effects:   none
*/
char CharArrayList::last() const {
    if(isEmpty()) {
        string error_msg = "cannot get last of empty ArrayList";
        throw runtime_error(error_msg);
    }
    return data[numItems - 1];
}

/*
* name:      elementAt
* purpose:   returns the character at a specified index
* arguments: integer
* returns:   character
* effects:   throws range error if index is out of range
*/
char CharArrayList::elementAt(int index) const {
    if (isEmpty() or index < 0 or index > numItems - 1) {
        string error_msg = "index (" + to_string(index);
        error_msg += ") not in range [0.." + to_string(size()) + ")";
        throw range_error(error_msg);
    }
    return data[index];
}

/*
* name:      toString
* purpose:   returns a string containing the characters in
             the arraylist
* arguments: none
* returns:   string
* effects:   arraylist elements are converted into a string
*/
std::string CharArrayList:: toString() const {
    std::stringstream ss;
    ss << "[CharArrayList of size " << size() << " <<";
    for (int i = 0; i < numItems; i++) {
        ss << data[i];
    }
    ss << ">>]";
    return ss.str();
}

/*
* name:      toReverseString
* purpose:   returns a string containing the arraylist elements
             in reverse order
* arguments: integer
* returns:   character
* effects:   none
*/
std::string CharArrayList::toReverseString() const {
    std::stringstream ss;
    ss << "[CharArrayList of size " << size() << " <<";
    for (int i = numItems - 1; i >= 0; i--) {
        ss << data[i];
    }
    ss << ">>]";
    return ss.str();
}

/*
* name:      pushAtBack
* purpose:   Inserts a given new element after the end of the existing
             elements of the arraylist.
* arguments: character
* returns:   none
* effects:   numItems is updated; capacity might also be updated;
             a new character is added in the arraylist
*/
void CharArrayList::pushAtBack(char c) {
    insertAt(c, numItems);
}

/*
* name:      pushAtFront
* purpose:   Inserts a given new element in front of the existing
             elements of the arraylist.
* arguments: character
* returns:   none
* effects:   numItems is updated; capacity might also be updated;
             a new character is added in the arraylist
*/
void CharArrayList::pushAtFront(char c) {
    insertAt(c, 0);
}

/*
* name:      insertAt
* purpose:   inserts a new element at the specified index and shifts the
             existing elements as necessary.
* arguments: character and integer
* returns:   none
* effects:   numItems is updated; capacity might also be updated;
             a new character is added in the arraylist; the positions of
             original elements are shifted.
*/
void CharArrayList::insertAt(char c, int index) {
    if(index < 0 or index > numItems) {
        string error_msg = "index (" + to_string(index);
        error_msg += ") not in range [0.." + to_string(size()) + "]";
        throw range_error(error_msg);
        return;
    }
    if(numItems == capacity) {
        expand();
    }
    for(int i = numItems - 1; i >= index; i--) {
        data[i+1] = data[i];
    }
    data[index] = c;
    numItems++;
}

/*
* name:      expand
* purpose:   increases the capacity of the arraylist
* arguments: none
* returns:   none
* effects:   the arraylist's capacity is updated
*/
void CharArrayList::expand() {
    char *new_data = new char[2 * capacity + 2];
    for(int i = 0; i < numItems; i++) {
        new_data[i] = data[i];
    }
    capacity = 2 * capacity + 2;
    delete [] data;
    data = new_data;
}

/*
* name:      insertInOrder
* purpose:   inserts a new element in the arraylist in ASCII order
* arguments: character
* returns:   none
* effects:   numItems is updated; capacity might also be updated;
             a new character is added in the arraylist; the positions of
             original elements are shifted
*/
void CharArrayList::insertInOrder(char c) {
    int i = 0;
    while(i < numItems and data[i] < c) {
        i++;
    }
    //cout << "index: " << i << endl;
    insertAt(c, i);
}

/*
* name:      popFromFront
* purpose:   removes first element from the arraylist
* arguments: none
* returns:   none
* effects:   numItems is updated; capacity might also be updated;
             an element is removed from the arraylist; the positions of
             original elements are shifted.
*/
void CharArrayList::popFromFront() {
    if(isEmpty()) {
        string error_msg = "cannot pop from empty ArrayList";
        throw runtime_error(error_msg);
    }
    removeAt(0);
}

/*
* name:      popFromBack
* purpose:   removes last element from the arraylist
* arguments: none
* returns:   none
* effects:   numItems is updated; capacity might also be updated;
             an element is removed from the arraylist.
*/
void CharArrayList::popFromBack() {
    if(isEmpty()) {
        string error_msg = "cannot pop from empty ArrayList";
        throw runtime_error(error_msg);  
    }
    removeAt(numItems - 1);
}

/*
* name:      removeAt
* purpose:   removes first element from the arraylist
* arguments: integer
* returns:   none
* effects:   numItems is updated; capacity might also be updated;
             an element is removed from the arraylist.
*/
void CharArrayList::removeAt(int index) {
    if(isEmpty() and index == 0) {
        string error_msg = "index (" + to_string(index);
        error_msg += ") not in range [0.." + to_string(size()) + ")";
        throw range_error(error_msg); 
    }
    if(index < 0 or index > numItems - 1) {
        string error_msg = "index (" + to_string(index);
        error_msg += ") not in range [0.." + to_string(size()) + ")";
        throw range_error(error_msg);
    }
    int i = 0;
    while(i < index) {
        i++;
    }
    //cout << "index: " << i << endl;
    if(i < numItems) {
        numItems = numItems - 1;
        for(int j = i; j < numItems; j++) {
            data[j] = data[j + 1];
        }
    }
    if(capacity > (2 * (numItems - 1) + 2)) {
        shrink();
    }
}

/*
* name:      replaceAt
* purpose:   replaces the element at the specified index with a new
             element.
* arguments: character and integer
* returns:   none
* effects:   a certain element is updated
*/
void CharArrayList::replaceAt(char c, int index) {
    if (index < 0 or index > numItems - 1) {
        string error_msg = "index (" + to_string(index);
        error_msg += ") not in range [0.." + to_string(size()) + ")";
        throw range_error(error_msg);
    }
    for(int i = 0; i < numItems; i++) {
        if(i == index) {
            data[i] = c;
        }
    } 
}

/*
* name:      concatenate
* purpose:   adds a copy of the arraylist pointed to by the parameter
             to the end of the arraylist the function was called from
* arguments: pointer to CharArrayList
* returns:   none
* effects:   numItems and capacity are both updated
*/
void CharArrayList::concatenate(CharArrayList *other) { 
    std::stringstream ss;
    if(not other->isEmpty()) {
        for (int i = 0; i < numItems; i++) {
        ss << data[i];
        }
        for (int i = 0; i < numItems; i++) {
            ss << other->data[i];
        }
        string data_string;
        data_string = ss.str();
        //cout << "data string: " << data_string << endl;
        //cout << "data string size: " << data_string.length() << endl;
        //cout << "data string[0]: " << data_string[0] << endl;
        clear();
        for(unsigned int i = 0; i < data_string.length(); i++) {
            pushAtBack(data_string[i]);
        }
    } 
}

/*
* name:      shrink
* purpose:   reduces the object's memory usage to the bare minimum
             required to store its elements
* arguments: none
* returns:   none
* effects:   capacity is updated
*/
void CharArrayList::shrink() {
    capacity = numItems;
}

/*
* JFFEs below
* Did not finish working on them
*/
// void CharArrayList::sort() {
//     //This function uses slice
// } 

/*
* name:      slice
* purpose:   takes a left index and a right index and returns
             a pointer to a new heap-allocated CharArrayList
* arguments: two integers
* returns:   pointer to CharArrayList
* effects:   new array contains characters starting at the left
             index and up to, but not including, the right index
*/
// CharArrayList CharArrayList::*slice(int left, int right) {
//     char *new_data = new char[capacity];
//     if(left < 0 or left > numItems - 1) {
//         string error_msg = "index (" + to_string(index);
//         error_msg += ") not in range [0.." + to_string(size()) + ")";
//         throw range_error(error_msg);   
//     }
//     if(right < 0; right > numItems) {
//         string error_msg = "index (" + to_string(index);
//         error_msg += ") not in range [0.." + to_string(size()) + "]";
//         throw range_error(error_msg); 
//     }
//     for(int i = 0; i < right; i++) {
//         new_data[i] = data[left + i];
//     }
//     delete [] data;
//     data = new_data;
//     return new_data;
// }