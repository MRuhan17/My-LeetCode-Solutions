class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        path = [0] * numCourses
        adj= [[] for _ in range(numCourses)]
        deg = [0] * numCourses
        for a, b in prerequisites:
            adj[a].append(b)
            path[b] |= ( 1 << a)
            deg[b] += 1

        queue = deque()

        for i in range(numCourses):
            if deg[i] == 0:
                queue.append(i)

        while queue:
            i = queue.popleft()
            for j in adj[i]:
                path[j] |= path[i]
                deg[j] -= 1
                if deg[j] == 0:
                    queue.append(j)

        ans = [False] * len(queries)

        for i, (u, v) in enumerate(queries):
            ans[i] = (path[v] >> u) & 1 == 1

        return ans


        
