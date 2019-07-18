/*
2019-07-14
Author: Logan "CodeWeaver" Hall

Image6bit is a library designed for the Gamebuino META, to draw graphics in 6-bit palettized color.
*/

#ifndef _CW_IMAGE6bit_h
#define _CW_IMAGE6bit_h

#include <Gamebuino_Meta.h>


class Image6bit : public Gamebuino_Meta::Graphics {
public:
	/* Constructor & destructor */
	Image6bit(int16_t w, int16_t h);
	~Image6bit();


	/* Required override functions */
	void _drawPixel(int16_t x, int16_t y) override;
	void drawBufferedLine(int16_t x, int16_t y, uint16_t *buffer, uint16_t w, Image& img) override;


	/* Optional override functions */
	void drawFastHLine(int16_t x, int16_t y, int16_t w) override __attribute__((optimize("-O3")));
	// We *must* override `drawImage()` because it directly affects the image buffer, and ours is 6-bit
	void drawImage(int16_t x, int16_t y, Image& img) override;
	void drawImage(int16_t x, int16_t y, Image& img, int16_t w, int16_t h) override;
	void drawImage(int16_t x, int16_t y, Image& img, int16_t x2, int16_t y2, int16_t w, int16_t h) override;


	/* Custom functions */
	// `drawImage()` overloads that work with Image6bit objects
	void drawImage(int16_t x, int16_t y, Image6bit& img);
	void drawImage(int16_t x, int16_t y, Image6bit& img, int16_t w, int16_t h);
	void drawImage(int16_t x, int16_t y, Image6bit& img, int16_t x2, int16_t y2, int16_t w, int16_t h);

	// For compatibility with Gamebuino_Meta::Image
	// (in this class, pixels are always a 6-bit index, so no need for `getPixelIndex()`)
	uint8_t getPixel(int16_t x, int16_t y) const;
	uint16_t getPixelColor(int16_t x, int16_t y) const;
	uint16_t getBufferSize() const;
	bool startRecording(char* filename);
	void stopRecording(bool output = false);
	bool save(char* filename);

private:
	uint8_t* _buffer = nullptr;	// Actual pixel data buffer
}


#endif//_CW_IMAGE6bit_h
