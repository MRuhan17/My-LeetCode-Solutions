class Twitter {
    private Map<Integer, Set<Integer>> followMap; 
    private Map<Integer, List<Tweet>> tweetMap; 
    private int timestamp;
    
    private class Tweet {
        int tweetId;
        int time;
        
        public Tweet(int tweetId, int time) {
            this.tweetId = tweetId;
            this.time = time;
        }
    }

    public Twitter() {
        followMap = new HashMap<>();
        tweetMap = new HashMap<>();
        timestamp = 0;
    }
    
    public void postTweet(int userId, int tweetId) {
        tweetMap.putIfAbsent(userId, new ArrayList<>());
        tweetMap.get(userId).add(new Tweet(tweetId, timestamp++));
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> feed = new ArrayList<>();
        
        PriorityQueue<Tweet> maxHeap = new PriorityQueue<>((a, b) -> b.time - a.time);
        
        if (tweetMap.containsKey(userId)) {
            maxHeap.addAll(tweetMap.get(userId));
        }
        
        if (followMap.containsKey(userId)) {
            for (int followeeId : followMap.get(userId)) {
                if (tweetMap.containsKey(followeeId)) {
                    maxHeap.addAll(tweetMap.get(followeeId));
                }
            }
        }
        
        int count = 0;
        while (!maxHeap.isEmpty() && count < 10) {
            feed.add(maxHeap.poll().tweetId);
            count++;
        }
        
        return feed;
    }
    
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; 
        followMap.putIfAbsent(followerId, new HashSet<>());
        followMap.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (followMap.containsKey(followerId)) {
            followMap.get(followerId).remove(followeeId);
        }
    }
}
