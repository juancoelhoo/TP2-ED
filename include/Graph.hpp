#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <memory>
#include <cstdint>
#include <stdexcept>

template <class T>
class Node {
    private:
        Node<T>* next;
        T data;

    public:
        Node(T data){
            next = nullptr;
            data = data;
        }

        Node<T>* get_next() const {
            return next;
        }

        void set_next(Node<T>* next) {
            this->next = next;
        }

        T get_data() const {
            return data;
        }
};


template <class T>
class LinkedList{
    private:
        Node<T>* root;
        Node<T>* last;
        unsigned int size;

    public:
        LinkedList(const T &item) {
            this->last = this->root = Node<T>* (item);
            this->size = 1;
        }

        LinkedList() {
            this->root = nullptr;
            this->last = nullptr;
            this->size = 0;
        }

        void insert(const T &item, unsigned int index) {
            if (index > size || index < 0) {
                throw std::runtime_error("Index out of bounds");
            }

            auto p = this->root;
            for (unsigned int i = 0; i < index; i++) {
                p = p->get_next();
            }

            auto newNode = Node<T>* (item);
            newNode->set_next(p->get_next());
            p->set_next(newNode);
            size++;
        }

        void insert(const T &item) {
            auto newNode = Node<T>* (item);
            if (this->root == nullptr) {
                this->root = this->last = newNode;
            } else {
                this->last->set_next(newNode);
                this->last = newNode;
            }
            size++;
        }

        std::shared_ptr<Node<T>> get_root() const {
            return this->root;
        }

        std::shared_ptr<Node<T>> get_last() const {
            return this->last;
        }

        int get_size() const {
            return this->size;
        }
};

class Graph{
    private:
        
};

        

#endif