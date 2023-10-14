class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> n;
        if (x < 0 or (x % 10 == 0 && x!=0) )
            return false;

        while(x >= 0){
            n.push_back(x%10);
            if (x < 10)
                break;
            x = x/10;

        }
        for (int i = 0; i <n.size()/2;i++){
            if(n[i]!= n[n.size()-1-i])
                return false;
        }
        return true;
    }
};