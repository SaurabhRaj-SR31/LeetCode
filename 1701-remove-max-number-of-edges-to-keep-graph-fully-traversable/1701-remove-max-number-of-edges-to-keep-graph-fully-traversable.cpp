class Solution {
public:
    // Function to be used as comparator for sorting
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] > b[0];
    }

    // Function to find the parent of a node
    int find(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x], parent);
    }

    // Function to create union of two disjoint sets
    bool union1(int x, int y, vector<int>& parent, vector<int>& rank) {
        int lx = find(x, parent);
        int ly = find(y, parent);

        // Merge their leader
        if (lx != ly) {
            if (rank[lx] > rank[ly]) {
                parent[ly] = lx;
            } else if (rank[lx] < rank[ly]) {
                parent[lx] = ly;
            } else {
                parent[lx] = ly;
                rank[ly] += 1;
            }
            return true;
        }
        return false;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int n1 = n + 1;

        // Sort on the basis of that edge which is traversable by both persons
        sort(edges.begin(), edges.end(), cmp);

        vector<int> parentA(n1), parentB(n1), rankA(n1), rankB(n1);

        // Initially, every node is a leader and their rank is 1.
        for (int i = 1; i <= n; i++) {
            parentA[i] = i;
            parentB[i] = i;
            rankA[i] = 1;
            rankB[i] = 1;
        }

        int connectedComponentA = n, connectedComponentB = n, remove = 0;

        // Iterate over all the edges.
        for (auto& i : edges) {
            if (i[0] == 3) { // Both persons can traverse
                bool mergeA = union1(i[1], i[2], parentA, rankA);
                bool mergeB = union1(i[1], i[2], parentB, rankB);

                if (mergeA) connectedComponentA--;
                if (mergeB) connectedComponentB--;

                if (!mergeA && !mergeB) remove++;
            } else if (i[0] == 1) { // Only person A can traverse
                bool mergeA = union1(i[1], i[2], parentA, rankA);

                if (mergeA) connectedComponentA--;

                if (!mergeA) remove++;
            } else { // Only person B can traverse
                bool mergeB = union1(i[1], i[2], parentB, rankB);

                if (mergeB) connectedComponentB--;

                if (!mergeB) remove++;
            }
        }

        if (connectedComponentA != 1 || connectedComponentB != 1) {
            return -1;
        }

        return remove;
    }
};
