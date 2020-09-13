/*
 * Copyright 2006-2016 Christian Stigen Larsen
 * Copyright 2020 Christoph Raitzig
 * Distributed under the GNU General Public License (GPL) v2.
 */

#ifndef INC_JP2A_H
#define INC_JP2A_H

int main(int argc, char** argv);
int read_into_buffer(FILE *fp, char **buffer, size_t *buffer_size, size_t *actual_size);

#endif
