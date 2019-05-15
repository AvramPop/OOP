#ifndef VICTIMFILE_H
#define VICTIMFILE_H


#include <string>
using namespace std;
class VictimFile {
    friend class Test;

private:
    string victimName;
    string placeOfOrigin;
    int age;
    string photograph;
public:
    VictimFile();
    /**
     * Create victim file with whole info.
     */
    VictimFile(string victimName, string placeOfOrigin, int age, string photograph);
    /**
     * Create stub victim file only with names.
     */
    VictimFile(string name);
    //   ~VictimFile()= default;

    bool operator==(const VictimFile &rhs) const;

    bool operator!=(const VictimFile &rhs) const;
    friend ostream &operator<<(ostream &outputStream, const VictimFile &file);

    friend istream& operator>>(std::istream& inStream, VictimFile& victimFile);
    /**
        * Format self as a string containing member data.
        * @return
        */
    string getName() { return victimName; };
    string getPlaceOfOrigin() { return placeOfOrigin; };
    int getAge() { return age; };
    string getPhotograph() { return photograph; };
    /**
     * Get VictimFile as string in right format to be dumped into file
     * @return
     */
    string toFormattedString();
    VictimFile& operator=(const VictimFile& victimFile);
    VictimFile(const VictimFile& victimFile) : victimName(victimFile.victimName), placeOfOrigin(victimFile.placeOfOrigin), age(victimFile.age), photograph(victimFile.photograph){};
};


#endif // VICTIMFILE_H
