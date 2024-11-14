import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (words == null || words.length == 0 || s.length() == 0) return result;

        int wordLen = words[0].length();
        int totalLen = wordLen * words.length;
        if (s.length() < totalLen) return result;

        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i, count = 0;
            Map<String, Integer> seenWords = new HashMap<>();

            while (right + wordLen <= s.length()) {
                String word = s.substring(right, right + wordLen);
                right += wordLen;

                if (wordCount.containsKey(word)) {
                    seenWords.put(word, seenWords.getOrDefault(word, 0) + 1);
                    count++;

                    while (seenWords.get(word) > wordCount.get(word)) {
                        String leftWord = s.substring(left, left + wordLen);
                        seenWords.put(leftWord, seenWords.get(leftWord) - 1);
                        count--;
                        left += wordLen;
                    }

                    if (count == words.length) {
                        result.add(left);
                    }
                } else {
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.findSubstring("barfoothefoobarman", new String[]{"foo", "bar"})); // Output: [0, 9]
        System.out.println(solution.findSubstring("wordgoodgoodgoodbestword", new String[]{"word", "good", "best", "word"}));
        System.out.println(solution.findSubstring("barfoofoobarthefoobarman", new String[]{"bar", "foo", "the"}));
    }
}