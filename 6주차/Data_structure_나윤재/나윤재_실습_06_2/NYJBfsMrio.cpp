#include"NYJLinkedQueue.h"
using namespace std;
const int MAZE_SIZE = 8;
char map[MAZE_SIZE][MAZE_SIZE] ={
	{'1', '1', '1', '1', '1', '1', '1', '1' },
	{'e', '0', '1', '0', '0', '0', '1', '1' },
	{'1', '0', '1', '0', '1', '0', '0', '1' },
	{'1', '0', '1', '0', '1', '1', '1', '1' },
	{'1', '0', '0', '0', '0', '1', '1', '1' },
	{'1', '0', '1', '1', '0', '0', '0', '1' },
	{'1', '0', '1', '1', '1', '1', '0', 'x' },
	{'1', '1', '1', '1', '1', '1', '1', '1' }
};
bool isValidLoc( int r, int c){
	if(r<0 || c< 0 || r>=MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] =='x';
}

void main()
{
	LinkedQueue locQueue;
	locQueue.enqueue(new Node(1,0));

	while( locQueue.isEmpty() == false){
		int r =locQueue.peek()->row;
		int c =locQueue.peek()->col;
			locQueue.dequeue();
		printf("(%d,%d)",r,c);
		if(map[r][c] == 'x'){
			printf("BFS 미로 탐색 성공\n");
				getchar();
				getchar();
			return;
		}
		else{
			map[r][c] = '.';
			if(isValidLoc(r-1,c)) locQueue.enqueue(new Node(r-1,c));
			if(isValidLoc(r+1,c)) locQueue.enqueue(new Node(r+1,c));
			if(isValidLoc(r,c-1)) locQueue.enqueue(new Node(r,c-1));
			if(isValidLoc(r,c+1)) locQueue.enqueue(new Node(r,c+1));
		}
	}
	printf("미로탐색실패\n");
	getchar();
	getchar();
}