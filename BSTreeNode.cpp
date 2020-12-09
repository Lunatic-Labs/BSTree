//
//  BSTreeNode.cpp
//  BSTree
//
//  Created by Alex Nordhoff on 10/22/19.
//  Copyright © 2019 Alex Nordhoff. All rights reserved.
//

#include "BSTreeNode.hpp"
//#include "BSTree.hpp"
//#pragma once

#include <algorithm>
#include <iostream>


int root;
int num = 2;
int iter = 0;
int temp = 0;

int rightc = 0;
int leftc = 0;

int rightdepth;
int leftdepth;

int finalsum = 0;

int rightsize;
int leftsize;

int lDepth;
int rDepth;

int tempr;
int templ;

int sizecount = 1;

int level1 = 0;
int level2 = 0;
int level3 = 0;
int level4 = 0;
int level5 = 0;
int level6 = 0;
int level7 = 0;
int level8 = 0;

int literation = 0;
int riteration = 0;



// ctor
template <class T>
BSTreeNode<T>::BSTreeNode(const T& value) : right(nullptr),
                                            left(nullptr),
                                            data(value),
                                            bf(0)
{
    // base member initialization happens in order that they are
    // declared in code, NOT in the order listed here ^^
}

// copy ctor
template <class T>
BSTreeNode<T>::BSTreeNode(const BSTreeNode<T> &rhs) : right(nullptr),
                                                      left(nullptr),
                                                      data(rhs.data),
                                                      bf(0)
{
    if (rhs.left != nullptr)
    {
        left = new BSTreeNode<T>(*rhs.left);
    }
    if (rhs.right != nullptr)
    {
        right = new BSTreeNode<T>(*rhs.right);
    }
}

// dtor
template <class T>
BSTreeNode<T>::~BSTreeNode()
{
    delete left;
    delete right;
}


// I used https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/ as a reference for AVL Insertion
template <class T>
void BSTreeNode<T>::AVLInsert(const T &value)
{
    /*BSTreeNode<T> *node = new BSTreeNode<T>(value);
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    node->data = value;
    node->bf = 0;
    BSTreeNode<T> *y = nullptr;
    BSTreeNode<T> *x = this->root;
    
    while (x != nullptr)
    {
        y = x;
        if (node->data < x->data)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    
    node->parent = y;
    if (y == nullptr)
    {
        root = node;
    }
    else if (node->data < y->data)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }
    
    updateBalance(node);
    */


}

template <class T>
void BSTreeNode<T>::Print()
{
    // for now, do an In-Order print....
    if (left != nullptr)
    {
        left->Print();
    }
    
    std::cout << data << " ";
    
    if (right != nullptr)
    {
        right->Print();
    }
}

template <class T>
void BSTreeNode<T>::Postprint()
{
    if (left != nullptr)
    {
        left->Print();
    }

    
    if (right != nullptr)
    {
        right->Print();
    }
    std::cout << data << " ";
}

template <class T>
void BSTreeNode<T>::Preprint()
{
     std::cout << data << " ";
    
    if (left != nullptr)
    {
        left->Print();
    }
    
    if (right != nullptr)
    {
        right->Print();
    }
}




template <class T>
void BSTreeNode<T>::PrintDOT()
{
    
    if (left != nullptr)
    {
        std::cout << data << "--" << left->data << std::endl;
        left->PrintDOT();
    }
    if (right != nullptr)
    {
        std::cout << data << "--" << right->data << std::endl;
        right->PrintDOT();
    }
}

//I used https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/ to reference for my rotation functions

template <class T>
void BSTreeNode<T>::L_rotate(BSTreeNode<T> *node)
{
    BSTreeNode<T> *y = node->right;
    node->right = y->left;
    if (y->left != nullptr)
    {
        y->left->parent = node;
        y->parent = node->parent;
        if (node->parent == nullptr)
            {
                root = y;
            }
        else if (node == node->parent->left)
        {
            node->parent->left = y;
        }
        else
        {
            node->parent->right = y;
        }
        y->left = node;
        node->parent = y;
        
        node->bf = node->bf - 1 - std::max(0, y->bf);
        y->bf = y->bf - 1 + std::min(0, node->bf);
    }
}


//I used https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/ to reference for my rotation functions
template <class T>
void BSTreeNode<T>::R_rotate(BSTreeNode *node)
{
    BSTreeNode *y = node->left;
    node->left = y->right;
    if (y->right != nullptr)
    {
        y->right->parent = node;
    }
    y->parent = node->parent;
    if (node->parent == nullptr)
    {
        this->root = y;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = y;
    }
    else
    {
        node->parent->left = y;
    }
    y->right = node;
    node->parent = y;
    
    // update the balance factor
    node->bf = node->bf + 1 - std::min(0, y->bf);
    y->bf = y->bf + 1 + std::max(0, node->bf);
}


