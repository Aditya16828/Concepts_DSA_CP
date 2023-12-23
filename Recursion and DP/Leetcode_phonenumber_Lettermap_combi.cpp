#include <bits/stdc++.h>
#define ll long long int

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/

string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
    vector<string> ans;
public:
    void helper(int i, string output, string &digits){
        if(i==digits.length()){ans.push_back(output);return;}
        for(auto &c:arr[digits[i]-'0']){
            helper(i+1, output+c, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) ans={};
        else helper(0,"",digits);
        return ans;
    }
};

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    
    
	return 0;
}
