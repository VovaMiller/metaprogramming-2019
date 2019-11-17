#pragma once

////////////////////////////////////////////////////////////////////////////////
// Conversion
// @param T         conversion from
// @param U         conversion to
// ::exists         1, if conversion is possible;
//                  0, otherwise.
////////////////////////////////////////////////////////////////////////////////
template <class T, class U>
class Conversion {
    typedef char Small;
    class Big { char dummy[2]; };
    static Small Test(U);
    static Big Test(...);
    static T MakeT();
public:
    enum { exists = sizeof(Test(MakeT())) == sizeof(Small) };
    enum { sameType = false };
};

template <class T>
class Conversion<T, T> {
public:
    enum { exists = 1, sameType = 1 };
};

////////////////////////////////////////////////////////////////////////////////
// SUPERSUBCLASS
// @param T         potential Parent class
// @param U         potential Child class
// @return          true, if T is parent class of U;
//                  0, otherwise.
////////////////////////////////////////////////////////////////////////////////
#define SUPERSUBCLASS(T, U) \
    (Conversion<const U*, const T*>::exists && \
    !Conversion<const T*, const void*>::sameType)


////////////////////////////////////////////////////////////////////////////////
// Type2Type
// Helper for imitation of partial specialization of template functions.
////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct Type2Type {
    using type = T;
};
