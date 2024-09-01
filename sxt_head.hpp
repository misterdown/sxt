#ifndef SXT_HEAD_HPP_
#   define SXT_HEAD_HPP_ 1
#if (!(defined SXT_HPP_ISDIGIT)) || (!(defined SXT_HPP_ISALPHA)) || (!(defined SXT_HPP_ISSAPCE))

#if (defined SXT_HPP_ISDIGIT) || (defined SXT_HPP_ISALPHA) || (defined SXT_HPP_ISSAPCE)
    static_assert(0, "define SXT_HPP_ISDIGIT, SXT_HPP_ISALPHA and SXT_HPP_ISSAPCE if you defined one of them");
#endif // defined SXT_HPP_ISDIGIT || defined SXT_HPP_ISALPHA || defined SXT_HPP_ISSAPCE
#   include <locale> // for isalpha, isspace
#   define SXT_HPP_ISDIGIT(c__) (::std::isdigit(c__))
#   define SXT_HPP_ISALPHA(c__) (::std::isalpha(c__))
#   define SXT_HPP_ISSAPCE(c__) (::std::isspace(c__))
#endif // !defined SXT_HPP_ISDIGIT || !defined SXT_HPP_ISALPHA || !defined SXT_HPP_ISSAPCE
#if (!(defined SXR_HPP_DEFAULT_CHAR_TRAITS))
#   include <type_traits> // for char_traits
#   define SXR_HPP_DEFAULT_CHAR_TRAITS ::std::char_traits
#endif // !defined SXR_HPP_DEFAULT_CHAR_TRAITS

#if (!(defined SXT_HPP_ASSERT))
#   include <cassert>
#   define SXT_HPP_ASSERT(expr__) assert(expr__)
#endif // defined defined SXT_HPP_ASSERT

#if (!(defined SXR_HPP_MOVE))
#   include <utility> // for move
#   define SXR_HPP_MOVE ::std::move
#endif // !defined SXR_HPP_MOVE

#define SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(it__, charcol__) ++(charcol__); ++(it__);// <- a bit slower. 
//do { ++(charcol__); ++(it__); } while(0) // but..
#define SXT__HPP_NEXT_CHAR_V(it__, itvalue__, charln__, charcol__) if (char_traits_type::eq(itvalue__, '\n')) { charcol__ = 0ULL; ++(charln__); } else { ++(charcol__); }  ++(it__);// <- a bit slower.
//do { if (char_traits_type::eq(itvalue__, '\n')) { charcol__ = 0ULL; ++(charln__); } else { ++(charcol__); }  ++(it__); } while(0) // but..

namespace sxt {
    enum token_type {
        STX_TOKEN_TYPE_WORD,            // [a-z]|[A-Z]|_
        STX_TOKEN_TYPE_FLOAT,           // -|[0-9]|.
        STX_TOKEN_TYPE_INTEGER,         // [0-9]
        STX_TOKEN_TYPE_STRING_LETTERAL, // " ... "
        STX_TOKEN_TYPE_PLUS,            // + 
        STX_TOKEN_TYPE_MINUS,           // -
        STX_TOKEN_TYPE_ASSIGN,          // =
        STX_TOKEN_TYPE_LPAREN,          // (
        STX_TOKEN_TYPE_RPAREN,          // )
        STX_TOKEN_TYPE_LCURLY,          // {
        STX_TOKEN_TYPE_RCURLY,          // }
        STX_TOKEN_TYPE_DOT,             // .
        STX_TOKEN_TYPE_COMMA,           // ,
        STX_TOKEN_TYPE_COLON,           // :
        STX_TOKEN_TYPE_SEMICOLON,       // ;
        STX_TOKEN_TYPE_QUOTE,           // '
        STX_TOKEN_TYPE_DOUBLE_QUOTE,    // "
        STX_TOKEN_TYPE_STAR,            // *
        STX_TOKEN_TYPE_TILDA,           // ~
        STX_TOKEN_TYPE_BACKCLASH,       // '\'
        STX_TOKEN_TYPE_MORE,            // >
        STX_TOKEN_TYPE_LESS,            // <
        STX_TOKEN_TYPE_EXCLAMATION,     // !
        STX_TOKEN_TYPE_QUESTION,        // ?
        STX_TOKEN_TYPE_EOF,             // '\0'
        STX_TOKEN_TYPE_INVALID,         // 
        STX_TOKEN_TYPE_MAX_ENUM,        // 
    };
    template <class CharT_>
    struct token_symbols_trait {
        public:
        typedef CharT_ char_type;

