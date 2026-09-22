struct Node {

    // cnt[r] = number of subarrays whose product % k == r
    int cnt[5] = {0};

    // Product of the complete segment % k
    int prod = 0;
};


class SegmentTree {

public:

    int n, k;
    vector<Node> tree;


    // ---------------------------------------------------------
    // Constructor
    // ---------------------------------------------------------
    SegmentTree(vector<int>& nums, int k) {

        this->k = k;
        n = nums.size();

        // Allocate space for the segment tree
        tree.assign(4 * n, Node());

        build(0, 0, n - 1, nums);
    }


    // ---------------------------------------------------------
    // Build Segment Tree
    // ---------------------------------------------------------
    void build(int node, int left, int right,
               vector<int>& nums) {

        // Leaf node -> represents one element
        if (left == right) {

            createLeaf(node, nums[left]);
            return;
        }

        int mid = left + (right - left) / 2;


        // Build left child
        build(
            2 * node + 1,
            left,
            mid,
            nums
        );


        // Build right child
        build(
            2 * node + 2,
            mid + 1,
            right,
            nums
        );


        // Combine both children
        tree[node] = mergeNodes(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }


    // ---------------------------------------------------------
    // Create Leaf Node
    // ---------------------------------------------------------
    void createLeaf(int node, int value) {

        // Clear previous information
        for (int remainder = 0;
             remainder < k;
             remainder++) {

            tree[node].cnt[remainder] = 0;
        }


        // Product remainder of this single element
        int remainder = value % k;


        // A single element itself is one subarray
        tree[node].cnt[remainder] = 1;

        tree[node].prod = remainder;
    }


    // ---------------------------------------------------------
    // Merge Two Nodes
    // ---------------------------------------------------------
    Node mergeNodes(const Node& leftNode,
                    const Node& rightNode) {

        Node mergedNode;


        // Product of the complete merged segment:
        //
        //     left product × right product
        //
        // We only need the remainder.
        mergedNode.prod =
            (leftNode.prod * rightNode.prod) % k;


        // -----------------------------------------------------
        // Subarrays coming from the LEFT segment
        // -----------------------------------------------------

        for (int remainder = 0;
             remainder < k;
             remainder++) {

            mergedNode.cnt[remainder] =
                leftNode.cnt[remainder];
        }


        // -----------------------------------------------------
        // Subarrays involving the RIGHT segment
        // -----------------------------------------------------

        for (int rightRemainder = 0;
             rightRemainder < k;
             rightRemainder++) {

            /*
                Every subarray represented by rightNode has
                product remainder = rightRemainder.

                When combined with the complete left segment:

                    new remainder =
                    leftNode.prod * rightRemainder % k
            */

            int combinedRemainder =
                (leftNode.prod * rightRemainder) % k;


            mergedNode.cnt[combinedRemainder] +=
                rightNode.cnt[rightRemainder];
        }


        return mergedNode;
    }


    // ---------------------------------------------------------
    // Update One Element
    // ---------------------------------------------------------
    void updateTree(int node,
                    int left,
                    int right,
                    int updateIndex,
                    int newValue) {

        // Reached the element that needs to be updated
        if (left == right) {

            createLeaf(node, newValue);
            return;
        }


        int mid = left + (right - left) / 2;


        // Update LEFT child
        if (updateIndex <= mid) {

            updateTree(
                2 * node + 1,
                left,
                mid,
                updateIndex,
                newValue
            );
        }

        // Update RIGHT child
        else {

            updateTree(
                2 * node + 2,
                mid + 1,
                right,
                updateIndex,
                newValue
            );
        }


        // Recalculate current node
        // because one of its children changed
        tree[node] = mergeNodes(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }


    // Easy-to-use update function
    void update(int index, int value) {

        updateTree(
            0,
            0,
            n - 1,
            index,
            value
        );
    }


    // ---------------------------------------------------------
    // Query Range [queryStart, queryEnd]
    // ---------------------------------------------------------
    Node queryTree(int queryStart,
                   int queryEnd,
                   int node,
                   int left,
                   int right) {


        // Current segment is completely inside query range
        if (left >= queryStart &&
            right <= queryEnd) {

            return tree[node];
        }


        int mid = left + (right - left) / 2;


        // Query lies completely in LEFT child
        if (queryEnd <= mid) {

            return queryTree(
                queryStart,
                queryEnd,
                2 * node + 1,
                left,
                mid
            );
        }


        // Query lies completely in RIGHT child
        if (queryStart > mid) {

            return queryTree(
                queryStart,
                queryEnd,
                2 * node + 2,
                mid + 1,
                right
            );
        }


        // Query overlaps BOTH children
        Node leftResult = queryTree(
            queryStart,
            queryEnd,
            2 * node + 1,
            left,
            mid
        );


        Node rightResult = queryTree(
            queryStart,
            queryEnd,
            2 * node + 2,
            mid + 1,
            right
        );


        // Combine both parts
        return mergeNodes(
            leftResult,
            rightResult
        );
    }


    // Easy-to-use query function
    Node query(int left, int right) {

        return queryTree(
            left,
            right,
            0,
            0,
            n - 1
        );
    }
};



class Solution {

public:

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        int n = nums.size();

        // Build Segment Tree
        SegmentTree segmentTree(nums, k);

        vector<int> answer;


        for (auto& query : queries) {

            int updateIndex = query[0];
            int newValue = query[1];

            int queryStart = query[2];
            int requiredRemainder = query[3];


            // -------------------------------------------------
            // 1. Update nums[updateIndex]
            // -------------------------------------------------

            segmentTree.update(
                updateIndex,
                newValue
            );


            // -------------------------------------------------
            // 2. Query [queryStart, n - 1]
            // -------------------------------------------------

            Node rangeResult =
                segmentTree.query(
                    queryStart,
                    n - 1
                );


            // -------------------------------------------------
            // 3. Get count of subarrays whose product % k
            //    equals requiredRemainder
            // -------------------------------------------------

            answer.push_back(
                rangeResult.cnt[requiredRemainder]
            );
        }


        return answer;
    }
};