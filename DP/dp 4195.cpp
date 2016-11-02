//
//  prac.c
//  baekjoon1
//
//  Created by 김형중 on 2016. 11. 02..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define FMAX 1000001

int parent[FMAX];
int level[FMAX];

int T , F;


int find(int val){
    if(val == parent[val]) return val;
    else
        return parent[val] = find(parent[val]);
}

int unionset(int first , int second){
    int u = find(first);
    int v = find(second);
    
    if(u != v){
        parent[v] = u;
        level[u] += level[v];
        level[v] = 1;
    }
    
    return level[u];
}

int main(void) {
    scanf("%d" , &T);
    while(T--){
        int u , v , num = 1;
        scanf("%d" , &F);
        for(int i = 1 ; i <= F ; i++ ){
            parent[i] = i;
            level[i] = 1;
        }
        map<string , int> m;
        char f[21] , s[21];
        for(int i = 0 ; i < F ; i++){
            scanf("%s %s", f , s);
            if(m.count(f)==0) m[f] = num++;
            u = m[f];
            if(m.count(s)==0) m[s] = num++;
            v = m[s];
            printf("%d\n", unionset(u, v));
        }
        
    }
    return 0;
}
