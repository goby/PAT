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
#include<stack>
#include<limits.h>
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

int main()
{
    DRIII(M, N, K);
    vector<int> instack;
    REP(k, K){
        int count = 0, pre = 0, tmp;
        bool result = true;
        instack.assign(N+1, 0);
        REP(i, N){
            RI(tmp);
            if(!result)
                continue;
            
            if(instack[tmp] == -1){
                result = false;
                continue;
            }
            
            REPP(j,pre + 1,tmp + 1){
                if(instack[j] == 0) {
                    instack[j] = 1;
                    count++;
                }
            }
            
            if(count > M)
                result = false;
            
            count--;
            instack[tmp] = -1;
            
            REPP(j, tmp, pre){
                if(instack[j] == 1) {
                    result = false;
                    break;
                }
            }
            pre = tmp;
        }
        printf("%s\n", result ? "YES" : "NO");
    }
    return 0;
}
