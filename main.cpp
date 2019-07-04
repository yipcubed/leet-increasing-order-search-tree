#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// https://leetcode.com/problems/increasing-order-search-tree/
// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    template<typename T>
    void inorderTP(TreeNode *r, T fptr) {
        if (!r) return;
        inorderTP(r->left, fptr);
        fptr(r);
        inorderTP(r->right, fptr);
    }

    // Morris Travel  is the btter solution https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
    TreeNode *increasingBST(TreeNode *root) {
        if (!root) return nullptr;
        vector<TreeNode *> v;
        auto lam = [&v](TreeNode *tp) {
            v.push_back(tp);
        };
        inorderTP(root, lam);
        for (int i = 0; i < v.size() - 1; ++i) {
            v[i]->left = nullptr;
            v[i]->right = v[i + 1];
        }
        // fix last one
        v[v.size() - 1]->left = v[v.size() - 1]->right = nullptr;

        return v[0];
    }
};

void test1() {
    vector<int> v1{5, 3, 6, 2, 4, -1, 8, 1, -1, -1, -1, 7, 9};
    auto t1 = new TreeNode(v1, -1);
    cout << t1 << endl;

    cout << "[1-2-3...] ? " << Solution().increasingBST(t1) << endl;

    vector<int> v2{5, 2};
    auto t2 = new TreeNode(v2, -1);
    cout << t2 << endl;

    cout << "[1-2-3...] ? " << Solution().increasingBST(t2) << endl;
}

void test2() {

}

void test3() {

}