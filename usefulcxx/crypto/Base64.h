#ifndef _USEFULCXX_CRYPTO_BASE64_H
#define _USEFULCXX_CRYPTO_BASE64_H

#include "Util.h"

OptBytes DecodeBase64String(std::string& str);

OptBytes DecodeBase64File(std::string_view path);

#endif // _USEFULCXX_CRYPTO_BASE64_H
