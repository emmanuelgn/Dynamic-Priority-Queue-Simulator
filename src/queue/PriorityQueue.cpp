// PriorityQueue.cpp

#include "PriorityQueue.h"

#include <iostream>
#include <stdexcept>
#include <utility>

void PriorityQueue::insert(const Client &client, int priority) {
    QueueElement newElement{client, priority};
    heap_.push_back(newElement);
    heapify_up(heap_.size() - 1);
}

Client PriorityQueue::extract() {
    if (heap_.empty()) {
        throw std::out_of_range("Queue is empty");
    }

    Client topClient = heap_.front().client;
    heap_[0] = heap_.back();
    heap_.pop_back();
    heapify_down(0);

    return topClient;
}

void PriorityQueue::change_priority(const Client &client, int new_priority) {
    for (size_t i = 0; i < heap_.size(); ++i) {
        if (heap_[i].client.get_name() == client.get_name()) {
            int old_priority = heap_[i].priority;
            heap_[i].priority = new_priority;

            if (new_priority < old_priority) {
                heapify_up(i);
            } else {
                heapify_down(i);
            }
            break;
        }
    }
}

void PriorityQueue::display() {
    for (const auto &el : heap_) {
        std::cout << "Client: " << el.client.get_name() << ", Priority: " << el.priority
                  << std::endl;
    }
}

void PriorityQueue::heapify_up(int index) {
    if (index && heap_[parent(index)] < heap_[index]) {
        std::swap(heap_[index], heap_[parent(index)]);
        heapify_up(parent(index));
    }
}

void PriorityQueue::heapify_down(int index) {
    int smallest = index;
    int left = left_child(index);
    int right = right_child(index);

    if (left < heap_.size() && heap_[left] < heap_[smallest]) {
        smallest = left;
    }

    if (right < heap_.size() && heap_[right] < heap_[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(heap_[index], heap_[smallest]);
        heapify_down(smallest);
    }
}
