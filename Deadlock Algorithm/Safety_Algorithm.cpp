#include <bits/stdc++.h>

using namespace std;

void In_file()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct process
{
    char p_id[20];
    int allocation[30];
    int max_need[30];
};

int32_t main()
{
    In_file();
    // cout << "Hello\n";

    int n;
    // cout << "Enter Total Number of processes\n";
    cin >> n;
    struct process pros[n];
    int r = 3;
    int available[r];
    // cout << "Please enter the number of instances of available resources\n";
    for (int i = 0; i < r; i++)
        cin >> available[i];

    // cout << "Please enter P-id Allocation Max_need\n";
    for (int i = 0; i < n; i++)
    {
        cin >> pros[i].p_id;
        for (int j = 0; j < r; j++)
            cin >> pros[i].allocation[j];
        for (int j = 0; j < r; j++)
            cin >> pros[i].max_need[j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
            pros[i].max_need[j] -= pros[i].allocation[j];
    }

    bool finish[n] = {false};
    vector<string> safe_seq;

    while (true)
    {
        bool check = false;

        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            if (finish[i] == false)
            {
                for (int j = 0; j < r; j++)
                {
                    if (pros[i].max_need[j] > available[j])
                        flag = false;
                }

                if (flag == true)
                {
                    check = true;
                    safe_seq.push_back(pros[i].p_id);
                    finish[i] = true;
                    for (int j = 0; j < r; j++)
                    {
                        available[j] += pros[i].allocation[j];
                    }
                }
            }
        }

        if (!check)
            break;
    }

    if (safe_seq.size() < n)
        cout << "Unsafe\n";
    else
    {
        cout << "Safe sequence:\n";
        for (auto it : safe_seq)
            cout << it << " ";
    }
    cout << endl;
}