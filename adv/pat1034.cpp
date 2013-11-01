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

const int SIZE = 26 * 26 * 26 + 1;

int SymbolTable[SIZE];
int relation[1001][1001];
int gangCal[1001];
bool marked[1001];
vector<int> Symbol;
int memberCount;
int gangAmount;

int str2i(char str[]){
    int result = 0;
    for(int i = 0; i < 3; i++){
        result *= 26;
        result += str[i] - 'A';
    }
    return result;
}

void dfs(int n){
    marked[n] = true;
    REP(i, memberCount){
        if(relation[n][i]){
            gangCal[n] += relation[n][i];
            gangCal[i] += relation[n][i];
            gangAmount += relation[n][i];
            if(!marked[i])
                dfs(i);
        }
    }
}

bool cmp(const pair<int, int>& left, const pair<int, int>& right){
    return  Symbol[left.first] < Symbol[right.first];
}

int main()
{
    int talktime, tmp, indexA, indexB;
    vector<pair<int, int>> result;
    DRII(N, K);
    MS1(SymbolTable);
    MS0(relation);
    while (N--) {
        char nameA[4], nameB[4];
        scanf("%s %s %d", nameA, nameB, &talktime);
        tmp = str2i(nameA);
        indexA = SymbolTable[tmp];
        if(indexA < 0) {
            indexA = Symbol.size();
            SymbolTable[tmp]=indexA;
            Symbol.push_back(tmp);
        }
        tmp = str2i(nameB);
        indexB = SymbolTable[tmp];
        if(indexB < 0) {
            tmp = str2i(nameB);
            indexB = Symbol.size();
            SymbolTable[tmp]=indexB;
            Symbol.push_back(tmp);
        }
        
        relation[indexA][indexB] += talktime;
    }
    memberCount = Symbol.size();
    MS0(marked);
    REP(i, memberCount){
        if(!marked[i]){
            gangAmount = 0;
            MS0(gangCal);
            dfs(i);
            if(gangAmount > K){
                int cnt = 0, maxindex = i;
                REP(j, memberCount){
                    if(gangCal[j]){
                        cnt++;
                        if(gangCal[j] > gangCal[maxindex])
                            maxindex = j;
                    }
                }
                if(cnt > 2){
                    result.push_back(MP(maxindex, cnt));
                }
            }
        }
    }
    
    sort(ALL(result), cmp);
    int size = result.size();
    printf("%d\n", size);
    REP(i, size){
        int value = Symbol[result[i].first];
        char name[4];
        name[0] = value / (26 * 26) + 'A';
        name[1] = value / 26 % 26 + 'A';
        name[2] = value % 26 + 'A';
        name[3] = 0;
        printf("%s %d\n",name, result[i].second);
    }
    
    return 0;
}
