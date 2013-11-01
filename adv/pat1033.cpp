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
#define OUTREPEAT() static int __repeat_time=0; printf("%d\n", __repeat_time++);
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

struct station{
    double price;
    double location;
};

bool cmp(station left, station right){
    return left.location < right.location;
}

int main()
{
    vector<station> stations;
    double Cmax, D, Davg, N;
    station s;
    scanf("%lf%lf%lf%lf", &Cmax, &D, &Davg, &N);
    REP(i, N){
        scanf("%lf%lf", &s.price, &s.location);
        stations.push_back(s);
    }
    
    sort(ALL(stations), cmp);
    int cur = 0;
    double runDis = Cmax * Davg, total = 0, amount = 0, available = 0;
    
    while (cur < N) {
        if(total >= D || total < stations[cur].location) break;
        
        int min = -1;
        for(int i = cur + 1;i < N
            && stations[i].location - stations[cur].location <= runDis; i++) {
            if(min == -1 || stations[i].price < stations[min].price)
                min = i;
            if(stations[min].price < stations[cur].price)
                break;
        }
        
        double needAdd = 0, cost = 0;
        if(min == -1) {
            if(total + runDis > D)
                cost = (D - total) / Davg;
            else
                cost = Cmax;
            
            needAdd = cost - available;
            total += cost * Davg;
            min = cur + 1;
        }
        else if(stations[min].location >= D){
            cost = (D - total) / Davg;
            needAdd = cost - available;
            total = D;
        }
        else if(stations[min].price > stations[cur].price) {
            if(total + runDis >= D) {
                cost = (D - total) / Davg;
                needAdd = cost - available;
                total = D;
            }
            else {
                cost = (stations[min].location - total) / Davg;
                needAdd = Cmax - available;
                total = stations[min].location;
            }
        }
        else {
            cost = (stations[min].location - total) / Davg;
            needAdd = cost - available;
            total = stations[min].location;
        }
        available = available + needAdd - cost;
        amount += needAdd * stations[cur].price;
        cur = min;
    }
    
    if(total < D) printf("The maximum travel distance = %.2lf", total);
    else printf("%.2lf", amount);
    
    return 0;
}
