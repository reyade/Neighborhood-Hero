#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
//* This program will function to utilize NYC open source data to analyze the average NYC response rate from the FDNY regarding calls they recieve, structured through classifying variables such as the date,time, location of incident and firehouse, type of incident,along with the rates at which they've been responded to. 


// struct defines a new custom data type
// data record represents each field or column for a record
struct dataRecord{
 string year;
 string month;
 string classification;
 string borough;
 string count;
 string response_time;
};


// function prototype
bool readCSVtoArray(string, dataRecord[], int);
void printRecord(dataRecord);
void print_n(dataRecord[], int);

// main function
int main(){

  // name of file for FDNY data 
  string filename = "FDNY_Monthly_Response_Times.csv";
  const int size = 4032;

  // create array of data records
  dataRecord myRecords[size];

  // call function to read in csv data 
  if (readCSVtoArray(filename, myRecords, size)){
    cout << "Data read in successfully\n";
  }
  else{
    cout << "Couldn't read in data\n";
  }

  // print first few records 
  print_n(myRecords, 10);

	return 0;
}


//function definitions



//read in csv records to array of data structs
bool readCSVtoArray(string fn, dataRecord records[], int size){
  bool success = false;

  ifstream infile(fn, ios::in); // open file 
  string line; // string to hold each line of data 
  if (infile){ // if file opened successfully
    cout << "\nFile opened\n";
    getline(infile, line); // read in header row
    // use for loop to go through remaining rows 
    for (int i = 0; i < size; i++){
      // read a row of data from file into string 
      getline(infile, line);
      // put row of data into istringstream
      istringstream rowData{line};
      // read fields into related string of datarecord struct

      /***********************************************
      SEPARATE YEAR/MONTH INTO SEPARATE YEAR AND MONTH FIELDS ****************************************/
      getline(rowData, records [i].year, '/');
      getline(rowData, records[i].month, ',');
      getline(rowData, records[i].classification, ',');
      getline(rowData, records[i].borough, ',');
      getline(rowData, records[i].count, ',');
      getline(rowData, records[i].response_time);
      
    }
    success = true; // true means we were able to read file 
  }

  return success;
}

void printRecord(dataRecord record){
  cout << "\n\nYear: " << record.year
  << "\nMonth: " << record.month
  << "\nClassification: " << record.classification
  << "\nBorough: " << record.borough
  << "\nCount: " << record.count
  << "\nAverage Response Time: " << record.response_time;
}

void print_n(dataRecord records[], int n){
  for (int i = 0; i < n; i++){
    printRecord(records[i]);
  }
}