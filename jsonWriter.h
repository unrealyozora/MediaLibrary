#ifndef JSON_WRITER_H
#define JSON_WRITER_H
#include <memory>
#include <AbstractItem.h>
#include <JsonVisitor.h>
class JsonWriter{
private:
    static JsonVisitor jvisitor;
public:
    void readObject(std::shared_ptr<AbstractItem> obj);
    JsonVisitor getVisitor();
};
#endif