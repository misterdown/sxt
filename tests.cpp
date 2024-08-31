#include "sxt_head.hpp"
#include <string>
#include <vector>
#include <list>
#include <iostream>
void test_default() {
    std::string data(
    "std::wstring datal(data.begin(), data.end());\n"
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    "sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    sxt::tokenizer<std::string> tokenizer(data.begin(), data.end());
    sxt::token_new<std::string> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
    std::cout << L"data to tokenize: \"" << data << L"\"\n";
    while (tk.is_valid()) {
        std::cout << tokenizer.line() + 1ULL << ':'  << tokenizer.colon() - tk.value().size() + 1ULL << ':' << sxt::token_type_to_wstring(tk.type()) << ":\"" <<  tk.value() << "\"\n";
        tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
    }
};
void test_wchar() {
    std::wstring data(
    L"std::wstring datal(data.begin(), data.end());\n"
    L"sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    L"sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    sxt::tokenizer<std::wstring> tokenizer(data.begin(), data.end());
    sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
    std::wcout << L"data to tokenize: \"" << data << L"\"\n";
    while (tk.is_valid()) {
        std::wcout << tokenizer.line() + 1ULL << L':'  << tokenizer.colon() - tk.value().size() + 1ULL << L':' << sxt::token_type_to_wstring(tk.type()) << L":\"" <<  tk.value() << L"\"\n";
        tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
    }
};
void test_string_letterals() {
    std::string data(
    "std::wstring datal = L\"greate greate greate GREATE!!!!! \\\"not greate really\\\"\";\n"
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    "sxt::token_new<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    sxt::tokenizer<std::string> tokenizer(data.begin(), data.end());
    sxt::token_new<std::string> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
    std::cout << L"data to tokenize: \"" << data << "\"\n";
    while (tk.is_valid()) {
        std::cout << tokenizer.line() + 1ULL << ':'  << tokenizer.colon() - tk.value().size() + 1ULL << ':' << sxt::token_type_to_wstring(tk.type()) << ":\"" <<  tk.value() << "\"\n";
        tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
    }
};
int main() {
    test_default();
    test_wchar();
    test_string_letterals();
    return 0;
}
