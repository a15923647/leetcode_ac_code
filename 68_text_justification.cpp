class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        //prefix sum of total lenght
        //query for segment closet to maxWidth to form a new line (do binary search to the answer, upper_bound-1)
        //calculate for the space width and padding
        const size_t sum_size = words.size()+1;
        vector<int> sum(sum_size); //store the prefix sum for word in words padding with a space
        //sum[x] = sum of first x words length + x
        sum[0] = 0;
        for (int i = 1; i < sum_size; i++) {
          sum[i] = sum[i-1] + words[i-1].size() + 1;
        }
        vector<string> ans;
        //query for segment closet to maxWidth+1(including last space)
        int idx, prev_idx, seg_count, total_space, avg_space, additional_bound;
        for (prev_idx = 1; prev_idx < sum_size; prev_idx = idx) {
          idx = upper_bound(sum.begin()+prev_idx, sum.end(), sum[prev_idx-1] + maxWidth + 1) - sum.begin();
          seg_count = idx - prev_idx;
          total_space = maxWidth - (sum[idx-1] - sum[prev_idx-1] - seg_count);//subtract extra spaces
          avg_space = (idx < sum_size) ? total_space / max(1, seg_count-1) : 1;
          additional_bound = prev_idx + ( (idx < sum_size) ? total_space % max(1, seg_count-1) : 0 );
          string s;
          for (int i = prev_idx; i < idx; i++) {
            s += words[i-1];
            s += string((i < idx-1 ? (avg_space + (i < additional_bound)) : maxWidth-s.length()), ' ');
          }
          ans.push_back(s);
        }
        return ans;
    }
};