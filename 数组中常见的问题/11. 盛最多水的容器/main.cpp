//==================================================================
// Leetcode代码
// 作者：曹佳
//==================================================================
//
// 11. 盛最多水的容器
// 题目：给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别
// 为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 说明：你不能倾斜容器，且 n 的值至少为 2。
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//双指针

int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1,volume = 0;
    while(left < right){
        if(volume < (right - left) * min(height[left], height[right]))
            volume = (right - left) * min(height[left], height[right]);
        if(height[left] > height[right])
            right--;
        else
            left++;
    }
    return volume;
}

int main()
{
    vector<int> ivec = {1,8,6,2,5,4,8,3,7 };
    int a = maxArea(ivec);
    cout << a << endl;//预期结果49
    return 0;
}
