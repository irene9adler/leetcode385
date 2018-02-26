#include <iostream>

using namespace std;
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '[') return NestedInteger(stoi(s));
        stack <NestedInteger> stack_nest;
        int start = 1;
        int i;
        for (i = 0;i < s.length();i++)
        {
            if(s[i] == '[')
            {
                stack_nest.push(NestedInteger());
                start = i+1;
            }
            else if(s[i] == ',' || s[i] == ']')
            {
                if(s[i] == ','){
                if(i >start)
                    stack_nest.top()->add(stoi(s.substr(start,i-start)));
                }
                start = i + 1;
                if(s[i] == ']')
                {
                    NestedInteger tmp= stack_nest.top();
                    stack_nest.pop();
                    stack_nest.top()->add(tmp);


                }

            }
        }

        return stack_nest.top();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
