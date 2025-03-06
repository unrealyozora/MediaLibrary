#include "JsonWriter.h"

void JsonWriter::readObject(std::shared_ptr<AbstractItem> obj){
    obj->accept(this->jvisitor);
}

JsonVisitor JsonWriter::getVisitor() {
    return this->jvisitor;
}
