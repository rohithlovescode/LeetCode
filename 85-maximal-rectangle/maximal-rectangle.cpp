class Solution {
public:
int largestRectangleArea(vector<int> heights) {
        // left
        // right
        // right-left-1
        // heights[i]*width
        // max area
        // yahi cheeze karni NSR-NSL-1
        vector<int> v;
        vector<int> v1;
        stack<pair<int, int>> lst;

        int pseudo = -1;
       
        for (int i = 0; i < heights.size(); i++) {
            if (lst.size() == 0) {
                v.push_back(pseudo);
            } else if (lst.size() > 0 && lst.top().first < heights[i]) {
                v.push_back(lst.top().second);
            } else if (lst.size() > 0 && lst.top().first >= heights[i]) {
                while (lst.size() > 0 && lst.top().first >= heights[i]) {
                    lst.pop();
                }
                if (lst.size() == 0)
                    v.push_back(pseudo);
                else
                    v.push_back(lst.top().second);
            }
            lst.push({heights[i], i});
        }
        stack<pair<int, int>> rst;
        int pseudo1 = heights.size();
      
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (rst.size() == 0) {
                v1.push_back(pseudo1);
            } else if (rst.size() > 0 && rst.top().first < heights[i]) {
                v1.push_back(rst.top().second);
            } else if (rst.size() > 0 && rst.top().first >= heights[i]) {
                while (rst.size() > 0 && rst.top().first >= heights[i]) {
                    rst.pop();
                }
                if (rst.size() == 0)
                    v1.push_back(pseudo1);
                else
                    v1.push_back(rst.top().second);
            }
            rst.push({heights[i], i});
        }
        reverse(v1.begin(), v1.end());
        int width[heights.size() + 1];
        int maxi = -1;
        int area;
        for (int i = 0; i < heights.size(); i++) {
            width[i] = v1[i] - v[i] - 1;
        }

        for (int i = 0; i < heights.size(); i++) {
            area = heights[i] * width[i];
            maxi = max(maxi, area);
        }
        return maxi;
    }
    vector<vector<int>> convertCharToIntBinaryArray(const vector<vector<char>>& matrix) {
    vector<vector<int>> matrix1;
    for (const auto& row : matrix) {
        vector<int> intRow;
        for (char element : row) {
            intRow.push_back(element - '0');
        }
        matrix1.push_back(intRow);
    }
    return matrix1;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        //n number of maximum histogram problems 
        //1). convert char to integer matrix
        //2). largest rectangle problem 
        //3). calculate maximum area for each histogram 
        //4). return maximum one 
        vector<vector<int>> matrix1 = convertCharToIntBinaryArray(matrix);
        int row = matrix1.size();
        int col = matrix1[0].size();
        vector<int>v2;
        for(int j=0;j<col;j++)
        {
            v2.push_back(matrix1[0][j]);
        }
        int maxwell=largestRectangleArea(v2);
        
        for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix1[i][j]==0)
                v2[j]=0;
                else
                v2[j]=v2[j]+matrix1[i][j];
            }
            maxwell=max(maxwell,largestRectangleArea(v2));
        }
        return maxwell;
    }
};