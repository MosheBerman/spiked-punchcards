//
//  FileIO.h
//  2-Shipments
//
//  Created by Moshe Berman on 11/25/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef ____Shipments__FileIO__
#define ____Shipments__FileIO__

#include <iostream>

using namespace std;

//
//  Function prototypes
//

bool openInputStream(ifstream &, string);
bool openOutputStream(ofstream &, string);
void closeInputStream(ifstream &stream);
void closeOutputStream(ofstream &);

#endif /* defined(____Shipments__FileIO__) */
