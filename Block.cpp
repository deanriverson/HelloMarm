//
//  Block.cpp
//  HelloMarm
//
//  Created by Dean Iverson on 7/29/14.
//
//

#include "Block.h"

Block::Block() {
    xy4 = new CIwSVec2[4];
    color = new CIwColour[4];
    
    color[0].Set(0xff, 0x80, 0xff);
    color[1].Set(0xff, 0x40, 0x80);
    color[2].Set(0xff, 0x40, 0x80);
    color[3].Set(0xff, 0x80, 0xff);
    
    enabled = true;
}

void Block::setEnabled(bool enabled) {
    this->enabled = enabled;
}

void Block::draw(int16 x, int16 y, int16 w, int16 h) {
    if (!enabled)
        return;
    
    xy4[0].x = x,     xy4[0].y = y;
    xy4[1].x = x,     xy4[1].y = y+h;
    xy4[2].x = x+w,   xy4[2].y = y+h;
    xy4[3].x = x+w,   xy4[3].y = y;
    
    IwGxSetVertStreamScreenSpace(xy4, 4);
    
    IwGxSetMaterial(IW_GX_ALLOC_MATERIAL());
    IwGxSetColStream(color, 4);
    
    // Draw single triangle
    IwGxDrawPrims(IW_GX_QUAD_LIST, NULL, 4);
}

Block::~Block() {
    delete xy4;
    delete color;
}