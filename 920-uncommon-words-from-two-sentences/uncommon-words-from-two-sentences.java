class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
       String[] words = s1.split(" ");  
       String[] word2 = s2.split(" ");
        Set<String> s=new HashSet<String>();
        Set<String> c=new HashSet<String>();
       
       for(int i=0;i<words.length;i++)
       {
        if(s.contains(words[i]))
        { c.add(words[i]);
        }
        else
        {
            s.add(words[i]);
        }
       }
       for(int i=0;i<word2.length;i++)
       {
        if(s.contains(word2[i]))
        { c.add(word2[i]);
          
        }
        else
        {
            s.add(word2[i]);
        }
       }
       for(String elements:c)
       {
        s.remove(elements);
       }
       String[] array = s.toArray(new String[0]);
       return array;
    }
}