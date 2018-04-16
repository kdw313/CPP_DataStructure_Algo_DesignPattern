/** one of the insertion sorts,
 *  1. minimize the number of copies to increase performance
 *    as musch as possible
 *  2. get the array close to being partially sorted,  
 * 
**/
#include "UnorderedArray.h"
using namespace std;

int main(int args, char *arg[])
{
    cout << "Shellsort Algorithm" << endl;
    cout << "Chapter 8: Advance Sorting" << endl << endl;
 
    const int size = 10;
    int i = 0;
 
    UnorderedArray<int> array(size);
 
    for(i = 0; i < size; i++)
        array.push(rand() % 100);
 
    cout << "Before shellsort sort:";
 
    for(i = 0; i < size; i++)
        cout << " " << array[i];
    
    cout << endl;

    array.Shellsort();
    
    cout << " After shellsort sort:";
    
    for(i = 0; i < size; i++)
        cout << " " << array[i];
    
    cout << endl << endl;
    
    return 1;
}