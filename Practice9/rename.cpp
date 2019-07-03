#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void rename(string* participants, int idx)
{
    string currentName = participants[idx];
    int repeat = 1;
    for (int i = 0; i < idx; i++)
    {
        if (currentName.compare(participants[i]) == 0)
        {
            repeat++;
        }
    }
    if (repeat == 1)
    {
        string newName = "";
        bool exists = 0;
        for (int i = 1; i <= currentName.length() + 1; i++)
        {
            newName = currentName.substr(0, i);
            exists = 0;
            for (int j = 0; j < idx; j++)
            {
                if (newName.compare(participants[j].substr(0, i)) == 0)
                {
                    exists = 1;
                    break;
                }
            }
            if (exists == 0)
            {
                cout<<newName<<endl;
                break;
            }
        }
    }
    else
    {
        string rep = to_string(repeat);
        currentName.append(" ");
        currentName.append(rep);
        cout<<currentName<<endl;
    }
}

int main()
{
    int N = 0;
    cin >> N;
    string* participants;
    participants = new string[N];
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < N; i++)
    {
        cin >> participants[i];
        rename(participants, i);
    }
    return 0;
}
