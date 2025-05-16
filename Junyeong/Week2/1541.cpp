#include <iostream>
#include <string>

using namespace std;

// 1541 잃어버린 괄호

int main()
{
    string expression,number;
    // "-" 체크를 하는 이유
    // "-" 연산자가 나왔을 경우 그 후에 나오는 피연산자들을 모두 뺀다면 가장 작은 값을 얻을 수 있다.
    // 예시1) 55 - 50 + 40 -> 55 - (50 + 40) = -35 "-" 후에 나타나는 값들을 모두 결과값에서 뺀다면 결과값 도출 가능
    // 예시2) 30 - 10 - 70 + 40 - 30 -> 30 - 10 - (70 + 40) - 30 = -120
    
    bool minus_check=false;
    int answer=0;

    cin>>expression;
    
    // 시간복잡도 : 주어진 문자열의 길이가 N 이라고 했을 때 -> O(N)

    for(int i=0;i<=expression.length();i++)
    {
        if(expression[i]=='+'||expression[i]=='-'||i==expression.length())
        {
            if(minus_check==true)
            {
                answer-=stoi(number);
                number="";
            }
            else if(minus_check==false)
            {
                answer+=stoi(number);
                number="";
            }
        }

        //number라는 변수에 문자들을 합치다가  연산자를 탐색했을 경우 정수로 변환한다.
        //이미 사용된 숫자들을 제거하기 위해 number=""를 통해 초기화 시킨다.

        else
        {
            number+=expression[i];
        }
     
        
        if(expression[i]=='-')
        {
            minus_check=true;
        }

    }
    cout<<answer;
    return 0;
}