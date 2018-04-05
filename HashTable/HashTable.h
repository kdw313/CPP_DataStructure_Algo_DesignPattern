#include "HashNode.h"
#include <string>
/**
 * HasTable for linear probing 
 **/

template <typename T>
class HashTable
{
    private:
        HashNode<T> *m_table;
        int m_size;
        int m_totalItems;
        bool isNumPrime(int val)
        {
            for (int i = 2; (i * i) <= val; i++)
            {
                if ((val % i) == 0)
                    return false;
            }

            return true;
        }


        int GetNextPrimeNum(int val)
        {
            int i = -1;
            for (i = val + 1;; i++)
            {
                if(isNumPrime(i))
                    break;
            }

            return i;
        }
                
    public:
        HashTable(int size): m_size(0), m_totalItems(0)
        {
            if(size > 0)
            {
                m_size = GetNextPrimeNum(size);
                m_table = new HashNode<T>[m_size];
            }
        };


        ~HashTable()
        {
            if(m_table != nullptr)
            {
                delete[] m_table;
                m_table = nullptr;
            }
        };


        int HashFunction(int key)
        {
            return key % m_size;
        }


        int HashFunction(std::string &str)
        {
            int hash = 0;

            for (int i = 0; i < (int)str.size(); i++)
            {
                int val = (int)str[i];
                hash = (hash * 256 + val) % m_size;
            }

            return hash;
        }


        bool Insert (const int key, const T &obj)
        {
            if(m_totalItems == m_size)
                return false;

            int hash = HashFunction(key);

            while(m_table[hash].GetKey() != -1)
            {
                hash++;
                hash %= m_size;
            }

            m_table[hash].SetKey(key);
            m_table[hash].SetObj(obj);
            m_totalItems++;

            return true;
        }


        
        void Delete(const int key)
        {
            int hash = HashFunction(key);
            int originalHash = hash;

            while(m_table[hash].GetKey() != -1)
            {
                //if found match
                if(m_table[hash].GetKey() == key)
                {
                    m_table[hash].SetKey(-1);
                    m_totalItems--;

                    return;
                }

                hash++;
                hash %= m_size;

                //if nothing found
                if(originalHash == hash)
                {
                    return;
                }
            }
        }

        
        bool Find(int key, T *obj)
        {
            int hash = HashFunction(key);
            int originalHash = hash;

            while(m_table[hash].GetKey() != -1)
            {
                if(m_table[hash].GetKey() == key)
                {
                    if(obj != nullptr)
                        *obj = m_table[hash].GetObj();

                    return true;
                }

                hash++;
                hash %= m_size;

                if(originalHash == hash)
                    return false;
            }

            return false;
        }

        
        int GetSize() const
        {
            return m_size;
        }


        int GetTotalItem() const
        {
            return m_totalItems;
        }


        bool IsEmpty() const
        {
            return m_totalItems == 0;
        }
};