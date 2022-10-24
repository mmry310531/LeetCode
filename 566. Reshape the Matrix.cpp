class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        // if(r*c != mat.size()*mat[0].size()) return mat;
        // vector<vector<int>> reshapeResult(r, vector<int>(c, 0));
        // vector<int> tmp;
        // for(int i=0;i<mat.size();i++){
        //     for(int j=0;j<mat[0].size();j++){
        //         tmp.push_back(mat[i][j]);
        //     }
        // }
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         reshapeResult[i][j] = tmp[i*c+j];
        //     }
        // }
        // return reshapeResult;

        int mat_r = mat.size();
        int mat_c = mat[0].size();
        if(mat_r * mat_c != r * c) return mat;

        vector<vector<int>> reshapeResult(r, vector<int>(c, 0));
        int total = mat_r * mat_c;

        for(int i=0;i<total;i++){
            reshapeResult[i/c][i%c] = mat[i/mat_c][i%mat_c];
        }
        return reshapeResult;

    }
};