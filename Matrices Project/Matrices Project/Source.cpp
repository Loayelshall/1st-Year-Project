	#include<iostream>
	#include<string>
	#include<cstdlib>
	#include<sstream>
	#include<complex>

	using namespace std;


	float **matrixReading(string x, int &rowCount, int &colCount, int &elementCount);
	void matrixComplexReading(string x,complex<float> result[100][100], int& rowCount, int& colCount, int& elementCount);
	string matrixToString(float** inputResult, int &rowCount, int &colCount);
	string complexMatrixToString(complex<float> inputResult[100][100], int& rowCount, int& colCount);
	float **matrixSum(float** st, float** nd,int &rowCount,int &colCount);
	float **matrixSubt(float** st, float** nd, int &rowCount, int &colCount);
	float **matrixMult(float**  st, float** nd, int &rowCount, int &colCount, int &mRowCount);
	void matrixComplexSum(complex<float> st[100][100], complex<float> nd[100][100],complex<float> result[100][100], int& rowCount, int& colCount);
	void matrixComplexSubt(complex<float> st[100][100], complex<float> nd[100][100],complex<float> result[100][100], int& rowCount, int& colCount);
	void matrixComplexMult(complex<float> st[100][100], complex<float> nd[100][100], complex<float> result[100][100] , int& rowCount, int& colCount, int& mRowCount);
	float **matrixTranspose(float** input, int &rowCount, int &colCount);
	float **matrixPower(float** input, int &rowCount, int &colCount, int power);
	float matrixDet(float** input, int rowCount, int colCount);
	float **detMatSwap(float** input, int rowCount, int colCount, int swapStart, int swapEnd);
	float **detMatMult(float** input, int rowCount, int colCount, float multiValue, int rowMult);
	float **detMatRowAddToRow(float** input, int rowCount, int colCount, int rowRef, int rowToBeMult, float multValue);
	float **matrixInverse(float** input, int& rowCount, int& colCount);
	float **matrixDivision(float** input1, float** input2, int& strowCount, int& stcolCount, int& ndRowCount, int& ndColCount);
	string popBack(string x);


	int main() {
		//takes input from the user and stores it in a string
		string mainInput;
		string result;
		char enteredOperator;
		int power;
		int isComplex = 0;
		int stRow = 0, stCol = 0, ndRow = 0, ndCol = 0, numbersCount=0;

		float** matrix1 = { 0 };
		float** matrix2 = { 0 };

		complex<float> matrixComplex1[100][100] = { 0 };
		complex<float> matrixComplex2[100][100] = { 0 };
		complex<float> matrixResult[100][100] = { 0 };

		//Getting the first matrix
		//cout << "Please enter the First Matrix:";
		getline(cin, mainInput);

		for (int i = 0; i < mainInput.length(); i++) {
			if (mainInput[i] == 'i') {
				isComplex = 1;
			}
		}
		if (isComplex == 1) {
			matrixComplexReading(mainInput, matrixComplex1 ,stRow, stCol, numbersCount);
		}
		else {
			matrix1 = matrixReading(mainInput, stRow, stCol, numbersCount);
		}
		mainInput.clear();

		//Getting the operator
		//cout << "Please enter an operator " ;
		cin >> enteredOperator;
		/*
		if (enteredOperator != '+' || enteredOperator != '-')
			cout << "ERROR Wrong operator";
			*/
			//Getting the second matrix
			//cout << "Please enter the Second Matrix:";

		cin.ignore();
	

		//ignoring second input in case one parameter only is needed
		if (enteredOperator == '^') {
			cin >> power;
		}else if (enteredOperator != 'T' && enteredOperator != 'D' && enteredOperator != 'I') {
			getline(cin, mainInput);
			if (isComplex == 1) {
				 matrixComplexReading(mainInput,matrixComplex2, ndRow, ndCol, numbersCount);
			}
			else {
				matrix2 = matrixReading(mainInput, ndRow, ndCol, numbersCount);
			}
			mainInput.clear();
		}


		//Performing Operations
		switch (enteredOperator)
		{
		case'+':
			if (stRow != ndRow || stCol != ndCol)
				cout << "ERROR";
			else {
				if (isComplex == 1) {
					 matrixComplexSum(matrixComplex1, matrixComplex2,matrixResult, stRow, stCol);
					result = complexMatrixToString(matrixResult, stRow, stCol);
					cout << result << endl;
				}
				else {
					float** resultMatrixSum = matrixSum(matrix1, matrix2, stRow, stCol);
					result = matrixToString(resultMatrixSum, stRow, stCol);
					cout << result << endl;
				}
			}

			system("pause");
		

			break;

		case'-':
			if (stRow != ndRow || stCol != ndCol)
				cout << "ERROR";
			else {
				if (isComplex == 1) {
					 matrixComplexSubt(matrixComplex1, matrixComplex2,matrixResult, stRow, stCol);
					result = complexMatrixToString(matrixResult, stRow, stCol);
					cout << result << endl;
				}
				else {
					float** resultMatrixSub = matrixSubt(matrix1, matrix2, stRow, stCol);
					result = matrixToString(resultMatrixSub, stRow, stCol);
					cout << result << endl;
				}
			}

			system("pause");

			break;

		case'*':
			if (stCol != ndRow)
				cout << "ERROR";
			else {
				if (isComplex == 1) {
					 matrixComplexMult(matrixComplex1, matrixComplex2,matrixResult, stRow, ndCol, stCol);
					result = complexMatrixToString(matrixResult, stRow, ndCol);
					cout << result << endl;
				}
				else {
					float** resultMatrixMult = matrixMult(matrix1, matrix2, stRow, ndCol, stCol);
					result = matrixToString(resultMatrixMult, stRow, ndCol);
					cout << result << endl;
				}
			}
			system("pause");
			break;

		case'T': {
			if (numbersCount == (stRow * stCol)) {
				float** resultMatrixTran = matrixTranspose(matrix1, stRow, stCol);
				result = matrixToString(resultMatrixTran, stCol, stRow);
				cout << result << endl;
			}
			else {
				cout << "ERROR";
			}

		
		
			break;
		}
			
		case'^': {
			if (stRow == stCol) {
				float **resultMatrixPower = matrixPower(matrix1, stRow, stCol, power);
				result = matrixToString(resultMatrixPower, stRow, stCol);
				cout << result << endl;
			} else {
				cout << "ERROR";
			}
		
			break;

		}

	

		case'D': {
			if (stRow == stCol) {
				float result = matrixDet(matrix1, stRow, stRow);
				cout << result;
			} else {
				cout << "ERROR";
			}
		
		
			break;
		}

		

		case'I': {
			if (stRow == stCol) {
				float** resultMatrixInverse = matrixInverse(matrix1, stRow, stCol);
				result = matrixToString(resultMatrixInverse, stRow, stCol);
				cout << result << endl;
			}
			else {
				cout << "ERROR";
			}

		
			break;
		}


		case'/': {

			if (stCol != ndRow || ndRow != ndCol) {
				cout << "ERROR";
			}
			else {
				float** resultMatrixDivide = matrixDivision(matrix1, matrix2, stRow, stCol,ndRow,ndCol);
				result = matrixToString(resultMatrixDivide, stRow, stCol);
				cout << result << endl;
			}

			system("pause");
			break;
		}


		default:
			cout << "Wrong Operator";
			break;
		}





	}

	//Matrix reading function 
	float  **matrixReading(string x, int &rowCount,int &colCount,int &elementCount) {
		int strLength = x.length();
	
		float **matrix;
	
	
		int flag = 0;
		colCount = 0;
		rowCount = 0;
		int elementsCount = 0;


			//Counting no of rows and columns
			for (int i = 0; i < strLength; i++) {

				if (x[i] != '[' || x[i] != ']') {

					if ((x[i] == ' ' || x[i] == '[') && flag == 0) {
						colCount++;
						//elementsCount++;
					}
					if (x[i] == ';' || x[i] == ']') {
						rowCount++;
						//elementsCount++;
						flag = 1;
					}
					//elementsCount++;
				}
			}


			//Checking for a right No of rows and columns 
			if (elementsCount != (rowCount * colCount)) {
				//cout << "ERROR";
			}
			/*
			//initializing 2D Array
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					matrix[i][j] = 0;
				}
			}
		*/

		//initializing a 2D Array
			matrix = new float* [100];
			for (int h = 0; h < 100; h++) {
				matrix[h] = new float[100];

				for (int w = 0; w < 100; w++) {
					matrix[h][w] = 0;
				}
			}


			//filling in matrix values
			int currentRow = 0;
			int currentCol = 0;
			string tempNo;
			for (int k = 0; k < strLength; k++) {
				if (x[k] != '[') {
					if (x[k] == ' ' || x[k] == ';' || x[k] == ']') {

						matrix[currentRow][currentCol] = atof(tempNo.c_str());
						elementsCount++;
						currentCol++;
						tempNo.clear();

					}
					else {
						tempNo += x[k];

					}
					if (x[k] == ';') {

						matrix[currentRow][currentCol] = atof(tempNo.c_str());

						tempNo.clear();

					}
					if (x[k] == ']') {

						matrix[currentRow][currentCol] = atof(tempNo.c_str());


						tempNo.clear();
					}

					if (x[k] == ';') {

						currentRow++;
						currentCol = 0;
					}
					if (x[k] == ']') {
						currentRow++;
						currentCol = 0;

					}

				}

			}
			elementCount = elementsCount;

			return matrix;
	
	}


	//Matrix to String Function
	string matrixToString(float** inputResult, int &rowCount, int &colCount) {
		string outputResult = "[";
		for (int l = 0; l < rowCount; l++) {
			for (int m = 0; m < colCount; m++) {
				string currentChar;

				ostringstream ss;
				float currentNumber = inputResult[l][m];
				ss << currentNumber;
				currentChar = ss.str();

				outputResult += currentChar;
				outputResult += ' ';
			}
			if (l != rowCount - 1) {
				outputResult = popBack(outputResult);
				outputResult += ';';
			}
			else {
				outputResult = popBack(outputResult);
				outputResult += ']';
			}
		
		}
	

		return outputResult;

	}


	//Matrix Summation 
	float **matrixSum(float** st, float** nd, int &rowCount ,int &colCount) {

		//initializing a 2D Array
		float **result;
		result = new float*[rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}
	
		//Summation for loop
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				result[i][j] = st[i][j] + nd[i][j];
			}
		}

		return result;


	}

	//matrix subtraction 
	float **matrixSubt(float** st, float** nd, int &rowCount, int &colCount) {
		//initializing a 2D Array
		float **result;
		result = new float*[rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}

		//Subtraction for loop
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				result[i][j] = st[i][j] - nd[i][j];
			}
		}

	
		return result;
	}


	//matrix Multiplication
	float **matrixMult(float** st, float** nd, int &rowCount, int &colCount ,int &mRowCount) {
		//initializing a 2D Array
		float **result;
		result = new float*[rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}

		//Multiplication For loop
		for (int a = 0; a < rowCount; a++) {
			for (int b = 0; b < colCount; b++) {
				float resultFloat = 0;
				for (int c = 0; c <= mRowCount;c++) {
					float test = st[a][c];
					float test2 = nd[c][b];
					resultFloat += (st[a][c] * nd[c][b]);
				}
				result[a][b] = resultFloat;
			}

		}

		return result;
	}
	string popBack(string x) {
		int l = x.length();
		string output = x.substr(0, l-1);
		return output;
	}


	//Matrix Transpose Function
	float **matrixTranspose(float** input, int &rowCount, int &colCount) {
		int tempRow = colCount;
		int tempCol = rowCount;

		//initializing a 2D Array
		float **result;
		result = new float*[tempRow];
		for (int h = 0; h < tempRow; h++) {
			result[h] = new float[tempCol];

			for (int w = 0; w < tempCol; w++) {
				result[h][w] = 0;
			}
		}


		for (int i = 0; i < tempRow; i++) {
			for (int j = 0; j < tempCol; j++) {
				result[i][j] = input[j][i];
			}
		}

		return result;

	}

	//Matrix Power Funciton 

	float **matrixPower(float** input, int &rowCount, int &colCount, int power) {
		//initializing a 2D Array
		float **result;
		result = new float*[rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}


		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				result[i][j] = input[i][j];
			}
		}

		for (int c = 1; c < power; c++) {
			result = matrixMult(result, input, rowCount, colCount, colCount);
		}


		return result;

	}


	int negativeFlag = 1;
	int multFlag = 1;


	// Matrix Determinant Function 
	float matrixDet(float** input, int rowCount, int colCount) {
		float result = input[0][0];
		int zeroFlag = 1;
		float pivot = input[0][0];
		float pivot2 = input[1][0];
	
		do {

			for (int n = 0; n < rowCount; n++) {
			
				for (int j = n + 1; j < colCount; j++) {
					pivot = input[n][n];
					pivot2 = input[n + 1][n];
					float temp1 = input[2][0];
					float temp2 = input[3][0];
				
					while (pivot == 0) {
						input = detMatSwap(input, rowCount, colCount, n, n + 1);
					}
					input = detMatRowAddToRow(input, rowCount, colCount, n, j, (input[j][n]/pivot));

				}
			}




			//Checking for zeros under diagonal and changes flag to 0 if a non-zero is found
			for (int i = 1; i < rowCount; i++) {
				for (int j = 0; j < i; j++) {
					if (input[i][j] != 0) {
						zeroFlag = 0;
					}
					else {
						zeroFlag = 1;
					}
				}
			}
		} while (zeroFlag == 0);

		//Computing determinant value in case of zero under diagonal
		for (int i = 1; i < rowCount; i++) {
			if (zeroFlag == 1) {
				result *= input[i][i];
				result *= negativeFlag;
				result *= multFlag;
			}
		}

		return result;
	}


	// Determinant sub-Function

	//    Row swapping
	float** detMatSwap(float** input, int rowCount, int colCount, int swapStart, int swapEnd) {
		//initializing a 2D Array
		float** result;
		result = new float* [rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}


		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				if (i == swapStart) {
					result[swapEnd][j] = input[swapStart][j];
				} else if (i == swapEnd) {
					result[swapStart][j] = input[swapEnd][j];
				} else {
					result[i][j] = input[i][j];
				}
			}
		}

		negativeFlag *= -1;
		return result;
	}


	//     Row multipy by a value
	float** detMatMult(float** input, int rowCount, int colCount, float multiValue, int rowToBeMult){
		//initializing a 2D Array
		float** result;
		result = new float* [rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}

		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				if (i == rowToBeMult) {
					result[i][j] = multiValue * (input[i][j]);
				}
				else {
					result[i][j] = input[i][j];
				}
			}
		}
		return result;
	}

	//    Add a scalar multiple of a row to another row
	float** detMatRowAddToRow(float** input, int rowCount, int colCount, int rowRef, int rowToBeMult, float multValue) {
		//initializing a 2D Array
		float** result;
		result = new float* [rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}

		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				if (i == rowToBeMult) {
					result[i][j] = input[i][j];
					result[i][j] -= multValue * (input[rowRef][j]);
					float test1 = result[i][j];
					float test2 = input[rowRef][j];
				}
				else {
					result[i][j] = input[i][j];
					float test3 = input[i][j];
				}
			}
		}

		return result;
	}

	float** matrixInverse(float** input, int& rowCount, int& colCount) {
		//initializing a 2D Array
		float** result;
		result = new float* [rowCount];
		for (int h = 0; h < rowCount; h++) {
			result[h] = new float[colCount];

			for (int w = 0; w < colCount; w++) {
				result[h][w] = 0;
			}
		}
		//Creating an identity matrix called result
		for (int n = 0; n < rowCount; n++) {
			result[n][n] = 1;
		}


		//Creating a lower Triangle matrix
		int zeroFlag = 1;
		float pivot = input[0][0];
		float pivot2 = input[1][0];

		do {

			for (int n = 0; n < rowCount; n++) {

				for (int j = n + 1; j < colCount; j++) {
					pivot = input[n][n];
					pivot2 = input[n + 1][n];
				
					while (pivot == 0) {
						input = detMatSwap(input, rowCount, colCount, n, n + 1);
						result = detMatSwap(result, rowCount, colCount, n, n + 1);
					}
					result = detMatRowAddToRow(result, rowCount, colCount, n, j, (input[j][n] / pivot));
					input = detMatRowAddToRow(input, rowCount, colCount, n, j, (input[j][n] / pivot));
				

				}
			}




			//Checking for zeros under diagonal and changes flag to 0 if a non-zero is found
			for (int i = 1; i < rowCount; i++) {
				for (int j = 0; j < i; j++) {
					if (input[i][j] != 0) {
						zeroFlag = 0;
					}
					else {
						zeroFlag = 1;
					}
				}
			}
		} while (zeroFlag == 0);


		//inverted triangle matrix operations
	
		int zeroFlagI = 1;
		float pivotI = input[rowCount - 1][colCount - 1];
		float pivotI1 = input[rowCount - 2][colCount - 1];

		do {
			for (int n = rowCount-1; n >= 0; n--) {

				for (int j = n - 1; j >= 0; j--) {
					pivotI = input[n][n];
					pivotI1 = input[n - 1][n];


					while (pivotI == 0) {
						input = detMatSwap(input, rowCount, colCount, n, n - 1);
						result = detMatSwap(result, rowCount, colCount, n, n - 1);
					}
					result = detMatRowAddToRow(result, rowCount, colCount, n, j, (input[j][n] / pivotI));
					input = detMatRowAddToRow(input, rowCount, colCount, n, j, (input[j][n] / pivotI));
				

				}
			}

			// Checking for zeros under diagonal and changes flag to 0 if a non - zero is found
				for (int i = rowCount -1; i >= 0; i--) {
					for (int j = colCount -1 ; j >= i; j--) {
						if (input[i][j] != 0) {
							zeroFlag = 0;
						}
						else {
							zeroFlag = 1;
						}
					}
				}


		} while (zeroFlagI == 0);

		for (int i = 0; i < rowCount; i++) {
			result = detMatMult(result, rowCount, colCount, (1 / input[i][i]), i);
		}

	


		return result;
	}


	// Matrix Division Function
	float** matrixDivision(float** input1, float** input2, int& strowCount, int& stcolCount, int& ndRowCount, int& ndColCount) {

		//initializing a 2D Array
		float** result;
		result = new float* [strowCount];
		for (int h = 0; h < strowCount; h++) {
			result[h] = new float[ndColCount];

			for (int w = 0; w < ndColCount; w++) {
				result[h][w] = 0;
			}
		}

	
		input2 = matrixInverse(input2, ndRowCount, ndColCount);

		//Multiplication For loop
		for (int a = 0; a < strowCount; a++) {
			for (int b = 0; b < ndColCount; b++) {
				float resultFloat = 0;
				for (int c = 0; c < ndRowCount; c++) {
					resultFloat += (input1[a][c] * input2[c][b]);
				}
				result[a][b] = resultFloat;
			}

		}
	
		return result;

	}


	// Matrix Complex Reading Function
	void matrixComplexReading(string x, complex<float> complexMatrix[100][100], int& rowCount, int& colCount, int& elementCount) {
		int strLength = x.length();



		int flag = 0;
		colCount = 0;
		rowCount = 0;
		int elementsCount = 0;


		//Counting no of rows and columns
		for (int i = 0; i < strLength; i++) {

			if (x[i] != '[' || x[i] != ']') {

				if ((x[i] == ' ' || x[i] == '[') && flag == 0) {
					colCount++;
					//elementsCount++;
				}
				if (x[i] == ';' || x[i] == ']') {
					rowCount++;
					//elementsCount++;
					flag = 1;
				}
				//elementsCount++;
			}
		}

		


		//filling in matrix values
		int currentRow = 0;
		int currentCol = 0;
		string tempNo;
		string tempNo2;
		string tempNo3;
		int isReal = 1;
		int isNeg = 0;
		for (int k = 0; k < strLength; k++) {
			if (x[k] != '[') {
				if (x[k] == ' ' || x[k] == ';' || x[k] == ']') {
					for (int i = 0; i < tempNo.length(); i++) {

						if ((tempNo[i] == '+' || tempNo[i] == '-') && i != 0) {
							isReal = 0;
						}

						if (tempNo[i] != '+'  && isReal == 1) {
							isNeg = 0;
							if (tempNo[i] == '-' && i == 0) {
								tempNo2 += tempNo[i];
								isNeg = 1;
							}
							if(isNeg==0){

								tempNo2 += tempNo[i];
							}
						}
						
						 
						 if(tempNo[i] != 'i' && isReal == 0){
							tempNo3 += tempNo[i];
							if (tempNo3 == "+")
								tempNo3.clear();
						}
					}
					
					complexMatrix[currentRow][currentCol] = complex<float>(atof(tempNo2.c_str()), atof(tempNo3.c_str()));
					float x = complexMatrix[currentRow][currentCol].imag();
					elementsCount++;
					currentCol++;
					tempNo.clear();
					tempNo2.clear();
					tempNo3.clear();
					isReal = 1;

				}
				else {
					tempNo += x[k];

				}
				if (x[k] == ';') {

					for (int i = 0; i < tempNo.length(); i++) {
						if (tempNo[i] != '+' && isReal == 1) {
							tempNo2 += tempNo[i];
						}
						else if (tempNo[i] == '+') {
							isReal = 0;
						}
						else if (tempNo[i] != 'i' && isReal == 0) {
							tempNo3 += tempNo[i];
						}
					}
					complexMatrix[currentRow][currentCol] = complex<float>(atof(tempNo2.c_str()), atof(tempNo3.c_str()));

					tempNo.clear();
					tempNo2.clear();
					tempNo3.clear();
					isReal = 1;

				}
				if (x[k] == ']') {

					for (int i = 0; i < tempNo.length(); i++) {
						if (tempNo[i] != '+' && isReal == 1) {
							tempNo2 += tempNo[i];
						}
						else if (tempNo[i] == '+') {
							isReal = 0;
						}
						else if (tempNo[i] != 'i' && isReal == 0) {
							tempNo3 += tempNo[i];
							if (tempNo3 == "+") {
								tempNo3.clear();
							}
						}
					}
					complexMatrix[currentRow][currentCol] = complex<float>(atof(tempNo2.c_str()), atof(tempNo3.c_str()));


					tempNo.clear();
					tempNo2.clear();
					tempNo3.clear();
					isReal = 1;
				}

				if (x[k] == ';') {

					currentRow++;
					currentCol = 0;
				}
				if (x[k] == ']') {
					currentRow++;
					currentCol = 0;

				}

			}

		}
		elementCount = elementsCount;

		

	}

	// Complex Matrix to String Function
	string complexMatrixToString(complex<float> inputResult[100][100], int& rowCount, int& colCount) {
		string outputResult = "[";
		for (int l = 0; l < rowCount; l++) {
			for (int m = 0; m < colCount; m++) {
				string currentCharReal;
				string currentCharImag;
				int isNeg = 0;

				complex<float> temp = inputResult[l][m];
				float real = temp.real();
				float imag = temp.imag();
				ostringstream ss;
				ostringstream ss2;

				if (imag < 0) {
					isNeg = 1;
				}

				float currentNumberReal = real;
				ss << currentNumberReal;
				currentCharReal = ss.str();

				float currentNumberImag = imag;
				ss2 << currentNumberImag;
				currentCharImag = ss2.str();
				if (isNeg == 0) {
					outputResult += (currentCharReal + '+' + currentCharImag + 'i');
					outputResult += ' ';
				}
				else {
					outputResult += (currentCharReal + currentCharImag + 'i');
					outputResult += ' ';

				}

			}
			if (l != rowCount - 1) {
				outputResult = popBack(outputResult);
				outputResult += ';';
			}
			else {
				outputResult = popBack(outputResult);
				outputResult += ']';
			}

		}


		return outputResult;
	}


	// Matrix Complex Summation Function
	void matrixComplexSum(complex<float> st[100][100], complex<float> nd[100][100], complex<float> result[100][100], int& rowCount, int& colCount) {
	
	
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
		
				result[i][j] = st[i][j] + nd[i][j];
			}
		}
		
	}

	// Matrix Complex Subtraction Function
	void matrixComplexSubt(complex<float> st[100][100], complex<float> nd[100][100], complex<float> result[100][100], int& rowCount, int& colCount) {
	

		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				result[i][j] = st[i][j] - nd[i][j];
			}
		}

	

	}
	// Matrix Complex Multiplication Function
	void matrixComplexMult(complex<float> st[100][100], complex<float> nd[100][100], complex<float> result[100][100], int& rowCount, int& colCount, int& mRowCount) {

	

		//Multiplication For loop
		for (int a = 0; a < rowCount; a++) {
			for (int b = 0; b < colCount; b++) {
				complex<float> resultFloat = 0;
				for (int c = 0; c < mRowCount; c++) {
					complex<float> test = st[a][c];
					complex<float> test2 = nd[c][b];
					resultFloat += (st[a][c] * nd[c][b]);
				}
				result[a][b] = resultFloat;
			}

		}


	
	}
