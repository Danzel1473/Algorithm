#include <iostream>

// 병합 함수 (Merge)
// array : 병합할 배열 변수
// leftArray : 왼쪽 배열 변수
// leftArrayLength : 왼쪽 배열 크기
// rightArray : 오른쪽 배열 변수
// rightArrayLength : 오른쪽 배열 크기
void Merge(int* array, 
	int* leftArray, int leftArrayLength, 
	int* rightArray, int rightArrayLength)
{
	// 인덱스 변수 선언

	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// 왼쪽/오른쪽 배열의 요소를 비교하면서 작은 순서로 array에 값 할당
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex;
		}
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex;
		}

		++mergedIndex;
	}

	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++mergedIndex;
		++leftIndex;
	}
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++mergedIndex;
		++rightIndex;
	}
}

// 정렬 함수 (MergeSort)
void MergeSort(int* array, int length)
{
	// 탈출 조건
	if (length <= 1)
	{
		return;
	}

	// 배열 분할
	int mid = length / 2;
	int* leftArray = new int[mid];
	int* rightArray = new int[length - mid];

	// 값 복사
	memcpy(leftArray, array, sizeof(int) * mid);
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

	// 재귀적 호출
	// 왼쪽 배열에 대해
	MergeSort(leftArray, mid);

	// 오른쪽 배열에 대해
	MergeSort(rightArray, length - mid);

	Merge(array, leftArray, mid, rightArray, length - mid);

	// 메모리 해제
	delete[] leftArray;
	delete[] rightArray;
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
	int array[] = { 5, 8, 1, 3, 124, 179, 12, 231, 4, 125, 13, 34, 5321, 8, 44, 56, 37624, 9, 31 };

	int length = _countof(array);

	std::cout << "정렬 전: ";
	PrintArray(array, length);

	// 정렬
	MergeSort(array, length);

	std::cout << "정렬 후: ";
	PrintArray(array, length);


	std::cin.get();
}