#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    init_capacity_ = 16;
    capacity_ = 16;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity) // Overload constructor
{
    init_capacity_ = capacity;
    capacity_ = capacity;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
    delete[] items_;
}

bool DynamicStack::empty() const
{
    return size_ == 0;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if (size_ == capacity_){

        StackItem* itemsCopy_ = new StackItem[capacity_ * 2];
        for (int i = 0; i < capacity_; ++i) {
            itemsCopy_[i] = items_[i];
        }
        delete[] items_;
        capacity_ *= 2;
        items_ = itemsCopy_;
    }
    items_[size_] = value;
    size_++;
}

DynamicStack::StackItem DynamicStack::pop()
{
    if (empty()){
        return EMPTY_STACK;
    }
    size_--;

    if (size_ <= capacity_ / 4 && (capacity_ / 2 >= init_capacity_)){
        capacity_ /= 2;
    }

    return items_[size_];
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if (empty()){
        return EMPTY_STACK;
    }
    return items_[size_ - 1];
}

void DynamicStack::print() const
{
    for (int i = size_ - 1; 0 <= i; --i) {
        std::cout << items_[i];
    }
}
