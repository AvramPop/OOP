//
// Created by dani on 3/27/19.
//

#ifndef LAB5_VICTIMFILE_H
#define LAB5_VICTIMFILE_H

#include <string>
#include <ostream>

using namespace std;

class VictimFile {
    friend class Test;
    private:
        string victimName;
        string placeOfOrigin;
        int age;
        string photograph;

    public:
        VictimFile(string victimName, string placeOfOrigin, int age, string photograph);

        VictimFile();

        VictimFile(string name);

        bool operator==(const VictimFile &rhs) const;

        bool operator!=(const VictimFile &rhs) const;

        friend ostream &operator<<(ostream &os, const VictimFile &file);
};


#endif //LAB5_VICTIMFILE_H
