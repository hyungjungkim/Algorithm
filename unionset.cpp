//
//  main.cpp
//  baekjoon1
//
//  Created by 김형중 on 2016. 10. 29..
//  Copyright © 2016년 김형중. All rights reserved.
//  union set
//

#include <stdio.h>
#include <stdlib.h>


int parent[1000001];
int level[1000001];

int N, M;


int find(int val){
    if(val == parent[val]) return val;
    else
        return find(parent[val]);
}

void unionset(int first , int second){
    int u = find(first);
    int v = find(second);
    
    if(u == v) return;
    else{
        if (level[u] > level[v])
            parent[v] = u;
        else if (level[u] == level[v]) {
            parent[v] = u;
            level[u]++;
        }
        else     parent[u] = v;
    }
}

int main(void) {
    int state, first , second;
    
    scanf("%d %d", &N , &M);
    //init
    for(int i = 0 ; i <= N ; i++){
        parent[i] = i;
        level[i] = 1;
    }
    
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d %d", &state , &first, &second);
        if(state){
            if(find(first) == find(second)) printf("YES\n");
            else printf("NO\n");
        }else
            unionset(first , second);
    }
    
    return 0;
}
