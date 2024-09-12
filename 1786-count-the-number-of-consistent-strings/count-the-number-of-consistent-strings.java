class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int count = 0;
        char[] all = allowed.toCharArray();
        HashSet<Character> set = new HashSet<Character>();
        for(char ch : all){
            set.add(ch);
        }
        for(String word : words){
            boolean consistent = true;
            for(char ch : word.toCharArray()){
                if(!set.contains(ch)){
                    consistent = false;
                    break;
                }
            }
            if(consistent)
            count++;
        }
        return count;
    }
}