#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i <= topIndex; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Stack() {
        capacity = 10;
        topIndex = -1;
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (topIndex >= capacity - 1) {
            resize(capacity * 2);
        }
        topIndex++;
        data[topIndex] = value;
    }

    void pop() {
        if (empty()) {
            throw "Стек пустой";
        }
        topIndex--;
    }

    T& top() {
        if (empty()) {
            throw "Стек пустой";
        }
        return data[topIndex];
    }

    bool empty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }

    void clear() {
        topIndex = -1;
    }

    void print() const {
        if (empty()) {
            cout << "Стек пустой" << endl;
            return;
        }
        cout << "Стек (сверху вниз): [";
        for (int i = topIndex; i >= 0; i--) {
            cout << data[i];
            if (i > 0) cout << ", ";
        }
        cout << "]" << endl;
    }
};
