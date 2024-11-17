class Solution {
      public static int getMaxArea(char arr[], int n) {
            Stack<Integer> s = new Stack<Integer>();
            int res = 0;
            int tp = 0;
            int curr = 0;
            for (int i = 0; i < n; i++) {
                while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                    tp = s.pop();
                    curr = arr[tp] * (s.empty() ? i : i - s.peek() - 1);
                    res = Math.max(curr, res);
                }
                s.push(i);
            }
            while (!s.isEmpty()) {
                tp = s.pop();
                curr = arr[tp] * (s.empty() ? n : n - s.peek() -1 );
                res = Math.max(curr, res);
            }
            return res;
        }

    public int maximalRectangle(char[][] mat) {
        if (mat == null || mat.length == 0 || mat[0].length == 0){
            return 0;
        }
            int r = mat.length;
        int c = mat[0].length;
        char[] heights = new char[c];
        int res = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            res = Math.max(res, getMaxArea(heights, c));
        }
        return res;
        }
    }