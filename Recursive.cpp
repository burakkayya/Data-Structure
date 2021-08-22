#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib> 
#include <string>

using namespace std;

int rowsum = 0;
int coloumnsum = 0;

int rowcounter(int arr[][20], int i, int j) {


	if (arr[i][j] == 1) {

		if (arr[i - 1][j - 1] == 1 && (j - 1) >= 0 && (i - 1) >= 0) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i - 1, j - 1);

		}

		else if (arr[i - 1][j] == 1 && (i - 1) >= 0) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i - 1, j);

		}

		else if (arr[i - 1][j + 1] == 1 && (j + 1) <= 19 && (i - 1) >= 0) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i - 1, j + 1);

		}

		else if (arr[i][j - 1] == 1 && (j - 1) >= 0) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i, j - 1);

		}
		else if (arr[i][j + 1] == 1 && (j + 1) <= 19) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i, j + 1);

		}

		else if (arr[i + 1][j - 1] == 1 && (i + 1) <= 9 && (j - 1) >= 0) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i + 1, j - 1);

		}
		else if (arr[i + 1][j] == 1 && (i + 1) <= 9) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i + 1, j);

		}

		else if (arr[i + 1][j + 1] == 1 && (i + 1) <= 9 && (j + 1) <= 19) {


			arr[i][j] = 0;

			rowsum = rowcounter(arr, i + 1, j + 1);

		}




		else
			return i;

	}

	return rowsum + i;



}

int coloumncounter(int arr[][20], int i, int j) {


	if (arr[i][j] == 1) {

		if (arr[i - 1][j - 1] == 1 && (j - 1) >= 0 && (i - 1) >= 0) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i - 1, j - 1);

		}

		else if (arr[i - 1][j] == 1 && (i - 1) >= 0) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i - 1, j);

		}

		else if (arr[i - 1][j + 1] == 1 && (j + 1) <= 19 && (i - 1) >= 0) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i - 1, j + 1);

		}

		else if (arr[i][j - 1] == 1 && (j - 1) >= 0) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i, j - 1);

		}

		else if (arr[i][j + 1] == 1 && (j + 1) <= 19) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i, j + 1);

		}

		else if (arr[i + 1][j - 1] == 1 && (i + 1) <= 9 && (j - 1) >= 0) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i + 1, j - 1);

		}

		else if (arr[i + 1][j] == 1 && (i + 1) <= 9) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i + 1, j);

		}

		else if (arr[i + 1][j + 1] == 1 && (i + 1) <= 9 && (j + 1) <= 19) {


			arr[i][j] = 0;

			coloumnsum = coloumncounter(arr, i + 1, j + 1);

		}



		else
			return j;

	}
	return coloumnsum + j;

}




