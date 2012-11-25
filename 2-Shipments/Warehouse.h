//
//  Warehouse.h
//  2-Shipments
//
//  Created by Moshe Berman on 11/25/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef __Shipments_Warehouse_h
#define __Shipments_Warehouse_h

#include "Item.h"

using namespace std;

class Warehouse {
public:
    string name;
    Item items[3];
};

#endif
