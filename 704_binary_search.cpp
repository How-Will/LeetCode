#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int lower_index = 0;
        int higher_index = nums.size() - 1; // 初始搜索范围[lower_index, higher_index]
        
        while(lower_index <= higher_index){
            int median_index = (lower_index + higher_index) / 2;
            if(nums[median_index] > target){
                // 调整搜索范围[lower_index, median_index - 1]
                higher_index = median_index - 1;
            }else if(nums[median_index] < target){
                // 调整搜索范围[median_index + 1, higher_index]
                lower_index = median_index + 1;
            }else{
                // 找到了target，返回下标
                return median_index;
            }
        }

        return -1;  // 数组中不存在target
    }
};

int main(){
    vector<int> ivec{-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution* sol = new Solution();

    int res = sol->search(ivec, target);

    cout << "res = " << res << endl;

    return 0;
}
