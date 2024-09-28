#include <iostream>
#include <stdlib.h>
#include <stdio.h>



using namespace std;

class arrayADT {

public:
	int *A;
	int size;
	int length;

	arrayADT(int size) {
		this->size=size;
		A = new int[size];
		this->length = 0;
		
	}

	void Display() {
		cout << "Display: Size of array " <<this->size<<". Length of array " <<this->length<< endl;
		for (int i = 0; i < this->length; i++) {

			cout << this->A[i] << "\t";

		}
		cout << endl;
	}
	void Add(int element) {
		if (this->length == this->size) {
			cout << "Array is full! "<<element<<" could not added" << endl;
		}
		else {
			this->A[length] = element;
			this->length++;
			cout << "Element " <<element<< " was added."<<endl;

		}
		
	}

	void Insert(int index, int element) {
		if (index < 0) {
		 cout << "Index can not be smaller than zero! " << element << " could not inserted! " << endl;
		}
		else if (this->length == this->size) {
			cout << "Array is full! "<<element<<" could not inserted! " << " Please run ExpandArray function if you insert an element!" << endl;
		}
		else if(index >= this->size){
			cout << "Index is bigger than size! "<<element<<" could not inserted!" <<"Please expand the size if you want to insert an element!" << endl;
		}
		else if (this->length == 0) {
			cout << "Array is empty! " << element << " was inserted first index " << endl;
			this->A[0] = element;
			this->length++;
		}
		else if (this->size > this->length) {
			
			if (index >=this->length) {
				cout << element << " could not insert because index " << index << " is bigger than array length! "
					<<"Element was added end of the array!" << endl;
				this->A[this->length] = element;
				this -> length++;
				


			}
			else {
				for (int i = this->length; i > index; i--) {
					this->A[i] = this->A[i - 1];
				}
				this->A[index] = element;
				this->length++;
				cout << "Element " << element << " was inserted index " << index << "." << endl;

			}

			

		}
		

	}
	void Delete(int index) {
		if (index < 0) {
			cout << "Index can not be smaller than zero! Index could not deleted! There is no " << index << " index here" << endl;
		}
		else if (index >= this->size) {
			cout << "Index is bigger than size! Index could not deleted! There is no "<<index<<" index here"<<endl;
		}
		else if (this->length == 0) {
			cout << "Length is zero! There is no element to delete here" << endl;
		}
		else if(index>=this->length) {
			cout << "Index is equal or bigger than array length! Index could not deleted! There is no " << index << " index here" << endl;

		}
		else {

			cout << "Element "<< this->A[index] << " of the index "<<index<<" was deleted!" << endl;

			for (int i = index; i < this->length-1; i++) {

				// reduced if statement using
				
				this->A[i] = this->A[i + 1];

				

				
			}
			this->length--;

			// copy another array existing array because fix last index is garbage value
			int* B = new int[this->size];

			for (int j = 0; j < this->length; j++) {
				B[j] = A[j];
			}


			delete[] A;
			A = B;
			// i can't delete B because this is pointer and created heap not in stack
			//delete[] B;
			
			
			

		}

	}

	void Search(int element) {

		if (this->length == 0)
			cout << "Array is empty! Can not be searched element. Add element!" << endl;
		
		else {
			bool flag = false;

			for (int i = 0; i < this->length; i++) {
				if (element == this->A[i]) {
					cout << "Element " << element << " found " << i << ". index." << endl;
					flag = true;
				}
			}
			if (flag == false) {
				cout << "Element " << element << " not found" << endl;
			}
		}
		
	}
	void Get(int index) {
		if (index < 0)
			cout << "Index can not be smaller than zero!" << endl;
		else if (this->length == 0)
			cout << "Array is empty! Can not be got element. Add element!" << endl;
		else if (index < this->length)
			cout << "Get index " << index << " contains " << this->A[index] << endl;
		else if (index >= this->length)
			cout << " Index can not be equal or bigger than array length!" << endl;


	}
	void Set(int index, int element) {
		if (index < 0)
			cout << "Index can not be smaller than zero!" << endl;
		else if (this->length == 0)
			cout<<"Array is empty! Can not be setted element. Add element!"<<endl;
		else if (index < this->length) {
			cout << "Set index " << index << " as  " << element << endl;
			this->A[index] = element;
		}	
		else if (index >= this->length)
			cout << " Index can not be equal or bigger than array length!" << endl;
	}
	void Max() {
		if (this->length == 0) {
			cout << "Array is empty! Can not be find max. Add elements!" << endl;
		}
		else {
			int max = this->A[0];
			for (int i = 0; i < this->length; i++) {
				if (this->A[i] > max) {
					max = this->A[i];
				}
			}
			cout << "Max element is " << max << endl;
		}
	}
	void Min() {
		if (this->length == 0) {
			cout << "Array is empty! Can not be find min. Add elements!" << endl;
		}
		else {
			int min = this->A[0];
			for (int i = 0; i < this->length; i++) {
				if (this->A[i] < min) {
					min = this->A[i];
				}
			}
			cout << "Min element is " << min << endl;
		}
	}
	int SumRecursive(int index) {
		
		// this is a head recursion
		
		if (index < 0)
			return 0;
		if (this->length <= 0)
			return 0;
		if (index == this-> length)
			index --;
		if (index > this->length)
			return -1;
		if (this->length > 0 ) {
			return this->A[index] + SumRecursive(index - 1);
			

		}
		

	}

	int Sum(){
	
		int sum = 0;
			if (this->length == 0) {
				cout << "Array is empty! Can not be find sum. Add elements!" << endl;
			}
			else {

				for (int i = 0; i < this->length; i++) {
					sum += this->A[i];
				}




			}
			cout << "Sum of element is iteratively " << sum << endl;
			return sum;
	}

