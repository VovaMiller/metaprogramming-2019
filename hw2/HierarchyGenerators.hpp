#pragma once

#include "Typelist.hpp"
#include "EmptyType.hpp"

////////////////////////////////////////////////////////////////////////////////
// GenScatterHierarchy
// Classic Scatter Hierarchy generator.
////////////////////////////////////////////////////////////////////////////////
template <typename TList, template <class> class Unit>
class GenScatterHierarchy;

template <typename Head, typename... Tail, template <class> class Unit>
class GenScatterHierarchy<Typelist<Head, Tail...>, Unit> :
    public GenScatterHierarchy<Head, Unit>,
    public GenScatterHierarchy<Typelist<Tail...>, Unit> {
public:
    using TList = Typelist<Head, Tail...>;
    using LeftBase = GenScatterHierarchy<Head, Unit>;
    using RightBase = GenScatterHierarchy<Typelist<Tail...>, Unit>;
};

template <typename AtomicType, template <class> class Unit>
class GenScatterHierarchy : public Unit<AtomicType> {
public:
    using LeftBase = Unit<AtomicType>;
};

template <template <class> class Unit>
class GenScatterHierarchy<Typelist<>, Unit> {};


////////////////////////////////////////////////////////////////////////////////
// GenLinearHierarchy
// Classic Linear Hierarchy generator.
////////////////////////////////////////////////////////////////////////////////

template <
    typename TList,
    template <class AtomicType, class Base> class Unit,
    typename Root = EmptyType
> class GenLinearHierarchy;

template <
    typename Head,
    typename Head2,  // here we suppose that TList has at least 2 types
    typename... Tail,
    template <class, class> class Unit,
    typename Root
> class GenLinearHierarchy<Typelist<Head, Head2, Tail...>, Unit, Root>
    : public Unit<Head, GenLinearHierarchy<Typelist<Head2, Tail...>, Unit, Root> > {};

template <
    typename T,
    template <class, class> class Unit,
    typename Root
> class GenLinearHierarchy<Typelist<T>, Unit, Root>
    : public Unit<T, Root> {};
