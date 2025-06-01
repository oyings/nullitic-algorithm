#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1759 암호 만들기

int L,C;
vector<char> alphabets;
vector<char> result;

void solution(int index){
    if(result.size()==L){
        int vowel=0,consonant=0;
        for(int i=0;i<L;i++){
            // 비밀번호는 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어있기 때문에
            // 유효성검사를 할 필요가 있다.
            switch(result[i]){
                case 'a':
                    vowel++;
                    break;
                case 'e':
                    vowel++;
                    break;
                case 'i':
                    vowel++;
                    break;
                case 'o':
                    vowel++;
                    break;
                case 'u':
                    vowel++;
                    break;
                default:
                    consonant++;
            }
        }
        if(vowel>=1&&consonant>=2){
                for(char c : result){
                cout<<c;
            }
            cout<<'\n';
            result.pop_back();
            return;
        }else{
            result.pop_back();
            return;
        }

    }else{
        // 현재 탐색하는 index보다 뒤에 위치한 알파벳을 탐색해야 하므로 i=index+1
        // 비밀번호는 알파벳이 증가하는 순서대로 배열되기 때문
        for(int i=index+1;i<alphabets.size();i++){
            result.push_back(alphabets[i]);
            solution(i);
        }
    }
    
    if(result.size()<L){
        result.pop_back();
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>L>>C;

    for(int i=0;i<C;i++){
        char temp;
        cin>>temp;
        alphabets.push_back(temp);
    }

    sort(alphabets.begin(),alphabets.end());

    // C개의 알파벳이 주어졌으므로 탐색하는 범위는 0 ~ C
    for(int i=0;i<C;i++){
        // 남아있는 알파벳의 개수가 비밀번호의 길이보다 작을 경우 탐색하지 않는다.
        if(C-L<i){
            break;
        }
        else{
            result.push_back(alphabets[i]);
            solution(i);
        }
    }

    return 0;
}