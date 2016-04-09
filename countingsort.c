// http://ideone.com/7RLpDt
#include <stdio.h>
#include <stdlib.h>

void Print_Array(int * array, int array_size){
	for (int i = 0; i < array_size; ++i)
	{
		if(i == (array_size-1)){
			printf("%d \n", array[i]);
		} else {
			printf("%d, ", array[i]);
		}
	}
}

int Maximum_Number(int * array, int array_size){
	int max_no = array[0];
	for (int i = 0; i < array_size; ++i)
	{
		if(array[i]> max_no){
			max_no = array[i];
		}
	}
	return max_no;
}

void Counting_Sort(int * array, int array_size){

	int max = Maximum_Number(array, array_size);
	int arrayB[array_size];
	int arrayC[max];
	int k = 0;

	for (int i = 0; i < array_size; ++i) // init B
	{
		arrayB[i] = 0;
	}

	for (int i = 0; i <= max; ++i) // init C
	{
		arrayC[i] = 0;
	}

	for (int i = 0; i < array_size; ++i) 
	{
		arrayC[array[i]]++; // C[A[i]] = C[A[i]] + 1;
	}
	
	for(int i = 0; i <= max; i++){ 
		for(int j = 0; j < arrayC[i]; j++){ 
			arrayB[k] = i; 
			k++; 
		}
	}

	printf("Input array: "); Print_Array(array, array_size);
	printf("Sorted array: "); Print_Array(arrayB, array_size);	

}

int main(){
	int arrayA[] = {2, 6, 4, 3, 2, 3, 4, 6, 3, 4, 3, 5, 2, 6}; 
	int sizeA = sizeof(arrayA)/sizeof(int); // size of array A.
	Counting_Sort(arrayA, sizeA); // caller
	return 0;
}