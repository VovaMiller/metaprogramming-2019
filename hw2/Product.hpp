class Product {
public:
    Product() : id("Product") {}

    void identify() {
        std::cout << id << std::endl;
    }

protected:
    std::string id;
};


class Chair : public Product {
public:
    Chair() { id = "Chair"; }
};

class Table : public Product {
public:
    Table() { id = "Table"; }
};

class Sofa : public Product {
public:
    Sofa() { id = "Sofa"; }
};


class WoodenChair : public Chair {
public:
    WoodenChair() { id = "WoodenChair"; }
};

class WoodenTable : public Table {
public:
    WoodenTable() { id = "WoodenTable"; }
};

class WoodenSofa : public Sofa {
public:
    WoodenSofa() { id = "WoodenSofa"; }
};


class MetalChair : public Chair {
public:
    MetalChair() { id = "MetalChair"; }
};

class MetalTable : public Table {
public:
    MetalTable() { id = "MetalTable"; }
};

class MetalSofa : public Sofa {
public:
    MetalSofa() { id = "MetalSofa"; }
};


class MetalRichChair : public MetalChair {
public:
    MetalRichChair() { id = "MetalRichChair"; }
};

class MetalRichTable : public MetalTable {
public:
    MetalRichTable() { id = "MetalRichTable"; }
};

class MetalRichSofa : public MetalSofa {
public:
    MetalRichSofa() { id = "MetalRichSofa"; }
};


class MetalPoorChair : public MetalChair {
public:
    MetalPoorChair() { id = "MetalPoorChair"; }
};

class MetalPoorTable : public MetalTable {
public:
    MetalPoorTable() { id = "MetalPoorTable"; }
};

class MetalPoorSofa : public MetalSofa {
public:
    MetalPoorSofa() { id = "MetalPoorSofa"; }
};
