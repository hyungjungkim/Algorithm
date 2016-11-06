//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 6..
//  Copyright © 2016년 김형중. All rights reserved.
//  MST
//
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define NMAX 1001

typedef pair<int,int> pii;


priority_queue<pair<int , pii>> pq;

bool chk[NMAX];
int arr[NMAX][NMAX];
bool updown[NMAX][NMAX];

int N , M , ans_max , ans_min;

int main(int argc , const char *argv[]){
    
    scanf("%d %d", &N , &M);
    int src, dest, weight;
    
    memset(chk , 0 , sizeof(chk));
    memset(arr , -1 , sizeof(arr));
    
    for(int i = 0 ; i <= M ; i++){
        scanf("%d %d %d", &src , &dest, &weight);
        arr[src][dest] = weight;
        arr[dest][src] = weight;
        if(weight){
            updown[src][dest] = true;
            updown[dest][src] = true;
        }else{
            updown[src][dest] = false;
            updown[dest][src] = false;
        }
    }
    
    chk[0] = true;
    pq.push(make_pair(arr[0][1] , make_pair(0,1)));
            
    while(!pq.empty()){
        pair<int , pii > now = pq.top();
        pq.pop();
        
        int from = now.second.first;
        int to = now.second.second;
        
        if(chk[to]) continue;
        
        chk[to] = true;
        
        if(updown[from][to])
            ans_max += now.first;
        
        for(int i = 0 ; i <= N ; i ++){
            if(arr[to][i]!=-1)
                pq.push(make_pair(arr[to][i] , make_pair(to,i)));
        }
    }
    
    memset(chk , 0 , sizeof(chk));
    
    chk[0] = true;
    pq.push(make_pair(-1 * arr[0][1] , make_pair(0,1)));
    
    while(!pq.empty()){
        pair<int , pii > now = pq.top();
        pq.pop();
        
        int from = now.second.first;
        int to = now.second.second;
        
        if(chk[to]) continue;
        
        chk[to] = true;
        
        if(updown[from][to]){
            int w = -1 * now.first;
            ans_min+= w;
        }
        
        for(int i = 0 ; i <= N ; i ++){
            if(arr[to][i]!=-1)
                pq.push(make_pair(-1 * arr[to][i] , make_pair(to,i)));
        }
    }
    
    printf("%d\n" , ((N-ans_min) *(N-ans_min)) - ((N-ans_max) * (N-ans_max)));
    return 0;
}
