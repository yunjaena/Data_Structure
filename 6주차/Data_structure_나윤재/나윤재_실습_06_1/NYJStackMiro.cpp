#include"NYJLinkedStack.h"
using namespace std;
const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] ={
	{'1', '1', '1', '1', '1', '0'},
	{'e', '0', '1', '0', '0', '0'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '0', '0', '1', 'x'},
	{'0', '0', '1', '0', '0', '0'},
};
bool isValidLoc( int r, int c){
	if(r<0 || c< 0 || r>=MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] =='x';
}

void main()
{
	LinkedStack mLinkedStack;
	mLinkedStack.push(new Node(1,0));

	while( mLinkedStack.isEmpty() == false){
		int r = mLinkedStack.peek()->row;
		int c = mLinkedStack.peek()->col;
		mLinkedStack.pop();


		printf("(%d,%d)",r,c);
		if(map[r][c] == 'x'){
			printf(" 미로 탐색 성공\n");
			getchar();
			getchar();
			return;
		}
		else{
			map[r][c] = '.';
			if(isValidLoc(r-1,c)) mLinkedStack.push(new Node(r-1,c));
			if(isValidLoc(r+1,c)) mLinkedStack.push(new Node(r+1,c));
			if(isValidLoc(r,c-1)) mLinkedStack.push(new Node(r,c-1));
			if(isValidLoc(r,c+1)) mLinkedStack.push(new Node(r,c+1));
		}
	}
	printf("미로탐색실패\n");
}