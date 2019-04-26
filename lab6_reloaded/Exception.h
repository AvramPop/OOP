//
// Created by dani on 4/26/19.
//

#ifndef LAB6_RELOADED_EXCEPTION_H
#define LAB6_RELOADED_EXCEPTION_H


#include <bits/exception.h>

class RepositoryException : public std::exception {};
class ValidatorException : public std::exception {};
class FileException : public std::exception {};


#endif //LAB6_RELOADED_EXCEPTION_H
