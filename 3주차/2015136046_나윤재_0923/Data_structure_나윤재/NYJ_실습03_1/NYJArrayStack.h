#include<cstdio>
#include<cstdlib>


inline void error(char *message){
	printf("%s\n",message);
	exit(1);
}

const int MAX_STACK_SIZE = 20;

class NYJArrayStack
{
	int top;
	char data[MAX_STACK_SIZE];
public:
	NYJArrayStack(){ top = -1;}
	~NYJArrayStack(){}
	bool isEmpty(){ return  top == -1;}
	bool isFull(){ return top == MAX_STACK_SIZE-1;}

	void push(int e){
		if(isFull()) error("���� ��ȭ ����");
		data[++top] = e;
	}

	char pop(){
		if(isEmpty()) error("���� ���� ����");
		return data[top--];
	}

	char peek(){
		if(isEmpty()) error("���� ���� ����");
	    return data[top];
	}

	void display(){
		printf("[���� �׸��� �� = %2d] ==>", top+1);
		for(int i=0 ; i <= top ; i++)
			printf("<%2c>",data[i]);
		printf("\n");
	}

};
