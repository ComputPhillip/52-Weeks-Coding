//Author: Phillip Gooden
//Submitted: 01-21-2023
//This program reads data from a file, calculates the data and stores it into an array, and finally displays the data

#include <iostream>
#include <fstream>

using namespace std;
//input data
void Read(int data[3][7]);
//process data
void Calculate(int data[3][7], int sum[3], int avg[3]);
//output data
void Display(int data[3][7], int (&sum)[3], int (&avg)[3]);

int main(){

    int data[3][7];
    int sum[3] = {0};
    int avg[3] = {0};
    //Input-Process-Output
    Read(data);
    Calculate(data, sum, avg);
    Display(data, sum, avg);
}

//Input data
void Read(int data[3][7]){
    fstream inFile;
    inFile.open("numbers.txt", ios::in);
    if(inFile.is_open()){
        cout << "file data:" << endl;
    }else
        cout << "Error, file is closed\n";
    for (int i {0}; i < 3; i++){
        for (int j {0}; j < 7; j++){
            inFile >> data[i][j];
            }
    }           
    inFile.close();
}
//Process data
void Calculate(int data[3][7], int sum[3], int avg[3]){
    for (int i {0}; i < 3; i++){
        for (int j {0}; j < 7; j++){
            sum[i] += data[i][j];
        }
            avg[i] = sum[i] / 7;
    }
}
//output data
void Display(int data[3][7], int (&sum)[3], int (&avg)[3]){
    for (int i {0}; i < 3; i++){
        for(int j{0}; j < 7; j++){
            cout << data[i][j] << ' ';
        }
        cout << "sum: " << sum[i] << " avg: " << avg[i] << '\n';
    }
}