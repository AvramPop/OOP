#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <memory>


template <typename TemplateClass>
class Repository {
protected:
    virtual int indexOfElement(TemplateClass element) = 0;
    std::vector<TemplateClass> buffer;
public:
    virtual void add(TemplateClass element) = 0;

    virtual std::vector<TemplateClass> asList() = 0;

    virtual bool containsElement(TemplateClass element) = 0;

    virtual void remove(TemplateClass element) = 0;

    virtual void update(TemplateClass element) = 0;

    virtual int getSize() = 0;

    virtual TemplateClass& at(int index) = 0;

    virtual ~Repository(){};

    virtual TemplateClass operator[](int index) = 0;

    virtual Repository* cloneImplementation() const = 0;

    auto clone() const { return std::unique_ptr<Repository<TemplateClass>>(cloneImplementation()); }


};


#endif // REPOSITORY_H
