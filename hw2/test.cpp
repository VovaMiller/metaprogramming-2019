////////////////////////////////////////////////////////////////////////////////
// Ignore this file.
// This is backup of testing some specific functionalities.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Typelist.hpp"
#include "AbstractFactoryGenerator.hpp"
#include "Product.hpp"

// GenLinearHierarchy test
template <class T, class Base>
class Handler : public Base {
public:
    virtual void Check(Type2Type<T>) {
        T obj;
        obj.identify();
    }
};

int main() {
    ////////////////////////////////////////////////////////////////////////////
    // TL::TypeAt test
    ////////////////////////////////////////////////////////////////////////////
    // using MyTList = Typelist<int, double, std::string>;
    // using TypeInt = typename TL::TypeAt<MyTList, 0>::Result;
    // using TypeDouble = typename TL::TypeAt<MyTList, 1>::Result;
    // using TypeString = typename TL::TypeAt<MyTList, 2>::Result;
    //
    // TypeInt i = 5;
    // TypeDouble d = 5;
    // i /= 2;
    // d /= 2;
    // TypeString s = "okay okay";
    //
    // std::cout << i << std::endl;
    // std::cout << d << std::endl;
    // std::cout << s << std::endl;


    ////////////////////////////////////////////////////////////////////////////
    // TL::TypeExists test
    ////////////////////////////////////////////////////////////////////////////
    // if (TL::TypeExists<MyTList, int>::Result) {
    //     std::cout << "int +" << std::endl;
    // } else {
    //     std::cout << "int -" << std::endl;
    // }
    // if (TL::TypeExists<MyTList, double>::Result) {
    //     std::cout << "double +" << std::endl;
    // } else {
    //     std::cout << "double -" << std::endl;
    // }
    // if (TL::TypeExists<MyTList, float>::Result) {
    //     std::cout << "float +" << std::endl;
    // } else {
    //     std::cout << "float -" << std::endl;
    // }
    // if (TL::TypeExists<MyTList, char>::Result) {
    //     std::cout << "char +" << std::endl;
    // } else {
    //     std::cout << "char -" << std::endl;
    // }
    // if (TL::TypeExists<MyTList, MyTList>::Result) {
    //     std::cout << "MyTList +" << std::endl;
    // } else {
    //     std::cout << "MyTList -" << std::endl;
    // }


    ////////////////////////////////////////////////////////////////////////////
    // TL::ListWithType test
    ////////////////////////////////////////////////////////////////////////////
    // using IntList = Typelist<int, unsigned int>;
    // using FloatList = Typelist<float, double>;
    // using StringList = Typelist<char, std::string>;
    // using TTss = Typelist<IntList, FloatList, StringList>;
    //
    // using _IntList = typename TL::ListWithType<TTss, int>::result;
    // using _DoubleList = typename TL::ListWithType<TTss, double>::result;
    // using _CharList = typename TL::ListWithType<TTss, char>::result;
    //
    // typename TL::TypeAt<_IntList, 0>::result i = 5;
    // i /= 2;
    // typename TL::TypeAt<_DoubleList, 0>::result f;
    // typename TL::TypeAt<_DoubleList, 1>::result d = 5;
    // d /= 2;
    // std::cout << sizeof(f) << std::endl;
    // std::cout << sizeof(d) << std::endl;
    // std::cout << i << std::endl;
    // std::cout << d << std::endl;


    ////////////////////////////////////////////////////////////////////////////
    // SUPERSUBCLASS test
    ////////////////////////////////////////////////////////////////////////////
    // std::cout << "Product -> Table" << std::endl;
    // std::cout << SUPERSUBCLASS(Product, Table) << std::endl;
    //
    // std::cout << "Table -> Product" << std::endl;
    // std::cout << SUPERSUBCLASS(Table, Product) << std::endl;
    //
    // std::cout << "Sofa -> MetalSofa" << std::endl;
    // std::cout << SUPERSUBCLASS(Sofa, MetalSofa) << std::endl;
    //
    // std::cout << "MetalSofa -> Sofa" << std::endl;
    // std::cout << SUPERSUBCLASS(MetalSofa, Sofa) << std::endl;
    //
    // std::cout << "Chair -> Chair" << std::endl;
    // std::cout << SUPERSUBCLASS(Chair, Chair) << std::endl;
    //
    // std::cout << Conversion<Chair, Chair>::sameType << std::endl;
    // std::cout << Conversion<Chair, MetalChair>::sameType << std::endl;
    // std::cout << Conversion<Chair, Table>::sameType << std::endl;



    ////////////////////////////////////////////////////////////////////////////
    // TL::GetChild test
    ////////////////////////////////////////////////////////////////////////////
    // using MyList = Typelist<MetalChair, MetalTable, MetalSofa>;
    //
    // using MyChildTable = typename TL::GetChild<MyList, Table>::result;
    // using MyChildChair = typename TL::GetChild<MyList, Chair>::result;
    // using MyChildSofa = typename TL::GetChild<MyList, Sofa>::result;
    // using MyChildNone = typename TL::GetChild<MyList, MetalPoorChair>::result;
    //
    // Table* table = new MyChildTable();
    // std::cout << "MetalTable == ";
    // table->identify();
    // delete table;
    //
    // Chair* chair = new MyChildChair();
    // std::cout << "MetalChair == ";
    // chair->identify();
    // delete chair;
    //
    // Sofa* sofa = new MyChildSofa();
    // std::cout << "MetalSofa == ";
    // sofa->identify();
    // delete sofa;
    //
    // std::cout << "1 == ";
    // std::cout << Conversion<MyChildNone, NullType>::sameType << std::endl;




    ////////////////////////////////////////////////////////////////////////////
    // TL::Reverse test
    ////////////////////////////////////////////////////////////////////////////
    // using MyTList = Typelist<Sofa, Chair, Table>;
    // using MyTListReversed = typename TL::Reverse<MyTList>::result;
    // using T0 = typename TL::TypeAt<MyTListReversed, 0>::result;
    // using T1 = typename TL::TypeAt<MyTListReversed, 1>::result;
    // using T2 = typename TL::TypeAt<MyTListReversed, 2>::result;
    // T0 t0;
    // T1 t1;
    // T2 t2;
    // std::cout << "Table == ";
    // t0.identify();
    // std::cout << "Chair == ";
    // t1.identify();
    // std::cout << "Sofa == ";
    // t2.identify();



    ////////////////////////////////////////////////////////////////////////////
    // GenLinearHierarchy test
    ////////////////////////////////////////////////////////////////////////////
    // using MyHandler = GenLinearHierarchy<Typelist<Table, Chair, Sofa>, Handler>;
    // MyHandler obj;
    // std::cout << "Sofa == ";
    // (static_cast<Handler<Sofa, EmptyType>&>(obj)).Check(Type2Type<Sofa>());



    ////////////////////////////////////////////////////////////////////////////
    // AbstractFactory & ConcreteFactory test
    ////////////////////////////////////////////////////////////////////////////

    // using TListGeneral = Typelist<Table, Chair, Sofa>;
    // using TListConcrete = Typelist<MetalTable, MetalChair, MetalSofa>;
    //
    // using AF = AbstractFactory<TListGeneral>;
    // using AFC = ConcreteFactory<AF, ConcreteFactoryUnit, TListConcrete>;
    //
    // AFC afc;
    // std::cout << "MetalTable == ";
    // afc.Get<Table>()->identify();
    // std::cout << "MetalChair == ";
    // afc.Get<Chair>()->identify();
    // std::cout << "MetalSofa == ";
    // afc.Get<Sofa>()->identify();



    ////////////////////////////////////////////////////////////////////////////
    // TL::GetSupers test
    ////////////////////////////////////////////////////////////////////////////

    // using Supers1 = typename TL::GetSupers<
    //     Typelist<Chair, Table, Sofa>,
    //     Typelist<WoodenChair, WoodenTable, WoodenSofa>,
    //     Typelist<MetalChair, MetalTable, MetalSofa>,
    //     Typelist<MetalRichChair, MetalRichTable, MetalRichSofa>,
    //     Typelist<MetalPoorChair, MetalPoorTable, MetalPoorSofa>
    // >::result;
    // using Supers2 = typename TL::GetSupers<
    //     Typelist<WoodenChair, WoodenTable, WoodenSofa>,
    //     Typelist<MetalChair, MetalTable, MetalSofa>,
    //     Typelist<Chair, Table, Sofa>,
    //     Typelist<MetalRichChair, MetalRichTable, MetalRichSofa>,
    //     Typelist<MetalPoorChair, MetalPoorTable, MetalPoorSofa>
    // >::result;
    // using Supers3 = typename TL::GetSupers<
    //     Typelist<WoodenChair, WoodenTable, WoodenSofa>,
    //     Typelist<MetalChair, MetalTable, MetalSofa>,
    //     Typelist<MetalRichChair, MetalRichTable, MetalRichSofa>,
    //     Typelist<MetalPoorChair, MetalPoorTable, MetalPoorSofa>,
    //     Typelist<Chair, Table, Sofa>
    // >::result;
    //
    // typename TL::TypeAt<Supers1, 0>::result obj10;
    // typename TL::TypeAt<Supers1, 1>::result obj11;
    // typename TL::TypeAt<Supers1, 2>::result obj12;
    // typename TL::TypeAt<Supers2, 0>::result obj20;
    // typename TL::TypeAt<Supers2, 1>::result obj21;
    // typename TL::TypeAt<Supers2, 2>::result obj22;
    // typename TL::TypeAt<Supers3, 0>::result obj30;
    // typename TL::TypeAt<Supers3, 1>::result obj31;
    // typename TL::TypeAt<Supers3, 2>::result obj32;
    //
    // std::cout << "Chair == ";
    // obj10.identify();
    // std::cout << "Table == ";
    // obj11.identify();
    // std::cout << "Sofa == ";
    // obj12.identify();
    //
    // std::cout << "Chair == ";
    // obj20.identify();
    // std::cout << "Table == ";
    // obj21.identify();
    // std::cout << "Sofa == ";
    // obj22.identify();
    //
    // std::cout << "Chair == ";
    // obj30.identify();
    // std::cout << "Table == ";
    // obj31.identify();
    // std::cout << "Sofa == ";
    // obj32.identify();


    return 0;
}
