//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 7..
//  Copyright © 2016년 김형중. All rights reserved.
//  LSI
//
#include <stdio.h>
#include <iostream>

using namespace std;

#define NMAX 40001

int DP[NMAX];
int N , lastidx , input;


int main(int argc , const char *argv[]){
    scanf("%d", &N);
    scanf("%d" ,&input);
    DP[lastidx] = input;
    
    for(int i = 1 ; i < N ; i++){
        scanf("%d" , &input);
        if(DP[lastidx] < input){
            lastidx ++;
            DP[lastidx] = input;
        }else{
            for(int j = 0; j <= lastidx ;j++){
                if(DP[j] >= input){
                    DP[j] = input;
                    break;
                }
            }
        }
    }
    printf("%d\n" , lastidx + 1);
    return 0;
}
