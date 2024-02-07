#include "SnowSportCollection.hpp"
#include <iostream>

// Implementation of ListNode constructor
//Takes newData as argument which could be any type
template <typename T>
ListNode<T>::ListNode(const T& newData) : data(newData), next(nullptr) {}

// Implementation of SnowSportCollection constructor
template <typename T>
SnowSportCollection<T>::SnowSportCollection() : head(nullptr) {}

// Implementation of SnowSportCollection destructor
template <typename T>
SnowSportCollection<T>::~SnowSportCollection() {
    clear();
}

// Implementation of add function
template <typename T>
void SnowSportCollection<T>::add(const T& newData) {
    // Create a new node with the provided data
    ListNode<T>* newNode = new ListNode<T>(newData);

    // Set the next pointer of the new node to the current head
    newNode->next = head;

    // Update the head to point to the new node
    head = newNode;
}

// Implementation of clear function
template <typename T>
void SnowSportCollection<T>::clear() {
    // Start with the head of the list
    ListNode<T>* current = head;

    // Traverse the list and delete each node
    while (current != nullptr) {
        // Save the next node in the list
        ListNode<T>* nextNode = current->next;

        // Delete the current node
        delete current;

        // Move to the next node
        current = nextNode;
    }

    // Set the head to nullptr to indicate an empty list
    head = nullptr;
}

// Implementation of printAll function
template <typename T>
void SnowSportCollection<T>::printAll() const {
    ListNode<T>* current = head;

    // Traverse the list and print each element
    while (current != nullptr) {
        (current->data).displayMetrics();

        // Move to the next node
        current = current->next;
    }
}

template class SnowSportCollection<SnowSport>;
