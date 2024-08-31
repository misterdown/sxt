# SXT Framework

SXT is a small C++ framework designed to simplify string tokenization. It provides convenient tools for splitting strings into tokens, which can be useful for developing parsers, compilers, and other text-processing applications.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Installation

To use the SXT Framework, you need to copy the `sxt_head.hpp` file into your project. This file contains all the necessary definitions and implementations.

## Usage

The framework provides the `sxt::tokenizer` class, which allows you to split strings into tokens. Here is an example of how to use it:

```cpp
#include "sxt_head.hpp"
#include <iostream>
#include <string>

int main() {
    std::string input = "hello + world = 42";
    sxt::tokenizer<std::string> tokenizer(input.begin(), input.end());

    while (true) {
        auto token = tokenizer.next_new_token(0);
        if (!token.is_valid()) break;
        std::cout << "Token: " << token.value() << " (" << sxt::token_type_to_string(token.type()) << ")" << std::endl;
    }

    return 0;
}
'''
## License
This project is licensed under the MIT License. See the LICENSE file for details.
