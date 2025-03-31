// PriorityQueue.h

#ifndef SRC_QUEUE_PRIORITYQUEUE_H_
#define SRC_QUEUE_PRIORITYQUEUE_H_

#include <vector>
#include <algorithm>
#include "Client.h"

class PriorityQueue {
 public:
    void insert(const Client& client, int priority);
    Client extract();
    void change_priority(const Client& client, int new_priority);
    void display();

 private:
    struct QueueElement {
        Client client;
        int priority;

        bool operator<(const QueueElement& other) const {
            return priority > other.priority;  // Min-heap based on priority
        }
    };

    std::vector<QueueElement> heap_;

    void heapify_up(int index);
    void heapify_down(int index);
    int parent(int index) const { return (index - 1) / 2; }
    int left_child(int index) const { return 2 * index + 1; }
    int right_child(int index) const { return 2 * index + 2; }
};

#endif  // SRC_QUEUE_PRIORITYQUEUE_H_
