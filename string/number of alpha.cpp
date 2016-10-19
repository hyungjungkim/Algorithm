//
//  main.cpp
//  skct
//
//  Created by 김형중 on 2016. 10. 19..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>

char Alpha[26];
char K[101];

int main(int argc , char *argv[]){
    
    scanf("%s", &K);
    
    int i = 0;
    
    while(K[i] != NULL){
        Alpha[K[i]-'a']++;
        i++;
    }
    
    for(i = 0 ; i < 26 ; i++){
        printf("%d " , Alpha[i]);
    }
    printf("\n");
    
    return 0;
    
}
