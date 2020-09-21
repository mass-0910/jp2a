/*! \file
 * \noop Copyright 2006-2016 Christian Stigen Larsen
 * \noop Copyright 2020 Christoph Raitzig
 *
 * \brief The main function and a helper function.
 *
 * \author Christian Stigen Larsen
 * \author Christoph Raitzig
 * \copyright Distributed under the GNU General Public License (GPL) v2.
 */

#ifndef INC_JP2A_H
#define INC_JP2A_H

/*!
 * \brief The main function.
 *
 * \param argc argument count
 * \param argv the arguments
 */
int main(int argc, char** argv);

/*!
 * \brief Reads from a stream into a buffer.
 *
 * This function is used to make a seekable stream from a non-seekable stream:
 * Read the contents of the non-seekable stream into a buffer (with this function) and open a stream to this buffer (with fmemopen()).
 * The buffer is (re)allocated as needed.
 *
 * \param fp stream to read into buffer
 * \param buffer the buffer to read into
 * \param buffer_size the allocated size of the buffer
 * \param actual_size the number of bytes read into the buffer
 * \return true if sucessful, false otherwise
 */
int read_into_buffer(FILE *fp, char **buffer, size_t *buffer_size, size_t *actual_size);

#endif
