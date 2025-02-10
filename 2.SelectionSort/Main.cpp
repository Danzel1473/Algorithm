#include <iostream>

void SelectionSort(int* array, int length)
{
	for (int i = 0; i < length-1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		std::swap<int>(array[i], array[minIndex]);
	}
}

// 출력 함수
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i] << " ";
	}

	std::cout << "\n";
}

int main()
{
	int array[] = { 5,2,3,4,1,5,7,9,15,21,33,10,14 };

	// 배열 길이
	int length = sizeof(array) / sizeof(int);

	// 출력
	std::cout << "정렬 전: ";
	PrintArray(array, length);

	std::cout << "정렬 후: ";
	SelectionSort(array, length);
	PrintArray(array, length);
}