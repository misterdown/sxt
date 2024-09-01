#include "sxt_head.hpp"
#include <string>
#include <iostream>

void test_default() {
    const std::string data(
    "std::wstring datal(data.begin(), data.end());\n"
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    "sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    sxt::tokenizer<std::string> tokenizer(data.begin(), data.end());
    while (true) {
        const sxt::token_new<std::string> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_NONE);
        if (!tk.is_valid())
            break;
        std::cout << token_type_to_string(tk.type()) << ':' << tk.value() << '\n';
    }
};
void test_wchar() {
    const std::wstring data(
    L"std::wstring datal(data.begin(), data.end());\n"
    L"sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    L"sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    sxt::tokenizer<std::wstring> tokenizer(data.begin(), data.end());
    while (true) {
        const sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_NONE);
        if (!tk.is_valid())
            break;
        std::wcout << token_type_to_wstring(tk.type()) << L':' << tk.value() << L'\n';
    }
};
void test_string_letterals() {
    const std::string data(
    "std::wstring datal = L\"greate greate greate GREATE!!!!! \\\"not greate really\\\"\";\n"
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    "sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    sxt::tokenizer<std::string> tokenizer(data.begin(), data.end());
    while (true) {
        const sxt::token_new<std::string> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
        if (!tk.is_valid())
            break;
        std::cout << token_type_to_string(tk.type()) << ':' << tk.value() << '\n';
    }
};

int main() {
    test_default();
    test_wchar();
    test_string_letterals();

    return 0;
}
