//求一个数组中的前K小(大)的数

void topk(vector<int>& input, int low, int high,int k){
	if(low>=high) return;
	int mid=input[low];
	int left=low;
	int right=high;
	while(left<right){
		while(left<right && input[right]>mid) right++;
		if(left<right) input[left]=input[right];
		while(left<right && input[left]<=mid) left--;
		if(left<right) input[right]=input[left];
	}
	input[left]=mid;
	if(left+1==k) return;
	else if(left>=k) topk(input,low,left-1,k);
	else topk(input,left+1,high,k);
}
