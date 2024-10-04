#include <stdio.h>
#include <stdlib.h>
//冒泡排序
void bubbleSort(int array[], int size)
{
	int i,j,temp;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size - i -1; j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp; 
			}
		}
	}	
} 

//选择排序
void selectSort(int array[], int size)
{
	int i,j,min,temp;
	for(i = 0; i < size; i++)
	{
		min = i; 
		for(j = i+1; j < size; j++)	
		{
			if(array[j] < array[min])
				min = j;
			if( min != i)
			{
				temp = array[i];
				array[i] = array[min];
				array[min] = temp; 
			}
		}
	}	
} 

//插入排序		不熟练 
void insertSort(int *nums, int num)
{
	int i,temp;			//dst表要插入的目标索引 
	int preIndex = 0; 	//已排序下标
	int currentVal;		//当前排序的值，下标为	preIndex + 1;
			 
	for(i = 0; i < num; i++)
	{
		preIndex = i-1;					//已排序下标 
		currentVal = nums[preIndex+1];	//当前排序的值 
		
		//在已被排序过数据中倒序寻找合适的位置
		//如果当前待排序数据比 比较的元素要小，将比较的元素元素后移一位
		while( preIndex >= 0 && currentVal < nums[preIndex]) 	//后面数比前面大 
		{
			nums[preIndex + 1] = nums[preIndex];		//右移 
			preIndex--;
		}
		nums[preIndex + 1] = currentVal;				//插入排序数 
	}	
} 
void insertSort2(int *nums, int num)
{
	int i,j;
	int val;
	for(i = 1; i < num; i++)
	{
		val = nums[i];
		for(j = i-1; j >= 0; j--)
		{
			if(val > nums[j]) 
				break;
			nums[j+1] = nums[j];
		}
		nums[j + 1] = val;
	}
	
} 
//希尔排序  不了解  不熟悉  需反复复习 
//对希尔排序中的单个组进行排序
//*nums-待排序的数组地址，num-数组总的长度，strat-分组的起始位置, step-分组的步长(增量)
void groupSort(int *nums, int num, int start, int step)
{
	int i,j;
	int val;	//插入排序中的插入值 
	for(i = start + step; i < num; i = i + step)		//排序轮数 
	{
		val = nums[i];
		for(j = i - step; j >= 0; j = j - step)
		{
			if(val > nums[j])
				break;
			nums[j + step] = nums[j];
		}
		nums[j + step] = val;
	}
} 
void shellSort(int *nums, int num)
{
	int i;
	int step = num / 2;	
	while(step > 0)				//排序轮数，直到step = 0 
	{
		for(i = 0; i < step; i++) {
			groupSort(nums, num, i, step);	
		}
		step /= 2;
	} 
}

/*
for(i = 0; i < quotient; i++)
{
	for(j = 0; j < quotient; j++)
	{
		preIndex = j-1;	
		currentVal = nums[preIndex + quotient];	//当前排序的值 
		
		while( preIndex >= 0 && currentVal < nums[preIndex]) 	//后面数比前面大 
		{
			nums[preIndex + quotient] = nums[preIndex];		//右移 
			preIndex -= quotient;
		}
		nums[preIndex + quotient] = currentVal;				//插入排序数 
}
}
*/
//快速排序  不了解 
/*
1)先从数列中取出一个元素作为基准数
2)扫描数列，将比基准数小的元素全部放到它的左边，
大于或等于基准数的元素全部放到它的右边，得到左右两个区间
3)再对左右区间重复第二步，直到各区间少于两个元素
*/
//挖坑填数 + 分治 
void quickSort(int *nums, int num)
{
	int val = nums[0];		//temp 表示比较的基准值 
	int left  = 0;
	int right = num -1;		 
	int moving = 2;			//moving表示当前需要移动的标志 ，1---left    2---right;
	if(num <2)	return; 
	while(left < right)
	{
		if(moving == 2)
		{
			if(nums[right] >= val)
			{
				right--;
				continue;
			}
			else
			{
				nums[left] = nums[right];
				left++; 
				moving = 1;
			}
		}
		else if(moving == 1)
		{
			if(nums[left] <= val)
			{
				left++;
				continue;
			}
			else
			{
				nums[right] = nums[left];
				right--;
				moving = 2;
			}
		}
	} 
	//printf("%d   %d\n",left,right); 
	nums[left] = val;
	quickSort(nums, left);				//基准数左侧递归 
	quickSort(nums+left+1, num-left-1);	//基准数右侧递归 
} 



//归并排序   ----   归来  排序核心程序入口 
void merge(int* arr, int* tempAyy, int left, int mid, int right)
{
	int pos = left;	// 临时数组下标 
	int l_pos = left;		// 左半区第一个未排序的元素下标 
	int r_pos = mid + 1;	// 右半区第一个未排序的元素下标 
	
	while(l_pos <= mid && r_pos <= right)
	{
		if(arr[l_pos] <= arr[r_pos])		// 左半区第一个元素更小 
			tempAyy[pos++] = arr[l_pos++];
		else								// 右半区第一个元素更小 
			tempAyy[pos++] = arr[r_pos++];
	}
		
	while(l_pos <= mid)						// 合并左半区剩余元素 
		tempAyy[pos++] = arr[l_pos++];
	while(r_pos <= right)					// 合并右半区剩余元素 
		tempAyy[pos++] = arr[r_pos++];
		
	while(left <= right)
	{
		arr[left] = tempAyy[left];
		left++;
	}
	
} 

//归并排序   ---- 递去  划分函数入口 
void msort(int* arr, int* tempAyy, int left, int right)
{
	
	int mid;
	// 只有一个区域不需要划分，只需要归并即可 
	if(left < right)
	{
		//mid = left + (right - left) / 2;
		mid =  (left + right) / 2;
 		// 递去-----裂开 
		// 左侧递归  递归划分左侧部分 
		msort(arr, tempAyy, left, mid);
		// 右侧递归   递归划分右侧部分
		msort(arr, tempAyy, mid + 1, right);
		
		// 归来---排序  合并已经排序的部分 
		merge(arr, tempAyy, left, mid, right); 
	}
}



//归并排序   ---函数总入口   不熟悉 理解不了一点 
void mergeSort(int arr[], int numSize)
{
	int * tempAyy = (int *)malloc(numSize * sizeof(int));
	if(tempAyy)
	{
		msort(arr, tempAyy, 0, numSize-1);
		free(tempAyy);
	}	
	else
		printf("malloc failed\n");
}


int main()
{
	int a[10]={4,2,6,3,5,9,8,7,1,0};
	mergeSort(a,sizeof(a)/sizeof(a[0]));
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		printf("%d ",a[i]); 

} 
