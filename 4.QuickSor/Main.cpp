#include <iostream>

// 피벗 선택 함수
int Partition(int* array, int left, int right)
{
	// 피벗 선택
	int first = left;
	int pivot = array[first];
	
	// 다음 위치로 이동
	++left;

	while (left <= right)
	{
		// left는 pivot보다 큰 값 검색
		while (array[left] <= pivot)
		{
			++left;
		}

		//right는 pivot보다 작은 값 검색
		while (array[right] > pivot)
		{
			--right;
		}

		if (left >= right)
		{
			break;
		}

		if (left < right)
			std::swap(array[left], array[right]);
		else
			break;
	}
		
	// 교환
	std::swap(array[first], array[right]);

	// 피벗 반환
	return right;
}

// 퀵 정렬 함수
void QuickSort(int* array, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int partition = Partition(array, left, right);
	QuickSort(array, left, partition - 1);

	QuickSort(array, partition + 1, right);
}

void PrintArray(int array[], int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}


int main()
{
	int array[] = { 18, 19, 21, 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16, 11, 25 };

	int length = _countof(array);

	std::cout << "정렬 전: ";
	PrintArray(array, length);

	QuickSort(array, 0, length - 1);

	std::cout << "정렬 후: ";
	PrintArray(array, length);

	std::cin.get();
	
}