class Solution:
    def findMedianSortedArrays(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: float
        """
        m, n = len(A), len(B)
        if m > n:
            A, B, m, n = B, A, n, m
            
        if m == 0:
            if n % 2 == 0:
                return (B[n // 2] + B[n // 2 - 1]) / 2
            else:
                return B[n // 2]
            
        imin, imax, half_len = 0, m, (m + n + 1) // 2

        while True:
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and A[i] < B[j - 1]:
                imin = i + 1
            elif i > 0 and A[i - 1] > B[j]:
                imax = i - 1
            else:
                if (m + n) % 2 == 1:
                    if i == 0:
                        return B[j - 1]
                    elif i == m and j == 0:
                        return A[i - 1]
                    else:
                        return max(A[i - 1], B[j - 1])

                else:
                    if i == 0:
                        max_of_left = B[j - 1]
                        if j == n:
                            min_of_right = A[i]
                        else:
                            min_of_right = min(A[i], B[j])
                    elif i == m:
                        min_of_right = B[j]
                        if j == 0:
                            max_of_left = A[i - 1]
                        else:
                            max_of_left = max(A[i - 1], B[j - 1])
                    else:
                        max_of_left = max(A[i - 1], B[j - 1])
                        min_of_right = min(A[i], B[j])
                    return (max_of_left + min_of_right) / 2
