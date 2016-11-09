//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 9..
//  Copyright © 2016년 김형중. All rights reserved.
//  DP
//  icpc.me/1520
//
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

#define NMAX 501

int arr[NMAX][NMAX];
int DP[NMAX][NMAX];

int dr[4] = { 1, 0 , -1 , 0};
int dc[4] = { 0, 1 , 0 , -1};


int N , M;

int func(int row , int cal){
    
    if(row < 0 || cal < 0 || row >= N || cal >= M)
        return 0;
    
    int &ret = DP[row][cal];
    if(ret) return ret;
    
    for (int i = 0; i < 4; i++){
        if (arr[row][cal] > arr[row + dr[i]][cal + dc[i]])
            ret += func(row + dr[i], cal + dc[i]);
    }
    
    return ret;
}



int main(int argc , const char *argv[]){
    memset(DP , 0 , sizeof(DP));
    
    scanf("%d %d", &N , &M);
    
    for(int i =  0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    DP[N-1][M-1] = 1;
    
    printf("%d\n" , func(0,0));

    return 0;
}
