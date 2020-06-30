#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int board[10][10];
string answer;
void concatBoard(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			string c=to_string(board[i][j]);
			answer+=c;
		}
        answer.append("\n");
	}
	answer.append("\n");
}
bool check(int row, int col,int n)
{
	int i, j;

	for (i=0;i< col;i++)
		if (board[row][i])
			return false;

	for (i=row,j=col;i>=0&&j>=0;i--,j--)
		if (board[i][j])
			return false;

	for (i=row,j=col;j>=0&&i<n;i++,j--)
		if (board[i][j])
			return false;

	return true;
}

bool solve(int col,int n)
{
	if (col == n)
	{
		concatBoard(n);
		return true;
	}
	bool res = false;
	for (int i = 0; i <n; i++)
	{
		if ( check(i,col,n) )
		{
			board[i][col] = 1;
			res = solve(col + 1,n) || res;
			board[i][col] = 0;
		}
	}
	return res;
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
string nQueens(int n)
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	bool t=solve(0,n);
	if(t==true)
		return answer;
	else
		return "No Solution Exists\n";
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    int n;
    cin>>n;
	cout<<nQueens(n);
}
