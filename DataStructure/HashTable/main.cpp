#include <iostream> 
#include "HashTable.h"

using namespace std; 

int main(int args, char *  * argc) {

    // Create table and fill it in.
    HashTable <int> hashTable(20);

    int item = 0; 

    item = 348; 
    hashTable.Insert(112, item);

    item = 841; 
    hashTable.Insert(87,  item);

    item = 654; 
    hashTable.Insert(24,  item);

    item = 11;
    hashTable.Insert(66,  item);
    
    item = 156;
    hashTable.Insert(222,  item);

    // Search for inserted items.
    if (hashTable.Find(87, &item))
    {
        cout << "Item:87 has a value of " << item <<"." << endl; 
    } else {
        cout <<"Item:87 not found." << endl; 
    }
                
    
    if (hashTable.Find(112, &item))
    {
        cout <<"Item:112 has a value of " << item <<"." << endl; 
    } else {
        cout <<"Item:112 not found." << endl; 
    }

    if (hashTable.Find(66, &item))
    {
        cout <<"Item:66 has a value of " << item <<"." << endl; 
    } else {
        cout <<"Item:66 not found." << endl; 
    }

    if (hashTable.Find(24, &item))
    {
        cout <<"Item:66 has a value of " << item <<"." << endl; 
    } else {
        cout <<"Item:66 not found." << endl; 
    }

    if (hashTable.Find(222, &item))
    {
        cout <<"Item:66 has a value of " << item <<"." << endl; 
    } else {
        cout <<"Item:66 not found." << endl; 
    }
    if (hashTable.Find(100, &item))
    {
        cout <<"Item:100 has a value of " << item <<"." << endl; 
    } else {
        cout <<"Item:100 not found." << endl; 
    }
    
    cout << endl; 
    
    // Test hashing a string.
    string str("cats"); 
    
    int stringHash = hashTable.HashFunction(str); 
    
    cout <<"The string cats hash to " << stringHash << "." << endl << endl;

    cout << endl
         << "The num of elements in the hashTable is " << hashTable.GetTotalItem() << endl;

    cout 
         << "The size of hashTable is " << hashTable.GetSize() << endl;
    return 1;
}