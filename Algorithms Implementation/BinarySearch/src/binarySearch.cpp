//
// Created by auddn on 2020-05-08.
//
// 공식 버전
bool binarySearch(vector<int>& A, int N, int x)
{
    // search space is A[low..high]
    int low = 0, high = N - 1;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (x == A[mid])
            return true;

        else if (x < A[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return false;
}

// 내 버젼
bool binarySearch(vector<int>& arr, int x){
    int left = 0;
    int right = arr.size()-1;

    while(left <= right){
        int mid = (left+right)/2 +1;
        if(arr[mid] == x)
            return true;

        if(left == right)
            return arr[left] == x;
        else if(arr[mid] > x){
            right = mid-1;
        } else
            left = mid+1;
    }
    return false;
}

