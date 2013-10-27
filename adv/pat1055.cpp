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
#include "functional"
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

typedef struct {
    char name[9];
    int age;
    int net_worth;
} Man;

bool cmp(Man* left, Man* right){
    if(left->net_worth == right->net_worth){
        if(left->age == right->age)
            return strcmp(left->name, right->name) < 0;
        return left->age < right->age;
    }
    return left->net_worth > right->net_worth;
}

int available[200001];
vector<Man*> totalGroup;
int ageGroup[201] = {0};

int main()
{
    Man* man;
    int maxAge = 0, minAge=200, num, from, to, size, len;
    DRII(N,K);
    REP(i, N){
        man = new Man;
        RS(man->name);
        RII(man->age, man->net_worth);
        if(man->age > maxAge) maxAge=man->age;
        if(man->age < minAge) minAge=man->age;
        totalGroup.push_back(man);
    }
    
    sort(ALL(totalGroup), cmp);

    len = 0;
    REP(i, N){
        if(ageGroup[totalGroup[i]->age] < 100){
            available[len++]=i;
            ageGroup[totalGroup[i]->age]++;
        }
    }
    
    REP(k, K){
        RIII(num, from, to);
        if(from < minAge) from = minAge;
        if(to > maxAge) to = maxAge;
        
        printf("Case #%d:\n", k+1);
        int i=size=0, idx;
        
        while(size < num && i < len && from <= to){
            idx=available[i];
            if(totalGroup[idx]->age >= from && totalGroup[idx]->age <= to){
                printf("%s %d %d\n", totalGroup[idx]->name, totalGroup[idx]->age,
                       totalGroup[idx]->net_worth);
                size++;
            }
            i++;
        }
        if(size==0) printf("None\n");
    }
    
    return 0;
}
