#include <iostream>
#include <queue>

using namespace std;

// 16918 봄버맨

int R,C,N;
char grid[200][200];

queue<pair<int,int>>locate;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void plant_bomb(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j]=='.'){
                grid[i][j]='O';
            }
        }
    }
}

void locate_bomb(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j]=='O'){
                locate.push({i,j});
            }
        }
    }
}

void explode_bomb(){
    vector<pair<int,int>>same_time;
    // 같은 시간에 설치된 폭탄에 대한 정보
    for(int i=0;i<locate.size();i++){
        same_time.push_back(locate.front());
        locate.push(locate.front());
        locate.pop();
    }

    while(!locate.empty()){
        pair<int,int> cur=locate.front();
        grid[cur.first][cur.second]='.';
        locate.pop();
        for(int i=0;i<4;i++){
            int cur_x=cur.first+dx[i];
            int cur_y=cur.second+dy[i];
            // 변경된 범위 초사
            if(cur_x<0||cur_x>=R||cur_y<0||cur_y>=C)continue;
            // .이면 수정 안함
            if(grid[cur_x][cur_y]=='.')continue;
            // 폭탄 인근지역 수정
            grid[cur_x][cur_y]='.';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>R>>C>>N;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='O'){
                locate.push({i,j});
            }
        }
    }

    // 첫번째 시도
    // N이 짝수일 경우에는 격자판 모든 칸에 폭탄을 설치하므로 C*R만큼 O를 출력한다.
    // N이 1, 5, 9일경우 주어진 입력을 그대로 처리함
    // N이 3, 7, 11일 경우 폭탄을 심고 심어진 위치를 토대로 폭파시킴
    // if(N%2==0){ // N = 2 4 6 ..
    //     for(int i=0;i<R;i++){
    //         for(int j=0;j<C;j++){
    //             cout<<'O';
    //         }
    //         cout<<'\n';
    //     }
    // }else if(N%4==1){ // N = 1 5 9 ...
    //     for(int i=0;i<R;i++){
    //         for(int j=0;j<C;j++){
    //             cout<<grid[i][j];
    //         }
    //         cout<<'\n';
    //     }
    // }else if(N%4==3){ // N = 3 7 11 ....
    //     plant_bomb();
    //     explode_bomb();
    //     for(int i=0;i<R;i++){
    //         for(int j=0;j<C;j++){
    //             cout<<grid[i][j];
    //         }
    //         cout<<'\n';
    //     }
    // }

    // 두번째 시도
    // .에 폭탄 심음 -> 첫번째 심은 폭탄터짐 -> 두번째 심은 폭탄 터짐 로테이션
        // bomb_cnt는 전에 설치된 폭탄의 갯수
        // 2n일때 폭탄설치하고 위치와 개수 확인
        // 2n+1일때 3초전에 설치한 폭탄 폭파
        // for(int i=0;i<=N;i++){
        //     if(i==1)continue;
        //     if(i%2==0){
        //         // N=0일때 (초기) 폭탄의 위치확인
        //         for(int i=0;i<R;i++){
        //             for(int j=0;j<C;j++){
        //                 cin>>grid[i][j];
        //                 if(grid[i][j]=='O'){
        //                     locate.push({i,j});
        //                     bomb_cnt++;
        //                 }
        //             }
        //         }
        //         // bomb_cnt=plant_bomb(&locate);
        //     }else{
        //         explode_bomb(&locate,bomb_cnt);
        //     }
        // }

    if(N%2==0){ // N = 2 4 6 ..
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<'O';
            }
            cout<<'\n';
        }
    }else{ // N = 1 3 5 ..
        if(N!=1){
        //N = 1이 아닌 홀수일 때 폭탄의 위치를 지정하고, 설치한뒤 폭파시킨다.
            for(int i=1;i<N;i+=2){
                locate_bomb();
                plant_bomb();
                explode_bomb();
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<grid[i][j];
            }
            cout<<'\n';
        }
    }

    return 0;
}