        public:
        constexpr static char_type c_plus        ()  {return '+';};
        constexpr static char_type c_minus       ()  {return '-';};
        constexpr static char_type c_assign      ()  {return '=';};
        constexpr static char_type c_lparen      ()  {return '(';};
        constexpr static char_type c_rparen      ()  {return ')';};
        constexpr static char_type c_lcurly      ()  {return '{';};
        constexpr static char_type c_rcurly      ()  {return '}';};
        constexpr static char_type c_dot         ()  {return '.';};
        constexpr static char_type c_comma       ()  {return ',';};
        constexpr static char_type c_colon       ()  {return ':';};
        constexpr static char_type c_semicolon   ()  {return ';';};
        constexpr static char_type c_quote       ()  {return '\'';};
        constexpr static char_type c_double_quote()  {return '\"';};
        constexpr static char_type c_star        ()  {return '*';};
        constexpr static char_type c_tilda       ()  {return '~';};
        constexpr static char_type c_backslash   ()  {return '\\';};
        constexpr static char_type c_more        ()  {return '>';};
        constexpr static char_type c_less        ()  {return '<';};
        constexpr static char_type c_exclamation ()  {return '!';};
        constexpr static char_type c_question    ()  {return '?';};

        public:
        constexpr static const char_type* str_plus        ()    {return "+";};
        constexpr static const char_type* str_minus       ()    {return "-";};
        constexpr static const char_type* str_assign      ()    {return "=";};
        constexpr static const char_type* str_lparen      ()    {return "(";};
        constexpr static const char_type* str_rparen      ()    {return ")";};
        constexpr static const char_type* str_lcurly      ()    {return "{";};
        constexpr static const char_type* str_rcurly      ()    {return "}";};
        constexpr static const char_type* str_dot         ()    {return ".";};
        constexpr static const char_type* str_comma       ()    {return ",";};
        constexpr static const char_type* str_colon       ()    {return ":";};
        constexpr static const char_type* str_semicolon   ()    {return ";";};
        constexpr static const char_type* str_quote       ()    {return "\'";};
        constexpr static const char_type* str_double_quote()    {return "\"";};
        constexpr static const char_type* str_star        ()    {return "*";};
        constexpr static const char_type* str_tilda       ()    {return "~";};
        constexpr static const char_type* str_backslash   ()    {return "\\";};
        constexpr static const char_type* str_more        ()    {return ">";};
        constexpr static const char_type* str_less        ()    {return "<";};
        constexpr static const char_type* str_exclamation ()    {return "!";};
        constexpr static const char_type* str_question    ()    {return "?";};
    };

    template <>
    struct token_symbols_trait<wchar_t> {
        public:
        typedef wchar_t char_type;

        public:
        constexpr static char_type c_plus        ()  {return L'+';};
        constexpr static char_type c_minus       ()  {return L'-';};
        constexpr static char_type c_assign      ()  {return L'=';};
        constexpr static char_type c_lparen      ()  {return L'(';};
        constexpr static char_type c_rparen      ()  {return L')';};
        constexpr static char_type c_lcurly      ()  {return L'{';};
        constexpr static char_type c_rcurly      ()  {return L'}';};
        constexpr static char_type c_dot         ()  {return L'.';};
        constexpr static char_type c_comma       ()  {return L',';};
        constexpr static char_type c_colon       ()  {return L':';};
        constexpr static char_type c_semicolon   ()  {return L';';};
        constexpr static char_type c_quote       ()  {return L'\'';};
        constexpr static char_type c_double_quote()  {return L'\"';};
        constexpr static char_type c_star        ()  {return L'*';};
        constexpr static char_type c_tilda       ()  {return L'~';};
        constexpr static char_type c_backslash   ()  {return L'\\';};
        constexpr static char_type c_more        ()  {return L'>';};
        constexpr static char_type c_less        ()  {return L'<';};
        constexpr static char_type c_exclamation ()  {return L'!';};
        constexpr static char_type c_question    ()  {return L'?';};

