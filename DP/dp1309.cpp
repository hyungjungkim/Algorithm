//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 9..
//  Copyright © 2016년 김형중. All rights reserved.
//  DP
//  icpc.me/
//
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

#define NMAX 100001

int N;

int DP[NMAX][3];

int main(int argc , const char *argv[]){
   
    scanf("%d" , &N);
    
    DP[0][0] = 1;
    DP[0][1] = 1;
    DP[0][2] = 1;
    
    for(int i = 1 ; i < N ; i++){
        DP[i][0] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2]) % 9901;
        DP[i][1] = (DP[i-1][0] + DP[i-1][2]) % 9901;
        DP[i][2] = (DP[i-1][0] + DP[i-1][1]) % 9901;
    }
   
    
    printf("%d", (DP[N-1][0] + DP[N-1][1] + DP[N-1][2]) % 9901);
    
    
    return 0;
}
