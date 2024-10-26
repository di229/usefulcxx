#include "usefulcxx/util/Result.h"

#include <string>
#include <cstring>

using usefulcxx::Result;

static Result<std::string, int> get_some() {
  std::string r = "ok!";
  return r;
}

static Result<std::string, int> get_none() {
  return {};
}

static Result<std::string, int> get_none2() {
  auto a = Result<std::string, int>::Error(-1);
  return a;
}

int main() {

  Result<std::string, int> r{};  
  auto a = get_some();

  if (a.Ok()) {
    printf("%s\n", a->c_str());
  }

  auto d = get_none2();

  if (!d.Ok()) {
    printf("No result, error=%d\n", d.Error());
  }

  try {
    auto b = get_none();
    auto c = *b;
    // crash here if exceptions are disabled:
    auto e = b->c_str();
  }
  catch (const std::exception& e) {
    printf("%s\n", e.what());
  }

  return 0;
}
