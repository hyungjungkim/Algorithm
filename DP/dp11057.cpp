//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 9..
//  Copyright © 2016년 김형중. All rights reserved.
//  DP
//  icpc.me/11057
//
#include <stdio.h>
#include <iostream>

#define MOD 10007

using namespace std;

int N;
int DP[1001][10];
int ans;

int main(int argc , const char *argv[]){

    scanf("%d", &N);
    
    
    for(int i = 0 ; i < 10 ; i++)
        DP[1][i] = 1;
    
    for(int i = 2 ; i <= N ; i++){
        for(int j = 0; j < 10 ; j++){
            for(int k = 0 ; k <= j; k++){
                    DP[i][j] = (DP[i][j] + DP[i-1][k]) % MOD;
            }
        }
    }
    
    for(int i = 0 ; i < 10 ; i++){
        ans = (ans + DP[N][i]) % MOD;
    }
    
    printf("%d\n" , ans % MOD);
    
    return 0;
}
