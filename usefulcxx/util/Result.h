#ifndef USEFULCXX_UTIL_RESULT_H_
#define USEFULCXX_UTIL_RESULT_H_

#include <utility>
#include <exception>
#include <stdexcept>

namespace usefulcxx {

template <class T, class E>
class Result {
private:
  T item_;
  E error_;
  bool ok_;
public:
  Result() : ok_(false) {
  }

  Result(T item)
    : item_(std::move(item))
    , ok_(true) {
  }

  // Check if there is a result item to access
  bool Ok() {
    return ok_;
  }

  // Access the underlying result item
  T& operator*() {
    if (ok_) {
      return item_;
    }
#if defined(USEFULCXX_ALLOW_EXCEPTIONS)
    std::throw_with_nested(std::runtime_error("Attempt to access result via operator* when not Ok"));
#endif
    return item_;
  }

  // Access a pointer to the underlying result item
  T* operator->() {
    if (ok_) {
      return &item_;
    }
#if defined(USEFULCXX_ALLOW_EXCEPTIONS)
    std::throw_with_nested(std::runtime_error("Attempt to access result via operator-> when not Ok"));
#endif
    return nullptr;
  }

  // Access the error
  E& Error() {
    if (!ok_) {
      return error_;
    }
#if defined(USEFULCXX_ALLOW_EXCEPTIONS)
    std::throw_with_nested(std::runtime_error("Attempt to access error when Ok"));
#endif
    return error_;
  }

  // Factory returning a Result with the error set
  static Result<T,E> Error(E error) {
    auto r = Result<T,E>{};
    r.error_ = std::move(error);
    return r;
  }

};

} // namespace usefulcxx

#endif // USEFULCXX_UTIL_RESULT_H_
