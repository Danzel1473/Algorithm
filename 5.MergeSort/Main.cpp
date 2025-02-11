#include <iostream>

// ���� �Լ� (Merge)
// array : ������ �迭 ����
// leftArray : ���� �迭 ����
// leftArrayLength : ���� �迭 ũ��
// rightArray : ������ �迭 ����
// rightArrayLength : ������ �迭 ũ��
void Merge(int* array, 
	int* leftArray, int leftArrayLength, 
	int* rightArray, int rightArrayLength)
{
	// �ε��� ���� ����

	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// ����/������ �迭�� ��Ҹ� ���ϸ鼭 ���� ������ array�� �� �Ҵ�
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

// ���� �Լ� (MergeSort)
void MergeSort(int* array, int length)
{
	// Ż�� ����
	if (length <= 1)
	{
		return;
	}

	// �迭 ����
	int mid = length / 2;
	int* leftArray = new int[mid];
	int* rightArray = new int[length - mid];

	// �� ����
	memcpy(leftArray, array, sizeof(int) * mid);
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

	// ����� ȣ��
	// ���� �迭�� ����
	MergeSort(leftArray, mid);

	// ������ �迭�� ����
	MergeSort(rightArray, length - mid);

	Merge(array, leftArray, mid, rightArray, length - mid);

	// �޸� ����
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

	std::cout << "���� ��: ";
	PrintArray(array, length);

	// ����
	MergeSort(array, length);

	std::cout << "���� ��: ";
	PrintArray(array, length);


	std::cin.get();
}