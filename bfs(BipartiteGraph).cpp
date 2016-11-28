//
//  main.cpp
//  algoprac
//
//  Created by 김형중 on 2016. 11. 23..
//  Copyright © 2016년 김형중. All rights reserved.
//  icpc.me/1707
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define NMAX 20002

int T, V, E, from, to;
vector< vector<int> > v;
int chk[NMAX], color[NMAX] , q[NMAX];

bool bfs(int idx){
    
    int head = 0 , tail = 0;
    q[tail++] = idx;
    color[idx] = 1;
    
    while(head < tail){
        int now = q[head++];
        int nowco = color[now];
        for(int i = 0 ; i < v[now].size() ; i++){
            int next = v[now][i];
            if(color[next] == -1){
                color[next] = !nowco;
                q[tail++] = next;
            }else{
                if(nowco == color[next]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    scanf("%d" , &T);
    
    while(T--){
        
        int ans = 1;
        memset(chk , -1 , sizeof(chk));
        memset(color, -1, sizeof(color));
        v = vector<vector<int>>(NMAX);
        
        scanf("%d %d", &V, &E);
        
        
        for(int i = 0 ; i < E ; i++){
            scanf("%d %d", &to , &from);
            v[to].push_back(from);
            v[from].push_back(to);
        }
        for(int i = 1 ; i <= V ; i++){
            if(color[i] == -1)
                ans &= bfs(i);
        }
        
        ans ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