        public:
        constexpr static const char_type* str_plus        ()    {return L"+";};
        constexpr static const char_type* str_minus       ()    {return L"-";};
        constexpr static const char_type* str_assign      ()    {return L"=";};
        constexpr static const char_type* str_lparen      ()    {return L"(";};
        constexpr static const char_type* str_rparen      ()    {return L")";};
        constexpr static const char_type* str_lcurly      ()    {return L"{";};
        constexpr static const char_type* str_rcurly      ()    {return L"}";};
        constexpr static const char_type* str_dot         ()    {return L".";};
        constexpr static const char_type* str_comma       ()    {return L",";};
        constexpr static const char_type* str_colon       ()    {return L":";};
        constexpr static const char_type* str_semicolon   ()    {return L";";};
        constexpr static const char_type* str_quote       ()    {return L"\'";};
        constexpr static const char_type* str_double_quote()    {return L"\"";};
        constexpr static const char_type* str_star        ()    {return L"*";};
        constexpr static const char_type* str_tilda       ()    {return L"~";};
        constexpr static const char_type* str_backslash   ()    {return L"\\";};
        constexpr static const char_type* str_more        ()    {return L">";};
        constexpr static const char_type* str_less        ()    {return L"<";};
        constexpr static const char_type* str_exclamation ()    {return L"!";};
        constexpr static const char_type* str_question    ()    {return L"?";};
    };

    enum ext_token_type_flag_bit {
        STX_EXT_TOKEN_TYPE_FLAG_BIT_NONE = (0),
        STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL = (1 << 0),
        STX_EXT_TOKEN_TYPE_FLAG_BIT_MAX_ENUM,
    };

    template<class StringT_>
    struct token_new {
        public:
        typedef StringT_& reference;
        typedef const StringT_& const_reference;
        typedef typename StringT_::const_iterator const_iterator;

        private:
        StringT_ value_;
        token_type type_;
        
        public:
        token_new() : value_(), type_(STX_TOKEN_TYPE_INVALID) {

        }
        token_new(token_type type__, const StringT_& str__) : value_(str__), type_(type__) {

        }
        token_new(token_type type__, StringT_&& str__) : value_(SXR_HPP_MOVE(str__)), type_(type__) {

        }

        public:
        [[nodiscard]] reference value() noexcept {
            return value_;
        }
        [[nodiscard]] const_reference value() const noexcept {
            return value_;
        }
        [[nodiscard]] token_type type() const noexcept {
            return type_;
        }
        [[nodiscard]] bool is_valid() const noexcept {
            return (type_ < STX_TOKEN_TYPE_EOF);
        }
    };
    /**
     * @brief A tokenizer class that can be configured to split input strings into tokens based on customizable delimiters and traits.
     *
     * @tparam StringT_ type of string to use.
     * @tparam CharTraitsT_ the type of the срфк traits. Defaults to token_symbols_trait<typename StringT_::value_type>.
     * @tparam TokenSymbolsTraitsT_ the type of the token symbols traits. Defaults to SXR_HPP_DEFAULT_CHAR_TRAITS<typename StringT_::value_type>.
     */
    template<class StringT_, class CharTraitsT_ = SXR_HPP_DEFAULT_CHAR_TRAITS<typename StringT_::value_type>, class TokenSymbolsTraitsT_ = token_symbols_trait<typename StringT_::value_type>>
    struct tokenizer {
        public:
        typedef typename StringT_::const_iterator const_iterator;
        typedef token_new<StringT_> token_new_type;
        typedef typename StringT_::value_type char_type;
        typedef TokenSymbolsTraitsT_ symbols_trait_type;
        typedef CharTraitsT_ char_traits_type;

        private:
        const_iterator begin_;  ///@brief The beginning iterator of the input range.
        const_iterator current_;///@brief The current iterator position in the input range.
        const_iterator end_;    ///@brief The ending iterator of the input range.
        size_t line_{0ULL};     ///@brief The current line number in the input range.
        size_t colon_{0ULL};    ///@brief The current column number in the input range.

        public:
        tokenizer() {

        }
        /**
         * @brief Constructor that initializes the tokenizer with a range of iterators.
         *
         * @param beginI The beginning iterator of the input range.
         * @param endI The ending iterator of the input range.
         */
        tokenizer(const_iterator beginI, const_iterator endI) : begin_(beginI), current_(beginI), end_(endI) {

        }

