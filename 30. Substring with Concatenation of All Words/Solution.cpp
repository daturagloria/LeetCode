class Solution
{
  public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int s_len = s.size();
        int words_len = words.size();
        if (words_len == 0 || s_len < words_len * words[0].size())
            return res;
        int word_len = words[0].size();
        int total_len = word_len * words_len;
        unordered_map<string, int> map_dict;
        unordered_map<string, int> cur_dict;
        for (vector<string>::iterator word = words.begin(); word != words.end(); word++)
            if (map_dict.find(*word) == map_dict.end())
                map_dict.insert({*word, 1});
            else
                map_dict.find(*word)->second++;

        for (int start = 0; start < s_len - total_len + 1; start++)
        {
            int end = start;
            while (end < start + total_len)
            {
                string substr = s.substr(end, word_len);
                auto search = cur_dict.find(substr);
                if (search != cur_dict.end())
                    search->second++;
                else
                    cur_dict.insert({substr, 1});
                search = map_dict.find(substr);
                if (search == map_dict.end())
                    map_dict.insert({substr, 0});
                if (cur_dict[substr] > map_dict[substr])
                    break;
                end += word_len;
            }
            if (end == start + total_len)
                res.push_back(start);
            cur_dict.clear();
        }
        return res;
    }
};