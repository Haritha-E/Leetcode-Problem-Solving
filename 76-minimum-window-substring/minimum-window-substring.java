class Solution {
    public String minWindow(String a, String b) {
       int ascii[]=new int[128];
       for(char ch:b.toCharArray()){
        ascii[ch]++;
       } 
       int counter=b.length();
       int start=0;
       int minstart=0;
       int minlen=Integer.MAX_VALUE;
       for(int  i=0;i<a.length();i++){
        char ch=a.charAt(i);
        if(ascii[ch]>0){
            counter--;
        }ascii[ch]--;
        while(counter==0){
            if(minlen > i-start+1){
                minlen=i-start+1;
                minstart=start;
            }
            char front=a.charAt(start);
            ascii[front]++;
            if(ascii[front]>0){
                counter++;
            }start++;
        }
         }  return minlen==Integer.MAX_VALUE?"":a.substring(minstart,minstart+minlen);
    }
}