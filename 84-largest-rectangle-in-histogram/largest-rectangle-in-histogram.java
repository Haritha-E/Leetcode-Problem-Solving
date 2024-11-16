class Solution {
    public int largestRectangleArea(int[] heights) {
        int left[]=new int[heights.length];
        int right[]=new int[heights.length];


        Stack<Integer> st=new Stack<>();//used to store index
        for(int i=0;i<heights.length;i++){
            while(!st.isEmpty() && heights[st.peek()]>=heights[i]){
                st.pop();
            }
            left[i]=st.isEmpty()?-1:st.peek();
            st.push(i);
        }

        st.clear();

        for(int i=heights.length-1;i>=0;i--){
            while(!st.isEmpty() && heights[st.peek()]>heights[i]){
                st.pop();
            }
            right[i]=st.isEmpty()?heights.length:st.peek();
            st.push(i);
        }
        int max=Integer.MIN_VALUE;
        for(int i=0;i<heights.length;i++){
            int area=heights[i]*(right[i]-left[i]-1);
            max=Math.max(max,area);
        }
        return max;
    }
}