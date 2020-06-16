#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

struct TrieNode{
	struct TrieNode *children[26]; 
	bool isEndOfWord; 
};

struct TrieNode* getNode(void){

	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < 26; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
}


void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

        // mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 

string trieSearch(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length()&&pCrawl!=NULL; i++) 
	{ 
		int index = key[i] - 'a'; 
		if (pCrawl->isEndOfWord) 
			return key.substr(0,i);

		pCrawl = pCrawl->children[index]; 
	} 

	return key;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
string replaceWords(vector<string>& dict, string sentence) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	
	string ans ="";

	struct TrieNode *trie = getNode();

	for(auto root:dict){
		insert(trie,root);
	}
	for(int i=0;i<sentence.length();i++){
		stringstream word;

		while(i<sentence.length()&&sentence[i]!=' '){
			word<<sentence[i];
			i++;
		}
		ans = ans + trieSearch(trie,word.str());
		if(i<=sentence.length()-1){
			ans.push_back(' ');
		}
	}
	return ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

}

int main(){

    int n;cin>>n;
    vector<string> dict(n,"");

    for(int i=0;i<n;i++){
    	cin>>dict[i];
    }
    string sentence;
	getline(cin,sentence);
	getline(cin,sentence);
    string ans = replaceWords(dict,sentence);
    cout<<ans<<endl;

}
