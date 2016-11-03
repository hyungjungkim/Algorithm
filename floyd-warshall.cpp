//
//  main.cpp
//  kook
//
//  Created by 김형중 on 2016. 11. 3..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>
#include <iostream>


using namespace std;

#define NMAX 101
#define INF 987654321

int arr[NMAX][NMAX];


int T; //tcase

int a, b, c;  // 방 번호 a, b 거리 c

int N, M, K;

int room[NMAX];
int ans;
int idx;

int main(int argc, const char * argv[]) {
    
    scanf("%d" , &T);
    
    while(T--){
        
        scanf("%d %d" , &N , &M);
        ans = INF;
        idx = 0;
        
        for(int i = 1 ; i <= N ; i++) {
            for(int j = 1 ; j <= N ; j++){
                if(i == j){
                    arr[i][j] = 0;
                }
                else{
                    arr[i][j] = INF;
                }
            }
        }
        
        for(int i = 1 ; i <= M ; i++){
            scanf("%d %d %d", &a , &b , &c);
            arr[a][b] = arr[b][a] = c;
        }
        
        scanf("%d", &K);
        
        for(int i = 0 ; i < K ; i++)
            scanf("%d" , &room[i]);
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                for(int k=1; k<=N; k++){
                    if(arr[j][k] > arr[j][i] + arr[i][k]){
                        arr[j][k] = arr[j][i] + arr[i][k];
                    }
                }
            }
        }
  
        
        for(int i = 1 ; i <= N ; i++){
            int tmp = 0;
            for(int j = 0 ; j < K ; j++){
                tmp += arr[room[j]][i];
            }
            if(ans > tmp){
                ans = tmp;
                idx = i;
            }
        }
        printf("%d\n" , idx);
        
    }
    
    return 0;
}
