//
//  Paddle.cpp
//  HelloMarm
//
//  Created by Dean Iverson on 7/29/14.
//
//

#include "Paddle.h"

void drawBlock(int16 x, int16 y, int16 w, int16 h, uint8 r, uint8 g, uint8 b) {
    CIwMaterial* pMat = IW_GX_ALLOC_MATERIAL();
    
    // Set this as the active material
    IwGxSetMaterial(pMat);
    
    // Set up screenspace vertex coords
    int16 y1 = (int16)IwGxGetScreenHeight() * 7 / 8;
    
    static CIwSVec2 xy4[4];
    xy4[0].x = x,     xy4[0].y = y;
    xy4[1].x = x,     xy4[1].y = y+h;
    xy4[2].x = x+w,   xy4[2].y = y+h;
    xy4[3].x = x+w,   xy4[3].y = y;
    
    IwGxSetVertStreamScreenSpace(xy4, 4);
    
    // Set up vertex colours
    static CIwColour cols[4] =
    {
        {r, g, b},
        {r >> 1, g >> 1, b >> 1},
        {r >> 1, g >> 1, b >> 1},
        {r, g, b}
    };
    
    IwGxSetColStream(cols, 4);
    
    // Draw single triangle
    IwGxDrawPrims(IW_GX_QUAD_LIST, NULL, 4);
}


void drawPaddle(int16 pos) {
    // Set up screenspace vertex coords
    int16 y = (int16)IwGxGetScreenHeight() * 7 / 8;
    drawBlock(pos, y, 100, 20, 0x40, 0x60, 0xff);
}

