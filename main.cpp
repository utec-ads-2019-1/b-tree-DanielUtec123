#include <iostream>

#include "btree.h"

using namespace std;

int main(int argc, char *argv[]) {
    BTree<int> t(3); // A B-Tree with minium degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);


    cout << "imprimiendo arbol b ";
    t.print();

    int k = 6;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";

    k = 15;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";


    //references : https://www.geeksforgeeks.org/b-tree-set-1-introduction-2/, https://www.geeksforgeeks.org/b-tree-set-1-insert-2/

    return EXIT_SUCCESS;
}