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

char A[301],B[301];
int N;
int getexp(char*& str){
    int result=0;
    while (*str=='0') {
        str++;
    }
    char *p=str;
    if(p[0]=='.'){
        p ++;
        while (*p) {
            if(*p=='0') result--;
            else break;
            p++;
        }
        str += 1 - result;
    }
    else {
        while (*p && *p !='.'){
            result++;
            p++;
        }
        while (*p=='.' && *(p+1)) {
            *p ^= *(p+1);
            *(p+1) ^= *p;
            *p ^= *(p+1);
            p++;
        }
        *p='\0';
        
    }
    REP(i, N)
        if(str[i]==0) {str[i]='0';str[i+1]=0;}
    str[N]=0;
    if(str[0]=='0') result = 0;
    return result;
}

int main()
{
    int i;
    bool result=false;
    RI(N);
    RS(A);RS(B);
    char *p=A, *q=B;
    int ea=getexp(p), eb=getexp(q);
    
    result=(ea==eb) && (strcmp(p, q)==0);
    
    printf("%s 0.", result?"YES":"NO");
    REP(k, N) printf("%c", p[k]);
    printf("*10^%d",ea);
    if(!result){
        printf(" 0.");
        REP(k, N) printf("%c", q[k]);
        printf("*10^%d",eb);
    }
    return 0;
}
