#include"NYJLinkedList.h"

void main(){

	printf("\n************* [ 2018�⵵ 2�б� �ڷᱸ�� �ǽ����� 7 ] *************\n\n");
	printf("            1. ��ũ�� ����Ʈ �׽�Ʈ ���α׷�(�����)\n\n");
	printf("\t\t\t\t  �й� :2015136046  �̸� : ������\n\n");

	LinkedList list;
	list.insert( 0, new Node(1.0) );
	list.insert( 0, new Node(2.0) );
	list.insert( 1, new Node(3.0) );
	list.insert( list.size(), new Node(4.0) );
	list.insert( 2, new Node(5.0) );
	list.display();

	list.remove( 2 );
	list.remove( list.size()-1 );
	list.remove( 0 );
	list.display();

	list.replace( 1, new Node(9.0) ) ;
	list.display();

	list.clear();
	list.display();
	
	getchar();
	getchar();
}