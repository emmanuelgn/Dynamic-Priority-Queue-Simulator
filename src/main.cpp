// Copyright [2025] Emmanuel Notargiacomo
// main.cpp

#include <iostream>
#include "queue/Client.h"
#include "queue/PriorityQueue.h"

int main() {
    PriorityQueue queue;

    // Criando alguns clientes
    Client client1("Alice");
    Client client2("Bob");
    Client client3("Charlie");

    // Inserindo clientes na fila com prioridades
    queue.insert(client1, 3);
    queue.insert(client2, 1);
    queue.insert(client3, 2);

    std::cout << "Initial Priority Queue:" << std::endl;
    queue.display();

    // Extracting the client with the highest priority (lowest number)
    std::cout << "\nExtracting client with the highest priority:" << std::endl;
    Client extractedClient = queue.extract();
    std::cout << "Extracted client: " << extractedClient.get_name() << std::endl;

    std::cout << "\nPriority Queue after extraction:" << std::endl;
    queue.display();

    // Changing the priority of a client
    std::cout << "\nChanging Charlie's priority to 0:" << std::endl;
    queue.change_priority(client3, 0);

    std::cout << "\nPriority Queue after priority change:" << std::endl;
    queue.display();

    return 0;
}
