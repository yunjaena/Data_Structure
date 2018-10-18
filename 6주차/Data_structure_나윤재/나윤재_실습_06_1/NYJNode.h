#include "NYJLocation.h"

class Node : public Location2D{
	Node * link;
public:
	Node(int r=0, int c=0):Location2D(r,c){link = NULL;}
	~Node(void){}
	Node* getLink(){ return link;}
	void setLink(Node *p){ link =p;}
};
