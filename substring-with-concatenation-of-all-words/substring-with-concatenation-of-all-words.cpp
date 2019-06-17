#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> allPos;
        if(words.empty()) return allPos;
        int totalWords = words.size();
        int wordSize = words[0].size();
        int totalLen = wordSize * totalWords;
        if(s.size()<totalLen) return allPos;
        
        unordered_map<string,int> wordCount;
        for(int i=0; i<totalWords; i++)
            wordCount[words[i]]++;
        
        for(int i=0; i<=s.size()-totalLen; i++) {
            if(checkSubstring(s, i, wordCount, wordSize, totalWords))
                allPos.push_back(i);
        }
        return allPos;
    }
    
    bool checkSubstring(string S, int start, unordered_map<string,int> &wordCount, int wordSize, int totalWords) {
        if(S.size()-start+1 < wordSize*totalWords) return false;
        unordered_map<string,int> wordFound;
        
        for(int i=0; i<totalWords; i++) {
            string curWord = S.substr(start+i*wordSize,wordSize);
            if(!wordCount.count(curWord)) return false;
            wordFound[curWord]++;
            if(wordFound[curWord]>wordCount[curWord]) return false;
        }
        return true;    
    }
};

int main(void){
    Solution sl;

    string s = "barfoothefoobarman";
    vector<string> words({"foo", "bar"});

    vector<int> ret = sl.findSubstring(s, words);

    for(int i = 0; i < ret.size(); i++)
        printf("%d ", ret[i]);

    printf("\n");
}
