#include <iostream>
#include <vector>
// 힙 만들기 (Heapify) 함수
void Heapify(std::vector<int>& array, int length, int i)
{
	while (true)
	{
		// 힙 구성을 위한 인덱스
		int largest = i;
		
		// 왼쪽 자손 인덱스
		int left = 2 * i + 1;

		// 오른쪽 자손 인덱스
		int right = 2 * i + 2;
	
		if (left < length && array[left] > array[largest])
		{
			largest = left;
		}
		if (right < length && array[right] > array[largest])
		{
			largest = right;
		}
		
		if (largest == i) break;

		std::swap(array[i], array[largest]);
		i = largest;
	}
}

// 힙 정렬 함수 (HeapSort)
void HeapSort(std::vector<int>& array)
{
	// 전체 크기
	int length = (int)array.size();

	for (int i = length / 2 - 1; i >= 0; --i)
	{
		// 힙 만들기
		Heapify(array, length, i);
	}

	// 정렬
	for (int i = length - 1; i > 0; --i)
	{
		std::swap(array[0], array[i]);
		Heapify(array, i, 0);
	}
}

void PrintArray(std::vector<int>& array)
{
	for (int ix = 0; ix < array.size(); ++ix)
	{
		std::cout << array[ix];
		if (ix < array.size() - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

int main()
{
	std::vector<int> array = { 5, 8, 1, 3, 124, 179, 12, 231, 4, 125, 13, 34, 5321, 8, 44, 56, 37624, 9, 31 };

	// 정렬 전 출력
	std::cout << "정렬 전: ";
	PrintArray(array);

	HeapSort(array);

	std::cout << "정렬 후: ";
	PrintArray(array);

	HeapSort(array);
}