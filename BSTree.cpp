//
//  BSTree.cpp
//  BSTree
//
//  Created by Alex Nordhoff on 10/22/19.
//  Copyright © 2019 Alex Nordhoff. All rights reserved.
//

#include "BSTree.hpp"
#include "BSTreeNode.hpp"


// constructor
template <class T>
BSTree<T>::BSTree() : theTree(nullptr) // copy constructor semantics
{
    
}

// constructor where someone passes in a tree
template <class T>
BSTree<T>::BSTree(const BSTree<T> & rhs) : theTree(nullptr)
{
    if (rhs.theTree != nullptr)
    {
        theTree = new BSTreeNode<T>(*rhs.theTree);
    }
}

// destructor
template <class T>
BSTree<T>::~BSTree()
{
    // What to de here? Hmmmm....
    delete theTree;
}

template <class T>
bool BSTree<T>::IsEmpty()
{
    return (theTree != nullptr);
}

template <class T>
void BSTree<T>::AVLInsert(const T &data)
{
    return theTree->AVLInsert(data);
}

template <class T>
void BSTree<T>::L_rotate()
{
    return theTree->L_rotate(theTree);
}

template <class T>
void BSTree<T>::R_rotate()
{
    return theTree->R_rotate(theTree);
}

template <class T>
void BSTree<T>::LR_rotate()
{
    return theTree->LR_rotate(theTree);
}

template <class T>
void BSTree<T>::RL_rotate()
{
    return theTree->RL_rotate(theTree);
}

template <class T>
void BSTree<T>::rebalance(BSTreeNode<T> *node)
{
    if(theTree == nullptr)
    {
        return;
    }
    return rebalance(theTree);
    //return theTree->rebalance(node);
}

template <class T>
void BSTree<T>::updateBalance(BSTreeNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        return updateBalance(node);
    }
}


template <class T>
void BSTree<T>::Print()
{
    if (theTree != nullptr)
    {
        theTree->Print();
    }
}

template <class T>
void BSTree<T>::Insert(const T & data)
{
    if (theTree == nullptr)
    {
        // the tree is currently emtpy
        theTree = new BSTreeNode<T>(data); // use constructor of BSTreeNode right here
    }
    else
    {
        theTree->Insert(data);
    }
}


template <class T>
bool BSTree<T>::Search(T data)
{
   if(theTree->Search(data))
   {
       return true;
   }
   else
   {
       return false;
   }
}
 

template <class T>
size_t BSTree<T>::Size()
{
    if(theTree == NULL)
    {
        return 0;
    }
    else
    {
        return theTree->Size();
    }
}

template <class T>
void BSTree<T>::Clear()
{
    return theTree->Clear();
}


template <class T>
double BSTree<T>::ComputeACE()
{
    double total = 0;
    int level = 1;
    if(theTree == nullptr){
        return 0.0;
    }
    else{
        total = 1;
        theTree->ComputeACE(total, level);
    }
    return ((total / Size()));
};

template <class T>
int BSTree<T>::ComputeNodes()
{
    return theTree->ComputeNodes();
};


template <class T>
void BSTree<T>::PrintDOT()
{
    return theTree->PrintDOT();
};

template <class T>
void BSTree<T>::Preprint()
{
    if (theTree != nullptr)
    {
        theTree->Preprint();
    }
}

template <class T>
void BSTree<T>::Postprint()
{
    if (theTree != nullptr)
    {
        theTree->Postprint();
    }
}

template <class T>
int BSTree<T>::Max()
{
    if(theTree == NULL)
    {
        return 0;
    }
    else
    {
        
        return theTree->Max();
    }
    
}
 














//explicit template class instantiation
template class BSTree<int>;
template class BSTree<float>;


