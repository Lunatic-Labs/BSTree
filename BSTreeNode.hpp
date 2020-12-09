//
//  BSTreeNode.hpp
//  BSTree
//
//  Created by Alex Nordhoff on 10/22/19.
//  Copyright © 2019 Alex Nordhoff. All rights reserved.
//

#ifndef BSTreeNode_h
#define BSTreeNode_h


//#include "BSTree.hpp"
#include <stdio.h>

template <class T>
class BSTreeNode
{
private:
    
    BSTreeNode<T> *root;
    
    BSTreeNode<T> *right;
    BSTreeNode<T> *left;
    BSTreeNode<T> *parent;
    
    T data;
    bool balanceEnabled = false;
    int bf;                         // balance factor
    
public:
    size_t count = 0;
    BSTreeNode(const T& value);
    BSTreeNode(const BSTreeNode &rhs);
    const BSTreeNode<T> & operator = (const BSTreeNode<T> &rhs);
    
    ~BSTreeNode();
    
    void Insert(const T& value);
    void AVLInsert(const T &value);
    bool Search(const T& value);
    
    size_t Size();
    void Clear();
    void Print();
    void PrintDOT();
    void Postprint();
    void Preprint();
    
    int Max();
    
    // get set for balanceEnabled here... 
    int ComputeNodes();
    void L_rotate(BSTreeNode<T> *node);
    void R_rotate(BSTreeNode<T> *node);
    void LR_rotate(BSTreeNode<T> *node);
    void RL_rotate(BSTreeNode<T> *node);
    void rebalance(BSTreeNode<T> *node);
    void updateBalance(BSTreeNode<T> *node);
    double ComputeACE(double &num, int level);
};

//#include "BSTreeNode.cpp"




#endif /* BSTreeNode_hpp */
