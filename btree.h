#ifndef BTREE_H
#define BTREE_H

#include "node.h"

template <typename T>
class BTree {
    private:
        Node<T>* root;
        unsigned int t; //grado minimo

    public:
        BTree(unsigned int t) : t(t), root(nullptr) {};

        Node<T>* search(unsigned int k) {
                return (root == nullptr)? nullptr : root->search(k);
        }

        bool insert(int k) {
            {

                if(search(k))
                    return false;
                if (!root)
                {

                    this->root = new Node<T>(t, true);
                    this->root->keys[0] = k;
                    this->root->n = 1;

                }
                else
                {
                    if (root->n == 2*t-1)
                    {
                        Node<T> *s = new Node<T>(t, false);

                        s->childs[0] = root;

                        s->splitChild(0, root);

                        int i = 0;
                        if (s->keys[0] < k)
                            i++;
                        s->childs[i]->insertNonFull(k);

                        root = s;
                    }
                    else
                        root->insertNonFull(k);
                }
                return true;
            }
        }

        bool remove(int k) {
            // TODO
        }

        void print() {
            if (root != nullptr) root->print();
        }

        ~BTree(){

        };
};

#endif