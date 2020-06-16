#include <bits/stdc++.h>
using namespace std;

class WordLadder {
  public:
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        bool isValidTranformation(string a, string b)
        {
            int difference = 0;
            for (int i = 0; i < a.length(); ++i)
            {
                if (a[i] != b[i]) {
                    difference++;
                }
            }
            return difference == 1;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        int ladderLength(string beginWord, string endWord,vector<string> wordList) 
        {
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            wordList.push_back(beginWord);
            vector<vector <int> > vec(wordList.size());
            int destination = -1;
            for(int i=0;i<wordList.size();i++)
            {
                for(int j=i+1;j<wordList.size();j++)
                {
                    if(isValidTranformation(wordList[i],wordList[j]))
                    {
                        vec[i].push_back(j);
                        vec[j].push_back(i);
                    }
                }
                if(wordList[i]==endWord)
                    destination =i;
            }


            queue<int> q;
            int level[wordList.size()]={0};
            q.push(wordList.size()-1);
            level[wordList.size()-1]=1;
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
                for(int i=0;i<vec[front].size();i++)
                {
                    if(level[vec[front][i]]==0)
                    {
                        q.push(vec[front][i]);
                        level[vec[front][i]]=level[front]+1;
                    }
                }
            }

            
            if(destination == -1)
                return 0;
            else if(level[destination]==0)
                return 0;
            else
                return level[destination];

            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};

int main() {
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList;
    for(int i =0;i<n;i++)
    {
        string s;
        cin>>s;
        wordList.push_back(s);
    }
    int result = WordLadder().ladderLength(beginWord, endWord, wordList);
    cout << result;
    return 0;
}
