#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 2667 단지번호붙이기

int town_count=0;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

char Map[25][25];
bool visited[25][25];
vector<int>result;

// 단지 번호는 이 함수가 호출된 횟수가 될 것이다.
void solution(int N,int x,int y)
{
    town_count++;
    int house_count=1;
    queue<pair<int,int>>location;
    
    // make_pair(x,y)와 {x,y}의 차이가 뭐였더라..
    location.push(make_pair(x,y));
    
    // 단지를 이루는 집들의 개수를 구한다
    while(!location.empty())
    {
        pair<int,int> current_location=location.front();
        location.pop();

        // 현재 방문중인 집에 인접한 집들을 모두 찾아서 큐에 집어넣어 봅시다.
        for(int i=0;i<4;i++)
        {
            int current_x=current_location.first+dx[i];
            int current_y=current_location.second+dy[i];

            // 집이 없는 위치이거나 이미 방문한 집에대해선 처리할 필요가 없다
            // 배열의 범위를 먼저 검사하면 런타임 에러를 해결할 수 있다
            if(current_x<0||current_x>=N||current_y<0||current_y>=N)continue;
            if(Map[current_x][current_y]=='0'||visited[current_x][current_y])continue;
            
            visited[current_x][current_y]=true;
            house_count++;
            location.push(make_pair(current_x,current_y));
        }
    }
    result.push_back(house_count);
}

int main()
{
    // N * N 행렬 생성
    int N;

    cin>>N;

    for(int i=0;i<N;i++)
    {
        string houses;
        cin>>houses;
        for(int j=0;j<N;j++)
        {
            Map[i][j]=houses[j];
        }
    }

    // 현재 방문중인 배열의 위치에 집이 있다면, 단지에 몇 채의 집이 있는지와 번호를 매기도록 하는 solution()함수를 호출한다.
    // 방문중인 현재위치에 대한 정보를 넘겨야 할 것
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Map[i][j]=='1'&&visited[i][j]==false)
            {
                visited[i][j]=true;
                solution(N,i,j);
            }
        }
    }

    sort(result.begin(),result.end());

    cout<<town_count<<'\n';

    for(int i=0;i<town_count;i++)
    {
        cout<<result.at(i)<<'\n';
    }

    return 0;
}