#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool frepeat() {

    string repeatt;
    cout << "\nRepeat? (Y/N) " << endl;
    cin >> repeatt;
    while (((repeatt == "Y") || (repeatt == "y") || (repeatt == "N") || (repeatt == "n")) != 1 || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Unidentified operator, try again" << endl;
        cout << "Repeat? (Y/N) " << endl;
        cin >> repeatt;
        cout << endl;
    }
    if (repeatt == "Y" || repeatt == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void duplicate(vector<int>& in)
{
    sort(in.begin(), in.end());
    auto last = std::unique(in.begin(), in.end());
    in.erase(last, in.end());
}

int check_int(char& f,int& num)												
{
    if (f == '1')
    {
        int in_value;
        cout << "Input the number of integers>";
        cin >> in_value;
        while ((cin.fail()) || (cin.peek() != '\n' || in_value <= 0))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Wrong type of input data, try again: "; cin >> in_value;
            cout << endl;
        }
        return in_value;
    }
    if (f == '2')
    {
        int in_value;
        
        cout << "Input the integer #" << num+1 << ">";
        cin >> in_value;
        while ((cin.fail()) || (cin.peek() != '\n' || in_value <= 0))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Wrong type of input data, try again: "; cin >> in_value;
            cout << endl;
        }
        return in_value;
    }
}

int main()
{
    cout << "Repeated numbers elimination" << endl;
    bool r = true;
    vector<int> m;
    int n;
    while (r)
    {
        char a = '1';
        int i = 0;
        n = check_int(a,i);
        for (i; i < n; i++)
        {
            a = '2';
            int in;
            in = check_int(a, i);
            m.push_back(in);
        }
        duplicate(m);
        cout << "Result:";
        for (i = 0; i < m.size(); i++)
        {
            if (i != m.size() - 1) cout << m[i] << ", ";
            else cout << m[i] << endl;
        }
        r = frepeat();
        m.clear();
    }
    return 0;
}