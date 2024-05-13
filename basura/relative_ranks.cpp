#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int size = score.size();
        vector<string> ans(size);
	vector<int> tmp(score.begin(), score.end());
        map<int,string> places;

        sort(tmp.rbegin(), tmp.rend());
        
        places[ tmp[0] ] = "Gold Medal";
        places[ tmp[1] ] = "Silver Medal";
        places[ tmp[2] ] = "Bronze Medal";
        
        for (int i = 3; i < size; ++i)
        {
            places[ tmp[i] ] = to_string(i + 1);
        }

        for (int i = 0; i < size; ++i)
        {
            ans[i] = places[ score[i] ];
        }
        
        return ans;
    }
};

int main()
{
	Solution solve;
	vector<int> score = {10,3,8,9,4};
	solve.findRelativeRanks(score);
}
