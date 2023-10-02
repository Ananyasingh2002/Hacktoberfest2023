class Solution {
public:
    vector<int> boundaryTraversal(vector<vector<int>>& matrix, int n, int m) {
        vector<int> out;
        int i = 0, j = 0;
        for(; j < m; ++j) out.push_back(matrix[i][j]);
        ++i; --j;
		
        if(n > 1) {
            for(; i < n; ++i) out.push_back(matrix[i][j]);
            --i; --j;
			
            if(m > 1) {
                for(; j >= 0; --j) out.push_back(matrix[i][j]);
                --i; ++j;
				
                for(; i > 0; --i) out.push_back(matrix[i][j]);
            }
        }
        return out;
    }
};
