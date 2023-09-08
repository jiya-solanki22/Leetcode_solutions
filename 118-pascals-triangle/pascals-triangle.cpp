class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows<=0)
            return result;
        result.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i;j++)
            {
                v.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            v.push_back(1);
            result.push_back(v);
        }
        return result;
    }
};