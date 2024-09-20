class Solution {
    public int minBitFlips(int start, int goal) {
        String startBinary = Integer.toBinaryString(start);
        String goalBinary = Integer.toBinaryString(goal);
        return Integer.bitCount(start^goal);
    }
}