#include<iostream>
using namespace std;
bool checkcol(int board[][8],int row,int col) {
	if (board[row][col] == 1) {
		return true;
	}
	else if (col>=8) {
		return false;
	}
	else{
		return checkcol(board, row, col+1);
	}
}
bool checkupdiag(int board[][8], int row, int col) {
	if (board[row][col] == 1 /* && row>0 || row == 0 && col > 0 || col == 0*/) {
		return true;
	}
	else if (col >= 8 && row >=8) {
		return false;
	}
	else {
		return checkupdiag(board, row-1, col -1);
	}
}
bool checklowdiag(int board[][8], int row, int col) {
	if (board[row][col] == 1/* && col > 0 || col == 0 && row <8 */ ) {
		return true;
	}
	else {
		return checklowdiag(board, row + 1, col + 1);
	}
}
bool canplace(int board[8][8],int row,int col) {
	int i = 0;
	bool checker=checkcol(board,row,col),
		checker1=checkupdiag(board,row,col),
		checker2 = checklowdiag(board, row, col);
	if (checker == true || checker1 == true ||checker2 == true) {
		return false;
	}
	return true;
}
bool place(int board[][8],int row,int col) {
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 3 && j == 0 || i == 0 && j == 1 || i == 2 && j == 2 || i == 1 && j == 3) {
				cout << " 1 " << " ";
			}
			else
				cout << " 0 " << " ";
		}
		cout << endl;
	}*/
	if (col >= 8) {
		return true;
	}
	else {
		if (canplace(board, row, col)) {
			board[row][col] = 1;
			if (place(board, row, col + 1))
				return true;
			board[row][col] = 0;
			return place(board, row + 1, col);
		}
		return false;
	}
}
int main() {
	int* queens{ new int[8] {1,2,3,4,5,6,7,8} }, 
		chess[8][8] = { 
    {0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0}, 
	{0,0,0,0,0,0,0,0}, 
};
	bool cond = place(chess, 0, 0);
	if (cond == true) {
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << chess[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
