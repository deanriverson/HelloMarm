//
//  Paddle.cpp
//  HelloMarm
//
//  Created by Dean Iverson on 7/29/14.
//
//

#include "Paddle.h"

Paddle::Paddle() {
    color[0].Set(0x60, 0x80, 0xff);
    color[1].Set(0x30, 0x40, 0x80);
    color[2].Set(0x30, 0x40, 0x80);
    color[3].Set(0x60, 0x80, 0xff);
}

void Paddle::draw(int16 pos) {
    int16 y = (int16)IwGxGetScreenHeight() * 7 / 8;
    Block::draw(pos, y, 100, 20);
}
