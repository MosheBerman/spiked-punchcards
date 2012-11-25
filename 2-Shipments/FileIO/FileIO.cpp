//
//  FileIO.cpp
//  Some utility methods for file IO, by Moshe Berman.
//
//  Created by Moshe Berman on 11/25/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include <iostream>

#include <fstream>

#include "FileIO.h"

//
//  Opens an input stream
//

bool openInputStream(ifstream &stream, string fileName){
    
    stream.open(fileName.c_str());
    
    if (!stream.good()) {
        return false;
    }
    
    return true;
}


//
//  Opens an output stream
//

bool openOutputStream(ofstream &stream, string fileName){
    
    stream.open(fileName.c_str());
    
    if (!stream.good()) {
        return false;
    }
    
    return true;
}

//
//  Close the input stream
//

void closeInputStream(ifstream &stream){
    stream.close();
}

//
//  Close the output stream
//

void closeOutputStream(ofstream &stream){
    stream.close();
}
