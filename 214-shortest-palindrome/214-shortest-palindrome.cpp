class Solution {
public:
    string shortestPalindrome(string s) {
        string x = s;
        reverse(x.begin(), x.end());
        string pat = s + "*" + x;
        int n = pat.size();
        
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        
        while(i < n) {
            if(pat[i] == pat[j]) 
                lps[i++] = ++j;
            else {
                if(!j) i++;
                else j = lps[j-1];
            }
        }
        string temp = s.substr(lps[n-1]); //last element in lps array to know the longest match
        reverse(temp.begin(), temp.end());
        
        return temp + s;
    }
};



//The problem asks us to find the sortest string to be added to the front of "s" to make it a palindrome

//To solve this, we can find the longest palindrome starting from idx "0" and then we can add the reverse of the remaining characters (last chars) to the front of "s" to get a palindrome

//How to find the longest palindrome starting from idx "0"? 

//We form a string str = s + "#" + reverse(s). We use KMP to find the longest common prefix that's also a postfix. Then we add the remaining length chars from "s" to get the ans.

//Why to add "#" ? It's because we're forcing the reverse string to match with the prefix of "s" and not the postfix (see eg.1 to understand => The last a's in s can match with the reverse. We don't want this to happen!)
