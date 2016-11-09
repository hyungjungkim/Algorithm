//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 7..
//  Copyright © 2016년 김형중. All rights reserved.
//  DP
//
#include <stdio.h>
#include <iostream>

#define MOD 1000000000

using namespace std;

int main(int argc , const char *argv[]){
    int N;
    
    int DP[101][10];
    int ans = 0;
    
    scanf("%d", &N);
    
    for(int i = 0 ; i < 10 ; i++)
        DP[1][i] = 1;
    
    for(int i = 2 ; i <= N ; i++){
        for(int j = 0 ; j < 10 ; j ++){
            if(j == 0)
                DP[i][0] = DP[i - 1][1] % MOD;
            else if(j == 9)
                DP[i][9] = DP[i - 1][8] % MOD;
            else
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
        }
    }
    
    for(int i = 1 ; i < 10 ; i++){
        ans = (ans + DP[N][i]) % MOD;
    }

    printf("%d\n" , ans % MOD);
    
    return 0;
}
