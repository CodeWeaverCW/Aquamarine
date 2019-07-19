/*
2019-07-14
Author: Logan "CodeWeaver" Hall

Image6bit is a library designed for the Gamebuino META, to draw graphics in 6-bit palettized color.
*/

#include <Gamebuino_Meta.h>
#include "Image6bit.h"


Image6bit::Image6bit(int16_t w, int16_t h) : Gamebuino_Meta::Graphics(w,h) {
	// Init
	colorMode = ColorMode::index;

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
	uint8_t addr = (_width+1) * 3/4 * y + (x * 3/4);
	uint8_t colour = this.color.iu | this.color.i;	// Going with "colour" to distinguish from class member "color"
	switch (x % 4) {
		case 0:
			// 11111100 00000000 00000000
			_buffer[addr] &= 0x3;	// clear
			_buffer[addr] |= colour<<2;	// set
			break;

		case 1:
			// 00000011 11110000 00000000
			// clear
			_buffer[addr] &= 0xFC;
			_buffer[addr+1] &= 0xF;

			// set
			_buffer[addr] |= colour>>4;
			_buffer[addr+1] |= colour<<4;
			break;

		case 2:
			// 00000000 00001111 11000000
			// clear
			_buffer[addr] &= 0xF0;
			_buffer[addr+1] &= 0x3F;

			// set
			_buffer[addr] |= colour>>2;
			_buffer[addr+1] |= colour<<6;
			break;

		case 3:
			// 00000000 00000000 00111111
			_buffer[addr] &= 0xC0;	// clear
			_buffer[addr] |= colour;	// set
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

