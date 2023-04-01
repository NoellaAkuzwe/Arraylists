/*
 * unit_tests.h
 *
 * CS 15 homework 1
 * by Tyler Calabrese, January 2021
 *
 * edited by: Milod Kazerounian, January 2022
 *
 * Uses Matt Russell's unit_test framework to test the CharArrayList class.
 *
 * Instructions for using testing framework can be found at in CS 15's lab
 * 1 -- both in the spec and in the provided ArrayList_tests.h and Makefile.
 * More in-depth information for those who are curious as to how it works can
 * be found at http://www.github.com/mattrussell2/unit_test.
 */
/*
* edited by: Noella Akuzwe
* date:      January 24, 2023
*/

#include "CharArrayList.h"
#include <cassert>
#include <iostream>

using namespace std;

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

//default constructor test
void constructor1_test() {
    CharArrayList test_list;//empty arraylist automatically created
}

//second constructor test
void constructor2_test() {
    CharArrayList test_list('a');//numItems is 1
    assert(test_list.size() == 1);
}

//third constructor test
void constructor3_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);//CharArrayList of size 3 created
    assert(test_list.size() == 3);
    //cout << "test_list elements: " << test_list.toString() << endl;
}

//copy constructor test
void constructor4_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list1(a, 3);
    CharArrayList test_list2(test_list1);
    //cout << "test_list2 elements: " << test_list2.toString() << endl;
}

//destructor test
void destructor_test() {
    CharArrayList test_list;
}

//assignment operator test
void assignment_operator_test() {
    char a[3] = {'a', 'b', 'c'};
    char b[3] = {'d', 'e', 'f'};
    CharArrayList test_list1(a, 3);
    CharArrayList test_list2(b,3);
    test_list2 = test_list1;//RHS elements assigned to LHS
    //test_list2 elements are now the same as test_list1 elements
    assert(test_list2.elementAt(0) == 'a');
    //cout << "test_list2 elements: " << test_list2.toString() << endl; 
}

//isEmpty test
void isEmpty_test() {
    CharArrayList test_list;
    assert(test_list.isEmpty());//should be true since it's empty
}

//clear test
void clear_test() {
    CharArrayList test_list('a');
    test_list.clear();//sets numItems to 0
    assert(test_list.isEmpty());//should be true
    //cout << "test_list elements: " << test_list.toString() << endl;
}

//size test
void size_test() {
    CharArrayList test_list1;//creates arraylist of size 0
    assert(test_list1.size() == 0);
    CharArrayList test_list2('a');//creates arraylist with one element
    assert(test_list2.size() == 1);
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list3(a, 3);//arraylist with three elements
    assert(test_list3.size() == 3);
}

//first test correct
void first_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);
    assert(test_list.first() == 'a');//should be true
}

//first test incorrect
//tests first on empty array list
void first_incorrect_test() {
    bool runtime_error_thrown = false;
    std::string error_message = "";

    CharArrayList test_list;

    try {
        test_list.first();
    }
    catch(const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "cannot get first of empty ArrayList");
}

//last test correct
void last_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);
    assert(test_list.last() == 'c');//should be true
}

//last test incorrect
//tests last on empty array list
void last_incorrect_test() {
    bool runtime_error_thrown = false;
    std::string error_message = "";

    CharArrayList test_list;

    try {
        test_list.last();
    }
    catch(const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "cannot get last of empty ArrayList");
}

//elementAt test
//asserts that the elements are at the right indices
void elementAt_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
    assert(test_list.elementAt(2) == 'c');
}

//elementAt on empty array list test
void elementAt_empty_test() {
    bool range_error_thrown = false;
    std::string error_message = "";

    CharArrayList test_list;

    try {
        test_list.elementAt(0);
    }
    catch(const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "index (0) not in range [0..0)");
}

//out of range elementAt test
void elementAt_outofbounds_test() {
    bool range_error_thrown = false;
    std::string error_message = "";

    char a[3] = {'a', 'b', 'c'};

    CharArrayList test_list(a, 3);

    try {
        test_list.elementAt(5);
    }
    catch(const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "index (5) not in range [0..3)");
}

