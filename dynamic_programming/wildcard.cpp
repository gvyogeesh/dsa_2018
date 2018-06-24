/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

bool pattern_match(char *s1, char *s2){

    if(*s1 == '\0' && *s2 == '\0')
        return true;

    if(*s1 == *s2 || *s1 == '?')
        return pattern_match(s1+1, s2+1);

    if(*s1 == '*' && *(s1+1) != '\0'  && *s2 == '\0'){
        return false;
    }

    if(*s1 == '*' && *(s1+1) == '\0'){
        return true;
    }
    if(*s1 == '*'){
        return (pattern_match(s1, s2+1) || pattern_match(s1+1, s2));

    }
    return false;
}
bool pattern_match_dp(char *s1, char *s2){
    int rows = strlen(s1);
    int cols = strlen(s2);
    bool T[rows+1][cols+1];

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            T[i][j] = false;
        }
    }

    if(s1[0] == '*')
        T[1][0] = true;

    T[0][0] = true;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
                T[i][j] = T[i-1][j-1];
            else if(s1[i-1] == '*'){
                T[i][j] = T[i-1][j] || T[i][j-1];
            }
        }
    }
    // for(int i=0;i<=rows;i++){
    //     for(int j=0;j<=cols;j++){
    //         cout << T[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    return T[rows][cols];
}

bool pattern_match_dp1(char *s1, char *s2){
    int rows = strlen(s1);
    int cols = strlen(s2);
    bool T[rows+1][cols+1];

    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){

            if(i == 0 && j == 0){
                T[i][j] = true;
            }
            else if(i == 0 && j == 1 && s1[0] == '*'){
                T[i][j] = true;
            }
            else {
                if(s1[i] == s2[i] || s1[i] == '?')
                    T[i][j] = T[i-1][j-1];
                else if(s1[i] == '*'){
                    T[i][j] = T[i-1][j] || T[i][j-1];
                }
                else
                    T[i][j] = false;

            }

        }
    }
    // if(s1[0] == '*')
    //     T[0][1] = true;

    // T[0][0] = true;
    // for(int i=1;i<rows;i++){
    //     for(int j=1;j<rows;j++){
    //         if(s1[i] == s2[i] || s1[i] == '?')
    //             T[i][j] = T[i-1][j-1];
    //         else if(s1[i] == '*'){
    //             T[i][j] = T[i-1][j] || T[i][j-1];
    //         }
    //     }
    // }
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout << T[i][j] << "  ";
        }
        cout << endl;
    }
    return T[rows][cols];
}
int main(){
    char s1[] = "a*?a";
    char s2[] = "a1a";
    if(pattern_match(s1, s2) == true){
        cout << "Recursion:Pattern Matched" << endl;
    }
    else
        cout << "Recursion:Pattern din match..."<< endl;

    if(pattern_match_dp(s1, s2) == true){
        cout << "DP:Pattern Matched" << endl;
    }
    else
        cout << "DP:Pattern din match..."<< endl;
    return 0;
}
