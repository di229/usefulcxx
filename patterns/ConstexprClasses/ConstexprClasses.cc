#include <cstring>
#include <string>

#if __cplusplus >= 202002L
#define CXX20_OR_GREATER
#endif

class C1 {
private:
  char *str;
  size_t len_;
public:
  // cannot be constexpr: depends on `in` length
  // C1 cannot be used in constexpr context
  C1(const char* in) {
    size_t len = strlen(in);
    str = new char[len+1]();
    if (str) {
      memcpy(str, in, len);
      str[len] = 0;
    } else {
      str = nullptr;
    }
    len_ = len;
  }

  constexpr void print() {
    printf("str=%s\n", str);
  }

  constexpr size_t len() {
    return len_;
  }

#if defined(CXX20_OR_GREATER)
  // From c++20 onwards, new can be used in constexpr, but it must also be
  // deleted in that context
  constexpr size_t uses_dynamic_memory(size_t t) const {
    char *p = new char[t];
    // do something with p
    if (p) {
      delete[] p;
    }
    return t;
  }
#endif
};

#if defined(CXX20_OR_GREATER)
int f1() {
  C1 c{"test new in constexpr"};
  return c.uses_dynamic_memory(5);
}
#endif

class C2 {
private:
  int a_;
  char b_;

public:
  constexpr C2(int a, char b)
    : a_(a)
    , b_(b) {
  }

  constexpr int add() {
    return a_ + (int)b_;
  }
};

constexpr int f2() {
  C2 c{0x20, 'A'};
  return c.add();
}

int main(int argc, char *argv[]) {
  C1 c{argv[0]};
  c.print();
  printf("len()=%zu\n", c.len());
  printf("f2()=%d\n", f2());
}
