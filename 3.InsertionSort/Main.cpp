#include <iostream>

// 삽입 정렬 함수
void InsertionSort(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		int keyValue = array[i];
		int j = i - 1;

		// 셔플링
		while (j >= 0 && array[j] > keyValue)
		{
			array[j + 1] = array[j];
			--j;
		}

		//값 끼우기
		array[j + 1] = keyValue;

	}

}

// 배열 출력 함수
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << (i < length - 1 ? ", " : "\n");
	}
}

int main()
{
	int array[] = { 5,2,8,4,1,2,3,1,6,10,14,6,22,51 };
	int length = sizeof(array) / sizeof(int);

	PrintArray(array, length);

	InsertionSort(array, length);

	PrintArray(array, length);
}