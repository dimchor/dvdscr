#pragma once

#include <exception>
#include <string_view>

namespace ds
{

class Exception: public std::exception
{
    public:
        Exception(std::string_view);
        char const* 
        what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

        Exception(Exception const&) = default;
        Exception& operator=(Exception const&) = default;
        Exception(Exception&&) = default;
        Exception& operator=(Exception&&) = default;
        virtual ~Exception() = default;

    private:
        std::string_view _err{};
};

}
