//
//  main.cpp
//  kook2
//
//  Created by 김형중 on 2016. 11. 6..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

#define NMAX 1001

int N , input;
int DP[NMAX];

int max(int a , int b){ return a > b ? a: b;}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &N);
    
    for(int i = 1 ; i <= N ; i++){
        scanf("%d" , &input);
        for(int j = i ; j <= N ; j++)
            DP[j] = max(DP[j] , DP[j-i] + input);
        
    }
    
    printf("%d\n" , DP[N]);
    
    
    return 0;
}
