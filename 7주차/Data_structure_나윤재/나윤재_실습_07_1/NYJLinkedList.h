#include "NYJNode.h"
class LinkedList{
	Node org;
public:
	LinkedList():org(0){}
	~LinkedList(){clear();}
	void clear(){while(!isEmpty()) delete remove(0);}
	Node* getHead() { return org.getLink();}
	bool isEmpty() { return getHead() == NULL;}

	Node* getEntry(int pos){
		Node* n = &org;
		for(int i = -1; i < pos; i++, n = n->getLink()){
			if(n == NULL) break;
		}
		return n;
	}




	void insert(int pos, Node *n){

		Node* prev = getEntry(pos - 1);
		if(prev != NULL && n != NULL){
			n->setLink(prev->getLink());
			prev->setLink(n);

		}
	}

	Node* remove(int pos){
		Node* p;

		Node* prev = getEntry(pos - 1);
		p = prev->getLink();
		if(p != NULL) prev->setLink(p->getLink());

		return p;

	}

	Node* find(int val){
		for(Node *p = getHead(); p!=NULL; p=p->getLink())
			if(p->hasData(val)) return p;
		return NULL;
	}

	void replace(int pos, Node *n){
		delete remove(pos);
		insert(pos, n);
	}

	int size(){
		int count = 0;
		for(Node *p = getHead() ; p!= NULL; p=p->getLink())
			count++;
		return count;
	}

	void display(){
		printf("[(전체 항목 수(순방향 출력)= %2d] : ", size());
		for(Node *p = getHead() ; p!= NULL ; p=p->getLink())
			p->display();
		printf( "\n");
	}


};