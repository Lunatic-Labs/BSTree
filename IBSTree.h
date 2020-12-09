//
//  IBSTree.h
//  BSTree
//
//  Created by Alex Nordhoff on 10/22/19.
//  Copyright © 2019 Alex Nordhoff. All rights reserved.
//

#ifndef IBSTree_h
#define IBSTree_h

#include <stddef.h>

template <class T>
class IBSTree
{
public:
    
    IBSTree() {};   // Plain constructor
    
    IBSTree(const IBSTree<T> &rhs) {}; //copy constructor
    
    const IBSTree<T> & operator = (const IBSTree<T> &rhs) {};  // assignment operator
    
    
    virtual void Insert(const T &data) = 0;
    virtual bool Search(T data) = 0;
    virtual size_t Size() = 0;
    virtual void Clear() = 0;
    virtual bool IsEmpty() = 0;
    
    virtual void Print() = 0;// In order, preorder, or postorder see text
    virtual void PrintDOT() = 0; // copy and paste this output and put it in graph wiz
    
    virtual double ComputeACE() = 0;   //ACE SEE IN NOTES
    virtual void Postprint() = 0;
    virtual void Preprint() = 0;
    
    virtual ~IBSTree() {}; // destructor, only mark destructor virtual, not constructor
    virtual int Max() = 0;
    
    virtual void AVLInsert(const T &data) = 0;
};


#endif /* IBSTree_h */
