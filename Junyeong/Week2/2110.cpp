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

    for(int i=0;i<N;i++)
    {
        int x_i;
        cin>>x_i;
        location.push_back(x_i);
    }

    sort(location.begin(),location.end());

    start=1;
    end=location.at(N-1)-location.at(0);

    while(start<=end)
    {
        int pre_location=location.at(0);
        mid=(start+end)/2;
        count=1;
        for(int i=1;i<N;i++)
        {
            if(location.at(i)-pre_location>=mid)
            {
                pre_location=location.at(i);
                count++;
            }
        }
        if(count>=C)
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