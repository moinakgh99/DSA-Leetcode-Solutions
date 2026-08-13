class Solution {
public:

    struct Node {
        int prefix = 0;
        int suffix = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> tree;

    Node merge(const Node &left, const Node &right, int leftLen, int rightLen) {
        Node res;

        res.leftChar = left.leftChar;  // root me leftmost char hmesha left child hoga !!
        res.rightChar = right.rightChar;  // root me hmesha rightmost char right child k hi hoga !!

        res.prefix = left.prefix;  // root me prefix jo hoga , hmesha left child k hoga !!
        if(left.prefix == leftLen && left.rightChar == right.leftChar) {
            res.prefix = left.prefix + right.prefix;
        }

        res.suffix = right.suffix;  // root me suffix jo hoga , hmesha right child k hoga !!
        if(right.suffix == rightLen && right.leftChar == left.rightChar) {
            res.suffix = right.suffix + left.suffix;
        }

        res.maxLen = max(left.maxLen, right.maxLen);
        if(left.rightChar == right.leftChar) res.maxLen = max(res.maxLen, left.suffix + right.prefix);

        return res;
    }

    void buildSegTree(int idx, int left, int right, string &s) {
        if(left == right) {
            tree[idx] = {1, 1, 1, s[left], s[left]};  // agar last me pooch gye, to pre, suff, maxLen sb 1 honga !!
            return;
        }

        int mid = left + (right - left) / 2;
        buildSegTree(2 * idx + 1, left, mid, s);  // left subtree bnaaega !!
        buildSegTree(2 * idx + 2, mid + 1, right, s);  // right subtree bnaaega !!

        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2], mid - left + 1, right - mid);  // last me jaaka root me merge krna h !!
    }

    void update(int idx, int left, int right, int pos, char ch) {
        if(left == right) {
            tree[idx] = {1, 1, 1, ch, ch};  // lastme pooch gye , jo single char rkhta h !!
            return;
        }

        int mid = left + (right - left) / 2;
        if(pos <= mid) {
            // left subtree me jaao ..
            update(2 * idx + 1, left, mid, pos, ch);
        }
        else {
            // vrna right subtree me jaao !!!
            update(2 * idx + 2, mid + 1, right, pos, ch);
        }

        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2], mid - left + 1, right - mid);  // last me jaaka root me merge krna h !!
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        tree.assign(4 * n, Node());  // -> segment tree build kr rhe h ..

        buildSegTree(0, 0, n-1, s);

        int k = queryIndices.size();

        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(0, 0, n-1, pos, ch);   // string ko update krega !!

            ans[i] = tree[0].maxLen;  // root node me saare strings cover honga !!
        }

        return ans;
    }
};