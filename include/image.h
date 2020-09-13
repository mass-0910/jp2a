/*
 * Copyright 2006-2016 Christian Stigen Larsen
 * Copyright 2020 Christoph Raitzig
 * Distributed under the GNU General Public License (GPL) v2.
 */

#ifndef INC_JP2A_IMAGE_H
#define INC_JP2A_IMAGE_H

#include "config.h"

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#undef HAVE_STDLIB_H
#endif

#include "jpeglib.h"
#include "png.h"
#include <setjmp.h>

#include "html.h"

typedef struct rgb_t {
	JSAMPLE r, g, b;
} rgb_t;

typedef struct image_t {
	int w, h;
	rgb_t *pixels;
} image_t;

typedef struct Image_ {
	int width;
	int height;
	float *pixel; // luminosity
	float *red, *green, *blue;
	float *alpha; // opacity
	int *yadds;
	float resize_y;
	float resize_x;
	int *lookup_resx;
} Image;

typedef struct my_jpeg_error_mgr {
	struct jpeg_error_mgr pub;
	jmp_buf setjmp_buffer;
} my_jpeg_error_mgr;
typedef struct my_jpeg_error_mgr *my_jpeg_error_ptr;

typedef struct error_collector {
	my_jpeg_error_mgr *jpeg_error;
	char *png_error_msg;
	// These are true if an error has occurred and false otherwise:
	int jpeg_status;
	int png_status;
} error_collector;

void print_border(const int width);
void print_image(Image *image, FILE *f);
void print_image_colors(const Image* const image, const int chars, FILE *f);
void print_image_no_colors(const Image* const image, const int chars, FILE *f);
void clear(Image* i);
void normalize(Image* i);
void print_progress(float progress);
void print_info_jpeg(const struct jpeg_decompress_struct* jpg);
void print_info_png(const png_structp png_ptr, const png_infop info_ptr);
void process_scanline_jpeg(const struct jpeg_decompress_struct *jpg,
	const JSAMPLE* scanline, Image* i);
void process_scanline_png(const png_bytep row, const int current_y, const int color_components, Image* i);
void free_image(Image* i);
void malloc_image(Image* i);
void init_image(Image *i, int src_width, int src_height);
void decompress_jpeg(FILE *fin, FILE *fout, error_collector *errors);
void jpeg_error_exit(j_common_ptr jerr);
void decompress_png(FILE *fin, FILE *fout, error_collector *errors);
void print_errors(error_collector *errors);

#endif
