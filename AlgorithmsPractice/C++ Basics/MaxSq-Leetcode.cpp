My Solution : 57/68 passed, time exceeded


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    int maxSq = 0;
    int thisSq = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++){
                    thisSq = checkSquare(matrix, i, j);
                    if (thisSq  > maxSq)
                        maxSq = thisSq;
            }
        
    return maxSq*maxSq;
    }
    
    int checkSquare(vector<vector<char>>& matrix, int i, int j)
    {
        if(matrix[i][j] == '1'){
            if( i + 1 < matrix.size()){
                if( j + 1 < matrix[i].size())
                    return min({checkSquare(matrix,i+1,j),checkSquare(matrix,i,j+1),checkSquare(matrix,i+1,j+1)}) + 1;
                else
                    return 1;
                }
            else
                return 1;
        }
        else
            return 0;

    }
};

Accepted Solution : 

int maximalSquare(vector<vector<char>>& matrix) {
    int rst = 0;
    for(int ii=0; ii<matrix.size(); ++ii)
    {
        for(int jj=0; jj<matrix[0].size(); ++jj)
        {
            int a = (ii&&jj) ? matrix[ii-1][jj-1] : 0;  // This means that if i,j are both 1, then a = previous value
            int b = (ii) ? matrix[ii-1][jj] : 0;        // if only i
            int c = (jj) ? matrix[ii][jj-1] : 0;

            matrix[ii][jj] = (matrix[ii][jj]>'0') ? (min(a, min(b, c))+1) : 0;
            
            rst = max(rst, matrix[ii][jj]*matrix[ii][jj]);
        }
    }
    return rst;
}