//I used https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/ to reference for my rotation functions
template <class T>
void BSTreeNode<T>::LR_rotate(BSTreeNode *node)
{
    L_rotate(node);
    R_rotate(node);
}

//I used https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/ to reference for my rotation functions
template <class T>
void BSTreeNode<T>::RL_rotate(BSTreeNode *node)
{
    R_rotate(node);
    L_rotate(node);
}

//I used https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/ to reference for rebalancing the tree
template <class T>
void BSTreeNode<T>::rebalance(BSTreeNode *node)
{
    if (node->bf > 0)
    {
        if (node->right->bf < 0)
        {
            R_rotate(node->right);
            L_rotate(node);
        }
        else
        {
            L_rotate(node);
        }
    }
    else if (node->bf < 0)
    {
        if (node->left->bf > 0)
        {
            L_rotate(node->left);
            R_rotate(node);
        }
        else
        {
            R_rotate(node);
        }
    }
}

// I used https://algorithmtutor.com/Data-Structures/Tree/AVL-Trees/ to update the balance of a node
template <class T>
void BSTreeNode<T>::updateBalance(BSTreeNode<T> *node)
{
    if (node->bf < -1 || node->bf > 1)
    {
        rebalance(node);
        return;
    }
    
    if (node->parent != nullptr)
    {
        if (node == node->parent->left)
        {
            node->parent->bf -= 1;
        }
        
        if (node == node->parent->right)
        {
            node->parent->bf += 1;
        }
        
        if (node->parent->bf != 0)
        {
            updateBalance(node->parent);
        }
    }
}


template <class T>
bool BSTreeNode<T>::Search(const T& item)
{
    if (data == item)
    {
        return true;
    }
    else if ((item > data))
    {
        right->Search(item);
    }
    else if ((item < data))
    {
        left->Search(item);
    }
    else
    {
        return false;
    }
    return 1;
}



// insert ????
template <class T>
void BSTreeNode<T>::Insert(const T& value)
{
    if (value < data)
    {
        if(left != nullptr)
        {
            left->Insert(value);
            if(balanceEnabled)
            {
                bf++;
                rebalance(this);     // Private function to rebalance the tree
                                 // Add this function to BSTreeNode
            }
        }
        else
        {
            left = new BSTreeNode<T>(value);
        }
    }
    
    if (value > data)
    {
        if(right != nullptr)
        {
            right->Insert(value);
            if(balanceEnabled)
            {
                bf--;
                rebalance(this);     // Private function to rebalance the tree
            }
        }
        else
        {
            right = new BSTreeNode<T>(value);
        }
    }


}
    /*if (data == value){
        // do nothing, no duplicates allowed
    }
    else{
        if (value < data){
            if (left == nullptr){
                left = new BSTreeNode<T>(value);
                left->parent = this;
            }
            else{
                left->Insert(value);
            }
        }
        else{
            if (right == nullptr){
                right = new BSTreeNode<T>(value);
                right->parent = this;
            }
            else{
                right->Insert(value);
            }
        }
    }
}
     */

template <class T>
size_t BSTreeNode<T>::Size()
{
    
    /*if(left != nullptr)
    {
        leftsize = left->Max();
    }
    
    if (right != nullptr)
    {
        rightsize = right->Max();
    }
    
    if (leftsize > rightsize)
    {
        return(leftsize + 1);
    }
    else return(rightsize + 1);
     */
    if (left != nullptr)
    {
        left->Size();
    }
    
    sizecount ++;
    
    if (right != nullptr)
    {
        right->Size();
    }
    
    return sizecount;
    
}


template <class T>
void BSTreeNode<T>::Clear()
{
    data = NULL;
    left = nullptr;
    right = nullptr;
     
}
 

template <class T>
int BSTreeNode<T>::ComputeNodes()
{
    if(left != nullptr)
    {
        left->ComputeNodes();
    }
    
    if(right != nullptr)
    {
        right->ComputeNodes();
    }
    
    return (level1 + (level2 * 2) + (level3 * 3) + (level4 * 4) + (level5 * 5)+ (level6 * 6) + (level7 * 7) + (level8 * 8));
}

template <class T>
double BSTreeNode<T>::ComputeACE(double &num, int level)
{
    if (left != nullptr)
    {
        num += level + 1;
        left->ComputeACE(num, level + 1);
    }
    if(right != nullptr)
    {
        num += level + 1;
        right->ComputeACE(num, level + 1);
    }
    
    return 1.0;
}
 

// Thanks for the help with this function Dr. Nordstrom
template <class T>
int BSTreeNode<T>::Max()
{
    return std::max(left ? left->Max() : 0, right ? right->Max() : 0) + 1;
    
}
 

template class BSTreeNode<int>;
template class BSTreeNode<float>;








