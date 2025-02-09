class Twitter
{
    struct Tweet
    {
        int tweetId;
        int time;
        // Tweet(int id, int t): tweetId(id), time(t){};

        Tweet(int id, int t)
        {
            tweetId = id;
            time = t;
        }
    };

    // global clock
    int time;

    // map, userId to TWEETS, userId to the tweets that the user has posted
    unordered_map<int, vector<Tweet>> tweets;

    // map, userID to unordered_set userid, userId to his followings
    unordered_map<int, unordered_set<int>> following;

    class comp
    {
    public:
        bool operator()(const Tweet &a, const Tweet &b)
        {
            return a.time > b.time;
        }
    };

public:
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }

    // returning the tweetIds of 10 most recents tweets done by me OR by my followings
    vector<int> getNewsFeed(int userId)
    {
        // Min-heap to keep track of top 10 most recent tweets
        priority_queue<Tweet, vector<Tweet>, comp> minHeap;

        // add my tweets
        if (tweets.find(userId) != tweets.end())
        {
            for (auto tweet : tweets[userId])
            {
                minHeap.push(tweet);
                if (minHeap.size() > 10)
                    minHeap.pop(); // remove the oldest tweet
            }
        }

        // Add tweets from my followings
        if (following.find(userId) != following.end())
        {
            auto myFollowings = following[userId];
            for (auto followeeId : myFollowings)
            {
                if (tweets.find(followeeId) != tweets.end())
                {
                    for (auto tweet : tweets[followeeId])
                    {
                        minHeap.push(tweet);
                        if (minHeap.size() > 10)
                            minHeap.pop(); // remove the oldest tweet
                    }
                }
            }
        }

        // now I will have top 10 most recent tweets from userID and from the followings of userID
        vector<int> newsFeedTweets;
        while (!minHeap.empty())
        {
            auto [tweetId, time] = minHeap.top();
            minHeap.pop();
            newsFeedTweets.push_back(tweetId);
        }

        reverse(newsFeedTweets.begin(), newsFeedTweets.end());
        return newsFeedTweets;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return; // I can't follow myself
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (following.find(followerId) != following.end())
            following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */