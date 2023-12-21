#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList() {
    first = nullptr;
    last = nullptr;
}

LinkedList::LinkedList(Node& f, Node& l) {
    first = new Node(f);
    last = new Node(l);
    first->previous = nullptr;
    first->next = last;
    last->previous = first;
    last->next = nullptr;
    //std::cout << "first adress: " << first << " have value of: " << first->num << std::endl;
}

bool LinkedList::isEmpty() const {
    return first == nullptr;
}
void LinkedList::addNodeToBeg(const Node& n) {
    if (first == nullptr) { //when empty list
        first = new Node(n);
        last = first;
    }
    else if (first == last) { //list have only 1 elem
        first = new Node(n);
        last->previous = first;
        first->next = last;
    }
    else { //list have 2+ elems
        Node* newFirst = new Node(n);
        newFirst->next = first;
        first->previous = newFirst;
        first = newFirst;
    }
};
void LinkedList::addNodeToBeg(PointOnSphere* point) {
    if (first == nullptr) { //when empty list
        first = new Node(point);
        last = first;
    }
    else if (first == last) { //list have only 1 elem
        first = new Node(point);
        last->previous = first;
        first->next = last;
    }
    else { //list have 2+ elems
        Node* newFirst = new Node(point);
        newFirst->next = first;
        first->previous = newFirst;
        first = newFirst;
    }
};
void LinkedList::addNodeToEnd(const Node& n) {
    if (first == nullptr) {
        first = new Node(n);
        last = first;
    }
    else if (first == last) {
        last = new Node(n);
        first->next = last;
        last->previous = first;
    }
    else {
        Node* newLast = new Node(n);
        last->next = newLast;
        newLast->previous = last;
        last = newLast;
    }
}

void LinkedList::addNodeToEnd(PointOnSphere* point) {
    if (first == nullptr) {
        first = new Node(point);
    }
    else if (first->next == nullptr) {
        last = new Node(point);
        first->next = last;
        last->previous = first;
    }
    else {
        Node* newLast = new Node(point);
        last->next = newLast;
        newLast->previous = last;
        last = newLast;
    }
}

void LinkedList::deleteFirstNode() {
    if (isEmpty()) {
        std::cout << "List is empty, can not delete node!" << std::endl;
    }
    else if (first == last) {
        delete first;
        last = first = nullptr;
    }
    else {
        Node* tempFirst = first;
        first->next->previous = nullptr;
        first = first->next;
        delete tempFirst;
    } 
}
void LinkedList::deleteLastNode() {
    if (isEmpty()) {
        std::cout << "List is empty, can not delete node!" << std::endl;
    }
    else if (first == last) {
        delete first;
        last = first = nullptr;
    }
    else {
        Node* tempLast = last;
        last->previous->next = nullptr;
        last = last->previous;
        delete tempLast;
    }
    
}
void LinkedList::deleteNode(Node& n) {
    if (isEmpty()) {
        std::cout << "List is empty, can not delete node!" << std::endl;
        return;
    }
    else if (first == &n) {
        deleteFirstNode();
        return;
    }
    else if (last == &n) {
        deleteLastNode();
        return;
    }
    else {
        Node* findingFirst = first;
        Node* findingNextToFirst = first->next;
        while (findingNextToFirst != &n && findingNextToFirst != nullptr) {
            findingFirst = findingNextToFirst;
            findingNextToFirst = findingNextToFirst->next;
        }
        if (findingNextToFirst == &n) {
            n.previous->next = n.next;
            n.next->previous = n.previous;
            delete &n;
        }
        else
            std::cout << "Can't find this node in list!\n";
    }
}
void LinkedList::deleteNode(PointOnSphere* point) {
    if (isEmpty()) {
        std::cout << "List is empty, can not delete node!" << std::endl;
        return;
    }
    else if (first->point == point) {
        deleteFirstNode();
    }
    else {
        Node* findingFirst = first;
        Node* findingNextToFirst = first->next;
        while (findingNextToFirst->point != point && findingNextToFirst != nullptr) {
            findingFirst = findingNextToFirst;
            findingNextToFirst = findingNextToFirst->next;
        }
        if (findingNextToFirst == last) {
            deleteLastNode();
        }
        else if (findingNextToFirst == nullptr) {
            std::cout << "Can't find this node in list!\n";
        }
        else {
            findingNextToFirst->previous->next = findingNextToFirst->next;
            findingNextToFirst->next->previous = findingNextToFirst->previous;
            delete findingNextToFirst;
        }
            
    }
}
LinkedList::~LinkedList() {
    if (isEmpty()) // when empty
        return;
    else if (last == first) { // when only 1 elem in list
        delete first;
    }
    else { //when 2+ elems
        Node* tempFirst = first;
        Node* nextToFirst = first->next;
        while (nextToFirst != nullptr) {
            
            delete tempFirst;
            tempFirst = nextToFirst;
            nextToFirst = nextToFirst->next;
            //std::cout << "node deleted\n";
        }
        delete tempFirst; //When nextToFirst became nullptr
        //std::cout << "node deleted\n";
    }

}
Node* LinkedList::operator[](const int i) {
    if (i == 0) {
        return first;
    }
    else if (i > 0) {
        Node* p = first;
        for (int index = 0; index < i; index++) {
            p = p->next;
            if (!p) 
                return nullptr;
        }
        return p;
    }
    else if (i < 0) {
        Node* p = last;
        for (int index = -1; index > i; index--) {
            p = p->previous;
            if (!p)
                return nullptr;
        }
        return p;
    }
}

Node* LinkedList::getFirst() {
    return first;
}

Node* LinkedList::getLast() {
    return last;
}

