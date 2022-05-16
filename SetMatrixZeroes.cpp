// Shibam Debnath
// May 16,2022

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int row_flag = 0;
    int col_flag = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                {
                    row_flag = 1;
                }
                if (j == 0)
                {
                    col_flag = 1;
                }
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (row_flag == 1)
    {
        int m = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (col_flag == 1)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}
