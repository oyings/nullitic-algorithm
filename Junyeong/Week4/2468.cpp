#include <iostream>
#include <queue>

using namespace std;

// 2468 안전 영역

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int max_height,max_area;

int grid[100][100];
bool visited[100][100];

int N;

void clear(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=false;
        }
    }
}

void solution(int height,int x,int y){
    visited[x][y]=true;
    queue<pair<int,int>>location;
    location.push({x,y});

    while(!location.empty()){
        pair<int,int>current=location.front();
        location.pop();

        for(int i=0;i<4;i++){
            int current_x=current.first+dx[i];
            int current_y=current.second+dy[i];
            if(current_x<0||current_x>=N||current_y<0||current_y>=N)continue;
            if(grid[current_x][current_y]<=height||visited[current_x][current_y])continue;
            location.push({current_x,current_y});
            visited[current_x][current_y]=true;
        }
    }
}

int main()
{
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
            if(grid[i][j]>max_height){
                max_height=grid[i][j];
            }
        }
    }

    // i는 비의 높이, 비의 높이 보다 높은 지역을 발견할 경우 함수 호출 -> 안전 영역
    // 아무곳도 안잠길 수 있다고하면 비의 높이의 범위는 0~99정도가 될 수 있다.
    // ex1 모든 지대의 높이가 1이라면 비가 0이어야 잠기지 않는다.
    // ex2 모든 지대의 높이가 100이라면 비가 99이어야 잠기지 않는다.
    for(int i=0;i<100;i++){
        int count=0;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(grid[j][k]>i&&!visited[j][k]){
                    count++;
                    solution(i,j,k);
                }
            }
        }
        
        if(count>max_area){
            max_area=count;
        }
        clear();
    }

    cout<<max_area;

    return 0;
}