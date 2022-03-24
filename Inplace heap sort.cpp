Code : In-place heap sort
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
  // Solution
  //IN-PLACE word is used before those algorithims who have O(1) space complexity/

/******to make heap use INSERT() CODE and for sorting the heap use REMOVE() code*******/

//first we need to convert the given array into min heap
//then through remoe min function we one by one remove minimums from heap 
//and take them in array
//this will be our sorted array
void heapSort(int arr[], int n) {
    //making heap inside the given array
    //we are inserting elements from array for making a heap
    //i will tell us the starting element of unsorted array
    int i=1;//assuming that 0th element is in our heap
    for(i=1;i<n;i++)
    {
        int ci=i;//childindex
        while(ci>0)//up heapyfy condition....jab tak root pe nai pohoch te 
        {
            int pi = (ci-1)/2;
            if(arr[pi] > arr[ci])//we are making min heap
            {
                int temp = arr[pi];
                arr[pi] = arr[ci];
                arr[ci] = temp;
             }
            else
                break;
            ci = pi;
        }
    }
    //now we make out a sorted array out this heap
    //remove elements now
    int size = n;
    while(size>1){
        int temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;
    //now do down hepify
    size--;//becoz now the smallest is already at last which right position for decresing sort
    int pi = 0,LCI=2*pi+1,RCI=2*pi+2;
    while(LCI<size)
    {
        int minIndex = pi;
        if(arr[LCI]<arr[minIndex])
            minIndex = LCI;
        if(RCI<size && arr[RCI]<arr[minIndex])
            minIndex = RCI;
        if(minIndex == pi)
            break;
        
        int temp = arr[pi];
        arr[pi] = arr[minIndex];
        arr[minIndex] = temp;
        
        pi = minIndex;
        LCI=2*pi+1;
        RCI=2*pi+2;
    }
    }
    
}
