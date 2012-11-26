//
//  Warehouse.h
//  2-Shipments
//
//  Created by Moshe Berman on 11/25/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef __Shipments_Warehouse_h
#define __Shipments_Warehouse_h

#include <sstream>

using namespace std;

class Warehouse {
public:
    string name;
    int quantities[3];
    
    //
    //  Returns a string representing the data in the Warehouse
    //
    
    string description(){
        
        ostringstream stream;

        stream << name << '\t' << quantities[0] << '\t' << quantities[1] << '\t' << quantities[2] << '\n';
        
        return stream.str();
    }
};

#endif
