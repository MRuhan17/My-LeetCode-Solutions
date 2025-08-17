class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s = ''
        for letters in zip(*strs):
            if any(l != letters[0] for l in letters):
                return s
            s += letters[0]

        return s
