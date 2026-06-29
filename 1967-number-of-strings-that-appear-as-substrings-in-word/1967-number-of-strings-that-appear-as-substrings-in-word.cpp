class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(int i=0;i<patterns.size();i++){
            int x=word.find(patterns[i]);
            if(x>=0){
                count++;
            }
        }
        return count;
    }
};