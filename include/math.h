#pragma once

#include <climits>

namespace math {

struct Result {
    bool error = true;
    int result;
};

inline Result add (int x, int y){
    if (y > 0 && x > INT_MAX - y){
        return Result{};
    }
    if (y < 0 && x < INT_MIN - y){
        return Result{};
    }
    return Result{.error = false, .result = x + y};
}   

inline Result sub(int x, int y) {
    if (y > 0 && x < INT_MIN + y){
        return Result{};
    }
    if (y < 0 && x > INT_MAX + y){
        return Result{};
    }
    return Result{.error = false, .result = x - y};
}

inline Result mul(int x, int y){
    if (x == 0 || y == 0){
        return Result{.error = false, .result = 0};
    }
    if (x == INT_MIN && y == -1){
        return Result{};
    }
    if (x == -1 && y == INT_MIN){
        return Result{};
    }
    if (x > 0){
        if (y > 0 && x > INT_MAX / y){
            return Result{};
        }
        if (y < 0 && y != -1 && x > INT_MIN / y) {
            return Result{};
        }
    } else {
        if (y > 0 && x < INT_MIN / y){
            return Result{};
        }
        if (y < 0 && x < INT_MAX / y) {
            return Result{};
        }
    }
    return Result{.error = false, .result = x * y};
}

inline Result div(int x, int y){
    if (y == 0){
        return Result{};
    }
    if (x == INT_MIN && y == -1){
        return Result{};
    }
    return Result{.error = false, .result = x / y};
}

inline Result pow(int x, int y){
    if (y < 0){
        return Result{};
    }
    if (y == 0 || x == 1){
        return Result{.error = false, .result = 1};
    }
    if (x == -1) {
        return Result{.error = false, .result = (y % 2 == 0 ? 1 : -1)};
    }
    int result = x;
    for (int i = 1; i < y; ++i){
        if (x > 0 && result > INT_MAX / x){
            return Result{};
        }
        if (x < 0){
            if (result > 0 && result > INT_MIN / x){
                return Result{};
            }
            if(result < 0 && result < INT_MAX / x){
                return Result{};
            }
        }
        result *= x;
    }
    return Result{.error = false, .result = result};
}

inline Result factorial(int x){
    if (x < 0){
        return Result{};
    }
    if (x <= 1){
        return Result{.error = false, .result = 1};
    }

    Result sub = factorial(x - 1);
    if(sub.error){
        return Result{};
    }
    if (sub.result > INT_MAX / x){
        return Result{};
    }
    return Result{.error = false, .result = x * sub.result};
}

} // math