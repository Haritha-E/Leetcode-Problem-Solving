class Solution {
    public int calculate(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') continue;
            sb.append(s.charAt(i));
        }
        s = sb.toString();
        int num = 0;
        int res = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '*') {
                int nextNum = 0;
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    i++;
                    nextNum = nextNum * 10 + (s.charAt(i) - '0');
                }
                num = num * nextNum;
            } else if (c == '/') {
                int nextNum = 0;
                while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                    i++;
                    nextNum = nextNum * 10 + (s.charAt(i) - '0');
                }
                num = num / nextNum;
            }
        }
        res += sign * num;
        return res;
    }
}