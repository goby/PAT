#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RREP(I, N) for (int I = (N) - 1; I >= 0; --I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define REPCC(I,A, C) for (int I = (A); !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;


void dbl(char *dest, const char* ori){
    int len = LEN(ori);
    int id = len;
    int flag =false;
    if(ori[0] >= '5') id=id+1;
    dest[id]='\0';
    for (int i = len-1;i >=0 ; i--) {
        int a = 2*(ori[i]-'0') + (flag ? 1 : 0);
        flag = a >= 10;
        dest[--id]= a % 10 + '0';
    }
    if(flag) dest[0]='1';
}

int main()
{
    int i;
    char ac[21], bc[22];
    RS(ac);
    dbl(bc, ac);
    for(int k =0; bc[k] != 0; k++){
        for(int j = 0; ac[j]!=0; j++){
            if(ac[j]== bc[k]) {
                ac[j]=' ';
                break;
            }
        }
    }
    for(i = 0; ac[i]!=0; i++){
        if(ac[i]!=' ')
            break;
    }
    if(ac[i]==0 && LEN(bc)== LEN(ac)) printf("Yes\n");
    else printf("No\n");
    printf("%s",bc);
    
    return 0;
}
