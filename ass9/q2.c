#include<stdio.h>
#include<stdbool.h>
int main(){
        int allocation[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
        int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
        int available[3]={3,3,2};
        int need[5][3], work[3], sequence[5], count, k=0, request[i][j];
        for(int i=0;i<3;i++){
                work[i]=available[i];
        }
        bool finish[5];
        for(int i=0;i<5;i++){
                finish[i]=false;
        }
        for(int i=0;i<5;i++){
                for(int j=0;j<3;j++){
                        need[i][j]=max[i][j]-allocation[i][j];
                }
        }
        for(int l=0;l<5;l++){
                while(finish[l]==false){
                        for(int i=0;i<5;i++){
                        count=0;
                        if(finish[i]==false){
                                for(int j=0;j<3;j++){
                                        if(request[i][j]<=work[j]){
                                                count++;
                                        }
                                }
                                if(count==3){
                                        printf("ERROR! Exceeded maximum limit");
                                }
                        }
                        for(int j=0;j<3;j++){
                                work[j]=work[j]+allocation[i][j];
                        }
                        }
                }
        }
        for(int i=0;i<5;i++){
                printf("P%d ",sequence[i]);
        }
}
