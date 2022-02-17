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

  //output values 
  outFile << "SKU" << "\t" << "Brand" << "\t" << "Cate." << "\t" << "Year" << "\t" << "Price"<< endl; 

  for (int j = 0; j < vSKU.size() - 1; j++) {
    outFile << vSKU[j] << "\t" << vBrand[j] << "\t" << vCategory[j] << "\t" << vYear[j] << "\t" << vPrice[j] << endl;
  }

  outFile << endl;
 
 

  //Set Decimal Precision to 2 Places
  outFile.precision(2);

  //Putting each brand with each price into a map
  map<string, vector<float> > brandPrice; 
  for (int i = 0; i < vBrand.size() - 1; i++) {
      brandPrice[vBrand[i]].push_back(vPrice[i]); 
  }

  map<string, vector<float> >::iterator brandItr;

  //Iterating through the map and calculating the average and writing to the file
  outFile << "Average Price of Each Brand" << endl;
  for (brandItr = brandPrice.begin(); brandItr != brandPrice.end(); ++brandItr) {
      float totalPrice = 0;
      for(int i = 0; i < brandItr->second.size(); i++) {
          totalPrice+=brandItr->second[i];
      }

      outFile << brandItr->first << " : " << totalPrice / brandItr->second.size() << endl; 
  }
    
  //Putting each category with each price into a map
  map<string, vector<float> > catePrice; 
  for (int i = 0; i < vCategory.size() - 1; i++) {
      catePrice[vCategory[i]].push_back(vPrice[i]); 
  }

  //catePrice iterator
  map<string, vector<float> >::iterator cateItr;

  //Iterating through the map and calculating the average and writing to the file
  outFile << "Average Price of Each Category" << endl;
  for (cateItr = catePrice.begin(); cateItr != catePrice.end(); ++cateItr) {
      float totalPrice = 0;
      for(int i = 0; i < cateItr->second.size(); i++) {
          totalPrice+=cateItr->second[i];
      }

      outFile << cateItr->first << " : " << totalPrice / cateItr->second.size() << endl; 
  }

  
  //Create Map for year to sku
  map<int, vector<int> > yearSKU; 
  for (int i = 0; i < vYear.size() - 1; i++) {
      yearSKU[vYear[i]].push_back(vSKU[i]); 
  }

  //yearSKU iterator
  map<int, vector<int> >::iterator skuItr;

  //Iterating through the map to output the SKUs by year
  outFile << "SKUs by Year" << endl;
  for (skuItr = yearSKU.begin(); skuItr != yearSKU.end(); ++skuItr) {
  outFile << skuItr->first << "(" << skuItr->second.size() << ") : ";
      for(int i = 0; i < skuItr->second.size(); i++) {
          
        outFile << skuItr->second[i] << " ";
          

      }

      outFile << endl;

  }
  //Closing output file
  outFile.close();

}
