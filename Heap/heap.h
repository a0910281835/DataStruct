#ifndef  _H_HEAP
#define  _H_HEAP
#include "basic.h"

typedef struct HEAP_T * P_HEAP_T;


typedef struct HEAP_T
{
    NUM_T capacity;
    NUM_T size;
    int *array;
}HEAP_T;

P_HEAP_T CreateHeap(NUM_T size);
DECIDE_T IsFullHeap(P_HEAP_T pHeap);
DECIDE_T IsEmptyHeap(P_HEAP_T pHeap);
//MAX Heap operation
void InsertMaxHeap(P_HEAP_T pHeap, int val);
int DeleteMaxHeap(P_HEAP_T pHeap);
DECIDE_T IsMaxHeap(P_HEAP_T pHeap);
P_HEAP_T CreateHeapByArray(int *array);


//Leetocde 1464
//Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
//Example 1:
//
//Input: nums = [3,4,5,2]
//Output: 12
//Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
//
//
//Example 2:
//
//Input: nums = [1,5,4,5]
//Output: 16
//Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.,
int maxProduct(int* nums, int numsSize);




/*
 *
 * Twitter
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

    Twitter() Initializes your twitter object.
    void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
    List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
    void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
    void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.


    Example 1:

    Input
    ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
    [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
    Output
    [null, null, [5], null, null, [6, 5], null, [5]]

    Explanation
    Twitter twitter = new Twitter();
    twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
    twitter.follow(1, 2);    // User 1 follows user 2.
    twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.unfollow(1, 2);  // User 1 unfollows user 2.
    twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.


Constraints:

1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 104
All the tweets have unique IDs.
At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
*/


 // leetocode 62 Unique Paths
 // 2. Unique Paths
 // Medium
 // There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 //
 // Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 //
 // The test cases are generated so that the answer will be less than or equal to 2 * 109.
 //
 // Input: m = 3, n = 7
 // Output: 28
 //
 //
 //
 // Input: m = 3, n = 2
 // Output: 3
 // Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 // 1. Right -> Down -> Down
 // 2. Down -> Down -> Right
 // 3. Down -> Right -> Down
 //
 // 1 <= m, n <= 100
 //  _ _ _ _
 // | | | | |

#endif
