#pragma once
#include "HashNode.h"

template <typename T>

class HashTable
{
    private:
      Hashnode<T> *m_table;
      int m_size;
      int m_totalItems;
      bool isNumPrime(int val);
      int GetNextPrimeNum(int val);
      
    public:
        HashTable(int size) : m_size(0), m_totalItems(0);
        ~HashTable();
                
        bool insert (const int key, const T &obj);
        void deleteByKey(const int key);
        bool find(int key, T *obj);

        int sizeOf() const;
        int isEmpty() const;
        void display() const;

};