#pragma once

namespace d3 {
    class OutOfRangeException {};

    template<typename T>
    class deque {
        struct node {
            node *prev = nullptr;
            node *next = nullptr;
            T    data;

            node(T *data) {
                this->data = data;
            }
            node(node *prev, T data, node *next = nullptr) {
                this->data = data;
                this->prev = prev;
                this->next = next;
            }
        };
        class Iterator {
            const node* cursor;
            public:
            Iterator(const node* ptr){
                this->cursor = ptr;
            }
            Iterator& operator++() {
                if (this->cursor) {
                    this->cursor = this->cursor->next;
                }
                return *this;
            }
            // Postfix ++ overload 
            Iterator operator++(int) { 
                Iterator iterator = *this; 
                ++*this; 
                return iterator; 
            } 
            Iterator& operator--() {
                if (this->cursor) {
                    this->cursor = this->cursor->prev;
                }
                return *this;
            }
            // Postfix -- overload 
            Iterator operator--(int) { 
                Iterator iterator = *this; 
                --*this; 
                return iterator; 
            } 
            bool operator!=(const Iterator& iterator) { 
                return this->cursor != iterator.cursor; 
            } 
            T operator*() { 
                return this->cursor->data; 
            } 
        };

        size_t length = 0;
        node *head = nullptr;
        node *tail = nullptr;
      public:
        typedef Iterator iterator;

        iterator begin() {
            return Iterator(this->head);
        }
        iterator end() {
            return Iterator(this->tail);
        }

        size_t size() {
            return this->length;
        }
        
        T& operator[](size_t pos) {
            node *cursor = this->head;
            for (size_t i = 0; i < this->length; i++) {
                if (pos == i) {
                    return cursor->data;
                }
                cursor = cursor->next;
            }

            throw OutOfRangeException();
        }

        size_t push_back(T data) {
            node* prev = this->tail;

            node* newNode = new node(prev, data);

            if (prev) {
                prev->next = newNode;
            }

            if (this->head == nullptr) {
                this->head = newNode;
            }
            this->tail = newNode;
            
            return ++(this->length);
        }

        void insert_after(size_t pos, T data) {
            if (pos >= this->length) {
                throw OutOfRangeException();
            }

            node* prev = nullptr;
            node* next = nullptr;
            {
                node* curr = this->head;
                for (size_t i = 0; i < this->length; i++) {
                    if (i == pos) {
                        prev = curr;
                        next = curr->next;
                        break;
                    }
                    curr = curr->next;
                }
            }

            node* newNode = new node(prev, data, next);

            if (prev) {
                prev->next = newNode;
            }
            if (next) {
                next->prev = newNode;
            }

            if (this->head == nullptr) {
                this->head = newNode;
            }
            if (this->tail == nullptr) {
                this->tail = newNode;
            }

            this->length++;
        }

        T pop() {
            T data = this->tail->data;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            this->length--;
            return data;
        }

    };
}
