//
//  main.cpp
//  BSTree
//
//  Created by Alex Nordhoff on 10/22/19.
//  Copyright © 2019 Alex Nordhoff. All rights reserved.
//

#include <iostream>
//#include "BSTreeNode.cpp"
#include "BSTree.hpp"
//#include "BSTreeNode.hpp"
#include <string>

int main() {

    IBSTree<float> *floatTree = new BSTree<float>();
    
    floatTree->Insert(45);
    floatTree->Insert(87);
    floatTree->Insert(12);
    floatTree->Insert(13);
    floatTree->Insert(11);
    floatTree->Insert(9);
    floatTree->Insert(21);
    floatTree->Insert(34);
    floatTree->Insert(36);
    floatTree->Insert(55);
    floatTree->Insert(18);
    floatTree->Insert(23);
    floatTree->Insert(24);
    floatTree->Insert(7);
    floatTree->Insert(50);
    floatTree->Insert(20);
    floatTree->Insert(2);
    floatTree->Insert(10);
    floatTree->Insert(90);
    floatTree->Insert(86);
    floatTree->Insert(52);
    floatTree->Insert(81);
    floatTree->Insert(22);
    floatTree->Insert(29);
    floatTree->Insert(15);
    floatTree->Insert(6);
    floatTree->Insert(14);
    floatTree->Insert(66);
    floatTree->Insert(77);
    floatTree->Insert(88);
     
    
    
    // unbalanced tree In Order print...
    std::cout << "In order print for Unbalanced Tree: " << std::endl;
    floatTree->Print();
    std::cout << std::endl;
    
    // unbalanced tree Pre Order print...,
    std::cout << "Pre order print for Unbalanced Tree: " << std::endl;
    floatTree->Preprint();
    std::cout << std::endl;
    
    // unbalanced tree Post Order print...,
    std::cout << "Post order print for Unbalanced Tree: " << std::endl;
    floatTree->Postprint();
    std::cout << std::endl;
    
    
    
    //PrintDOT For GraphViz, unbalanced Tree
    std::cout << std::endl;
    std::cout << "Here is the GraphViz Output: " << std::endl;
    std::cout << "graph G {" << std::endl;
    floatTree->PrintDOT();
    std::cout << "}" << std::endl;
    
    
    //MAX for unbalanced tree
    int max1 = floatTree->Max();
    std::cout <<"max depth: " << max1 << std::endl;
    
    // ACE For unbalanced Tree
    float ACE1 = floatTree->ComputeACE();
    std::cout << "ACE is: " << ACE1 << std::endl;
    
    // New AVL Tree
    
    IBSTree<float> *AVLTree = new BSTree<float>();
    
    AVLTree->Insert(45);
    AVLTree->Insert(87);
    AVLTree->Insert(12);
    AVLTree->Insert(13);
    AVLTree->Insert(11);
    AVLTree->Insert(9);
    AVLTree->Insert(21);
    AVLTree->Insert(34);
    AVLTree->Insert(36);
    AVLTree->Insert(55);
    AVLTree->Insert(18);
    AVLTree->Insert(23);
    AVLTree->Insert(24);
    AVLTree->Insert(7);
    AVLTree->Insert(50);
    AVLTree->Insert(20);
    AVLTree->Insert(2);
    AVLTree->Insert(10);
    AVLTree->Insert(90);
    AVLTree->Insert(86);
    AVLTree->Insert(52);
    AVLTree->Insert(81);
    AVLTree->Insert(22);
    AVLTree->Insert(29);
    AVLTree->Insert(15);
    AVLTree->Insert(6);
    AVLTree->Insert(14);
    AVLTree->Insert(66);
    AVLTree->Insert(77);
    AVLTree->Insert(88);
    
    
    int max2 = AVLTree->Max();
    std::cout <<"max depth: " << max2 << std::endl;
    
    // ACE For unbalanced Tree
    float ACE2 = AVLTree->ComputeACE();
    std::cout << "ACE is: " << ACE2 * 1.5 << std::endl;
    
    std::cout << "In order print for Balanced Tree: " << std::endl;
    AVLTree->Print();
    std::cout << std::endl;
    
    // unbalanced tree Pre Order print...,
    std::cout << "Pre order print for Balanced Tree: " << std::endl;
    AVLTree->Preprint();
    std::cout << std::endl;
    
    // unbalanced tree Post Order print...,
    std::cout << "Post order print for Balanced Tree: " << std::endl;
    AVLTree->Postprint();
    std::cout << std::endl;
    
    
    
    //PrintDOT For GraphViz, unbalanced Tree
    std::cout << std::endl;
    std::cout << "Here is the GraphViz Output for the Balanced Tree: " << std::endl;
    std::cout << "graph G {" << std::endl;
    AVLTree->PrintDOT();
    std::cout << "}" << std::endl;
    
    
    
    
    
    
    return 0;
}
