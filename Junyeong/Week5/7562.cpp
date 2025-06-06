#include <iostream>
#include <queue>

// 7562 나이트의 이동

using namespace std;
int test_case,L;
bool visited[300][300];

// 나이트가 이동할 수 있는 8방향에 대한 배열들
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

void clear(){
    for(int i=0;i<300;i++){
        for(int j=0;j<300;j++){
            visited[i][j]=false;
        }
    }
}

int solution(pair<int,int>start_p,pair<int,int>end_p){
    int cnt=0;
    queue<pair<pair<int,int>>,int>locate;
    locate.push({start_p,0});

    while(!locate.empty()){
        pair<int,int>now=locate.front().first;
        cnt=locate.front().second;
        locate.pop();

        // 나이트가 움직일 수 있는 8방향에 대한 조사
        // 너비우선탐색할 경우 최적해를 발견한 즉시 탐색 종료할 수 있다.
        for(int i=0;i<8;i++){
            int diff_x=now.first+dx[i];
            int diff_y=now.second+dy[i];
            if(diff_x<0||diff_x>=L||diff_y<0||diff_y>=L)continue;
            if(!visited[diff_x][diff_y])continue;
            if(diff_x==end_p.first&&diff_y==end_p.second){
                return cnt+1;
            }else{
                visited[diff_x][diff_y]=true;
                locate.push({{diff_x,diff_y},cnt+1});
            }
        }
    }
}

int main(){
    cin>>test_case;
    while(test_case--){
        int start_x,start_y,end_x,end_y;
        cin>>L;
        cin>>start_x>>start_y;
        cin>>end_x>>end_y;
        if(start_x==end_x&&start_y==end_y){
            cout<<0<<'\n';
        }else{
            cout<<solution({start_x,start_y},{end_x,end_y})<<'\n';
        }
        clear();
    }
    return 0;
}