#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char *name;
    int value;
} Map;

int main(){
    int n;
    scanf("%d",&n);
    int i=n;

    Map table[5]={
        {"mu",0},
        {"huo",1},
        {"tu",2},
        {"jin",3},
        {"shui",4},
    };

    int value[2];

    while(i>0){
        char name[32];
        for(int j=0;j<2;j++){
            scanf("%s",name);
            for(int k=0;k<5;k++)
                if(strcmp(name,table[k].name)==0)
                    value[j]=table[k].value;
        }

        if((value[0]-value[1]+5)%5==4) printf("%s sheng %s\n",
            table[value[0]].name,table[value[1]].name);
        else if((value[1]-value[0]+5)%5==4) printf("%s sheng %s\n",
            table[value[1]].name,table[value[0]].name);
        else if((value[0]-value[1]+5)%5==3) printf("%s ke %s\n",
            table[value[0]].name,table[value[1]].name);
        else if((value[1]-value[0]+5)%5==3) printf("%s ke %s\n",
            table[value[1]].name,table[value[0]].name);
        
        i--;
    }
    return 0;
}