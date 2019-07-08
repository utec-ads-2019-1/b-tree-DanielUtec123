#ifndef NODE_H
#define NODE_H

#include <vector>
#include <set>


using namespace std;

template <typename T>
class Node {


    public:
        unsigned int t; //grado minimo
        vector<unsigned int> keys;
        vector<Node<T>*> childs;
        int n; // current number of keys
        bool isLeaf;
        Node(unsigned int t, bool isLeaf) : t(t) {
            keys.resize(2*t - 1);
            this->isLeaf = isLeaf;
            childs.resize(2*t);
            n = 0;
        }


        Node<T>* search(unsigned int k){

            int i = 0;
            while (i < n && k>keys[i])
                i++;

            if(keys[i] == k)
                return this;

            if(isLeaf)
                return nullptr;

            return childs[i]->search(k);
        };

        void insertNonFull (int k){

            int i = n-1;

            if (isLeaf)
            {
                while (i >= 0 && keys[i] > k)
                {
                    keys[i+1] = keys[i];
                    i--;
                }

                keys[i+1] = k;
                n = n+1;
            }
            else
            {
                while (i >= 0 && keys[i] > k)
                    i--;

                if (childs[i+1]->n == 2*t-1)
                {
                    splitChild(i+1, childs[i+1]);

                    if (keys[i+1] < k)
                        i++;
                }
                childs[i+1]->insertNonFull(k);
            }
        }


        void splitChild(int i, Node<T>* y){

            Node<T> *z = new Node<T>(y->t, y->isLeaf);
            z->n = t - 1;

            for (int j = 0; j < t-1; j++)
                z->keys[j] = y->keys[j+t];

            if (y->isLeaf == false)
            {
                for (int j = 0; j < t; j++)
                    z->childs[j] = y->childs[j+t];
            }

            y->n = t - 1;

            for (int j = n; j >= i+1; j--)
                childs[j+1] = childs[j];

            childs[i+1] = z;

            for (int j = n-1; j >= i; j--)
                keys[j+1] = keys[j];

            keys[i] = y->keys[t-1];

            n = n + 1;

        }

        void print(){

            int i;
            for (i = 0; i < n; i++)
            {

                if (isLeaf == false)
                    childs[i]->print();
                cout << " " << keys[i];
            }

            // Print the subtree rooted with last child
            if (isLeaf == false)
                childs[i]->print();
        }

};

#endif