#include <iostream>
#include "deque.hpp"

const char * FAIL = "\033[1;31mFAIL!\033[0m";
const char * PASS = "\033[1;32mPASS!\033[0m";

template<typename T>
bool assert(T expect, T actual, const char* test_name) {
    if (expect != actual) {
        std::cerr << FAIL << " " << test_name << ": " << "Expected " << expect << " but got " << actual << std::endl;
        return false;
    }
    return true;
}

bool test_push_back() {
    const char * test_name = "test_push_back";
    bool all_pass = true;

    d3::deque<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    all_pass &= assert(10, l[0], test_name);
    all_pass &= assert(20, l[1], test_name);
    all_pass &= assert(30, l[2], test_name);
    all_pass &= assert(40, l[3], test_name);
    all_pass &= assert(50, l[4], test_name);

    if (all_pass) {
        std::cerr << PASS << " " << test_name << std::endl;
    }

    return all_pass;
}

bool test_insert_after() {
    const char * test_name = "test_insert_after";
    bool all_pass = true;

    d3::deque<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    l.insert_after(0, 15);
    l.insert_after(2, 25);
    l.insert_after(4, 35);
    l.insert_after(6, 45);
    l.insert_after(8, 55);

    all_pass &= assert(10, l[0], test_name);
    all_pass &= assert(15, l[1], test_name);
    all_pass &= assert(20, l[2], test_name);
    all_pass &= assert(25, l[3], test_name);
    all_pass &= assert(30, l[4], test_name);
    all_pass &= assert(35, l[5], test_name);
    all_pass &= assert(40, l[6], test_name);
    all_pass &= assert(45, l[7], test_name);
    all_pass &= assert(50, l[8], test_name);
    all_pass &= assert(55, l[9], test_name);

    if (all_pass) {
        std::cerr << PASS << " " << test_name << std::endl;
    }

    return all_pass;
}

bool test_index_operator() {
    const char * test_name = "test_index_operator";
    bool all_pass = true;

    d3::deque<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    l[0] = 90;
    l[2] = 80;
    l[4] = 70;

    all_pass &= assert(90, l[0], test_name);
    all_pass &= assert(20, l[1], test_name);
    all_pass &= assert(80, l[2], test_name);
    all_pass &= assert(40, l[3], test_name);
    all_pass &= assert(70, l[4], test_name);

    if (all_pass) {
        std::cerr << PASS << " " << test_name << std::endl;
    }

    return all_pass;
}

bool test_iterator_postfix_increment() {
    const char * test_name = "test_iterator_postfix_increment";
    bool all_pass = true;

    d3::deque<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    auto iter = l.begin();

    all_pass &= assert(10, *iter++, test_name);
    all_pass &= assert(20, *iter++, test_name);
    all_pass &= assert(30, *iter++, test_name);
    all_pass &= assert(40, *iter++, test_name);
    all_pass &= assert(50, *iter++, test_name);

    if (all_pass) {
        std::cerr << PASS << " " << test_name << std::endl;
    }

    return all_pass;
}

bool test_iterator_prefix_increment() {
    const char * test_name = "test_iterator_prefix_increment";
    bool all_pass = true;

    d3::deque<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    all_pass &= assert(10, *l.begin(), test_name);
    all_pass &= assert(20, *(++l.begin()), test_name);
    all_pass &= assert(30, *(++++l.begin()), test_name);

    if (all_pass) {
        std::cerr << PASS << " " << test_name << std::endl;
    }

    return all_pass;
}


bool test_iterator_postfix_decrement() {
    const char * test_name = "test_iterator_postfix_decrement";
    bool all_pass = true;

    d3::deque<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    auto iter = l.end();

    all_pass &= assert(50, *iter--, test_name);
    all_pass &= assert(40, *iter--, test_name);
    all_pass &= assert(30, *iter--, test_name);
    all_pass &= assert(20, *iter--, test_name);
    all_pass &= assert(10, *iter--, test_name);

    if (all_pass) {
        std::cerr << PASS << " " << test_name << std::endl;
    }

    return all_pass;
}

bool test_iterator_prefix_decrement() {
    const char * test_name = "test_iterator_prefix_decrement";
    bool all_pass = true;

    d3::deque<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    all_pass &= assert(30, *l.end(), test_name);
    all_pass &= assert(20, *(--l.end()), test_name);
    all_pass &= assert(10, *(----l.end()), test_name);

    if (all_pass) {
        std::cerr << PASS << " " << test_name << std::endl;
    }

    return all_pass;
}



int main(int argc, char* argv[]) {

    bool all_pass = true;
    all_pass &= test_push_back();
    all_pass &= test_insert_after();
    all_pass &= test_index_operator();
    all_pass &= test_iterator_postfix_increment();
    all_pass &= test_iterator_prefix_increment();
    all_pass &= test_iterator_postfix_decrement();
    all_pass &= test_iterator_prefix_decrement();

    if (all_pass) {
        std::cout << "OK! All tests successful passed" << std::endl;
    }

    return 0;
}