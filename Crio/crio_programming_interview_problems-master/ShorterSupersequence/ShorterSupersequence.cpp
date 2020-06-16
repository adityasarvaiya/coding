#include<bits/stdc++.h>
using namespace std;

int shortestSupersequence(  int smaller_size, vector<int> &ar, int larger_size, vector<int> &br)
{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	map<int, int> M;
	int l = 0, r = 0, ans = 1e9 , start = 0, end = 0;

	for ( int i = 0 ; i < smaller_size ; i++) {
		M[ar[i]]++;
	}

	int required =  M.size();
	int formed = 0;
	map<int , int > Windowcount;
	while (r < larger_size) {
		Windowcount[br[r]]++;
		if (Windowcount[br[r]] == M[br[r]]) {
			formed++;
		}
		while (l <= r && formed == required) {
			int last = br[l];

			ans = min(ans, r - l + 1);
			start = l;
			end = r;


			Windowcount[br[l]]--;
			if (M[br[l]] > 0 && Windowcount[br[l]] < M[br[l]]) {
				formed --;
			}
			l++;
		}
		r++;
	}
	if ( ans == 1e9) return -1;
	return ans ;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int smaller_size , larger_size;
	cin >> smaller_size >> larger_size;
	vector<int> ar(smaller_size), br(larger_size);

	for (int i = 0; i < smaller_size; i++)
		cin >> ar[i];
	for (int i = 0; i < larger_size; i++)
		cin >> br[i];
	if (smaller_size > larger_size) {
		swap(smaller_size, larger_size);
		swap(ar, br);
	}
	cout << shortestSupersequence(smaller_size, ar, larger_size, br) << endl;
}