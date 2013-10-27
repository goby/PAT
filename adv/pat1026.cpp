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

#define SIZE 101

#define GETTIME(H, M, S) ((H)*3600+(M)*60+(S))

#define CLOSETIME 21*3600

typedef struct _player {
    int arrriveTime;
    int playTime;
    int isVIP;
} Player;

bool cmp(Player left, Player right){
    return left.arrriveTime < right.arrriveTime;
}
vector<int> normalList, vipList;
vector<Player> playerList;
int availableTime[SIZE] = {0};
bool table[SIZE] = {0};
int serveCount[SIZE] = {0};

void to_time(int value, int& hh, int& mm, int& ss){
    hh = value / 3600;
    mm = (value % 3600)/60;
    ss = value % 60;
}

void println(int arriveTime, int startTime){
    int hh, mm, ss;
    to_time(arriveTime, hh, mm, ss);
    printf("%02d:%02d:%02d ", hh, mm, ss);
    to_time(startTime, hh, mm, ss);
    printf("%02d:%02d:%02d ", hh, mm, ss);
    
    printf("%d\n", ((startTime-arriveTime)+30)/60);
}

void reorderPlayerList(int startIndex, int totalPlayer, int beforeTime){
    REPP(i, startIndex+1, totalPlayer){
        if(playerList[i].isVIP && playerList[i].arrriveTime <= beforeTime){
            Player tmp = playerList[i];
            for(int k = i; k> startIndex; k--)
                playerList[k]=playerList[k-1];
            playerList[startIndex]=tmp;
            return;
        }
    }
}

int main()
{
    int hh, mm, ss, playTime, vip;
    DRI(N);
    REP(i, N){
        Player p;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &playTime, &vip);
        p.arrriveTime = GETTIME(hh, mm, ss);
        p.playTime=(playTime > 120 ? 120 : playTime) * 60;
        p.isVIP=vip;
        playerList.push_back(p);
    }
    sort(ALL(playerList), cmp);
    
    REP(i, N){
        if(playerList[i].isVIP) vipList.push_back(i);
        else normalList.push_back(i);
    }
    
    DRII(K, M);
    REP(i, M){
        DRI(tmp);
        table[tmp-1] = true;
    }
    
    REP(i, N){
        if(playerList[i].arrriveTime >= CLOSETIME)
            break;
        
        int availIndex=-1, vipIndex=-1;
        REP(k, K){
            if(availableTime[k] < playerList[i].arrriveTime){
                availIndex=k;
                break;
            }
        }
        REP(k, K){
            if(table[k] && availableTime[k] < playerList[i].arrriveTime){
                vipIndex=k;
                break;
            }
        }
        
        if(availIndex >= 0){
            if(playerList[i].isVIP && vipIndex >= 0)
                availIndex=vipIndex;
            serveCount[availIndex]++;
            availableTime[availIndex]=playerList[i].arrriveTime+playerList[i].playTime;
            println(playerList[i].arrriveTime, playerList[i].arrriveTime);
        }
        else{
            int ealist=CLOSETIME;
            REP(k, K){
                if(availableTime[k] < ealist){
                    ealist=availableTime[k];
                    availIndex=k;
                }
            }
            if(availIndex < 0)
                break;
            
            if(table[availIndex] && (!playerList[i].isVIP))
                reorderPlayerList(i, N, availableTime[availIndex]);
            serveCount[availIndex]++;
            println(playerList[i].arrriveTime, availableTime[availIndex]);
            availableTime[availIndex]+=playerList[i].playTime;
        }
    }
    
    printf("%d", serveCount[0]);
    REPP(i, 1, K){
        printf(" %d", serveCount[i]);
    }
    
    return 0;
}
