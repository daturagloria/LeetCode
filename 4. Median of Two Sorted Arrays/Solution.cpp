class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int>& A = m < n ? nums1 : nums2;
        vector<int>& B = m < n ? nums2 : nums1;
        if (m > n) {
            int temp = m;
            m = n;
            n = temp;
        }
        if (m == 0) {
            if (n % 2 == 0)
                return (B[n / 2] + B[n / 2 - 1]) / 2.0;
            else
                return B[n / 2];
        }
        int imin = 0, imax = m, half_len = (m + n + 1) / 2;
        while (true) {
            int i = (imin + imax) / 2;
            int j = half_len - i;
            if (i < m && A[i] < B[j - 1])
                imin = i + 1;
            else if (i > 0 && A[i - 1] > B[j])
                imax = i - 1;
            else {
                if ((m + n) % 2 == 1) {
                    if (i == 0)
                        return B[j - 1];
                    else if (i == m && j == 0)
                        return A[i - 1];
                    else
                        return A[i - 1] > B[j - 1] ? A[i - 1] : B[j - 1];
                }
                else {
                    int max_of_left, min_of_right;
                    if (i == 0) {
                        max_of_left = B[j - 1];
                        if (j == n)
                            min_of_right = A[i];
                        else
                            min_of_right = A[i] < B[j] ? A[i] : B[j];
                    }
                    else if (i == m) {
                        min_of_right = B[j];
                        if (j == 0)
                            max_of_left = A[i - 1];
                        else
                            max_of_left = A[i - 1] > B[j - 1] ? A[i - 1] : B[j - 1];
                    }
                    else {
                        max_of_left = A[i - 1] > B[j - 1] ? A[i - 1] : B[j - 1];
                        min_of_right = A[i] < B[j] ? A[i] : B[j];
                    }
                    return (max_of_left + min_of_right) / 2.0;
                }
            }
        }
    }
};