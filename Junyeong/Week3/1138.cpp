#include <iostream>
#include <vector>

using namespace std;

// 1138번 한 줄로 서기

int N;
int people[11];
bool visited[11];
vector<int> result;


// 방문여부를 모두 false로 변경하는 함수
void clear()
{
    for(int i=1;i<=N;i++)
    {
        visited[i]=false;
    }
}

void solution(int prev_count,int current)
{
    visited[current]=true;
    result.push_back(current);

    // 처음으로 서는 사람 판별하기 >> 루트노드 선정
    if(prev_count==0&&people[current]==0)
    {
        for(int i=1;i<=N;i++)
        {
            if(!visited[i])
            {
                solution(prev_count+1,i);
            }
        }
    }

    // 두번째 이후로 서는 방법
    else
    {
        // 본인보다 키큰 사람의 수를 count한 후 people[i]값과 비교한다.
        int count=0;
        for(int i=0;i<prev_count;i++)
        {
            if(result[i]>current)
            {
                count++;
            }
        }
        
        // 일치하지 않는다면 본인 자리가 아니므로 전으로 돌아간다.
        if(count!=people[current])
        {
            visited[current]=false;
            result.pop_back();
            return;
        }

        // 일치한다면 바로 옆에 위치할 사람을 찾는다.
        else
        {
            for(int i=1;i<=N;i++)
            {
                if(!visited[i])
                {
                    solution(prev_count+1,i);
                }
            }
        }
    }

    if(result.size()!=N)
    {
        visited[current]=false;
        result.pop_back();
    }
}

int main()
{
    
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>people[i];
    }

    for(int i=1;i<=N;i++)
    {
        solution(0,i);
        clear();
    }

    for(int number:result)
    {
        cout<<number<<' ';
    }

    return 0;
}