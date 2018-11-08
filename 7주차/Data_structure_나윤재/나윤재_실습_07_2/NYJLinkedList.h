#include "NYJNode.h"
class LinkedList{
	Node *head;
public:
	LinkedList():head(NULL){}
	~LinkedList(){clear();}
	void clear(){while(!isEmpty()) delete removeInList(0);}
	Node* getHead() { return head;}
	bool isEmpty() { return getHead() == NULL;}

	Node* getEntry(int pos){
		Node* n = head;
		for(int i = 0; i < pos; i++, n = n->getLink()){
			if(n == NULL) break;
		}
		return n;
	}




	void insertInList(int pos, Node *n){
		if(pos == 0){
			n->setLink(head);
			head = n;
		}
		else{
			Node* prev = getEntry(pos - 1);
			if(prev != NULL && n != NULL){
				n->setLink(prev->getLink());
				prev->setLink(n);
			}
		}
	}

	Node* removeInList(int pos){
		Node* p;
		if(pos == 0){
			p = head;
			if(p != NULL) head = p->getLink();
		}
		else{
			Node* prev = getEntry(pos - 1);
			p = prev->getLink();
			if(p != NULL) prev->setLink(p->getLink());
		}
		return p;

	}

	Node* find(int val){
		for(Node *p = getHead(); p!=NULL; p=p->getLink())
			if(p->hasData(val)) return p;
		return NULL;
	}

	void replace(int pos, Node *n){
		delete removeInList(pos);
		insertInList(pos, n);
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

	void reverseDisplay2(){
		printf("[(전체 항목 수(역  순 출력)= %2d] : ", size());
		reverse(getHead());
		printf( "\n");
	}

	Node* reverse(Node* p){
		if(p==NULL) return NULL;
		reverse(p->getLink());
		p->display();



	}

};