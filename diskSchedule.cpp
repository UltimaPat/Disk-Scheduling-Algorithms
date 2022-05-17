//Assignment 4
//Scan, C-Scan, FCFS
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//Scan function
int Scan(vector<int> cy, int head, int req) {
	int totalSum = 0; //Total head movement
	vector<int> left, right;
	//inputting the values from the main disk vector to two seperate vectors
	left.push_back(0);
	for (int i = 0; i < req; i++) {
		
		if (cy[i] < head) {
			left.push_back(i);
		}
	}
	right.push_back(0);
	for (int i = 0; i < req; i++) {
		if (cy[i] > head) {
			right.push_back(i);
		}
	}
	//Calculation
	for (int i = 0; i < req%2+1; i++) {
		totalSum += abs(left[i] - head);
		head = left[i];
		for (int j = 0; j < req / 2; j++) {
			totalSum += abs(right[i] - head);
			head = right[i];
		}
		
	}


	return totalSum;
}

//C-Scan function
int cScan(vector<int> cy, int head, int req) {
	int totalSum = 0;
	vector<int> left, right;
	//inputting the values from the main disk vector to two seperate vectors
	left.push_back(0);
	for (int i = 0; i < req; i++) {

		if (cy[i] < head) {
			left.push_back(i);
		}
	}
	right.push_back(0);
	for (int i = 0; i < req; i++) {
		if (cy[i] > head) {
			right.push_back(i);
		}
	}
	//Calculation
	for (int i = 0; i < req % 2 + 1; i++) {
		totalSum += abs(right[i] - head);
		head = right[i];
		for (int j = 0; j < req / 2; j++) {
			totalSum += abs(left[i] - head);
			head = left[i];
		}

	}
	return totalSum;
}

//First Come First Serve function
int FCFS(vector<int> cy, int head, int req) {
	int totalSum = 0; //Total head movement
	
	for (int i = 0; i < req; i++) {
		totalSum += abs(cy[i] - head);
		head = cy[i];
	}

	return totalSum;
}

//Algorithms: FCFS, C-Scan, Scan
int main() {
	
	int head; //position of the head
	int req; //number of requests
	vector <int> cy; //vector to hold said requests

	/*cout << "Enter the size of the disk." << endl;
	cin >> disk;*/
	cout << "Enter the number of requests." << endl;
	cin >> req;

	cout << "Enter individual request sizes." << endl;
	for (int i = 0; i < req; i++) {
		cy.push_back(i);
		cin >> cy[i];
	}
	cout << "Enter the position of the head." << endl;
	cin >> head;
	//Output
	cout << "First Come First Serve Algorithm: " << endl;
	cout << "Total head movement: " << FCFS(cy, head, req) << endl;
	cout << "Scan Algorithm: " << endl;
	cout << "Total head movement: " << Scan(cy, head, req) << endl;
	cout << "C-Scan Algorithm: " << endl;
	cout << "Total head movement: " << cScan(cy, head, req) << endl;

	return 0;
}