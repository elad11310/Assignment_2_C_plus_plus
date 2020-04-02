//
// Created by elad on 02/04/2020.
//

#ifndef MATALA2_ANCESTORTREE_H
#define MATALA2_ANCESTORTREE_H

#include "string"
#include "queue"
#include <stdexcept>
#include <iostream>

namespace family {
    class Node {
    private:
        Node *father;
        Node *mother;
        std::string name;
        int rank;

    public:
        // outline functions
        Node(std::string name, int rank);

        Node *getFather();

        Node *getMother();

        void setFather(std::string name, int rank);

        void setMother(std::string name, int rank);

        void setName(std::string name);

        // returns the rank of the node(the depth)
        int &getRank();

        // returns the name of the person in this node
        std::string getName();

    };


    class Tree {
    private:
        Node *root;
        int treeRank;

    public:
        Tree(std::string root);

        int &getTreeRank();

        void addFather(std::string name, std::string parent);

        void addMother(std::string name, std::string parent);

        std::string relation(std::string name);

        std::string find(std::string name);

        // search the child in the tree - returns its pointer
        Node *search(std::string name, Node *current);

        // display the tree
        void display();

        // remove a node
        bool remove(std::string name);


    };

}
#endif //MATALA2_ANCESTORTREE_H