        public:
        /**
         * @brief Retrieves the next token from the input range.
         *
         * @param flags the flags for token type.
         * @return The next token of type token_new_type.
         */
        token_new_type next_new_token(ext_token_type_flag_bit flags) {
            const auto createNumberToken = [](const_iterator& currentr, size_t& colonr, const_iterator end__, const_iterator b) {
                token_type numberType = STX_TOKEN_TYPE_INTEGER;
                while (currentr != end__) {
                    const char_type currentValue = *currentr;
                    if (char_traits_type::eq(currentValue, '.')) {
                        if (numberType == STX_TOKEN_TYPE_FLOAT) 
                            break;
                        else
                            numberType = STX_TOKEN_TYPE_FLOAT;
                    } else if (!SXT_HPP_ISDIGIT(currentValue)) {
                        break;
                    }
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(currentr, colonr);
                }
                return token_new_type(numberType, StringT_(b, currentr));
            };
            const auto isWordSymbol = [](char_type c) {
                return (SXT_HPP_ISALPHA(c) || (char_traits_type::eq(c, '_')));
            };

            while (current_ != end_) {
                auto currentValue = *current_;
                if (SXT_HPP_ISSAPCE(currentValue)) {
                    SXT__HPP_NEXT_CHAR_V(current_, currentValue, line_, colon_);
                    continue;
                } else if (isWordSymbol(currentValue)) {
                    const const_iterator wordStart = current_;
                    while (current_ != end_) {
                        currentValue = *current_;
                        if (!isWordSymbol(currentValue))
                            break;
                        SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    }
                    return token_new_type(STX_TOKEN_TYPE_WORD, StringT_(wordStart, current_));
                    
                } else if (SXT_HPP_ISDIGIT(currentValue)) {
                    return createNumberToken(current_, colon_, end_, current_);

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_plus())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_PLUS,  symbols_trait_type::str_plus());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_minus())) {
                    const auto numberStart = current_;
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    currentValue = *current_;
                    if (SXT_HPP_ISDIGIT(currentValue))
                        return createNumberToken(current_, colon_, end_, numberStart);
                    return token_new_type(STX_TOKEN_TYPE_MINUS, symbols_trait_type::str_minus());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_assign())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_ASSIGN, symbols_trait_type::str_assign());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_lparen())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_LPAREN, symbols_trait_type::str_lparen());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_rparen())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_RPAREN, symbols_trait_type::str_rparen());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_lcurly())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_LCURLY, symbols_trait_type::str_lcurly());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_rcurly())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_RCURLY, symbols_trait_type::str_rcurly());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_dot())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_DOT, symbols_trait_type::str_dot());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_comma())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_COMMA, symbols_trait_type::str_comma());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_colon())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_COLON, symbols_trait_type::str_colon());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_semicolon())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_SEMICOLON, symbols_trait_type::str_semicolon());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_quote())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_QUOTE, symbols_trait_type::str_quote());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_double_quote())) {
                    if (flags & STX_EXT_TOKEN_TYPE_FLAG_BIT_STRING_LETTERAL) {
                        const auto wordStart = current_;
                        SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                        bool slash = false;
                        while (current_ != end_) {
                            currentValue = *current_;
                            if (slash) {
                                slash = false;
                            } else {
                                if (char_traits_type::eq(currentValue, symbols_trait_type::c_backslash())) {
                                    slash = true;
                                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_double_quote())) {
                                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                                    return token_new_type(STX_TOKEN_TYPE_STRING_LETTERAL, StringT_(wordStart, current_));
                                }
                            }
                            SXT__HPP_NEXT_CHAR_V(current_, currentValue, line_, colon_);
                        }
                    } else {
                        SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                        return token_new_type(STX_TOKEN_TYPE_DOUBLE_QUOTE, symbols_trait_type::str_double_quote());
                    }

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_star())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_STAR, symbols_trait_type::str_star());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_tilda())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_TILDA, symbols_trait_type::str_tilda());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_backslash())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_BACKCLASH, symbols_trait_type::str_backslash());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_more())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_MORE, symbols_trait_type::str_more());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_less())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_LESS, symbols_trait_type::str_less());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_exclamation())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_EXCLAMATION, symbols_trait_type::str_exclamation());

                } else if (char_traits_type::eq(currentValue, symbols_trait_type::c_question())) {
                    SXT__HPP_NEXT_CHAR_WITHOUT_LINECHECK(current_, colon_);
                    return token_new_type(STX_TOKEN_TYPE_QUESTION, symbols_trait_type::str_question());

                } else {
                    SXT_HPP_ASSERT(false); // unknown symbol
                    return token_new_type();
                }
            }
            return token_new_type();
        }
        [[nodiscard]] size_t line() const noexcept {
            return line_;
        }
        [[nodiscard]] size_t colon() const noexcept {
            return colon_;
        }
        [[nodiscard]] bool eof() const noexcept {
            return (current_ != end_);
        }
    };
    const char* token_type_to_string(token_type tt) {
        switch (tt) {
            case STX_TOKEN_TYPE_WORD:
                return "WORD";
            case STX_TOKEN_TYPE_FLOAT:
                return "FLOAT";
            case STX_TOKEN_TYPE_INTEGER:
                return "INTEGER";
            case STX_TOKEN_TYPE_STRING_LETTERAL:
                return "STRING LETTERAL";
            case STX_TOKEN_TYPE_PLUS:
                return "PLUS";
            case STX_TOKEN_TYPE_MINUS:
                return "MINUS";
            case STX_TOKEN_TYPE_ASSIGN:
                return "ASSIGN";
            case STX_TOKEN_TYPE_LPAREN:
                return "LPAREN";
            case STX_TOKEN_TYPE_RPAREN:
                return "RPAREN";
            case STX_TOKEN_TYPE_LCURLY:
                return "LCURLY";
            case STX_TOKEN_TYPE_RCURLY:
                return "RCURLY";
            case STX_TOKEN_TYPE_DOT:
                return "DOT";
            case STX_TOKEN_TYPE_COMMA:
                return "COMMA";
            case STX_TOKEN_TYPE_COLON:
                return "COLON";
            case STX_TOKEN_TYPE_SEMICOLON:
                return "SEMICOMMA";
            case STX_TOKEN_TYPE_QUOTE:
                return "QUOTE";
            case STX_TOKEN_TYPE_DOUBLE_QUOTE:
                return "DOUBLE_QUOTE";
            case STX_TOKEN_TYPE_STAR:
                return "STAR";
            case STX_TOKEN_TYPE_TILDA:
                return "TILDA";
            case STX_TOKEN_TYPE_BACKCLASH:
                return "BACKCLASH";
            case STX_TOKEN_TYPE_MORE:
                return "MORE";
            case STX_TOKEN_TYPE_LESS:
                return "LESS";
            case STX_TOKEN_TYPE_EXCLAMATION:
                return "EXCLAMATION";
            case STX_TOKEN_TYPE_QUESTION:
                return "QUESTION";
            case STX_TOKEN_TYPE_INVALID:
                return "INVALID";
            case STX_TOKEN_TYPE_EOF:
                return "EOF";
            case STX_TOKEN_TYPE_MAX_ENUM:
            default:
                SXT_HPP_ASSERT(false);
                return "";
        }
    }
    const wchar_t* token_type_to_wstring(token_type tt) {
        switch (tt) {
            case STX_TOKEN_TYPE_WORD:
                return L"WORD";
            case STX_TOKEN_TYPE_FLOAT:
                return L"FLOAT";
            case STX_TOKEN_TYPE_INTEGER:
                return L"INTEGER";
            case STX_TOKEN_TYPE_STRING_LETTERAL:
                return L"STRING LETTERAL";
            case STX_TOKEN_TYPE_PLUS:
                return L"PLUS";
            case STX_TOKEN_TYPE_MINUS:
                return L"MINUS";
            case STX_TOKEN_TYPE_ASSIGN:
                return L"ASSIGN";
            case STX_TOKEN_TYPE_LPAREN:
                return L"LPAREN";
            case STX_TOKEN_TYPE_RPAREN:
                return L"RPAREN";
            case STX_TOKEN_TYPE_LCURLY:
                return L"LCURLY";
            case STX_TOKEN_TYPE_RCURLY:
                return L"RCURLY";
            case STX_TOKEN_TYPE_DOT:
                return L"DOT";
            case STX_TOKEN_TYPE_COMMA:
                return L"COMMA";
            case STX_TOKEN_TYPE_COLON:
                return L"COLON";
            case STX_TOKEN_TYPE_SEMICOLON:
                return L"SEMICOMMA";
            case STX_TOKEN_TYPE_QUOTE:
                return L"QUOTE";
            case STX_TOKEN_TYPE_DOUBLE_QUOTE:
                return L"DOUBLE_QUOTE";
            case STX_TOKEN_TYPE_STAR:
                return L"STAR";
            case STX_TOKEN_TYPE_TILDA:
                return L"TILDA";
            case STX_TOKEN_TYPE_BACKCLASH:
                return L"BACKCLASH";
            case STX_TOKEN_TYPE_MORE:
                return L"MORE";
            case STX_TOKEN_TYPE_LESS:
                return L"LESS";
            case STX_TOKEN_TYPE_EXCLAMATION:
                return L"EXCLAMATION";
            case STX_TOKEN_TYPE_QUESTION:
                return L"QUESTION";
            case STX_TOKEN_TYPE_INVALID:
                return L"INVALID";
            case STX_TOKEN_TYPE_EOF:
                return L"EOF";
            case STX_TOKEN_TYPE_MAX_ENUM:
            default:
                SXT_HPP_ASSERT(false);
                return L"";
        }
    }
};

#endif //ifndef SXT_STX_HEAD_HPP_
