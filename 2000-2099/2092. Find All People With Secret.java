class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        boolean[] knowsSecret = new boolean[n];
        knowsSecret[0] = true;  
        knowsSecret[firstPerson] = true;  
      
        int totalMeetings = meetings.length;
        Arrays.sort(meetings, Comparator.comparingInt(meeting -> meeting[2]));
      
        for (int i = 0; i < totalMeetings;) {
            int endIndex = i;
            while (endIndex + 1 < totalMeetings && 
                   meetings[endIndex + 1][2] == meetings[i][2]) {
                endIndex++;
            }
          
            Map<Integer, List<Integer>> adjacencyList = new HashMap<>();
            Set<Integer> peopleInCurrentTime = new HashSet<>();
          
            for (int k = i; k <= endIndex; k++) {
                int person1 = meetings[k][0];
                int person2 = meetings[k][1];
              
                adjacencyList.computeIfAbsent(person1, key -> new ArrayList<>()).add(person2);
                adjacencyList.computeIfAbsent(person2, key -> new ArrayList<>()).add(person1);
              
                peopleInCurrentTime.add(person1);
                peopleInCurrentTime.add(person2);
            }
          
            Deque<Integer> queue = new ArrayDeque<>();
          
            for (int person : peopleInCurrentTime) {
                if (knowsSecret[person]) {
                    queue.offer(person);
                }
            }
          
            while (!queue.isEmpty()) {
                int currentPerson = queue.poll();
              
                for (int neighbor : adjacencyList.getOrDefault(currentPerson, Collections.emptyList())) {
                    if (!knowsSecret[neighbor]) {
                        knowsSecret[neighbor] = true;
                        queue.offer(neighbor);
                    }
                }
            }
          
            i = endIndex + 1;
        }
      
        List<Integer> result = new ArrayList<>();
        for (int person = 0; person < n; person++) {
            if (knowsSecret[person]) {
                result.add(person);
            }
        }
      
        return result;
    }
}
