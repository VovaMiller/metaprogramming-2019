#pragma once
#include "NullType.hpp"
#include "TypeManip.hpp"

////////////////////////////////////////////////////////////////////////////////
// Typelist definition
////////////////////////////////////////////////////////////////////////////////
template <typename... Ts>
struct Typelist {
      // using type = tlist;
};

namespace TL {

////////////////////////////////////////////////////////////////////////////////
// TypeAt
// @param TList     Typelist
// @param index     position of Type to get
// ::result         Type from Typelist at specified index.
////////////////////////////////////////////////////////////////////////////////
    template <typename TList, unsigned int index> struct TypeAt;

    template <typename Head, typename... Tail>
    struct TypeAt<Typelist<Head, Tail...>, 0> {
        using result = Head;
    };

    template <typename Head, typename... Tail, unsigned int i>
    struct TypeAt<Typelist<Head, Tail...>, i> {
        using result = typename TypeAt<Typelist<Tail...>, i - 1>::result;
    };

////////////////////////////////////////////////////////////////////////////////
// TypeExists
// @param TList     Typelist
// @param T         Type to search in TList
// ::result         1 if TList contains T;
//                  0 if TList doesn't contain T.
////////////////////////////////////////////////////////////////////////////////
    template <typename TList, typename T> struct TypeExists;

    template <typename T, typename... Tail>
    struct TypeExists<Typelist<T, Tail...>, T> {
        enum { result = 1 };
    };

    template <typename Head, typename... Tail, typename T>
    struct TypeExists<Typelist<Head, Tail...>, T> {
        enum { result = TypeExists<Typelist<Tail...>, T>::result };
    };

    template <typename T>
    struct TypeExists<Typelist<>, T> {
        enum { result = 0 };
    };

////////////////////////////////////////////////////////////////////////////////
// ListWithType
// @param TList     Typelist of typelists
// @param T         Type to search among typelists in TList
// ::result         The first Typelist from TList containing T if exists;
//                  NullType otherwise.
////////////////////////////////////////////////////////////////////////////////
    template <typename TList, typename T> struct ListWithType;

    template <typename Head, typename... Tail, typename T>
    struct ListWithType<Typelist<Head, Tail...>, T> {
        using result = typename std::conditional<
            TypeExists<Head, T>::result,
            Head,
            typename ListWithType<Typelist<Tail...>, T>::result
        >::type;
    };

    template <typename T>
    struct ListWithType<Typelist<>, T> {
        using result = NullType;
    };

////////////////////////////////////////////////////////////////////////////////
// Append
// @param TList     Typelist
// @param T         Type to append to TList
// ::result         Typelist with types from TList and appended type T
////////////////////////////////////////////////////////////////////////////////
    template <typename TList, typename T> struct Append;

    template <typename... Ts, typename T>
    struct Append<Typelist<Ts...>, T> {
        using result = Typelist<Ts..., T>;
    };

////////////////////////////////////////////////////////////////////////////////
// Reverse
// @param TList     Typelist
// ::result         Reversed TList
////////////////////////////////////////////////////////////////////////////////
    template <typename TList> struct Reverse;

    template <typename Head, typename... Tail>
    struct Reverse<Typelist<Head, Tail...> > {
        using ReversedTail = typename Reverse<Typelist<Tail...> >::result;
        using result = typename Append<ReversedTail, Head>::result;
    };

    template <>
    struct Reverse<Typelist<> > {
        using result = Typelist<>;
    };

////////////////////////////////////////////////////////////////////////////////
// GetTail
// @param TList     Typelist with at least 1 type
// ::result         TList without the first type
////////////////////////////////////////////////////////////////////////////////
    template <typename TList> struct GetTail;

    template <typename Head, typename... Tail>
    struct GetTail<Typelist<Head, Tail...> > {
        using result = Typelist<Tail...>;
    };

////////////////////////////////////////////////////////////////////////////////
// GetSupers
// @param TLists    Set of typelists
// ::result         Typelist from TList with highest classes in hierarchy tree,
//                  calculating by the first class in each typelist.
//                  We suppose that each typelist consists of classes
//                  on the same level of hierarchy tree and in specific order,
//                  so that we can find necessary typelist by checking just
//                  the first classes.
////////////////////////////////////////////////////////////////////////////////
    template <typename... TLists> struct GetSupers;

    template <typename Head, typename... Tail, typename TList, typename... OthersTLists>
    struct GetSupers<Typelist<Head, Tail...>, TList, OthersTLists...> {
        using OthersRes = typename GetSupers<TList, OthersTLists...>::result;
        using OthersResHead = typename TypeAt<OthersRes, 0>::result;
        using result = typename std::conditional<
            SUPERSUBCLASS(Head, OthersResHead),
            Typelist<Head, Tail...>,
            OthersRes
        >::type;
    };

    template <typename TList>
    struct GetSupers<TList> {
        using result = TList;
    };

}  // namespace TL
