class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda e: (e[1], -e[0]))

        res = [intervals[0][1]-1, intervals[0][1]]

        for e in intervals[1:]:

            if res[-2] < e[0] and res[-1] >= e[0]:
                res.append(e[1])

            elif e[0] > res[-1]:
                res.extend([e[1]-1, e[1]])

        return len(res)
