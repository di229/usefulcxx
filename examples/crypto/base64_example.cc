#include "usefulcxx/crypto/Base64.h"

#include <cstring>

int main()
{
  if (auto data = DecodeBase64File("base64_sample.txt"))
  {
    printf("decoded %zu bytes\n", data->size());
    if (data->size() > 4) {
      printf("%c %c %c %c\n", data->at(0), data->at(1), data->at(2), 
          data->at(3));
    }
    return 0;
  }
  else
  {
    printf("decode/open failed\n");
    return 1;
  }
}
