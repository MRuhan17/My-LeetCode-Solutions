class Solution: 
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int: 
 
        dim = len(A) 
 
        def shift_and_count(x_shift, y_shift, M, R): 
            # move it around and see what sticks
            # moving one up is basically the other going down
            left_shift_count, right_shift_count = 0, 0 
            
            for r_row, m_row in enumerate(range(y_shift, dim)): 
                for r_col, m_col in enumerate(range(x_shift, dim)): 
                    if M[m_row][m_col] == 1 and M[m_row][m_col] == R[r_row][r_col]: 
                        left_shift_count += 1 
                    if M[m_row][r_col] == 1 and M[m_row][r_col] == R[r_row][m_col]: 
                        right_shift_count += 1 
 
            return max(left_shift_count, right_shift_count) 
 
        max_overlaps = 0 
 
        # just try every possible shift and let the best one win
        for y_shift in range(0, dim): 
            for x_shift in range(0, dim): 
                
                # move A around B
                max_overlaps = max(max_overlaps, shift_and_count(x_shift, y_shift, A, B)) 
                
                # and now let B have its turn
                # same idea, just from the other side
                max_overlaps = max(max_overlaps, shift_and_count(x_shift, y_shift, B, A)) 
 
        return max_overlaps
