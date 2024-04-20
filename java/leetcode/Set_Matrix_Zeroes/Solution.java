package leetcode.Set_Matrix_Zeroes;

class Solution {
    public static void main(String[] args) {
        int[][] matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
        Solution solution = new Solution();
        solution.setZeroes(matrix);

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(" "+matrix[i][j]);
            }
            System.out.println();
        }
    }

    public void setZeroes(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        boolean[] rows = new boolean[n];
        boolean[] columns = new boolean[m]; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    rows[i] = true;
                    columns[j] = true;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rows[i] || columns[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}