	void Average() {
		double average = 0;
		if (this->length == 0) {
			cout << "Array is empty! Can not be find average. Add elements!" << endl;
		}
		else {

			average = (float)(this->Sum()) / (float)(this->length);




		}
		cout << "Average of element is " << average << endl;
	}
	
	
	void Reverse() {

		if (this->length == 0) {
			cout << "Array is empty! Can not be reversed. Add elements!" << endl;
		}
		else {


			int* B = new int[this->size];

			for (int i = 0; i < this->length; i++) {
				B[i] = this->A[this->length - 1 - i];
			}
			delete[]this->A;
			this->A = B;
			cout << "Array reversed" << endl;
		}

	}
	void RightShift() {
		if (this->length == 0) {
			cout << "Array is empty! Can not be shifted. Add elements!" << endl;
		}
		else if (this->length == this->size) {

			for (int i = 1; i < this->length; i++) {

				this->A[this->length - i] = this->A[this->length -i-1];
				
			}
			this->A[0] = 0;


			cout << "Array is full! Array shifted to right 1 index and last element deleted!" << endl;
			


		}
		else if(this->length < this->size) {
			for (int i = 0; i < this->length; i++) {

				this->A[this->length-i] = this->A[this->length - i-1];
			}
			this->A[0] = 0;
			cout << "Array shifted to right 1 index. Shift was presented 0."<< endl;
			this->length++;


		}

	}
	void LeftShift() {
		if (this->length == 0) {
			cout << "Array is empty! Can not be shifted. Add elements!" << endl;
		}
		else if (this->length == this->size) {

			for (int i = 0; i < this->length; i++) {

				this->A[i] = this->A[i+1];
			}
			this->A[this->length - 1] = 0;

			cout << "Array is full! Array shifted to left 1 index and first element deleted! Shift was presented 0." << endl;



		}
		else if (this->length < this->size) {
		
			for (int i = 1; i<this->length; i++) {

				this->A[i-1] = this->A[i];
			}
			this->A[this->length-1] = 0;
			cout << "Array shifted to left 1 index. Shift was presented 0." << endl;
			//			this->length++;


		}
		

	}
	void RightRotation() {
		if (this->length == 0) {
			cout << "Array is empty! Can not be shifted. Add elements!" << endl;
		}
		
		else if (this->length <= this->size) {
			int temp = this->A[this->length - 1];
			for (int i =0; i < this->length-1; i++) {

				this->A[this->length-i-1] = this->A[this->length-i-2];
			}
			this->A[0] = temp;
			cout << "Array rotated to right 1 index. Last element " << temp << " assigned to first index" << endl;
			


		}

	}
	void LeftRotation() {
		if (this->length == 0) {
			cout << "Array is empty! Can not be shifted. Add elements!" << endl;
		}

		else if (this->length <= this->size) {
			int temp = this->A[0];
			for (int i = 0; i < this->length - 1; i++) {

				this->A[i] = this->A[i+1];
			}
			this->A[this->length-1] = temp;
			cout << "Array rotated to left 1 index. First element " << temp << " assigned to last index" << endl;



		}

	}
	void Sort() {

		int temp,min,minindex;

		for (int j = 0; j < this->length;j++) {
			min = this->A[j];
			for (int i = 0+j; i < this->length; i++) {

				if (this->A[i] < min) {
					temp = this->A[j];
					this->A[j] = this->A[i];
					this->A[i] = temp;
					min = this->A[j];


				}
				
			}
		}
		cout << "Array sorted!" << endl;
	}
	void BinarySearch(int element) {
		int low=0, high=low+this->length-1, mid=(low+high)/2;

		if (this->A[mid] == element) {
			cout << "Element " << element << " found" << mid << " index by used Binary Search" << endl;
		}
		else {

			while (this->A[mid] != element) {
				if (element < this->A[mid]) {
					high = mid - 1;
					mid = (low + high) / 2;
				}
				else {
					low = mid + 1;
					mid= (low + high) / 2;
				}

				if (this->A[mid] == element) {
					cout << "Element " << element << " found " << mid << " index by using Binary Search" << endl;
				}
				else if(low>high ) {
					cout << "Element " << element << " can not found " << " by using Binary Search" << endl;
					break;

				}

			}
		}

	}

};



int main() {
	// find array address demonstrate
	//int x[3][3] = { {1,1,1},{1,1,1},{1,1,1} };
	//cout <<x<<endl<<&x[0][0] << endl << *(x + 1) << endl << x + 1 << endl << *(x + 2) + 3;

	int elementOfArrayNumber = 11;

	arrayADT array(elementOfArrayNumber);

	
	array.Insert(8, 11);
	array.Insert(8, 11);
	array.Add(1);
	array.Add(2);
	array.Add(4);
	array.Add(1);
	array.Add(98);
	array.Add(8);
	
	
	array.Display();
	array.Delete(6);
	array.Display();
	array.Delete(0);
	array.Set(3,24);
	array.Set(2, -5);
	array.Display();
	array.Search(9);
	array.Get(5);

	array.Max();
	array.Min();
	array.Reverse();
	array.Display();
	array.RightRotation();
	array.Display();
	array.Delete(0);
	array.Display();
	array.Sort();
	array.Display();
	array.Add(-8);
	array.Add(0);
	array.Add(4);
	array.Display();

	array.Sort();
	array.Display();
	array.BinarySearch(24);
	cout << "Sum recursively is " << array.SumRecursive(elementOfArrayNumber) << endl;
	array.Sum();
	array.Average();
	array.Add(-8);

	array.Display();
	
	
	array.RightShift();

	

	array.Display();




	

	

	








	return 0;
}