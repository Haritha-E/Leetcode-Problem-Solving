class Solution {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);
        int curr=skill[0]+skill[skill.length-1];
        long sum=skill[0]*skill[skill.length-1];
        int i=1;
        int j=skill.length-2;
        while(i<j){
            if(curr!=skill[i]+skill[j]) return -1;
            sum+=skill[i]*skill[j];
            i++;
            j--;
        }
        return sum;
        
    }
}