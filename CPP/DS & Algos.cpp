#include <iostream>

using namespace std;

int Partition(int nums[], int i, int k) {
	int low, mid, high, pivot, temp = 0;
	low = i;
	high = k;
	mid = i - (k + i) / 2;
	pivot = nums[mid];
	bool done = false;

	while (!done) {
		while (nums[low] < pivot) {
			++low;
		}
		while (nums[high] > pivot) {
			--high;
		}
		if (low >= high) {
			done = true;
		}
		else {
			temp = nums[low];
			nums[low] = nums[high];
			nums[high] = temp;
			++low;
			--high;
		}
	}

	return high;
}

void QuickSort(int nums[], int i, int k) {
	int j = 0;
	if (i >= k) {
		return;
	}
	j = Partition(nums, i, k);
	QuickSort(nums, i, j);
	QuickSort(nums, j + 1, k);

	return;
}

int BinarySearch(int nums[], int N, int K) {
	int low = 0;
	int mid = 0;
	int high = N;

	while (high >= low) {
		mid = (high + low) / 2;

		if (nums[mid] < K) {
			low = mid + 1;
		}
		else if (nums[mid] > K) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
}

void Merge(int nums[], int i, int j, int k) {
	int mSize = k + 1;
	int mPos = 0;
	int lPos = i;
	int rPos = j+1;
	int* mNums = new int[mSize];

	while (lPos <= j && rPos <= k) {
		if (nums[lPos] < nums[rPos]) {
			mNums[mPos] = nums[lPos];
			++lPos;
		}
		else {
			mNums[mPos] = nums[rPos];
			++rPos;
		}
		++mPos;

		while (lPos <= j) {
			mNums[mPos] = nums[lPos];
			++lPos;
			++mPos;
		}
		while (rPos <= k) {
			mNums[mPos] = nums[rPos];
			++rPos;
			++mPos;
		}

		for (int mPos = 0; mPos < mSize; ++mPos) {
			nums[i + mPos] = mNums[mPos];
		}
	}

}

void MergeSort(int nums[], int i, int k) {
	int j = 0;

	if (i < k) {
		j = (k + i) / 2;

		MergeSort(nums, i, j);
		MergeSort(nums, j + 1, k);

		Merge(nums, i, j, k);
	}
}

int main() {
	int arr[] = {2, 5, 13, 3, 56, 76, 3, 45, 24, 7, 86};
	int SIZE = sizeof(arr) / sizeof(arr[0]);
	cout << SIZE << endl;

	for (int i = 0; i < SIZE; ++i) {
		cout << arr[i] << " ";
	}

	cout << endl;

	MergeSort(arr, 0, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		cout << arr[i] << " ";
	}

}