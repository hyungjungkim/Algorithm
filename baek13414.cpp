//
//  main.cpp
//  kook
//
//  Created by 김형중 on 2016. 11. 3..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


int N , K;

int main(int argc, const char * argv[]) {
    
    map<string , int> m;
    vector<pair<string , int>> v;
    
    scanf("%d %d", &N , &K);
    
    for(int i = 0 ; i < K ; i++){
        string input;
        cin >> input;
        if(m.find(input) == m.end()){
            v.push_back(make_pair(input,0));
            m.insert(pair<string,int>(input,i));
        }else{
            v.push_back(make_pair(input,0));
            v[m[input]].second = 1;
            m[input] = i;
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(cnt < N ){
            if(v[i].second == 0){
                cout << v[i].first << "\n";
                cnt++;
            }
        }
        else
            break;
    }
    
    return 0;
}
