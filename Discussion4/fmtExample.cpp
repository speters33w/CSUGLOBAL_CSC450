// fmtExample.cpp
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#define FMT_HEADER_ONLY

#include <regex>
#include <fmt/color.h>

using namespace fmt;

int get_integer(const std::string& input);

int fmtExample_main() {
    int fortyTwo = get_integer("42");
    print(fg(color::crimson) | emphasis::bold,
          "The answer to life, {0}{1}!\n",
          "the universe and everything is ",
          fortyTwo);
    print(fg(color::floral_white) | bg(color::slate_gray) | emphasis::underline,
          "El sentido de la vida, {0}{1}!\n",
                      " el universo y todo lo demás es ",
                      fortyTwo);
    fmt::print(fg(color::steel_blue) | emphasis::italic,
               "生命、宇宙、{0}{1}\n",
               "以及任何事情的終極答案是",
               fortyTwo);
}

int get_integer(const std::string& input) {
    return stoi(regex_replace(input, std::regex(R"([^\-0-9.]+)"), ""));
}

#pragma clang diagnostic pop