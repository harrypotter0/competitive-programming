class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int>> flag(row, vector<int>(col, -1));
        int c, r;
        
        // find the first '1' (i.e. the first island) by scaning the matrix
        for (int i = 0; i < row * col; i++)
        {
            c = i % col;
            r = i / col;
            if (A[r][c] == 1)
                break;
        }
        
        // start from the first '1', use bfs to find all the '1' from the same island
        // also remember the all neighbor '0' of the first island
        queue<pair<int,int>> q1,q2;
        q1.push({r,c});
        flag[r][c] = 1;
        
        int d[][2] = {{-1,0}, {0,1}, {1,0}, {0, -1}};
        while (!q1.empty())
        {
            auto cur = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++)
            {
                int newr = cur.first + d[i][0];
                int newc = cur.second + d[i][1];
                
                if (newr < 0 || newc < 0 || newr >= row || newc >= col) continue;
                
                if (flag[newr][newc] == 1) continue;
                
                if (A[newr][newc] == 1)
                {
                    flag[newr][newc] = 1;
                    q1.push({newr, newc});
                }
                else
                {
                    q2.push({newr, newc});
                    flag[newr][newc] = 0;
                }
            }
        }
        
        // use bfs again from the neighbor '0' of the first island, count the steps to hit
        // another other '1', which will be the second island.        
        int step = 0;
        while (!q2.empty())
        {
            auto size = q2.size();
            step++;
            for (int j = 0; j < size; j++)
            {
                auto cur = q2.front();
                q2.pop();
                for (int i = 0; i < 4; i++)
                {
                    int newr = cur.first + d[i][0];
                    int newc = cur.second + d[i][1];

                    if (newr < 0 || newc < 0 || newr >= row || newc >= col) continue;
                    
                    if (flag[newr][newc] == 1 || flag[newr][newc] == 0) continue;
                    
                    if (A[newr][newc] == 1) return step;
                    else
                    {
                        q2.push({newr, newc});
                        flag[newr][newc] = 0;
                    }
                }
            }            
        }
    }
};