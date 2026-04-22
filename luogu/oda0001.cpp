#include<iostream>
#include<vector>
#include<string>
#include <utility> 
#include<algorithm>
#include<queue>
using namespace std;
int n, m;

// 定义方向
int direct[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};



// 通用 split 函数
vector<string> split(const string& str, const string& delimiter) {
    vector<string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);
    while (end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    // 添加最后一个部分
    result.push_back(str.substr(start));
    return result;
}

// BFS遍历连通区域的节点的数量和入口坐标
int bfs(vector<vector<string>>& ans, vector<vector<bool>>& visisted, int x , int y, vector<pair<int, int>> & enter) {
    visisted[x][y] = true;
    queue<pair<int, int>> pq;
    pq.push({x, y});
    int res = 0;
    while (!pq.empty()) {
        pair<int, int> p = pq.front();
        pq.pop();
        res++;
        int currentX = p.first;
        int currentY = p.second;

        // 边界判断， 入口
        if (currentX == 0 || currentY == 0|| currentY == m-1 || currentX == n-1) {
            enter.push_back({currentX, currentY});
        }

        for (int i = 0; i < 4; i++) {
            int newX = currentX + direct[i][0];
            int newY = currentY + direct[i][1];
            if (newX < 0 || newX >= n || newY < 0|| newY >=m || visisted[newX][newY] || ans[newX][newY] != "O") {
                continue;
            }
            visisted[newX][newY] = true;
            pq.push({newX, newY});
        }
    }
    return res;
}

// 根据连通区域大小升序排序
bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

int main() {
    cin >> n >> m;
    vector<vector<string>> ans(n);
    // 忽略换行符
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin , s);
        ans[i] = split(s, " ");
    }
    vector<vector<bool>> visisted(n, vector<bool>(m, false));
    // 记录满足条件的区域的边界坐标和节点数
    vector<pair<int, string>> resNode;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == "O" && !visisted[i][j]) {
                vector<pair<int, int>> enter;
                int res = bfs(ans, visisted, i, j, enter);
                // 存储符合条件的联通区域和入口地址
                if (enter.size() == 1) {
                    string tmp = to_string(enter[0].first)  + " " + to_string(enter[0].second);
                    resNode.push_back({res, tmp});
                } 
            }
        }
    }

    if (resNode.empty()) {
        cout << "NULL";
        return 0;
    } else if (resNode.size() == 1) {
        cout << resNode[0].second << " " << resNode[0].first;
        return 0;
    }

    sort(resNode.begin(), resNode.end(), cmp);
    if (resNode[0].first == resNode[1].first) {
        cout << resNode[0].first;
    } else {
        cout << resNode[0].second << " " << resNode[0].first;
    }
    return 0;
}
