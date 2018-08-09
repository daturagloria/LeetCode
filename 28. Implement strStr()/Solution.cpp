class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int len1 = haystack.size();
        int len2 = needle.size();
        if (len2 == 0)
            return 0;
        if (len1 < len2)
            return -1;
        int i, j = 0;
        const int N = len1 - len2 + 1;
        for (i = 0; i < N; i++)
        {
            j = 0;
            while (j < len2 && haystack[i + j] == needle[j])
            {
                j++;
            }
            if (j == len2)
                return i;
        }
        return -1;
    }
};