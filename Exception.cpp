#include "Exception.h"

namespace ds
{

Exception::Exception(std::string_view err): _err(std::move(err)) {}

char const* Exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW 
{ 
    return _err.data(); 
}
    
}
