//
//  Paddle.h
//  HelloMarm
//
//  Created by Dean Iverson on 7/29/14.
//
//

#ifndef __HelloMarm__Paddle__
#define __HelloMarm__Paddle__

#include <iostream>

#include "Block.h"

class Paddle : public Block {
public:
    Paddle();
    void draw(int16 pos);
};

#endif /* defined(__HelloMarm__Paddle__) */
