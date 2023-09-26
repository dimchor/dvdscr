#pragma once

#include <concepts>
#include <cstdlib>

namespace ds
{

template<std::integral Integer>
Integer random(Integer lb, Integer ub)
{
    return lb + (std::rand() % (ub - lb + 1));
}

}
