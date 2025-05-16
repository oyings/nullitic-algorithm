#include <iostream>
#include <vector>

using namespace std;

// 1654번 랜선 자르기

int main()
{
    long long int N,K,mx=0,start,end,count,result=0;
    
    //만약 가장 긴 길이가 2^31-1일 경우 오버플로우가 발생한다.
    long long int mid;
    vector<int> lan;
    cin>>K>>N;
    for(int i=0;i<K;i++)
    {
        int length;
        cin>>length;
        lan.push_back(length);
        if(mx<length)
        {
            mx=length;
        }
    }

    //검색범위 : 1 ~ mx (가장 긴 길이를 가진 랜선)
    start=1;
    end=mx;
    count=0;

    while(start<=end)
    {
        mid=(start+end)/2;
        count=0;

        for(int i=0;i<K;i++)
        {
            count+=lan.at(i)/mid;
        }
        if(count>=N)
        {
            result=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    cout<<result;
}