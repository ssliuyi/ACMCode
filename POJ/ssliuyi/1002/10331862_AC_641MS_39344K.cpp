#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <malloc.h> 
  
int hash[10000000];//需要的空间太大，默认情况下栈的大小不够，不能在函数里当局部变量 
int main(){ 
    char map[26] = 
{'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','Q','7','7','8','8','8','9','9','9','Z'}; 
  
    memset(hash,0,10000000); 
                long num, max = 0, min = 10000000; 
    int cur; 
    long i, j; 
    int k; 
    char tel[256], tmp[256]; 
    scanf("%d", &num); 
  
                for(i=0; i<num;i++){ 
        scanf("%s", tel); 
        k = 0; 
        for(j=0;j<strlen(tel);j++){ 
            if(tel[j]>='A'&&tel[j]<='Z') 
                tmp[k++] = map[tel[j]-'A']; 
            else if(tel[j]>='0'&&tel[j]<='9') 
                tmp[k++] = tel[j]; 
            else
                continue; 
        } 
        tmp[k] = '\0'; 
        cur = atoi(tmp); 
        if(cur>max) max = cur; 
        if(cur<min) min = cur; 
        hash[cur]++; 
    } 
    int flag = 0, head, tale; 
    for(i=min;i<=max;i++){ 
        if(hash[i]>1){ 
            head = i / 10000; 
            tale = i % 10000; 
            printf("%03d-%04d %d\n",head,tale,hash[i]); 
            flag = 1; 
        } 
    } 
    if(!flag) 
        printf("No duplicates.\n"); 
  
    return 0; 
}