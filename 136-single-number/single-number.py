class Solution:
    def singleNumber(self, l: List[int]) -> int:
        return 2*sum(set(l)) - sum(l)
        