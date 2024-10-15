class Solution {
    public long minimumSteps(String s) {
        long numberOfSwaps = 0;
        long numberOfBlackPieces = 0;
        for(int i = 0; i<s.length();i++){
            if(s.charAt(i) == '0'){
                numberOfSwaps += numberOfBlackPieces;
            }
            else{
                numberOfBlackPieces += 1;
            }
        }
        return numberOfSwaps;
    }
}