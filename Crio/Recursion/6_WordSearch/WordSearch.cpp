#include <bits/stdc++.h>
using namespace std;

class WordSearch {
  public:
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<vector<int> > visit;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    bool exist(vector<vector<char>> &board, string &word) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if(word.size() > (board.size()*board[0].size())) {
            return false;
        }
        visit.resize(board.size());
        for(int i=0;i<board.size();i++)
            visit[i].resize(board[0].size());


        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    bool ans=dfs(board,word,i,j,0);
                    if(ans== true)
                        return ans;
                }
            }
        }
        return false;
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    bool dfs(vector< vector<char> > &board , string &word , int i,int j,int same)
    {
        if(same == word.size()){
            return true;
        }        
        if(i >= board.size() || i < 0 || j >= board[i].size() || j < 0){
            return false;
        }
        if(board[i][j] != word[same] || visit[i][j]) {
            return false;
        }        
        visit[i][j] = 1;
        if(dfs(board, word, i-1, j, same+1) || 
           dfs(board, word, i+1, j, same+1) ||
           dfs(board, word, i, j-1, same+1) || 
           dfs(board, word, i, j+1, same+1)){
            return true;
        }
        visit[i][j] = 0;
        return false;
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
};

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> grid(row,vector<char> (col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cin>>grid[i][j];
    }
    string word;
    cin >> word;
    bool result = WordSearch().exist(grid, word);
    if(result == true)
        cout<<"true";
    else
        cout<<"false";
}
