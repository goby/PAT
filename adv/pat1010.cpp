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

long long cal(char* str, long long radix)
{
    long long a = 0;
    REPC(i,str[i]=='\0'){
        int value = (str[i] >= 'a') ? (str[i]-'a'+10):(str[i]-'0');
        if(value >= radix) return -1;
        a *= radix;
        a += value;
    }
    return a;
}

long long bfs(long long value, char* target, long long start, long long end){
    if(start == end) return 0;
    long long center = start + (end-start+1) / 2;
    long long s = cal(target, start);
    long long c = cal(target, center);
    long long e = cal(target, end);
    if(e<value || s > value) return 0;
    if(s==value) return start;
    if(center!=end&&c==e)
        return bfs(value, target, start, center);
    if(value==c) return center;
    if(center==end) return 0;

    if(value<c) return bfs(value, target, start, center);
    return bfs(value, target, center, end);
}

int main()
{
    char A[11],B[11],*c,*d;
    long long a = 0,result=0;
    RS(A);
    RS(B);
    DRII(tag,radix);
    if(tag==1){
        c=A;d=B;
    }
    else{
        c=B;d=A;
    }
    if(cal(c,37) * cal(d,37)==1) result = 2;
    else if(strcmp(c,d)==0) result=radix;
    else if((a=cal(c,radix))>=0){
        REP(i,37){
            if(cal(d,i)==a) {result=i;break;}
        }
        if(!result) result=bfs(a,d,2,a>36?a:36);
    }
    if(result)printf("%lld",result);
    else printf("Impossible");
    return 0;
}
