/*
 * Copyright 2020 Christoph Raitzig
 * Distributed under the GNU General Public License (GPL) v2.
 */

#ifndef INC_JP2A_HTML_H
#define INC_JP2A_HTML_H

void print_html_start(const int fontsize, FILE *fout);
void print_html_end(FILE *fout);
void print_html_char(FILE *fout, const char ch,
	const int red_fg, const int green_fg, const int blue_fg,
	const int red_bg, const int green_bg, const int blue_bg);
void print_html_newline(FILE *fout);
void print_xhtml_start(const int fontsize, FILE *fout);
void print_xhtml_end(FILE *fout);
void print_xhtml_char(FILE *fout, const char ch,
	const int red_fg, const int green_fg, const int blue_fg,
	const int red_bg, const int green_bg, const int blue_bg);
void print_xhtml_newline(FILE *fout);
const char* html_entity(const char ch);
void print_css(const int fontsize, FILE *f);

#endif
