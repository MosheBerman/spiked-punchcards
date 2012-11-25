//
//  main.cpp
//  2-Shipments
//
//  Created by Moshe Berman on 11/25/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>

//  Implicitly include Item.h, since Warehouse includes it
#include "Warehouse.h"

//  Some utility methods I wrote for file IO.
#include "FileIO/FileIO.h"

using namespace std;

//
//  Method implementations are preceeded by
//  full explanations of each piece of code.
//

bool pricesFromStringToArray(string input, double *);
string cityNameFromCard(string card);
string pricesForWarehouse(string card);

//
//  Declare a constant for the number of variables
//

const int numberOfWarehouses = 5;

//
//  The names of the warehouses
//

string warehouseNames[numberOfWarehouses] = {"New York", "Los Angeles", "Miami", "Houston", "Chicago"};



int main(int argc, const char * argv[])
{

    //
    //  Since we know there are 5 warehouses,
    //  we can declare a static array. No need
    //  for dynamic arrays or vectors or whatever.
    //

    Warehouse warehouses[numberOfWarehouses];
    
    //
    //  Read the warehouse names into the warehouse array.
    //  TODO: It would be awesome if we could do this dynamically,
    //  but there are too many edge cases to handle, so it's
    //  out of the scope the assignment...
    //
    
    for (int i=0; i<numberOfWarehouses; i++) {
        warehouses[i].name = warehouseNames[i];
    }
    
    //
    //  Open an the records file
    //
    
    ifstream recordsFile;
    string fileName = "cards.txt";
    
    //  If opening fails, print out an error.
    
    if(!openInputStream(recordsFile, fileName)){
        cout << "Could not open " << fileName << endl;
    }
    
    //  Otherwise, proceed to parse the file
    
    else{
      
        //
        //  Declare some variables to hold the prices
        //
        
        double prices[3];
        
        //
        //  Read out the line that contains the
        //  prices and parse it into an array.
        //
        
        string pricesString;
    
        getline(recordsFile, pricesString);
        
        pricesFromStringToArray(pricesString, prices);  
        
    }

    //
    //  Read in each line and process it.
    //
    
    while (!recordsFile.eof()) {
        
        string cardString;
        
        getline(recordsFile, cardString);
        
        //
        //  Check for an empty line
        //
        
        if (cardString != "") {
         
            //
            //  Get the type of record & the warehouse name
            //
            
            char recordType = cardString[0];
            string name = cityNameFromCard(cardString);
            
            //
            //  Take appropriate action, depending on
            //  the kind of record...
            //
            
            //  ... handle shipments here...
            
            if (recordType == 's') {
                
            }
            
            //  ... and Orders here.
            
            else if(recordType == 'o'){
             
                double price = 0;
                bool itemWasShippedFromWarehouseToWarehouse[3];
                
                
                
            }
            
        }
    }
    
    
    return 0;
}

//
//  Parses a string which contains dollar amounts
//  into an array of double values.
//
//  For the code to work, we assume that prices are
//  embedded in a single line string, preceeded by
//  a dollar sign, and followed by a space. If the format
//  varies, this code won't work.
//
//  IMPORTANT: We don't resize the buffer. So you have
//  to know how many strings you're planning to extract
//  ahead of time.
//

bool pricesFromStringToArray(string input, double *buffer){
    
    size_t position = 0;
    
    int indexForBuffer = 0;
    
    while (position < input.length()-1) {
        
        size_t positionOfDollarSign = input.find("$", position);
        
        //
        //  If there are no dollar signs, just
        //  set the position to out of range
        //  of the while loop and it will exit.
        //
        
        if (positionOfDollarSign == string::npos) {
            position = input.length();
            break;
        }
        
        size_t positionOfTrailingSpace = input.find(" ", positionOfDollarSign-1);
        
        //
        //  We found the last dollar sign,
        //  so take the substring from the
        //  dollar sign until the end.
        //
        
        if(positionOfTrailingSpace == string::npos){
            
            //
            //  Get the index of the last character
            //
            
            positionOfTrailingSpace = input.length()-1;
        }
        
        
        //
        //  By this point, we have to indices to use
        //  to grab a substring from the input.
        //
        
        string priceValueAsString;
        
        priceValueAsString = input.substr(positionOfDollarSign+1, positionOfTrailingSpace-positionOfDollarSign);
        
        //
        //  Convert the string into a double via a stream.
        //
        //  If for some reason the conversion fails, then
        //  return false
        //
        
        istringstream stringToDoubleConverter(priceValueAsString);
        
        if(!(stringToDoubleConverter >> buffer[indexForBuffer])){
            return false;
        }
        
        //
        //  Move the "header" of the loop to
        //  the next part of the string.
        //
        
        position = positionOfTrailingSpace;
        
        //
        //  Don't forget to update the buffer index
        //
        
        indexForBuffer++;
    }
    
    return true;
}

//
//  This method searches for
//  known city names and returns
//  the one that occurs in the
//  shipment card.
//
//  Known city names are defined in the
//  global array "warehouseNames".
//
//  Note that this is necessary because
//  city names have spaces.
//

string cityNameFromCard(string card){
    for (int i = 0; i < numberOfWarehouses; i++) {
        
        if (card.find(warehouseNames[i]) != string::npos) {
            return warehouseNames[i];
        }
    }
    
    return NULL;
}

//
//  This method returns the contents
//  of a card which follow its city name.
//
//  Based on our format, this is the prices.
//

string pricesForWarehouse(string card){
    
    string warehouseName = cityNameFromCard(card);
    
    size_t locationOfString = card.find(warehouseName);
    
    return card.substr(locationOfString+warehouseName.length());
}

//
//  Takes a string with prices, an array, an
//

bool loadQuantitiesFromString(string pricesString, double quantities[], const int numberOfQuantities){
    
    
    istringstream conversionStream(pricesString);
    
    for (int i = 0; i < numberOfQuantities; i++) {
        if(!(conversionStream >> quantities[i])){
            return false;
        }
    }

    return true;
}

