#ifndef LINEKD_LIST_H
#define LINKD_LIST_H

#include <iostream>

template <typename T>
class LinkedList {
private:
    class Link 
    {
    private:
        T value{};
        Link* m_prev;
        Link* m_next;
    public:
        Link() = default;
        Link(T value) : m_value{value} {};
    };
    Link* m_first_element;
    T value;
    LinkedList* m_next;
    LinkedList* m_prev;
public:
    LinkedList(size_t init_size);
    ~LinkedList();
    void append(T value);
    void erase(size_t index);
    size_t find(T el);
    size_t size();
    LinkedList* next(T value);
    friend std:: ostream& operator<< (std::ostream& out, LinkedList);
};

template <typename T>
LinkedList<T>::LinkedList(size_t init_size) {
    if (init_size == 0) {
        m_first_element = nullptr;
    } else {
        m_first_element = new Link();
        Link* current = m_first_element;
        for (size_t i{1}; i < init_size; i++) {
            current->m_next= new Link();
            current->m_next->m_prev = current;
            current = current->m_next;
        }
            
        }
    }

template <typename T>
LinkedList<T>::~LinkedList() {
    Link* current = m_first_element;
    Link* to_be_deleted;
    while (current != nullptr) {
        to_be_deleted = current;
        current = current->m_next;
        delete to_be_deleted;
    }
}

#endif