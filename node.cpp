#include "node.h"
#include <iostream>
using namespace std;

Node::Node(int _value, int _n){
    this->value = _value;
    this->n = _n;
    this->child_num = 0;
    this->parent = nullptr;
    this->children = nullptr;
}

void Node::deleteNode(Node* child){
    if(child){
    for (int i =0;i < child->child_num; i++){
        deleteNode(child->children[i]);
        delete child->children[i];
    }
    if(child_num > 0){
        delete[] child->children;  
    }
    }     
}

Node::~Node(){
    Node *victim = this;
    deleteNode(victim);
}

void Node::addChild(Node* child){
    Node** New_child = new Node*[this->n+1];
    for (int i =0;i < this->child_num; i++){
        New_child[i] = this->children[i];
    }
    New_child[this->child_num] = child;
    if (children != nullptr){
        delete[] children;
    }
    children = New_child;
    child_num++;
}

void Node::addChild(int _value){
    if(this->child_num == this->n){
        tooManyChildren error;
        throw error;
    }
    else {
        Node *child = new Node(_value,this->n);
        child->parent = this;
        if(this->child_num == 0){
            Node *track = this;
            while (track){
                track->height++;
                track = track->parent;
            }
        }
        this->addChild(child);
    }
}

void Node::traverse(){
    cout<<this->value<<" ";
    for (int i=0;i < this->child_num; i++){
        this->children[i]->traverse();
    }
}

bool Node::contain(Node *sub){
    bool child = true;
    bool current = false;
    if (sub->value == this->value){
        current = true;
        if(this->child_num != sub->child_num) {
            child = false;
        }
        else {
        for (int i =0; i < this->child_num; i++){
            if(!this->children[i]->contain(sub->children[i])){
                child = false;
            }
        }
        }
        if(child && current) {return true;}
        else {return false;}
    }
    else {
        bool Subtree = false;
        for (int i = 0;i < this->child_num; i++){
            if(this->children[i]->contain(sub)){
                Subtree = true;
            }
        }
        return Subtree;
    }
}

int Node::getHeight(){
    return this->child_num;
}

Node & Node::operator[](int i){
    if (i>child_num-1){
        invalidIndex error;
        throw error;
    }
    else {
        return *(this->children[i]);
    }
}