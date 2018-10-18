#include<iostream>
#include<stack>
#include<string>
using namespace std;
double calcPostfixExpr(FILE *fp =stdin){
	char c;
	stack<double> st;

	while((c=getc(fp))!='\n'){
		if(c=='+'||c=='-'||c=='*'||c=='/'){
			double val2 = st.top();
			st.pop();
			double val1 = st.top();
			st.pop();

			switch(c){
			case '+':st.push(val1 + val2); break;
			case '-':st.push(val1 - val2); break;
			case '*':st.push(val1 * val2); break;
			case '/':st.push(val1 / val2); break;
			}
		}
		else if(c>='0' && c<='9'){
			ungetc(c,fp);
			double val;
			fscanf(fp,"%lf", &val);
				st.push(val);
		}
	}
	
	return (st.top());
}