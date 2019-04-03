//
// Created by dani on 3/27/19.
//

#ifndef LAB5_VICTIMFILE_H
#define LAB5_VICTIMFILE_H

#include <string>
#include <ostream>

using namespace std;
/**
 * Class modeling the file of a victim.
 */
class VictimFile {
    friend class Test;
    private:
        string victimName;
        string placeOfOrigin;
        int age;
        string photograph;

    public:
    /**
     * Create victim file with whole info.
     */
        VictimFile(string victimName, string placeOfOrigin, int age, string photograph);
    /**
     * Create stub victim file with empty members.
     */
        VictimFile();
    /**
     * Create stub victim file only with names.
     */
        VictimFile(string name);

        bool operator==(const VictimFile &rhs) const;

        bool operator!=(const VictimFile &rhs) const;

        friend ostream &operator<<(ostream &os, const VictimFile &file);
    /**
     * Format self as a string containing member data.
     * @return
     */
        string toPlainString();

        string getName() { return victimName; };
        string getPlaceOfOrigin() { return placeOfOrigin; };
        int getAge() { return age; };
        string getPhotograph() { return photograph; };
};


#endif //LAB5_VICTIMFILE_H
