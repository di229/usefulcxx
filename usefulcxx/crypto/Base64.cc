#include "Base64.h"

#include <openssl/evp.h>
#include <cstring>

OptBytes DecodeBase64String(std::string& str)
{
  if (auto ctx = EVP_ENCODE_CTX_new()) 
  {
    EVP_DecodeInit(ctx);
    unsigned char *inp = reinterpret_cast<unsigned char*>(&str[0]);
    auto inlen = TrimTrailing(str);
    auto outlen = (3 * inlen) / 4;
    std::vector<char> res(outlen, 0);
    unsigned char *outp = reinterpret_cast<unsigned char*>(&res[0]);

    auto rc = EVP_DecodeUpdate(ctx, outp, &outlen, inp, inlen);

    if (rc != -1) 
    {
      int tmp;
      rc = EVP_DecodeFinal(ctx, outp + outlen, &tmp);
      outlen += tmp;
      /* internal whitespace is not decoded*/
      res.resize(outlen);
    }

    EVP_ENCODE_CTX_free(ctx);

    if (rc == 1)
    {
      return res;
    }

  }
  // decode failed
  return {};
}

OptBytes DecodeBase64File(std::string_view path)
{
  if (auto str = ReadFile(path))
  {
    return DecodeBase64String(*str);
  }
  return {};
}
