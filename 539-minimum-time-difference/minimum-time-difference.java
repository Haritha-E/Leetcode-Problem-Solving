class Solution {
    public int findMinDifference(List<String> timePoints) {
        ArrayList<Integer> min=new ArrayList<>();
        for(int i=0;i<timePoints.size();i++){
            String words[]=timePoints.get(i).split(":");
            int h=Integer.parseInt(words[0]);
            int m=Integer.parseInt(words[1]);
            min.add(h*60+m);
        }
        Collections.sort(min);
        int minDiff=Integer.MAX_VALUE;
        for(int i=1;i<min.size();i++){
            int diff=min.get(i)-min.get(i-1);
            minDiff=Math.min(minDiff,diff);
        }
        int firstDiff=(1440- min.get(min.size() - 1))+min.get(0);
        minDiff=Math.min(minDiff,firstDiff);
        return minDiff;
    }
}