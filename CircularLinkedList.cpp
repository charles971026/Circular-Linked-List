#include "CircularLinkedList.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Iterator;
class Node;
class CircularLinkedList;

        Iterator::Iterator(){
            pos = NULL;
            container = NULL;
        }

        string Iterator::get() const{
            assert(pos != NULL);
            return pos->data;
        } //look at the value at a position

        void Iterator::next(){
            assert(pos != NULL);
            pos = pos->next;
        } //advance the iterator to the next node

        void Iterator::prev(){
            if(pos == NULL){
                pos = container->last;
            }
            else{
                pos = pos->prev;
            }
        } //move the iterator to the prev node

        bool Iterator::equals(Iterator b) const{
            return pos == b.pos;
        } //compare iterators true if they are equal


        Node::Node(string e){
            data = e;
            next = NULL;
            prev = NULL;
        }

        CircularLinkedList::CircularLinkedList(){
            first = NULL;
            last = NULL;
        }

        void CircularLinkedList::push_back(string data){
            Node* newNode = new Node(data);
            if(last == NULL){
                first = newNode;
                last = newNode;
                first->prev = last;
                last->next = first;

            }
            else{
                last->next = newNode;
                newNode->prev = last;
                last = newNode;
                last->next = first;
                first->prev = last;

            }
        }

        void CircularLinkedList::insert(Iterator iter, string data){
            if(iter.pos == NULL){
                push_back(data);
                return;
            }
            Node* after = iter.pos;
            Node* before = after->prev;
            Node* newNode = new Node(data);
            newNode->next = after;
            newNode->prev = before;
            after->prev = newNode;
            if(before==NULL){
                newNode->prev = last;
                last->next = newNode;
                first = newNode;
            }
            else{
                before->next=newNode;
            }

        }

        Iterator CircularLinkedList::erase(Iterator iter){
            assert(iter.pos != NULL);
            Node* trash = iter.pos;
            Node* before = trash->prev;
            Node* after = trash->next;
            if(trash == first){
                after->prev = last;
                last->next = after;
                first = after;
            }
            else if(trash == last){
                before->next = first;
                first->prev = before;
                last = before;
            }
            else{
                before->next = after;
                after->prev = before;
            }
        }

        Iterator CircularLinkedList::begin(){
            Iterator iter;
            iter.pos = first;
            iter.container = this;
            return iter;
        }

        Iterator CircularLinkedList::end(){
            Iterator iter;
            iter.pos = NULL;
            iter.container = this;
            return iter;
        }
        
