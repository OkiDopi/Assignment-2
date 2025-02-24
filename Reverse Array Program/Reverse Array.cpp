#include <iostream> //input output!
//prototype for a function that will be used to take in an array, and flip it. The pre condition is the function needing the array to flip and the size of that array. Post condition is it will return a pointer towards the flipped array stored in heap.
int* flipArray(int const arr[], int arrSize); 
//prototype for a function that will run through the arrays and print their elements. The pre condition is an array and size of said array, and the post condition is it will print out the contents of the array to console. 
void print(int const arr[], int size); 

int main() {
	//populates an array
	const int arraySize = 12;
	int array[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = i + 1;
	}
	//stores the flipped array to a 
	int* flippedArray = flipArray(array, arraySize);
	//prints everything out to console
	std::cout << "Regular Array" <<"\n";
	print(array, arraySize); //specifically prints out the first array
	std::cout << "\n";
	std::cout << "Flipped Array" << "\n";
	print(flippedArray, arraySize); //specifically prints out the flipped array
	std::cout << "\n";
	delete[] flippedArray; //deletes the array from heap memory

	return 0;

}
//function that takes in an array, and flips it and stores to heap
int* flipArray(int const arr[], int arrSize) {

	int* flippedArray = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {

		flippedArray[i] = arr[arrSize - 1 - i];

	}

	return flippedArray;

}
//function that prints out input array
void print(int const arr[], int size) {

	for (int i = 0; i < size; i++) {

		std::cout << arr[i] << " ";

	}

}
