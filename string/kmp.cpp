//
//  main.cpp
//  kmp
//
//  Created by 김형중 on 2016. 10. 21..
//  Copyright © 2016년 김형중. All rights reserved.
//  http://bowbowbow.tistory.com/6
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MMAX 1000001

int N , M;
int ans;

string input;
string P;

int pi[MMAX];

void getPi(string p){
    int m = (int)P.size(), j=0;
    
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] !=  p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    
}
void kmp(){
    
    getPi(P);
    
    int n = (int)input.size(), m = (int)P.size(), j =0;
    for(int i = 0 ; i < n ; i++){
        while(j>0 && input[i] != P[j])
            j = pi[j-1];
        if(input[i] == P[j]){
            if(j==m-1){
                ans++;
                j = pi[j];
            }else{
                j++;
            }
        }
    }
}

int main(int argc , char *argv[]){
    
    scanf("%d" , &N);
    scanf("%d", &M);
    cin >> input;
    
    for(int i = 0 ; i < 2*N+1 ; i++){
        if(i % 2 == 0)
            P += 'I';
        else
            P += 'O';
    }
   
    kmp();
    
    
    printf("%d\n" , ans);
    
    return 0;
    
}
