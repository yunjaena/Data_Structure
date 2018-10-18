#include "NYJNode.h"
class LinkedStack{
	Node* top;
public :
		LinkedStack(){top = NULL;}
		~LinkedStack(){ while(!isEmpty()) delete pop();}
		bool isEmpty(){ return top == NULL;}
		void push(Node *p){
			if(isEmpty()) top = p;
			else{
				p->setLink(top);
				top = p;
			}
		}
		Node* pop(){
			if(isEmpty()) return NULL;
			Node *p = top;
			top = top->getLink();
			return p;
		}
		Node* peek() { return top;}

	
		
};
		