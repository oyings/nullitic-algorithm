#include <iostream>

using namespace std;

// 2302 극장 좌석
int N,M;
int seats[40];
int dp[41]={1,1,};

int main(){
    cin>>N;
    cin>>M;
    for(int i=0;i<M;i++){
        int seat_num;
        cin>>seat_num;
        seats[seat_num-1]=1;
    }

    // dp배열에는 붙어있는 좌석의 개수 i에 대해 구할 수 있는 모든 경우의 수를 저장한다
    for(int i=2;i<=40;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    //그룹을 이루는 좌석의 개수를 센다
    int count=0,total=1;

    for(int i=0;i<N;i++){
        // 0 = 일반, 1 = vip
        if(seats[i]==0){
            count++;
        }else{
            // vip가 나와서 그룹이 나눠지는 경우
            total*=dp[count];
            count=0;   
        }

        // 좌석을 모두 탐색한 경우
        if(i==N-1){
            total*=dp[count];
        }
    }

    cout<<total;

    return 0;
}