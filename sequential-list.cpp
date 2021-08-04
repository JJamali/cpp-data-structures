#include "sequential-list.h"
#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType[cap];
    capacity_ = cap;
    size_ = 0;
}

SequentialList::~SequentialList()
{
    delete[] data_;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size_ == 0)
    {
        return true;
    }
    return false;
}

bool SequentialList::full() const
{
    if (size_ == capacity_)
    {
        return true;
    }
    return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if(index >= size_) // if index is invalid
    {
       return data_[size_ - 1];
    }
    return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
    // simple linear search
    for (int i = 0; i < size_; i++)
    {
        if(data_[i] == val)
        {
            return i;
        }
    }
    return size_;
}

void SequentialList::print() const
{
    for (int i = 0; i < size_; i++)
    {
        std::cout << data_[i] << std::endl;
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if(full() || index > size_) // check to see if insert will fail
    {
        return false;
    }

    for (int i = size_; i > index; i--) // shift over elements in array
    {
        data_[i] = data_[i-1]; // start moving elements starting from back of array
    }
    data_[index] = val;
    size_++;
    return true;
}

bool SequentialList::insert_front(DataType val)
{
    return insert(val, 0);
}

bool SequentialList::insert_back(DataType val)
{
    return insert(val, size_);
}

bool SequentialList::remove(unsigned int index)
{
    if (index >= size_) // check if function will fail
    {
        return false;
    }

    size_--;
    for (int i = index; i < size_; i++) // shifting
    {
        data_[i] = data_[i+1];
    }
    return true;
}

bool SequentialList::remove_front()
{
    return remove(0);
}

bool SequentialList::remove_back()
{
    return remove(size_ - 1);
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index >= size_) // check if function will fail
    {
        return false;
    }
    data_[index] = val;
    return true;
}

