#pragma once

#include <iostream>
#include <vector>


template<typename T1, typename T2>
struct Pair {
    T1 key{};
    T2 value{};

    Pair(const T1& inKey, const T2& inValue);
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1 &inKey, const T2 &inValue) : key(inKey), value(inValue) {}

template<typename T1, typename T2>
class Registry {
public:
    void add(const T1& key, const T2& value);
    void print();
    void remove(const T1& key);
    std::vector<T2> find(const T1& key);

private:
    std::vector<Pair<T1, T2>> list{};
};

template<typename T1, typename T2>
void Registry<T1, T2>::add(const T1 &key, const T2 &value) {
    list.emplace_back(key, value);
}

template<typename T1, typename T2>
void Registry<T1, T2>::print() {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << "Key: " << list[i].key << ", value: " << list[i].value << std::endl;
    }
}

template<typename T1, typename T2>
void Registry<T1, T2>::remove(const T1& key) {
    int newSize = list.size();
    int insertionPoint = list.size() - 1;

    for (int i = 0; i < newSize;) {
        if (list[i].key == key) {
            std::swap(list[i], list[insertionPoint]);
            --insertionPoint;
            --newSize;
        } else {
            ++i;
        }
    }

    //Haven't figured out why it doesn't work yet "list.resize".
    //list.resize(newSize);
    while (list.size() != newSize) {
        list.pop_back();
    }
}

template<typename T1, typename T2>
std::vector<T2> Registry<T1, T2>::find(const T1 &key) {
    std::vector<T2> result;
    for (int i = 0; i < list.size(); ++i) {
        if (list[i].key == key) {
            result.push_back(list[i].value);
        }
    }
    return result;
}




