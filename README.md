# SXT

SXT is a small C++ framework designed to simplify string tokenization. It provides convenient tools for splitting strings into tokens, which can be useful for developing parsers, compilers, and other text-processing applications. The framework is compatible with C++11 and later versions.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [License](#license)

## Installation

To use the SXT Framework, you need to copy the `sxt_head.hpp` file into your project. This file contains all the necessary definitions and implementations.

## Usage

The framework provides the `sxt::tokenizer` class, which allows you to split strings into tokens. The framework supports various token types, including words, numbers, operators, and string literals.

### Requirements

- C++11 or later
- Optional: Standard Library (`<locale>`, `<type_traits>`, `<cassert>`, `<utility>`)
  - The framework can work without the Standard Library if the user correctly redefines the macros.

### Key Features

- Tokenization of strings into various token types.
- Support for custom token symbols and traits.
- Handling of string literals and escape sequences.
- Extensible and modular design.

## Examples

### Example 1: Simple Tokenization

```cpp
#include "sxt_head.hpp"
#include <iostream>
#include <string>

int main() {
    std::string input = "hello + world = 42";
    sxt::tokenizer<std::string> tokenizer(input.begin(), input.end());

    while (true) {
        const auto token = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_NONE);
        if (!token.is_valid()) break;
            std::cout << "Token: " << token.value() << " (" << sxt::token_type_to_string(token.type()) << ")" << '\n';
    }

    return 0;
}
```

### Example 2: Tokenization with String Literals Support

```cpp
#include "sxt_head.hpp"
#include <iostream>
#include <string>

int main() {
    std::string input = "\"hello world\" + 42";
    sxt::tokenizer<std::string> tokenizer(input.begin(), input.end());

    while (true) {
        const auto token = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
        if (!token.is_valid()) break;
            std::cout << "Token: " << token.value() << " (" << sxt::token_type_to_string(token.type()) << ")" << '\n';
    }

    return 0;
}
```
## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
