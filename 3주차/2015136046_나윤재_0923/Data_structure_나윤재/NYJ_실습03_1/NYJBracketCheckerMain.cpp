#include"NYJArrayStack.h"

#include"NYJBracketChecker.h"



void main()
{

	printf("\n************* [ 2018년도 2학기 자료구조 실습과제 3 ] *************\n\n");
	printf("                       1. 괄호 닫기 프로그램\n\n");
	printf(" 학번 : 2015136046  이름 : 나윤재\n\n");

	NYJBracketChecker checker;
	checker.CheckMatching("NYJArrayStack.h");
	checker.CheckMatching("NYJBracketChecker.h");
	checker.CheckMatching("NYJBracketCheckerMain.cpp");

	printf("********************* [ 괄호 닫기 문제 해결 ] ********************\n\n");
	checker.CheckMatching2("NYJBracketChecker.h");
	checker.CheckMatching2("TestText.txt");

	getchar();
	getchar();

}