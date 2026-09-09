class Solution {
public:
    int mergeSort(vector<long long>& prefix, int lower, int upper, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            int count = 0;
            count += mergeSort(prefix, lower, upper, start, mid);
            count += mergeSort(prefix, lower, upper, mid + 1, end);
            count += merge(prefix, lower, upper, start, mid, end);
            return count;
        }
        return 0;
    }

    int merge(vector<long long>& prefix, int lower, int upper, int start, int mid, int end) {
        int count = 0;
        int l = mid + 1;
        int r = mid + 1;

        // 1. Count the valid range sums across the two sorted halves
        for (int i = start; i <= mid; ++i) {
            while (l <= end && prefix[l] - prefix[i] < lower) l++;
            while (r <= end && prefix[r] - prefix[i] <= upper) r++;
            count += (r - l);
        }

        // 2. Standard merge sort combination step
        vector<long long> temp(end - start + 1, 0);
        int i = start;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end) {
            if (prefix[i] <= prefix[j]) {
                temp[k++] = prefix[i++];
            } else {
                temp[k++] = prefix[j++];
            }
        }

        while (i <= mid) temp[k++] = prefix[i++];
        while (j <= end) temp[k++] = prefix[j++];

        // 3. Copy the sorted temporary array back into the original prefix array
        for (int p = 0; p < temp.size(); ++p) {
            prefix[start + p] = temp[p];
        }

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        // Using long long to avoid integer overflow during sum checks
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        return mergeSort(prefix, lower, upper, 0, n);
    }
};
