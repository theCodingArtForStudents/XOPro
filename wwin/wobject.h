#ifndef WOBJECT_H
#define WOBJECT_H

#include <windows.h>
#include <string>
#include <list>

namespace WObjectType {
    enum WObjectType{
        Object,
        Widget
    };
}

class WObject
{
private:
    WObject *_parent;
    std::string _objectName;

    HWND _hwnd = nullptr;

    std::list<WObject> _childrens;

protected:
    void setHwnd(HWND hwnd);
public:
    WObject(WObject *parent);
    virtual ~WObject();

    HWND hwnd() const;

    WObjectType::WObjectType _type = WObjectType::Object;

    void setObjectName(std::string &name);

    void setType(WObjectType::WObjectType type);
    WObjectType::WObjectType type() const;

    void setParent(WObject* parent);
    WObject* parent() const;

//    virtual bool event(WEvent *e);
//    virtual bool eventFilter(WObject *watched, WEvent *event);
    void removeEventFilter(WObject* obj);

    // опции и рекурсивно
    WObject* findChild(const std::string &name) const;
    std::list<WObject*> children() const;
    std::list<WObject*> findChildren(const std::string &name) const;

//    std::string tr(const char *sourceText, constChar *disambiguation = nullptr, int n = -1);
    static LPWSTR tow( const std::string& s );
};

#endif // WOBJECT_H