void main() {
	fstream dataFile;
	char temp[50], buff[500], buff2[500];
	int  xfinder[10][20], xfinder2[10][20], xfinder3[10][20], totalrow = 0,totalcol=0;
	int i, j, k = 0, sayac = 0, sayac2 = 0, sayac3 = 0, sayac4 = 0, sayac5 = 0, sayac6 = 0,sayac7=0, xsayac = 0, rowindises = 0, coloumnindises = 0;
	char filename[30];
	float index1 = 0.0, index2 = 0.0;

	cout << "Enter file name to open:" << endl;
	cin >> filename;



	dataFile.open(filename, std::fstream::in);

	if (dataFile.is_open())
		cout << "Basarili" << endl;

	for (i = 0; !dataFile.eof(); i++) {
		/*dataFile >> buff[i];*/

		dataFile.get(buff[i]);
		sayac++;
	}

	i = 0;
	j = 0;

	while (1) {
			
		if (buff[i] != ' ') {
			sayac6++;
			i++;
		}
		else
			break;
	}

	for (j = sayac6 - 1; j >= 0;j--) {

		temp[0] = buff[j];

		totalrow = totalrow + stoi(temp)* pow(10, k);
		k++;
		
	}
	cout << totalrow << endl;
	i++;
	k = 0;
	while (1) {

		if (buff[i] != ' ' && buff[i]!= 'x') {
			
			i++;
		}
		else
			break;
	}

	for (j = i-2; j > sayac6; j--) {

		temp[0] = buff[j];

		totalcol = totalcol + stoi(temp)* pow(10, k);
		k++;

	}
	cout << totalcol << endl;

	for (i = 0; i < sayac; i++) {

		if (buff[i] == ' ')
			sayac4++;

		if (sayac4 != 1 || buff[i] == 'x') {


			if (buff[i] == ' ' || buff[i] == 'x') {

				buff2[sayac2] = buff[i];
				sayac2++;
			}
		}
	}

	for (i = 0; i < totalrow; i++) {
		for (j = 0; j < totalcol; j++) {

			xfinder[i][j] = 0;
		}
	}

	for (i = 0; i < totalrow; i++) {
		for (j = 0; j < totalcol; j++) {

			if (buff2[sayac3] == 'x') {

				xfinder[i][j] = 1;

			}
			sayac3++;
		}
	}

	cout << endl;
	cout << endl;

	for (i = 0; i < totalrow; i++) {
		for (j = 0; j < totalcol; j++) {

			if (xfinder[i][j] == 1)
				cout << "x";
			else if (xfinder[i][j] == 0)
				cout << " ";
		}
		cout << endl;
	}

	for (i = 0; i < totalrow; i++) {
		for (j = 0; j < totalcol; j++) {

			xfinder2[i][j] = xfinder[i][j];

		}
	}


	for (i = 0; i < totalrow; i++) {
		for (j = 0; j < totalcol; j++) {

			xfinder3[i][j] = xfinder[i][j];

		}
	}


X:
	xsayac = 0;
	for (i = 0; i < totalrow; i++) {
		for (j = 0; j < totalcol; j++) {
			sayac5 = 0;
			if (xfinder[i][j] == 1) {
				rowsum = 0;
				coloumnsum = 0;
				rowindises = rowcounter(xfinder, i, j);
				coloumnindises = coloumncounter(xfinder2, i, j);
				sayac5++;
				if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
					xsayac++;


			}
			if (xfinder3[i][j] == 1) {
				if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
					break;
			}
		}
		if (xfinder3[i][j] == 1) {
			if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
				break;
		}
	}
M:
	if (xfinder3[i - 1][j - 1] == 1 && j > 0 && i > 0) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;

		j = j - 1;
		i = i - 1;

		goto M;
	}

	else if (xfinder3[i - 1][j] == 1 && i > 0) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;

		i = i - 1;

		goto M;
	}

	else if (xfinder3[i - 1][j + 1] == 1 && i > 0 && j < 19) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;

		j = j + 1;
		i = i - 1;
		goto M;
	}
	else if (xfinder3[i][j - 1] == 1 && j > 0) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;

		j = j - 1;
		goto M;
	}
	else if (xfinder3[i][j + 1] == 1 && j < 19) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;

		j = j + 1;
		goto M;
	}

	else if (xfinder3[i + 1][j - 1] == 1 && i < 9 && j>0) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;

		i = i + 1;
		j = j - 1;

		goto M;
	}
	else if (xfinder3[i + 1][j] == 1 && i < 9) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;

		i = i + 1;
		goto M;
	}

	else if (xfinder3[i + 1][j + 1] == 1 && i < 9 && j < 19) {
		xfinder3[i][j] = 0;
		if (xfinder3[i - 1][j - 1] == 1 || xfinder3[i - 1][j + 1] == 1 || xfinder3[i + 1][j - 1] == 1 || xfinder3[i + 1][j + 1] == 1 || xfinder3[i][j + 1] == 1 || xfinder3[i][j - 1] == 1 || xfinder3[i + 1][j] == 1 || xfinder3[i - 1][j] == 1)
			xsayac++;
		i = i + 1;
		j = j + 1;

		goto M;
	}

	else
		xfinder3[i][j] = 0;


	index1 = (float)rowindises / (float)xsayac;
	index2 = (float)coloumnindises / (float)xsayac;

	if (xsayac != 0) {
		cout << xsayac << endl;

		cout << "blob's center of mass" << index1 << "  " << index2 << endl;
	}
	/*for (i = 0; i < totalrow; i++) {
		for (j = 0; j < totalcol; j++) {

			if (xfinder3[i][j] == 1)
				cout << "x";
			else if (xfinder3[i][j] == 0)
				cout << " ";
		}
		cout << endl;
	}*/

	if (sayac5 != 0)
		goto X;



	system("PAUSE");
}

