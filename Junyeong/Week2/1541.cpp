#include <iostream>
#include <string>

using namespace std;

// 1541 잃어버린 괄호

int main()
{
    string expression,number;
    bool minus_check=false;
    int answer=0;

    cin>>expression;
    
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