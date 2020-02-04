/*
 * Copyright 2020 Christoph Raitzig
 * Distributed under the GNU General Public License (GPL) v2.
 */

#ifndef INC_JP2A_CURL_H
#define INC_JP2A_CURL_H

#ifdef FEAT_CURL
int is_url(const char* s);
int curl_download(const char* url, const int debug);

#ifdef WIN32
size_t passthru_write(void *buffer, size_t size, size_t nmemb, void *userp);
void curl_download_child(void*);
#else
void curl_download_child();
#endif

#endif

#endif
