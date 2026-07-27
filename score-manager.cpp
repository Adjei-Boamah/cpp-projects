#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int size;
    do {
        cout<<"Enter the class size or number of students in the class"<<endl;
        cin>>size;
    }while ( size < 10 || size > 20);
    cin.ignore();
    if (size > 20) {
        cout<<"The maximum class size is 20."<<endl;
        return 1;
    }
    string studentNames[20]={"Amuzu NATHAN","Richmond BEKOE","Braimah BOAKYE","Michael OPOKU","Aheto MORRIS","Ampofo JOSEPH","Gifty ACHAMPONG","Mensah DAVID","Rodney KWEI","Oryeh EMMANUEL"};

    int scores[20]={63,90,78,88,76,83,92,75,81,95};
    int idNumber[20] = {217622,217623,217624,217625,217626,217627,217628,217629,217630,217631};
    char grade;
    float total = 0;
    string name;

    int i,j;
    //To add another student to the list
    cout<<"TO ADD ANOTHER STUDENT TO THE LIST"<<endl;
    int p = 10;
    do {

        cout<<"Student Name"<<endl;
        getline(cin,studentNames[p]);
        if (studentNames[p].empty()) {
            break;
        }

        cout<<"Student ID"<<endl;
        cin>>idNumber[p];

        cout<<"Student Score"<<endl;
        cin>>scores[p];
        cin.ignore();

        p++;
    }while ( p < size);


    int x =1;
    // displaying the names student_id  and scores of the students with their grades...............................
    cout<<"STUDENT NAME "<<"    STUDENT ID NUMBER"<<"      SCORES"<<"       GRADE"<<endl;
    for ( i = 0; i < size;i++) {
        if (scores[i] >= 80) {
            grade = 'A';
        }else if (scores[i] >= 70) {
            grade = 'B';
        }else if (scores[i] >= 60) {
            grade = 'C';
        }else if (scores[i] >= 50) {
            grade = 'D';
        }else if (scores[i] < 50) {
            grade = 'F';
        }

        cout<<x <<". "
            <<studentNames[i]
            <<":       "
            <<idNumber[i]
            << "             "
            <<scores[i]
            <<"         "
            <<grade
        <<endl;

        x++;
    }
  // getting the highest score from the list
    int max = scores[0];
    int maxId = 0;
    for ( i = 0; i < size;i++) {

        if (max < scores[i]) {
            max = scores[i];
            maxId = i;
        }

    }
    cout<<"The student with the highest score is "<<studentNames[maxId]<<" "<<idNumber[maxId]<<"  "<<max<<endl;

    //getting the least score from the list
    int min = scores[0];
    int minId = 0;
    for ( i = 0; i < size;i++) {

        if (min > scores[i]) {
            min = scores[i];
            minId = i;
        }

    }

    cout<<"The student with the lowest score is "<<studentNames[minId]<<" "<<idNumber[minId]<<"  "<<min<<endl;
    // calculating the average score of the class
   cout<<"THE AVERAGE SCORE OF THE CLASS"<<endl;
    for ( i = 0; i < size ;i++) {
        total += scores[i];
    }
    cout<<"The average score is "<<total/size<<endl;

    //implementing the search the student using their names
    bool found = false;
    cout<<"Enter the student name you are looking for: "<<endl;
    getline(cin,name);

    for ( i = 0; i < size;i++) {
        if (studentNames[i] == name) {
            found =true;
            cout<<name
                 <<"    ID:  "
                 <<idNumber[i]
                 <<"   SCORE:  "
                 <<scores[i]
            <<endl;
        }
    }
    if (!found) {
        cout<<"Student not in the list"<<endl;
    }

    //sorting the list from the highest score to  the lowest score
    for ( i = 0; i < size;i++) {
        for (  j = 0 ; j < i;j++) {
            if (scores[j] < scores[i]) {
                swap(scores[i],scores[j]);
                swap(idNumber[i],idNumber[j]);
                swap(studentNames[i],studentNames[j]);
            }
        }
    }
    // Displaying the sorted list of students
    cout << "STUDENTS SORTED BY SCORE (HIGHEST TO LOWEST)"<<endl;

    for( i = 0; i < size; i++)
    {
        cout << studentNames[i]
             << "      "
             << idNumber[i]
             << "     "
             << scores[i]
        << endl;
    }

    return 0;
}