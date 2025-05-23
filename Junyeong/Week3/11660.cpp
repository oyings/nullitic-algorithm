#include <iostream>

using namespace std;

int grid[1025][1025];
int sum[1025][1025];

int N,M;

// 11660번 구간 합 구하기

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>grid[i][j];
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+grid[i][j];
        }
    }

    for(int i=0;i<M;i++)
    {
        int x_1,y_1,x_2,y_2;
        int total=0;
        cin>>x_1>>y_1>>x_2>>y_2;
        total=sum[x_2][y_2]-sum[x_1-1][y_2]-sum[x_2][y_1-1]+sum[x_1-1][y_1-1];
        cout<<total<<'\n';
    }

    return 0;
}