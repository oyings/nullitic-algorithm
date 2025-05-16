#include <iostream>
#include <vector>

using namespace std;

// 1654번 랜선 자르기

int main()
{
    long long int N,K,mx=0;
    long long int start,end,count,result=0;
    
    //만약 가장 긴 길이가 2^31-1일 경우 오버플로우가 발생한다.
    long long int mid;
    vector<int> lan;
    cin>>K>>N;

    //가지고 있는 랜선의 길이를 저장한다.
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

    // 검색범위 : 1 ~ mx (가장 긴 길이를 가진 랜선)
    // 최악의 경우 : 주어진 최소길이가 1이고 최대길이가 2^31-1이며, 이미 가지고 있는 랜선의 개수가 10,000
    // 순차탐색을 통해 답을 산출하려면 (2^31-1) * 10,000(=K) 약 21,474,836,470,000로 2초안에 해결할 수 없어보인다.
    // 이분탐색을 통해 답을 산출할 경우 log2(2^31-1) * 10,000(=K) 약 320,000정도의 연산으로 해결할 수 있다. O(Klog(주어진 랜선의 최대길이))
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