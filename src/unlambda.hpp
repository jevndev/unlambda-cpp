#pragma once

#include <cstddef>
#include <string>
#include <type_traits>

namespace Unlambda {

template <typename T>
concept ProgramOutput = requires(T &t, char c) {
  { t.operator<<(c) };
};

template <typename T>
concept ProgramInput = requires(T &t, int &c) {
  { t.operator>>(c) };
};

class NoOutput_t {
public:
  constexpr NoOutput_t &operator<<(const char c) { return *this; };
};

static auto noOutput = NoOutput_t{};

class NoInput_t {
public:
  constexpr NoInput_t &operator>>(int &c) { return *this; };
};

static auto noInput = NoInput_t{};

class Program {
public:
  constexpr explicit Program(const std::string_view source) noexcept {}
  constexpr void evaluate(ProgramOutput auto &output,
                          ProgramInput auto &input) noexcept {}

  constexpr void evaluate() noexcept { evaluate(noOutput, noInput); }
};

constexpr Program operator""_unl(const char *source, const size_t n) {
  return Program{std::string_view{source, n}};
}
}; // namespace Unlambda
