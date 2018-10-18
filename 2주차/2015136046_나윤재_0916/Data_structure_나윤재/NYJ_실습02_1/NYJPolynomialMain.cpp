#include "NYJPolynomial.h"


void main(){
	printf("\n******************************* [ 2018년도 2학기 자료구조 실습과제 2 ] *******************************\n\n");
	printf("                                            1. 다항식 계산\n\n");
	printf("\t\t\t\t\t\t\t\t 학번 : 2015136046  이름 : 나윤재\n\n");

	NYJPolynomial a, b, c, d;
	a.Read("A"); // 첫 번째 다항식을 입력 받음
	b.Read("B"); // 두 번째 다항식을 입력 받음

	printf("\n******************************************************************************************************\n\n");

	a.display("            display(A)  = ");
	a.Trim();
	a.display("       display(Trim(A)) = ");

	b.display("            display(B)  = ");
	b.Trim();
	b.display("       display(Trim(B)) = ");

	a.display2("           display2(A)  = ");
	b.display2("           display2(B)  = ");


	c.Sub (a, b); // 두 다항식의 차를 계산

	c.display("\n        display(A - B)  = ");
	c.Trim();
	c.display("   display(Trim(A - B)) = ");
	c.display2("  display2(Trim(A - B)) = ");

	d.Mult (a, b); // 두 다항식의 곱을 계산
	d.display("\n        display(A * B)  = ");
	d.Trim();
	d.display("   display(Trim(A * B)) = ");
	d.display2("  display2(Trim(A * B)) = ");

	getchar();
	getchar();
}