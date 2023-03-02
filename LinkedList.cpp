/*********************************************************************
*                           LinkedList.cpp
*
* LinkedList class member definitions
*
* TODO why is this here
**********************************************************************/

#include <climits>
#include <cstddef>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    //initialize to "zero"
    _head = nullptr;
    _size = 0;
    _iterator = nullptr;
    _iterator_index = 0;
}

int LinkedList::get_size()
{
    return LinkedList::_size;
}

/********************************************************************
*
*                functions that only operate on end of list
*
*********************************************************************/

LinkedList::element LinkedList::get_element()
{
    //check if list is empty
    if (LinkedList::_size == 0)
    {
        return NULL;
    }

    return _head->_data;
}

bool LinkedList::add_element(element data)
{
    //check if list will overflow
    if (LinkedList::_size == INT_MAX)
    {
        return false;
    }

    //construct new node with element
    _iterator = new Node(data);

    //add new node to list
    _iterator->_link = _head;
    _head = _iterator;
}

bool LinkedList::remove_element()
{
    //check if list is empty
    if (_size == 0)
    {
        return false;
    }

    //set iterator to head
    _iterator = _head->_link;

    //free head memory
    delete _head;

    //set head to iterator
    _head = _iterator;

    //update iterator index and the size of the list
    _iterator_index = 0;
    _size -= 1;

    return true;
}

/********************************************************************
*
*                     nth element member functions
*
*********************************************************************/

LinkedList::element LinkedList::nth_element(int n)
{
    //check if element is in bounds or if list is empty
    if (n > _size - 1 or _size == 0)
    {
        return false;
    }

    //set LinkedList iterator to nth position
    if (_iterator_index > n) //iterator isn't less than or equal to nth position, and has to be reset in order to iterate up to nth position
    {
        _iterator = _head;
        _iterator_index = 0;
    }

    for (; _iterator_index < n; ++_iterator_index)
    {
        _iterator = _iterator->_link;
    }

    //return element at nth position
    return _iterator->_data;
}

bool LinkedList::set_nth_element(int n, element data)
{
    //check if element is in bounds or if list is empty
    if (n > _size - 1 or _size == 0)
    {
        return false;
    }

    //set LinkedList iterator to nth position
    if(_iterator_index > n) //iterator isn't less than nth position, and has to be reset in order to iterate up to nth position
    {
        _iterator = _head;
        _iterator_index = 0;
    }

    for (; _iterator_index < n; ++_iterator_index)
    {
        _iterator = _iterator->_link;
    }

    //set element at nth position in list
    _iterator->_data = data;
    return true;
}

bool LinkedList::remove_nth_element(int n)
{
    //check if element is in bounds or if list is empty
    if (n > _size - 1 or _size == 0)
    {
        return false;
    }

    if (n == 0) //special case, don't have to construct temporary node*
    {
        //set iterator to head
        _iterator = _head->_link;

        //free head's memory
        delete _head;

        //remove head from list
        _head = _iterator;

        //update iterator index and the size of the list
        _iterator_index = 0;
        _size -= 1;
    }
    else
    {
        //set LinkedList iterator to the n - 1 position
        if (_iterator_index > n - 1) //iterator isn't less than the n - 1 position, and has to be reset in order to iterate up to the n - 1 position
        {
            _iterator = _head;
            _iterator_index = 0;
        }

        for (; _iterator_index < n - 1; ++_iterator_index)
        {
            _iterator = _iterator->_link;
        }

        //create a temporary Node* at n position
        Node* temp = _iterator->_link;

        //remove node from list
        _iterator->_link = temp->_link;

        //free node's memory
        delete temp;
        temp = nullptr;

        //update size of the list
        _size -= 1;
    }

    return true;
}
