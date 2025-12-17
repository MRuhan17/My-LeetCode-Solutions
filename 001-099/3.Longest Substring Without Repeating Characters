class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_index_map = {}
        left_ptr = 0
        max_length = 0

        for right_ptr, char in enumerate(s):
            if char in char_index_map and char_index_map[char] >= left_ptr:
                left_ptr = char_index_map[char] + 1
            
            char_index_map[char] = right_ptr
            max_length = max(max_length, right_ptr - left_ptr + 1)
        
        return max_length
