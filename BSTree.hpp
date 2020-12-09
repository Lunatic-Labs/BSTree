//
//  BSTree.hpp
//  BSTree
//
//  Created by Alex Nordhoff on 10/22/19.
//  Copyright © 2019 Alex Nordhoff. All rights reserved.
//

#ifndef BSTree_hpp
#define BSTree_hpp

#include <stdio.h>
#include <iostream>


#include "IBSTree.h"
#include "BSTreeNode.hpp"


template <class T>
class BSTree : public IBSTree<T>
{
private:
    //BSTreeNode<T> *theTree; // The root
    BSTreeNode<T> *theTree;
    bool balanceEnabled = false;
public:
    
    BSTree();   // Plain constructor
    
    BSTree(const BSTree<T> &rhs); //copy constructor
    
    const BSTree<T> & operator = (const BSTree<T> &rhs);  // assignment operator
    
    
    void Insert(const T &data);
    void AVLInsert(const T &data);
    bool Search(T data);
    size_t Size();
    void Clear();
    bool IsEmpty();
    
    void Print();// In order, preorder, or postorder see text
    void PrintDOT(); // copy and paste this output and put it in graph wiz
    
    double ComputeACE();   //ACE SEE IN NOTES
    int ComputeNodes();
    void Postprint();
    void Preprint();
    void L_rotate();
    void R_rotate();
    void LR_rotate();
    void RL_rotate();
    void rebalance(BSTreeNode<T> *node);
    void updateBalance(BSTreeNode<T> *node);
    
    ~BSTree(); // destructor, only mark destructor virtual, not constructor
    int Max();
    
};


//#include "BSTree.cpp"

//template class BSTree<int>;
//template class BSTree<float>;


#endif /* BSTree_hpp */
