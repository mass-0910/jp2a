/*
 * Copyright 2020 Christoph Raitzig
 * Distributed under the GNU General Public License (GPL) v2.
 */

#ifndef INC_JP2A_HTML_H
#define INC_JP2A_HTML_H

#include "config.h"

void print_html_document_start(const int fontsize, FILE *fout);
void print_html_image_start(FILE *f);
void print_html_document_end(FILE *fout);
void print_html_image_end(FILE *f);
#if ASCII
void print_html_char(FILE *fout, const char ch,
	const int red_fg, const int green_fg, const int blue_fg,
	const int red_bg, const int green_bg, const int blue_bg);
#else
void print_html_char(FILE *fout, const char* ch,
	const int red_fg, const int green_fg, const int blue_fg,
	const int red_bg, const int green_bg, const int blue_bg);
#endif
void print_html_newline(FILE *fout);
void print_xhtml_document_start(const int fontsize, FILE *fout);
void print_xhtml_image_start(FILE *f);
void print_xhtml_document_end(FILE *fout);
void print_xhtml_image_end(FILE *f);
#if ASCII
void print_xhtml_char(FILE *fout, const char ch,
	const int red_fg, const int green_fg, const int blue_fg,
	const int red_bg, const int green_bg, const int blue_bg);
#else
void print_xhtml_char(FILE *fout, const char* ch,
	const int red_fg, const int green_fg, const int blue_fg,
	const int red_bg, const int green_bg, const int blue_bg);
#endif
void print_xhtml_newline(FILE *fout);
#if ASCII
const char* html_entity(const char ch);
#else
const char* html_entity(const char* ch);
#endif
void print_css(const int fontsize, FILE *f);
int escape_title();

#endif
