//
//  Card.h
//  2-Shipments
//
//  Created by Moshe Berman on 11/25/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#ifndef __Shipments_Card_h
#define __Shipments_Card_h

class Card {
public:
    char cardType;
    string city;
    int amount1 = 0;
    int amount2 = 0;
    int amount3 = 0;
    
    //
    //  Returns a string representing the data in the Warehouse
    //
    
    string description(){
        
        //  Set up a stream to pipe all of the properties to...
        
        ostringstream stream;
        
        //  ...pipe it all in...
        
        string cardTitle = cardType == 'o' ? "---- Order: ----\n" : "---- Shipment: ----\n";
        
        stream << cardTitle << ' ' << city << '\t' << amount1 << '\t' << amount2 << '\t' << amount3 << '\n';
        
        //  ... and return it.
        
        return stream.str();
    }
};

#endif
