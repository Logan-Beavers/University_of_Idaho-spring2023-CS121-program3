/*********************************************************************  
*                              LinkedList.h
* 
* LinkedList class definition
*                                  
* TODO why is this here
**********************************************************************/

//header guard
#pragma once

//0-indexed singly linked list of an "element" data type
class LinkedList
{
public:

    LinkedList();

    //standardize the node datatype and the linked list return type
    typedef char element;

    //return the size of the list
    int get_size();

    /********************************************************************
    *
    *                functions that only operate on end of list
    *
    *********************************************************************/

    /*  return the head element in the list
        NULL -> list is empty */
    element get_element();

    /* adds an element to the end of the list
       true -> element was added successfully
       false -> list has reached max size */
    bool add_element(element);

    /*  removes element from the end of the list
        true -> element was removed successfully
        false -> list was empty */
    bool remove_element();

    /********************************************************************
    * 
    *                     nth element member functions
    * 
    *********************************************************************/

    //TODO: DESCRIBE ALL THESE
    /*  return the nth element in the list
        NULL -> list was empty or nth element was out of bounds */
    element nth_element(int n);

    /*  set the value of the element at position n in the list
        false -> list was empty or nth element was out of bounds
        true -> element set successfully */
    bool set_nth_element(int n, element);

    /*  remove element at position n from the list
        false -> list was empty or nth element was out of bounds
        true -> element removed successfully */
    bool remove_nth_element(int n);

private:

    //Data structure the linked list uses internally
    struct Node {
        Node(element data)
        {
            Node::_data = data;
            Node::_link = nullptr;
        }
        //fundamental link part of list, points to next node
        Node* _link;

        //data part of linked list, each node holds contains an "element"
        element _data;
    };
    
    //Pointer to the head of the list
    Node* _head;

    //Pointer to the selected element in the list
    Node* _iterator;

    //index of the selected element in the list
    int _iterator_index;

    //The size of the list
    int _size;
};