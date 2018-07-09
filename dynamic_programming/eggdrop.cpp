/*
Given some number of floors and some number of eggs, what is the minimum number of attempts it will take to find out from which floor egg will break.

Detailed Explanation:

The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?

The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that total number of trials are minimized.

Source: Wiki for Dynamic Programming


*/

#include <iostream>
using namespace std;

int eggdrop(int egg, int floor){
    int cur = 0, result = INT_MAX;

    if(floor == 0)
        return 0;
    if(egg == 1)
        return floor;

    for(int k=1;k<=floor;k++){
            //MAX(BREAK, DOEST BREAK)
        cur = max(eggdrop(egg-1, k-1), eggdrop(egg, floor-k))+ 1;
        // cout << cur << endl;
        if(cur < result)
            result = cur;

    }
    return result;
}

int eggdrop_dp(int egg, int floor){
    int result[egg+1][floor+1];
    int cur;
    //If number of floors are zero, attempts will be zero
    for(int i=0;i<=egg;i++)
    {
        result[i][0] = 0;
    }
    //If only one egg is present and number of floors are N, result would be N
    for(int j=1;j<=floor;j++){
        result[1][j] = j;
    }
    for(int i=2;i<=egg;i++){
        for(int j=1;j<=floor;j++){
            result[i][j] = INT_MAX;
            for(int k=1;k<=j;k++){
                cur = 1 + max(result[i-1][k-1], result[i][j-k]);
                if(cur < result[i][j])
                    result[i][j] = cur;
            }
        }
    }
    return result[egg][floor];
}
int main(){
    int floors = 19, eggs = 10;
    // cout << "Recursion: " << eggdrop(eggs, floors) << endl;
    cout << "DP: " << eggdrop_dp(eggs, floors) << endl;
    return 0;
}
