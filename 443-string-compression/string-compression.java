class Solution {
    public int compress(char[] chars) {
        int i=0,j=0;
        while(i<chars.length){
            char currChar=chars[i];
            int count=0;
            while(i<chars.length && currChar==chars[i]){
                i++;
                count++;
            }
            chars[j]=currChar;
            j++;
            if(count>1){
                String stringCount=String.valueOf(count);
                for(char c: stringCount.toCharArray()){
                    chars[j]=c;
                    j++;
                }
            }
        }
        return j;
    }
}