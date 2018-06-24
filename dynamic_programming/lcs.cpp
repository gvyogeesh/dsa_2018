 /*
 LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences

 Examples:
 LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
 LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.


 */

#include <iostream>
#include <stack>

using namespace std;
int lcs(char s1[], char s2[], int i, int j, int sz1, int sz2){
    if(i >= sz1 || j >=sz2)
        return 0;
    if(s1[i] == s2[j]){
        return 1 + lcs(s1, s2, i+1, j+1, sz1, sz2);
    }
    return max(lcs(s1, s2, i+1, j, sz1, sz2), lcs(s1, s2, i, j+1, sz1, sz2));
}
int lcs_dp(char s1[], char s2[], int sz1, int sz2){
    stack<char>my_stk;
    int T[sz1+1][sz2+1];
    for(int i=0;i<=sz1;i++)
        T[i][0] = 0;
    for(int j=0; j<=sz2;j++)
        T[0][j] = 0;

    for(int i=1;i<=sz1;i++){
        for(int j=1;j<=sz2;j++){
            if(s1[i-1] == s2[j-1] ){
                T[i][j] = T[i-1][j-1] + 1;
            }
            else {
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }

        }
    }
    for(int i=0;i<=sz1;i++){
        for(int j=0;j<=sz2;j++){
            cout << T[i][j] << "  ";
        }
        cout << endl;
    }
    int i=sz1;
    int j=sz2;
    //

    // cout << s1[sz1-1] << "  " << s2[sz2-1] << endl;
    while(i > 0 && j> 0) {
        if(s1[i-1] == s2[j-1]){
            // cout << "Push " << s1[i-1] << endl;
            my_stk.push(s1[i-1]);
            i=i-1;
            j=j-1;
        }
        else{
            if(T[i][j] == T[i-1][j]){
                i=i-1;
            }
            else if (T[i][j] == T[i][j-1]){
                j=j-1;
            }
        }
    }
    while(my_stk.empty() == false){
        cout << my_stk.top();
        my_stk.pop();
    }
    cout << endl;

        //
    return T[sz1][sz2];
}
int main(){
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";
    cout << lcs(s1, s2, 0, 0, strlen(s1), strlen(s2)) << endl;
    cout << lcs_dp(s1, s2, strlen(s1), strlen(s2)) << endl;
}


// if(s1[i-1] == s2[j-1] )
// {
//     T[i][j] = T[i-1][j] + T[i][j-1];
// }
// else{
//         T[i][j] = max(T[i-1][j], T[i][j-1])
// }
