#include "List.h"  
#include <iostream>  

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    clear();
}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    if (other.size == 0) return;

    Node* current = other.head;
    while (current) {
        push_back(current->value);
        current = current->next;
    }
}

List& List::operator=(const List& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this;
}

void List::push_back(int value) {
    Node* new_node = new Node(tail, value);
    if (tail) {
        tail->next = new_node;
    }
    else {
        head = new_node;
    }
    tail = new_node;
    size++;
}

void List::push_front(int value) {
    Node* new_node = new Node(nullptr, value);
    if (head) {
        new_node->next = head;
        head->prev = new_node;
    }
    else {
        tail = new_node;
    }
    head = new_node;
    size++;
}

void List::clear() {
    while (size > 0) {
        pop_back();
    }
}

void List::reverse() {
    if (size <= 1) return;

    Node* current = head;
    Node* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = temp ? temp : current->prev;
    }

    std::swap(head, tail);
}

void List::pop_back() {
    if (size == 0) return;

    Node* temp = tail;
    if (size == 1) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

void List::pop_front() {
    if (size == 0) return;

    Node* temp = head;
    if (size == 1) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

void List::show() const {
    Node* current = head;
    while (current) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}