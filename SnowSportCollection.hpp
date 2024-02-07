#ifndef SNOW_SPORT_COLLECTION_HPP
#define SNOW_SPORT_COLLECTION_HPP

#include "SnowSports.hpp"

// Forward declaration of ListNode template class
template <typename T>
class ListNode;

// Declaration of the SnowSportCollection template class
template <typename T>
class SnowSportCollection {
private:
    // Pointer to the first node in the linked list
    ListNode<T>* head;

public:
    // Constructor
    SnowSportCollection();

    // Destructor
    ~SnowSportCollection();

    // Function to add a new element to the collection
    void add(const T& newData);

    // Function to clear the entire collection and free memory
    void clear();

    // Function to print all elements in the collection
    void printAll() const;
};

// Declaration of the ListNode template class
template <typename T>
class ListNode {
public:
    T data;

    ListNode* next;

    ListNode(const T& newData);
};

#endif // SNOW_SPORT_COLLECTION_HPP