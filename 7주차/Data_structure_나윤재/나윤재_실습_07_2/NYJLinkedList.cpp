#include"NYJLinkedList.h"

void main(){

	printf("\n************* [ 2018�⵵ 2�б� �ڷᱸ�� �ǽ����� 7 ] *************\n\n");
	printf("           2. ��ũ�� ����Ʈ �׽�Ʈ ���α׷�(�������Ʈ)\n\n");
	printf("\t\t\t\t  �й� : 2015136046  �̸� : ������\n\n");

	LinkedList list;
	list.insertInList( 0, new Node(1.0) );
	list.insertInList( 0, new Node(2.0) );
	list.insertInList( 1, new Node(3.0) );
	list.insertInList( list.size(), new Node(4.0) );
	list.insertInList( 2, new Node(5.0) );
	list.display();

	list.removeInList( 2 );
	list.removeInList( list.size()-1 );
	list.removeInList( 0 );
	list.display();

	list.replace( 1, new Node(9.0) ) ;
	list.display();

	list.clear();
	list.display();

	list.insertInList( 0, new Node(5.0) );
	list.insertInList( 0, new Node(4.0) );
	list.insertInList( 0, new Node(3.0) );
	list.insertInList( 0, new Node(2.0) );
	list.insertInList( 0, new Node(1.0) );
	list.display();
//	list.reverseDisplay();
	list.reverseDisplay2();
//	list.reverse();
	list.display();
	
	getchar();
	getchar();
}