/*
 * Copyright 2006-2016 Christian Stigen Larsen
 * Copyright 2020 Christoph Raitzig
 * Distributed under the GNU General Public License (GPL) v2.
 */

#ifndef INC_JP2A_IMAGE_H
#define INC_JP2A_IMAGE_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#undef HAVE_STDLIB_H
#endif

#include "jpeglib.h"
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
	int *yadds;
	float resize_y;
	float resize_x;
	int *lookup_resx;
} Image;

void print_border(const int width);
void print_image_colors(const Image* const i, const int chars, FILE* f);
void print_image(const Image* const i, const int chars, FILE *f);
void clear(Image* i);
void normalize(Image* i);
void print_progress(const struct jpeg_decompress_struct* jpg);
void print_info(const struct jpeg_decompress_struct* jpg);
void process_scanline(const struct jpeg_decompress_struct *jpg,
	const JSAMPLE* scanline, Image* i);
void free_image(Image* i);
void malloc_image(Image* i);
void init_image(Image *i, const struct jpeg_decompress_struct *jpg);
void decompress(FILE *fin, FILE *fout);

#endif
