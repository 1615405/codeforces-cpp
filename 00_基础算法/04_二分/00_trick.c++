/*
整数集合上的二分
lower_bound 返回最小的满足 nums[i] >= target 的 i
如果数组为空，或者所有数都 < target, 则返回 len(nums)
要求 nums 是非递减的，即 nums[i] <= nums[i + 1]

有序数组中二分查找的四种类型
    1. 第一个大于等于x的下标: low_bound(x)
    2. 第一个大于x的下标: 可以转换为第一个大于等于 x+1 的下标, low_bound(x+1)
    3. 最后一个一个小于x的下标: 可以转换为第一个大于等于 x 的下标的左边位置, low_bound(x) - 1;
    4. 最后一个小于等于x的下标: 可以转换为第一个大于等于 x+1 的下标的左边位置, low_bound(x+1) - 1;
*/

// 区间[left, rirht]被划分成[left, pivot]和[pivot + 1, right]时使用：
int bsearch_1(int left, int right)
{
    while (left < right) {
        int pivot = (left + right) / 2;
        if (is_blue(pivot)) {  // pivot 属于蓝色, right = pivot
            right = pivot;
        } else {
            left = pivot + 1;
        }
    }
    return left;
}


// 区间[left, right]被划分成[left, pivot - 1]和[pivot, right]时使用：
int bsearch_2(int left, int right)
{
    while (left < right) {
        int pivot = (left + right + 1) / 2;
        if (is_red(pivot)) {  // pivot 属于红色, left = pivot
            left = pivot;
        } else {
            right = pivot - 1;
        }
    }
    return left;
}