#include "NYJPolynomial.h"


void main(){
	printf("\n******************************* [ 2018�⵵ 2�б� �ڷᱸ�� �ǽ����� 2 ] *******************************\n\n");
	printf("                                            1. ���׽� ���\n\n");
	printf("\t\t\t\t\t\t\t\t �й� : 2015136046  �̸� : ������\n\n");

	NYJPolynomial a, b, c, d;
	a.Read("A"); // ù ��° ���׽��� �Է� ����
	b.Read("B"); // �� ��° ���׽��� �Է� ����

	printf("\n******************************************************************************************************\n\n");

	a.display("            display(A)  = ");
	a.Trim();
	a.display("       display(Trim(A)) = ");

	b.display("            display(B)  = ");
	b.Trim();
	b.display("       display(Trim(B)) = ");

	a.display2("           display2(A)  = ");
	b.display2("           display2(B)  = ");


	c.Sub (a, b); // �� ���׽��� ���� ���

	c.display("\n        display(A - B)  = ");
	c.Trim();
	c.display("   display(Trim(A - B)) = ");
	c.display2("  display2(Trim(A - B)) = ");

	d.Mult (a, b); // �� ���׽��� ���� ���
	d.display("\n        display(A * B)  = ");
	d.Trim();
	d.display("   display(Trim(A * B)) = ");
	d.display2("  display2(Trim(A * B)) = ");

	getchar();
	getchar();
}