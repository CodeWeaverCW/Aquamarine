/*
2019-07-14
Author: Logan "CodeWeaver" Hall

Image6bit is a library designed for the Gamebuino META, to draw graphics in 6-bit palettized color.
*/

#include <Gamebuino_Meta.h>
#include "Image6bit.h"


Image6bit::Image6bit(int16_t w, int16_t h) : Gamebuino_Meta::Graphics(w,h) {
	/*
	Allocate space for the image buffer.
	We can store 4 pixels every 3 bytes, so we're allocating 3/4 of `w*h` bytes.
	Plus 1 to "ceil" and not "floor" when the number gets truncated.
	*/
	_buffer = gb_malloc(uint16_t(w*h*3/4+1));
}
Image6bit::~Image6bit() {
	gb_free(_buffer);
	_buffer = nullptr;
}


void Image6bit::_drawPixel(int16_t x, int16_t y) {
	if (!_buffer)
		return;
	if ((x<0) || (y<0) || (x>=_width) || (y>=_height))
		return;

	// Four pixels fit evenly into every three bytes; mask off differently based on pixel mask
	switch (x % 4) {
		case 0:
			uint8_t mask = 0xFC;
			uint8_t addr = (_width+1) * 3/4 * y + (x * 3/4);
			_buffer[addr] ^= mask & (uint8_t)color.iu<<2;
			break;

		case 1:
			uint16_t mask = 0x03F0;
			// If color index is <= 15, do simple mask instead
			break;

		case 2:
			uint16_t mask = 0x0FC0;
			// If color index % 4 is 0, do simple mask instead
			break;

		case 3:
			uint8_t mask = 0x3F;
			break;
	}
}

void Image6bit::drawBufferedLine(int16_t x, int16_t y, uint16_t *buffer, uint16_t w, Image& img) {

}


void Image6bit::drawFastHLine(int16_t x, int16_t y, int16_t w) {

}
void Image6bit::drawImage(int16_t x, int16_t y, Image& img) {

}
void Image6bit::drawImage(int16_t x, int16_t y, Image& img, int16_t w, int16_t h) {

}
void Image6bit::drawImage(int16_t x, int16_t y, Image& img, int16_t x2, int16_t y2, int16_t w, int16_t h) {

}

void Image6bit::drawImage(int16_t x, int16_t y, Image6bit& img) {

}
void Image6bit::drawImage(int16_t x, int16_t y, Image6bit& img, int16_t w, int16_t h) {

}
void Image6bit::drawImage(int16_t x, int16_t y, Image6bit& img, int16_t x2, int16_t y2, int16_t w, int16_t h) {

}


uint8_t Image6bit::getPixel(int16_t x, int16_t y) {

}
uint16_t Image6bit::getPixelColor(int16_t x, int16_t y) {

}
uint16_t Image6bit::getBufferSize() {

}
bool Image6bit::startRecording(char* filename) {

}
void Image6bit::stopRecording(bool output = false) {

}
bool Image6bit::save(char* filename) {

}

