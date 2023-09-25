bool cmp(string &a, string &b)
{
    return a.length() < b.length();
}

class Solution {
public:

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), cmp);

        for(int i=0; i<words.size(); i++)
        {
            mp[words[i]] = 1;
            
            for(int j=0; j<words[i].length(); j++)
            {
                string check = "";
                check += words[i].substr(0, j);
                if(j+1 < words[i].length())
                check += words[i].substr(j+1);
                if(mp.count(check) > 0)
                {
                    mp[words[i]] = max(mp[words[i]], 1 + mp[check]);
                }
            }
        }

        int res = INT_MIN;

        for(auto x: mp)
        {
            res = max(res, x.second);
        }

        return res;
    }
};
