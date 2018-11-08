#include<cstdio>
class Node{
	Node* link;
	double data;

public:
	Node(double val =0) : data(val),link(NULL){}
	Node* getLink() { return link;}

	void setLink(Node * next){link =next;}
	void display(){printf(" <%2lf>" ,data);}
	bool hasData(int val) { return data == val;}

	void insertNext(Node *n){
		if(n!= NULL){
			n->link = link;
			link = n;
		}
	}
	Node* removeNext(){
		Node* removed = link;
		if(removed != NULL)
			link = removed->link;
		return removed;
	}
	
};