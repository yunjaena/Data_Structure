#include"NYJArrayStack.h"

#include"NYJBracketChecker.h"



void main()
{

	printf("\n************* [ 2018�⵵ 2�б� �ڷᱸ�� �ǽ����� 3 ] *************\n\n");
	printf("                       1. ��ȣ �ݱ� ���α׷�\n\n");
	printf(" �й� : 2015136046  �̸� : ������\n\n");

	NYJBracketChecker checker;
	checker.CheckMatching("NYJArrayStack.h");
	checker.CheckMatching("NYJBracketChecker.h");
	checker.CheckMatching("NYJBracketCheckerMain.cpp");

	printf("********************* [ ��ȣ �ݱ� ���� �ذ� ] ********************\n\n");
	checker.CheckMatching2("NYJBracketChecker.h");
	checker.CheckMatching2("TestText.txt");

	getchar();
	getchar();

}