//
// Created by elad on 02/04/2020.
//

#include "AncestorTree.h"

using namespace family;


Node::Node(std::string name, int rank) {
    this->name = name;
    this->mother = nullptr;
    this->father = nullptr;
    this->rank = rank;

}

Node *Node::getFather() {
    return this->father;

}

Node *Node::getMother() {
    return this->mother;
}

int &Node::getRank() {
    return this->rank;
}

void Node::setMother(std::string name, int rank) {
    this->mother = new Node(name, rank);
}

void Node::setFather(std::string name, int rank) {
    this->father = new Node(name, rank);
}

void Node::setName(std::string name) {
    this->name = name;
}

Tree::Tree(std::string root) {
    this->root = new Node(root, 0);
    this->treeRank = 0;
}

int &Tree::getTreeRank() {
    return this->treeRank;
}


std::string Node::getName() {
    return this->name;
}

void Tree::addFather(std::string name, std::string parent) {

    if (this->root != nullptr) {
        Node *temp = search(name, this->root);
        if (temp != nullptr) { // means the child was found
            if (temp->getFather() == nullptr) {
                temp->setFather(parent, temp->getRank() + 1);
            }
                // if a fother already exists
            else {
                temp->getFather()->setName(name);
            }
        } else { // if the child haven't been found
            throw std::invalid_argument("this child doesnt exists");
        }

    } else { // if the root of the tree doesnt exists
        throw std::invalid_argument("A root doesn't exists");
    }

}


void Tree::addMother(std::string name, std::string parent) {

    if (this->root != nullptr) {
        Node *temp = search(name, this->root);
        if (temp != nullptr) { // means the child was found
            if (temp->getMother() == nullptr) {
                temp->setMother(parent, temp->getRank() + 1);
            }
                // if a mother already exists
            else {
                temp->getMother()->setName(name);
            }
        } else { // if the child haven't been found
            throw std::invalid_argument("this child doesnt exists");
        }

    } else { // if the root of the tree doesnt exists
        throw std::invalid_argument("A root doesn't exists");
    }

}

Node *Tree::search(std::string name, Node *current) {


    if (current != nullptr) {
        if (current->getName()==name) {
            return current;
        }


         Node*tempF = search(name, current->getFather());

         Node* tempM = search(name, current->getMother());

        if(tempF!=nullptr){
            return tempF;
        }
        else if(tempM!=nullptr){
            return tempM;
        }
    }
    return nullptr;




}

void Tree::display() {

    if (this->root == nullptr) // in case its empty
        return;

    std::queue<Node *> q;


    q.push(root);
    while (!q.empty()) { // as long as its not empty

        int numberOfTreeLevel = q.size();
        while (numberOfTreeLevel > 0) {
            Node *top = q.front();
            q.pop();
            std::cout << top->getName() + " ";

            if (top->getFather() != nullptr)
                q.push(top->getFather());
            if (top->getMother() != nullptr)
                q.push(top->getMother());
            numberOfTreeLevel--;

        }
        std::cout << std::endl;

    }


}