//
//  Block.h
//  HelloMarm
//
//  Created by Dean Iverson on 7/29/14.
//
//

#ifndef __HelloMarm__Block__
#define __HelloMarm__Block__

#include "IwGx.h"
#include "IwDebug.h"
#include "IwGx.h"

class Block {
public:
    Block();
    
    void setEnabled(bool enabled);
    void draw(int16 x, int16 y, int16 w, int16 h);

    virtual ~Block();
    
protected:
    CIwColour *color;
    
private:
    CIwSVec2 *xy4;
    bool enabled;
};

#endif /* defined(__HelloMarm__Block__) */
