#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <string>
#include <cassert>

using namespace std;

class Iterator;
class Node;
class CircularLinkedList;

class Iterator{
    /*
    Iterator();
    string get() const;
    void next();
    void prev();
    bool equals(Iterator) const;
    */
    
    public:
        Iterator();
        
        string get() const;
        
        void next();
        
        void prev();
        
        bool equals(Iterator b) const;
        
    private:
        Node* pos;
        CircularLinkedList* container;
        
    friend class CircularLinkedList;
};

class Node{
    private:
        string data;
        Node* next;
        Node* prev;
        
    public:
        Node(string e);
    friend class CircularLinkedList;
    friend class Iterator;
};

class CircularLinkedList{
    /*
    LinkedList();
    void push_back(string);
    void insert(Iterator,string);
    Iterator erase(Iterator);
    Iterator begin();
    Iterator end();
    */
    
    public:
        CircularLinkedList();
        
        void push_back(string data);
        
        void insert(Iterator iter, string data);
        
        Iterator erase(Iterator iter);
        
        Iterator begin();
        
        Iterator end();
        /*
        void addFirst(string data){
            Node* newNode = new Node(data);
            if(first == NULL){
                first = newNode;
                
            }else{
                newNode->next = first;
                first = newNode;
            }
        }
        */
    
    private:
        Node* first;
        Node* last;
    friend class Iterator;
    
    
};
#endif
