#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <bits/exception.h>

class RepositoryException : public std::exception {};
class ValidatorException : public std::exception {};

#endif // EXCEPTION_H
