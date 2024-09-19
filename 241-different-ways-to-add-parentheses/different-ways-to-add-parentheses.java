import java.util.*;
public class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> result = new ArrayList<>();
        for(int i=0;i<expression.length();i++){
            char c = expression.charAt(i);
            if(c == '+' || c == '-' || c == '*'){
                List<Integer> firstHalf = diffWaysToCompute(expression.substring(0,i));
                List<Integer> secondHalf = diffWaysToCompute(expression.substring(i+1));

                for(int first:firstHalf){
                    for(int second:secondHalf){
                        if(c == '+')
                        result.add(first+second);
                        else if(c == '-')
                        result.add(first-second);
                        else if(c == '*')
                        result.add(first*second);
                    }
                }
            }
        }
        if(result.isEmpty())
        result.add(Integer.parseInt(expression));
        return result;
    }
}