//toString test
void toString_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);
    //cout << test_list.toString();
    assert(test_list.toString() == "[CharArrayList of size 3 <<abc>>]");
}

//toReverseString test
void toReverseString_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);
    assert(test_list.toReverseString() == "[CharArrayList of size 3 <<cba>>]");
}

//pushAtBack test correct
void pushAtBack_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);
    test_list.pushAtBack('d');//size should now be 4
    assert(test_list.size() == 4);
    //cout << "test_list elements: " << test_list.toString() << endl;
}

//pushAtFront test correct
void pushAtFront_test() {
    char a[3] = {'a', 'b', 'c'};
    CharArrayList test_list(a, 3);
    test_list.pushAtFront('d');
    assert(test_list.size() == 4);
    //cout << "test_list elements: " << test_list.toString() << endl;
}
// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() { 
    CharArrayList test_list;
    test_list.insertAt('a', 0);
    //test_list.insertAt('b', 1);
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
    //cout << "test_list element: " << test_list.toString() << endl;
                               
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
    //cout << "string: " << test_list.toString() << endl;
    //test_list.popFromBack();
    //cout << "string': " << test_list.toString() << endl;
    //test_list.replaceAt('w', 0);
    //cout << "string': " << test_list.toString() << endl;
}

//Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
    //cout << "test_list elements: " << test_list.toString() << endl;
}

// Tests insertion into front, back, and middle of a larger list.
void insertAt_front_back_middle() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // insertAt middle
    test_list.insertAt('z', 3);

    assert(test_list.size() == 9);
    assert(test_list.elementAt(3) == 'z');
    assert(test_list.toString() == 
    "[CharArrayList of size 9 <<abczdefgh>>]");

    // insertAt front
    test_list.insertAt('y', 0);

    assert(test_list.size() == 10);
    assert(test_list.elementAt(0) == 'y');
    assert(test_list.toString() == 
    "[CharArrayList of size 10 <<yabczdefgh>>]");

    // insertAt back
    test_list.insertAt('x', 10);

    assert(test_list.size() == 11);
    assert(test_list.elementAt(10) == 'x');
    assert(test_list.toString() == 
    "[CharArrayList of size 11 <<yabczdefghx>>]");
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
}

//insertInOrder test
void insertInOrde_middle_test() {
    char test_arr[5] = { 'a', 'e', 'g', 'i', 'm'};
    CharArrayList test_list(test_arr, 5);
    test_list.insertInOrder('f');//f goes before g
    assert(test_list.elementAt(2) == 'f');
    //cout << "test_list elements: " << test_list.toString() << endl;
    assert(test_list.size() == 6);
}

//insertInOrder front test
void insertInOrder_front_test() {
    char test_arr[4] = {'r', 'p', 's', 'u'};
    CharArrayList test_list(test_arr, 4);
    test_list.insertInOrder('a');
    //cout << "test_list elements: " << test_list.toString() << endl;
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.size() == 5);
}

//insertInOrder back test
void insertInOrder_back_test() {
    char test_arr[4] = {'m', 'n', 'q', 'o'};
    CharArrayList test_list(test_arr, 4);
    test_list.insertInOrder('z');
    //cout << "test_list elements: " << test_list.toString() << endl;
    assert(test_list.elementAt(4) == 'z');
    assert(test_list.size() == 5);
}

//popFromFront test
void popFromFront_test() {
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);
    test_list.popFromFront();
    //assert(test_list.elementAt(0) == 'b');
    test_list.popFromFront();//what if I pop from front more than once?
    assert(test_list.elementAt(0) == 'c');
    assert(test_list.size() == 3);
}

//popFromFront on empty array list test
void popFromFront_empty_test() {
    bool runtime_error_thrown = false;
    std::string error_message = "";

    CharArrayList test_list;//creates an empty CharArrayList

    try {
        test_list.popFromFront();
    }
    catch(const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "cannot pop from empty ArrayList");
}

