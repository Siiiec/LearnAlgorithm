#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using vvi = std::vector<std::vector<bool>>;

struct TimeStamp
{
    int discovered;
    int finished;
};

std::vector<TimeStamp> dfs(const vvi& edges)
{
    using namespace std;

    int time {1};
    const int n = edges.size();
    stack<int> st;
    vector<bool> reached(n);
    vector<TimeStamp> times(n);

    //���ׂĂ̕ӂɂ��čs��
    for (int i = 0; i < n; ++i)
    {
        if (reached[i])
            continue;

        reached[i] = true;
        times[i].discovered = time++;
        st.push(i);
        
        //�_j����Ȃ��邷�ׂĂ̕ӂ𒲂ׂ�
        while (!st.empty())
        {
            int top = st.top();
            for(int j = i + 1; j < n; ++j)
                if (!reached[j] && edges[top][j])
                {
                    reached[j] = true;
                    times[j].discovered = time++;
                    st.push(j);
                    break;
                }

            //���̓_����̒T����₪�Ȃ���ΑO�̓_�ɖ߂�
            if (top == st.top())
            {
                times[top].finished = time++;
                st.pop();
            }
        }
    }

    return times;
}

void solve()
{
    using namespace std;

    int n;
    cin >> n;

    vvi edges(n, vector<bool>(n));

    //�ǂݍ���
    for (int i = 0; i < n; ++i)
    {
        int u, k;
        cin >> u >> k;

        for (int j = 0; j < k; ++j)
        {
            int v;
            cin >> v;
            edges[u - 1][v - 1] = true;
        }
    }

    auto times = dfs(edges);

    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << " " << times[i].discovered << " " << times[i].finished << endl;
    }
}