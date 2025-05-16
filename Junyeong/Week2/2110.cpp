#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2110 공유기 설치

int main()
{
    int N,C,start,end,mid,count=0,result;
    vector<int>location;

    cin>>N>>C;


    // 주어진 집들의 위치를 저장한다.
    for(int i=0;i<N;i++)
    {
        int x_i;
        cin>>x_i;
        location.push_back(x_i);
    }

    // 이진탐색을 위해 집들의 위치를 정렬한다.  
    sort(location.begin(),location.end());

    // N = C 일경우 최소 간격인 1이 시작점
    // C = 2 일경우 최대간격인 마지막 위치 - 처음위치가 최대길이
    
    start=1;
    end=location.at(N-1)-location.at(0);

    while(start<=end)
    {
        int pre_location=location.at(0);
        mid=(start+end)/2;
        count=1;
        for(int i=1;i<N;i++)
        {
            // 탐색중인 집의 위치와 이전집과의 위치차가 현재 간격보다 크다면 공유기 설치가능, count++
            if(location.at(i)-pre_location>=mid)
            {
                pre_location=location.at(i);
                count++;
            }
        }

        // 현재 탐색중인 간격만큼 떨어진 집들에 모든 공유기를 설치할 수 있다면 거리를 늘려 다시 탐색한다.
        if(count>=C)
        {
            result=mid;
            start=mid+1;
        }

        // 그렇지 않다면 거리를 줄여 탐색해본다.
        else
        {
            end=mid-1;
        }
    }
    cout<<result;
}