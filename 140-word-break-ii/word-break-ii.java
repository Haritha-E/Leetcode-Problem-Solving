import java.util.*;

class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> result = new ArrayList<>();
        backtrack(s, wordDict, new StringBuilder(), 0, result);
        return result;
    }

    private void backtrack(String s, List<String> wordDict, StringBuilder current, int start, List<String> result) {
        if (start == s.length()) {
            result.add(current.toString().trim());
            return;
        }

        for (int end = start + 1; end <= s.length(); end++) {
            String substring = s.substring(start, end);
            if (wordDict.contains(substring)) {
                int currentLength = current.length();
                current.append(substring).append(" ");
                backtrack(s, wordDict, current, end, result);
                current.setLength(currentLength);
            }
        }
    }
}