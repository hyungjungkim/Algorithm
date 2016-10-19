//
//  main.cpp
//  skct
//
//  Created by 김형중 on 2016. 10. 19..
//  Copyright © 2016년 김형중. All rights reserved.
//

#include <stdio.h>
#include <string.h>


char A[4] , B[4];
char cpy_A[4] , cpy_B[4];

int main(int argc , char *argv[]){
    
    scanf("%s  %s", &A, &B);
    
    size_t len_a = strlen(A);
    
    int t = 2;
    
    for(int i = 0 ; i < len_a ; i++){
        cpy_A[i] = A[t];
        cpy_B[i] = B[t];
        t--;
    }
    
    if(strcmp(cpy_A, cpy_B)>0){
        printf("%s\n", cpy_A);
    }else{
        printf("%s\n", cpy_B);
    }
    return 0;
    
}
