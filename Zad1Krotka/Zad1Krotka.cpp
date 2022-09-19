#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

std::tuple<std::string, int, float> returnThree(std::string s, int i, float f)
{
    return std::make_tuple (s, i, f);
}

struct Patient
{
public:
    std::string _name = {};
    std::string _surname = {};
    int _PESEL = 0;
    float _height = 0.0f;
    int _weight = 0;

    Patient(std::string name, std::string surname, int PESEL, float height, int weight)
        : _name(name),
        _surname(surname),
        _PESEL(PESEL),
        _height(height),
        _weight(weight)
    {}
};

class MedicalRecord
{
private:
    std::vector<Patient> patients;
public:
    MedicalRecord() = default;
    virtual ~MedicalRecord() = default;

    void addPatient(Patient p)
    {
        patients.push_back(p);
    }
    std::tuple<std::string, float, int> getPatientData(int pesel)
    {
        auto patient = std::find_if(patients.cbegin(), patients.cend(), [pesel](auto p) { return p._PESEL == pesel; });
        return std::make_tuple(patient->_name, patient->_height, patient->_weight);
    }
};

int main()
{
    Patient p1("Sean", "Brown", 12345, 1.85f, 85);
    MedicalRecord mr;
    mr.addPatient(p1);
    auto krotka1 = mr.getPatientData(12345);

    std::cout 
        << "Name:" << std::get<0>(krotka1) 
        << " Height:" << std::get<1>(krotka1) 
        << " Weight:" << std::get<2>(krotka1) 
        << std::endl;

    
    auto krotka = returnThree("Hi", 5, 5.5f);
    int value = std::get<1>(krotka);
    std::cout << value << std::endl;

}
