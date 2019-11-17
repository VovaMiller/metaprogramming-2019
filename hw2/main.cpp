////////////////////////////////////////////////////////////////////////////////
// Testing GetAbstractFactory.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Typelist.hpp"
#include "AbstractFactoryGenerator.hpp"
#include "Product.hpp"

int main() {

    using MyFactoryHierarchy = GetAbstractFactory<
        3, 5,
        Typelist<Chair, Table, Sofa>,
        Typelist<WoodenChair, WoodenTable, WoodenSofa>,
        Typelist<MetalChair, MetalTable, MetalSofa>,
        Typelist<MetalRichChair, MetalRichTable, MetalRichSofa>,
        Typelist<MetalPoorChair, MetalPoorTable, MetalPoorSofa>
    >;
    MyFactoryHierarchy::Factory* MyFactory;
    Sofa* sofa;
    Table* table;
    Chair* chair;

    ////////////////////////////////////////////////////////////////////////////

    MyFactory = new MyFactoryHierarchy::GetConcreteFactory<MetalRichChair>::result;
    sofa = MyFactory->Get<Sofa>();
    table = MyFactory->Get<Table>();
    chair = MyFactory->Get<Chair>();

    std::cout << "MetalRichSofa = ";
    sofa->identify();
    std::cout << "MetalRichTable = ";
    table->identify();
    std::cout << "MetalRichChair = ";
    chair->identify();

    delete sofa;
    delete table;
    delete chair;
    delete MyFactory;

    ////////////////////////////////////////////////////////////////////////////

    MyFactory = new MyFactoryHierarchy::GetConcreteFactory<Table>::result;
    sofa = MyFactory->Get<Sofa>();
    table = MyFactory->Get<Table>();
    chair = MyFactory->Get<Chair>();

    std::cout << "Sofa = ";
    sofa->identify();
    std::cout << "Table = ";
    table->identify();
    std::cout << "Chair = ";
    chair->identify();

    delete sofa;
    delete table;
    delete chair;
    delete MyFactory;

    ////////////////////////////////////////////////////////////////////////////

    MyFactory = new MyFactoryHierarchy::GetConcreteFactory<WoodenSofa>::result;
    sofa = MyFactory->Get<Sofa>();
    table = MyFactory->Get<Table>();
    chair = MyFactory->Get<Chair>();

    std::cout << "WoodenSofa = ";
    sofa->identify();
    std::cout << "WoodenTable = ";
    table->identify();
    std::cout << "WoodenChair = ";
    chair->identify();

    delete sofa;
    delete table;
    delete chair;
    delete MyFactory;

    ////////////////////////////////////////////////////////////////////////////

    MyFactory = new MyFactoryHierarchy::GetConcreteFactory<MetalPoorChair>::result;
    sofa = MyFactory->Get<Sofa>();
    table = MyFactory->Get<Table>();
    chair = MyFactory->Get<Chair>();

    std::cout << "MetalPoorSofa = ";
    sofa->identify();
    std::cout << "MetalPoorTable = ";
    table->identify();
    std::cout << "MetalPoorChair = ";
    chair->identify();

    delete sofa;
    delete table;
    delete chair;
    delete MyFactory;

    ////////////////////////////////////////////////////////////////////////////


    return 0;
}
