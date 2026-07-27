#include <iostream>
using namespace std;

int main() {
    double mark;
    int creditHours;
    int totalCreditHours = 0.00;
    double totalMarks = 0.00;
    double allMarks = 0.00;
    double CWA = 0.00;
    int attempts = 0;

    while (true) {
        cout<<"Enter the Mark"<<endl;
        cin>>mark;
        if (mark==0 || mark < 0) {
            break;
        }
        cout<<"Enter the Credit Hours"<<endl;
        cin>>creditHours;
        totalMarks = mark * creditHours;
        totalCreditHours += creditHours;
        allMarks += totalMarks;
        attempts++;
        cout<<attempts<<endl;
    }
    if (totalCreditHours > 0) {

        CWA =allMarks/totalCreditHours;
        cout<<"Total credit hours is "<<totalCreditHours<<endl;
        cout<<"All marks is "<<allMarks<<endl;
        cout<<"CWA is "<<CWA<<endl;
    }else {
        cout<<"No value was entered "<<endl;
    }

    return 0;
}
