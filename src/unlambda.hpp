#pragma once

#include <cstddef>
#include <string>
#include <type_traits>

template <typename T>
concept ProgramOutput = requires(T &t, char c) {
  { t.operator<<(c) } -> std::same_as<T &>;
};

template <typename T>
concept ProgramInput = requires(T &t, int &c) {
  { t.operator>>(c) } -> std::same_as<T &>;
};

namespace Unlambda {
class Program {
public:
  constexpr explicit Program(const std::string_view source) noexcept {}
  constexpr void evaluate(ProgramOutput auto &output,
                          ProgramInput auto &input) noexcept {}
};

constexpr Program operator""_unl(const char *source, const size_t n) {
  return Program{std::string_view{source, n}};
}
}; // namespace Unlambda
