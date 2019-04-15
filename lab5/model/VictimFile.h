//
// Created by dani on 3/27/19.
//

#ifndef LAB5_VICTIMFILE_H
#define LAB5_VICTIMFILE_H

#include <string>
#include <ostream>
#include <istream>

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

        friend ostream &operator<<(ostream &outputStream, const VictimFile &file);
        friend istream& operator>>(std::istream& inStream, VictimFile& victimFile);

        /**
        * Format self as a string containing member data.
        * @return
        */
        string toPlainString();

        string getName() { return victimName; };
        string getPlaceOfOrigin() { return placeOfOrigin; };
        int getAge() { return age; };
        string getPhotograph() { return photograph; };
        VictimFile& operator=(const VictimFile &victimFile){
            victimName = victimFile.victimName;
            placeOfOrigin = victimFile.placeOfOrigin;
            age = victimFile.age;
            photograph = victimFile.photograph;
            return *this;
        }



};


#endif //LAB5_VICTIMFILE_H
