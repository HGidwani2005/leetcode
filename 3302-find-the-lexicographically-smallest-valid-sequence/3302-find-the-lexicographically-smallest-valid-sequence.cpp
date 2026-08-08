class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = latest index in word1 from which
        // word2[j...] can be matched exactly.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Build suffix information from right to left
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // If the entire word2 cannot even be matched exactly,
        // we may still be able to match it using one mismatch.
        bool mismatchUsed = false;

        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Normal matching case
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use our one allowed mismatch
            else if (!mismatchUsed &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;
                mismatchUsed = true;
            }
        }

        // Couldn't form a sequence of length m
        if (j != m)
            return {};

        return ans;
    }
};