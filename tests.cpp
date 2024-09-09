
#include "sxt_head.hpp"
#include <string>
#include <string_view>
#include <iostream>
#include <chrono>

void default_test() {
    std::cout << "default test\n";

    const std::string data(
    "std::wstring datal(data.begin(), data.end());\n\"\""
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    );
    sxt::tokenizer<std::string> tokenizer(data.begin(), data.end());
    while (true) {
        const sxt::value_token<std::string> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_NONE);
        if (!tk.is_valid())
            break;
        std::cout << token_type_to_string(tk.type()) << ":  " << tk.value() <<  " \n";
    }
};
void wchar_test() {
    std::cout << "wchar string test\n";

    const std::wstring data(
    L"std::wstring datal(data.begin(), data.end());\n"
    L"sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    );
    sxt::tokenizer<std::wstring> tokenizer(data.begin(), data.end());
    while (true) {
        const sxt::value_token<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_NONE);
        if (!tk.is_valid())
            break;
        std::wcout << token_type_to_wstring(tk.type()) << L":  " << tk.value() <<  L" \n";
    }
};
void string_letterals_test() {
    std::cout << "string letterals test\n";

    const std::string data(
    "std::wstring datal = L\"greate greate greate GREATE!!!!! \\\"not greate really\\\"\";\n"
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    );
    sxt::tokenizer<std::string> tokenizer(data.begin(), data.end());
    while (true) {
        const sxt::value_token<std::string> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
        if (!tk.is_valid())
            break;
        std::cout << token_type_to_string(tk.type()) << ":  " << tk.value() <<  " \n";
    }
};

void perfomance_test() {
    std::cout << "default perfomance test\n";

    const std::string data(
    "std::wstring datal = L\"greate greate greate GREATE!!!!! \\\"not greate really\\\"\";\n"
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    "sxt::value_token<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    for (size_t e = 0; e < 5; ++e) {
        const auto start = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 500000; ++i) {
            sxt::tokenizer<std::string> tokenizer(data.begin(), data.end());
            while (true) {
                const sxt::value_token<std::string> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
                if (!tk.is_valid())
                    break;
            }
        }
        std::cout << (double)(std::chrono::steady_clock::now() - start).count() / (double)std::chrono::steady_clock::period::den << '\n';
    }
}
#if (__cplusplus >= 202002L)
void perfomance_view_test() { //speed up x4 on O0 and ~x2 on O3
    std::cout << "perfomance test with string views\n";
    
    const std::string data(
    "std::wstring datal = L\"greate greate greate GREATE!!!!! \\\"not greate really\\\"\";\n"
    "sxt::tokenizer<std::wstring> tokenizer(datal.begin(), datal.end());\n"
    "sxt::value_token<std::wstring> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);\n"
    );
    const std::string_view view = data;
    for (size_t e = 0; e < 5; ++e) {
        const auto start = std::chrono::steady_clock::now();
        for (size_t i = 0; i < 500000; ++i) {
            sxt::tokenizer<std::string_view> tokenizer(view.begin(), view.end());
            while (true) {
                const sxt::value_token<std::string_view> tk = tokenizer.next_new_token(sxt::STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL);
                if (!tk.is_valid())
                    break;
            }
        }
        std::cout << (double)(std::chrono::steady_clock::now() - start).count() / (double)std::chrono::steady_clock::period::den << '\n';
    }
}
#else 
void perfomance_view_test() {

}
#endif // C++20

int main() {
    default_test();
    wchar_test();
    string_letterals_test();
    perfomance_test();
    perfomance_view_test();

    return 0;
}
