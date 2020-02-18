/*快速排序过程
1.递归终止条件left>=right
2.寻找中轴点mid
3.递归左边:left,mid-1
4.递归右边：mid+1,right
*/



void quick_sort(vector<int>& input, int low, int high){
	if(low>=high) return;
	int mid=input[low];
	int left=low;
	int right=high;
	auto get_index=[&]()->int{
		while(left<right){
			while(left<right && input[right]>=mid) right--;
			input[left]=input[right];
			while(left<right && input[left]<=mid) left++;
			input[right]=input[left];
		}
		input[left]=mid;
		return left;
	};
	int index=get_index();
	quick_sort(input,low,index-1);
	quick_sort(input,index+1,high);
}
