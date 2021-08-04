#include "doubly-linked-list.h"
#include <iostream>
#include <new>

DoublyLinkedList::Node::Node(DataType data) :
        value(data), next(nullptr), prev(nullptr) {
}

DoublyLinkedList::DoublyLinkedList()
        : head_(nullptr), tail_(nullptr), size_(0) {
}

/* DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list)
:size_(list.size_)
{


}*/

DoublyLinkedList::~DoublyLinkedList() {
    while (size_ > 0)
    {
        remove_front();
    }
}

bool DoublyLinkedList::empty() const {
    if (size_ == 0) {
        return true;
    }
    return false;
}

unsigned int DoublyLinkedList::size() const {
    return size_;
}

unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}

void DoublyLinkedList::print() const {
    Node *end = head_;
    for (int i = 0; i < size_; i++) {
        std::cout << end->value << std::endl;
        end = end->next;
    }
}

bool DoublyLinkedList::insert_front(DataType value) {
    return insert(value, 0);
}

bool DoublyLinkedList::remove_front() {
    return remove(0);
}

bool DoublyLinkedList::insert_back(DataType value) {
    return insert(value, size_);
}

bool DoublyLinkedList::remove_back() {
    return remove(size_ - 1);
}

bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (index > size_ || full()) // if operation fails
    {
        return false;
    }
    Node *myNode = new Node(value);

    if (empty()) // if list is empty
    {
        head_ = myNode;
        tail_ = myNode;
    } else if (index == 0) // if inserted node is new head
    {
        myNode->next = head_;
        head_->prev = myNode;
        head_ = myNode;
    } else if (index == size_) // if inserted node is new tail
    {
        myNode->prev = tail_;
        tail_->next = myNode;
        tail_ = myNode;
    } else // if node is somewhere in the middle
    {
        Node *end = getNode(index);
        myNode->next = end;
        myNode->prev = end->prev;
        myNode->prev->next = myNode;
        myNode->next->prev = myNode;
    }
    size_++;
    return true;
}

bool DoublyLinkedList::remove(unsigned int index) {
    if (index >= size_) // if operation fails
    {
        return false;
    }
    Node *end = getNode(index);

    if (size_ == 1) // if only one element
    {
        head_ = nullptr;
        tail_ = nullptr;
    } else if (index == 0) // if selected node is head
    {
        end->next->prev = nullptr;
        head_ = end->next;
    } else if (index == size_ - 1) // if selected node is tail
    {
        end->prev->next = nullptr;
        tail_ = end->prev;
    } else // if node is in the middle
    {
        end->prev->next = end->next;
        end->next->prev = end->prev;
    }
    delete end;
    size_--;
    return true;
}

unsigned int DoublyLinkedList::search(DataType value) const {
    Node *end = head_;
    for (int i = 0; i < size_; i++)// go through linked list until value is found
    {
        if (end->value == value)// if value is found, return index
        {
            return i;
        }
        end = end->next;
    }
    return size_;// if not found, return size
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if (index >= size_) {
        return tail_->value;
    }

    return getNode(index)->value;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if (index >= size_) {
        return false;
    }
    getNode(index)->value = value;
    return true;
}

DoublyLinkedList::Node *DoublyLinkedList::getNode(unsigned int index) const {
    Node *end = head_;
    for (int i = 0; i < index; i++) // go through linked list to index
    {
        end = end->next;
    }
    return end;
}

bool DoublyLinkedList::full() const {
    if (capacity() == size_) {
        return true;
    }
    return false;
}
