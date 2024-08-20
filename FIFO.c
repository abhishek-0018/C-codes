#include<stdio.h>
#include<math.h>
#include <stdlib.h> 
int main(){
    int size=20,frame_size=3,page_fault=0,c=0;
    int a[3]={-1,-1,-1};
    for(int j=0;j<size;j++){
        int p=0;
       int h = rand() % (9 + 1); 
       printf("%d",h);
        printf("\n");
        for(int i=0;i<frame_size;i++){
            if(a[i]==h){
                p++;
                break;
            }
        }
        if(p!=1){
            a[c]=h;
            page_fault++;
            c++;
            c%=3;
        }
         }
        printf("%d",page_fault);
}