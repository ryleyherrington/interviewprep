#include "stdio.h"
using namespace std;

//templated c++ linked list
template <class T>
class LLNode { 
	public:
		LLNode(const T &value): next(NULL), data(value) {}
		~LLNode() {}
	
		LLNode *getNext() const{return next;}
		const  T& value() const{return data;}
		void setNext(LLNode *node) {next = node;}
		void setValue(const T &value) {data = value;}
	
	private:
		LLNode *next;
		T data;
};

public LLNode<Integer> insertFront(LLNode<Integer> list, int data) {
	LLNode<Integer> n = new LLNode<Integer> (data);
	n.setNext(list);	
	return n;
} 

public LLNode<Integer> findNode(LLNode<Integer> head, int data) {
	LLNode<Integer> node = head;
	while (node != NULL && node.value() != node) {
		node = node.next();
	}
	return node;
}

public bool deleteNode(LLNode<Integer> head, LLNode<Integer> deletenode) {
	LLNode<Integer> node;

	if (!head || !deletenode)
		return false;

	node = head;
	//special case if we're deleting the head
	if (deletenode == head) {
		head = node.next();
		delete(deletenode); /* ~deletenode... how do I free it*/
		return true;	
	}

	//General case, check to see if next node is the one to delete
	while (node) {
		if (node.next() == deletenode) {
			delete(deletenode);
			return true;
		}
		node = node.next();
	}
	//else we didn't find the node... failed
	return false;
}

