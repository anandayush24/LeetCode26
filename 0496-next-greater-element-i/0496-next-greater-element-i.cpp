class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;

        //traverse from right to left
        for(int itr= n-1; itr>=0; itr--) {
            int current = nums2[itr];

            //if stack is not empty, remove elements till the element 
            //is greater than current
            while(!st.empty() && st.top()<=current) {
                st.pop();
            }
            
            //if stack is empty, map -1 with current
            //else, map top of stack with current
            mp[current] = st.empty() ? -1 : st.top();

            //push current to stack
            st.push(current);
        }

        for(int itr=0; itr<nums1.size(); itr++) {
            if(mp.find(nums1[itr]) != mp.end()) {
                ans.push_back(mp[nums1[itr]]);
            }
        }

        return ans;
    }
};