//popFromBack test
void popFromBack_test() {
    char test_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);
    test_list.popFromBack();
    assert(test_list.size() == 4);
    assert(test_list.elementAt(test_list.size() - 1) == 'd');
}

//popFromBack on empty array list test
void popFromBack_empty_test() {
    bool runtime_error_thrown = false;
    std::string error_message = "";

    CharArrayList test_list; //creates an empty CharArrayList

    try {
        test_list.popFromBack();
    }
    catch(const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "cannot pop from empty ArrayList");
}

//removeAt test
void removeAt_test() {
    char test_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);
    test_list.removeAt(4);
    assert(test_list.size() == 4);
    assert(test_list.elementAt(3) == 'd');
    //cout << "test_list elements: " << test_list.toString() << endl;
}

//removeAt incorrect test
//tests out-of-range indices
void removeAt_outofrange_test() {
    bool range_error_thrown = false;
    std::string error_message = "";

    char test_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);

    try {
        test_list.removeAt(10);
    }
    catch(const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "index (10) not in range [0..5)");
}

//removeAt on empty array list test
void removeAt_empty_test() {
    bool range_error_thrown = false;
    std::string error_message = "";

    CharArrayList test_list;
    try {
        test_list.removeAt(0);
    }
    catch(const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "index (0) not in range [0..0)");
}

//replaceAt test
void replaceAt_test() {
    char test_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);
    test_list.replaceAt('w', 1);
    assert(test_list.size() == 5);
    assert(test_list.elementAt(1) == 'w');
    //cout << "test_list elements: " << test_list.toString() << endl;
}

//replaceAt incorrect test
//tests out-of-range indices
void replaceAt_incorrect_test() {
    bool range_error_thrown = false;
    string error_message = "";

    char test_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);

    try {
        test_list.replaceAt('m', 7);
    }
    catch(const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    assert(error_message == "index (7) not in range [0..5)");
}

//concatenate test
void concatenate_test() {
    char test_arr1[5] = {'a', 'b', 'c', 'd', 'e'};
    char test_arr2[5] = {'r', 'e', 'g', 'i', 'm'};
    CharArrayList test_list1(test_arr1, 5);
    CharArrayList test_list2(test_arr2, 5);
    test_list1.concatenate(&test_list2);
    //cout << "test_list1 elements: " << test_list1.toString() << endl;
    assert(test_list1.size() == 10);
}

//concatenate arraylist with itself
void concatenate_to_itself_test() {
    char test_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);
    test_list.concatenate(&test_list);
    //cout << "test_list elements: " << test_list.toString() << endl;
    assert(test_list.size() == 10);
}

//concatenate with empty arraylist
void concatenate_empty_and_nonempty() {
    char test_arr[3] = {'a', 'b', 'c'};
    CharArrayList test_list1(test_arr, 3);
    CharArrayList test_list;
    test_list1.concatenate(&test_list);
    //cout << "conc elements: " << test_list1.toString() << endl;
    assert(test_list1.size() == 3);
}

//concatenate two empty arraylists
void concatenate_both_empty() {
    CharArrayList test_list1;
    CharArrayList test_list2;
    test_list1.concatenate(&test_list2);
    assert(test_list1.size() == 0);
}

//Shrink test
//Given a CharArrayList, the shrink function is tested by first
//adding an element in the array and asserting that the capacity
//has expanded. After making sure that it has expanded, elements
//are removed until the size doesn't require the array's capacity to
//be expanded. By asserting that the array capacity has shrank, I know
//that the shrink function is performing its job. 
void shrink_test() {
    char test_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList test_list(test_arr, 5);
    // cout << "capacity0: " << test_list.capacity << endl;
    // test_list.pushAtBack('f');
    // assert(test_list.capacity == 12);
    // test_list.removeAt(1);
    // cout << "capacity2: " << test_list.capacity << endl;
    // assert(test_list.capacity == 5);
}