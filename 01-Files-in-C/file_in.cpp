// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code! 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.

All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
//Added by Jon
#include <map>
#include <iterator>
using namespace std; 

int main() {

  // define variables
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ifstream in_stream;
  in_stream.open("./01-Files-in-C/data.csv"); //opening the file.

  if (!in_stream.fail()) { //if the file is open

    string line;

    getline(in_stream, line);
    //Changed while condition
    while (!in_stream.eof()) { //while the end of file is NOT reached

     // Fields: sku,brand,category,year,price

     getline(in_stream, sku, ',');
     stringstream ssku(sku); 
     int iSKU = 0;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(in_stream, brand, ',');
     vBrand.push_back(brand);

     getline(in_stream, category, ',');
     vCategory.push_back(category);

     getline(in_stream, year, ','); 
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(in_stream, price); 
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;

   } else {
    cout << "Unable to open file"; 
   }
 
  //Output File
  ofstream outFile("lab1.txt");
 
  //Finding the average price of each SKU and writing it to file.
  double avgPrice = 0;  

  for(int i = 0; i < vSKU.size(); i++) {
    avgPrice += vPrice[i];
  }

  outFile <<  "Average Price: " << avgPrice / vSKU.size() << endl;

  //2-D Vector where Year X SKU 
  map<int, vector<int>> mapz;

  //For every Year insert into map the where vSKU and vYear indexes are the same.
  for(int i = 0; i < vYear.size() - 1; i++) {
      vector<int> yearSKU;
      for (int j = 0; j < vSKU.size() - 1; j++) {
          if (vYear[i] == vYear[j]) {
              yearSKU.push_back(vSKU[j]);
          }
               
      }
    mapz.insert(pair<int, vector<int>>(vYear[i], yearSKU));
             
  }

  //Print out every pair within map
  for (const auto& pair : mapz) {
      outFile << pair.first << " (" << pair.second.size() << ") ";
      for (int d : pair.second) outFile << d << " " ;
      outFile << endl;
  }

  //Closing output file
  outFile.close();

}
