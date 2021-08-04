#include "circular-queue.h"
#include <iostream>

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    capacity_ = 16;
    items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    capacity_ = capacity;
    items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue()
{
    delete[] items_;
}

bool CircularQueue::empty() const
{
    return size_ == 0;
}

bool CircularQueue::full() const
{
    return size_ == capacity_;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if(full()){
        return false;
    }

    items_[tail_] = value;

    if (tail_ + 1 == capacity_){
        tail_ = 0;
    }
    else {
        tail_++;
    }
    size_++;

    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue()
{
    if(empty()){
        return EMPTY_QUEUE;
    }

    QueueItem output = items_[head_];

    if (head_ + 1 == capacity_){
        head_ = 0;
    }
    else {
        head_++;
    }
    size_--;

    return output;
}

CircularQueue::QueueItem CircularQueue::peek() const
{
    if(empty()){
        return EMPTY_QUEUE;
    }
    return items_[head_];
}

void CircularQueue::print() const
{

}
