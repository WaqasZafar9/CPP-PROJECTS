#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<ctime>


using namespace std;
//parent class
class Student {
protected:
    ////Data Members
    string name;
    string Gender;
    string phone;
    string Email;
    int roll_no;
    string Degree;
    int Matric_Marks;
    int Inter_mark;
    int total;

    int Scholarship;
    int total_fee;
    int tution_fee;
    int misscallaneuos;
    

public:
    ////Default Constructor
    Student() {

        name = "";
        Email = "";
        Gender = "";
        phone = "";
        roll_no = 3000;
        Matric_Marks = 0;
        Inter_mark = 0;
        total = 0;
        Scholarship = 0;
        total_fee = 0;
        Degree = "";
    }

};
////Multilevel inheritance
class Pass :public Student {
protected:
    int passkey;
    int attempt;
public:
    Pass() {
        passkey = 1234;
        attempt = 0;
    }
    bool password() {  /////Password Check
        int choice;
        cout << "\n\n\t\tENTER PASSWORD TO LOGIN IN =";
        cin >> choice;
        passe();
        if (choice == passkey) {
            cout << "\n\n\t\tLogin successfully " << endl;
            
            attempt = 0;
            return true;
        }
        else {

            attempt++;
            cout << "\n\n\t\tWrong PassWord .Enter Correct Password " << endl;
            if (attempt == 2) {
                check_human();    /////Verify Human
            }
            if (attempt == 3) {
                cout << "\n\n\t\tToo Many Attempts";
                exit(0);
            }
            password();  ///calling Function
        }
    }
    void check_human() {
        srand(time(0));     ///Time in seconds
        cout << "\n\t\tAre u Human " << endl;
        cout << "\n\t\tEnter Code" << endl;
        int r = 1 + rand();       ////taking random number
        cout << "\t\t" << r << endl;
        int a;
        cout << "\t       ->";
        cin >> a;
        if (a == r) {
            cout << "\n\t\tVerified" << endl;
            password();
        }
        else {
            cout << "\n\n\t\tWrong Entry";
            check_human();
        }
    }

    void passe() {
        ifstream read;    /////Reading Saved password from file
        read.open("Pass.txt");
        if (!read.fail()) {
            read >> passkey;
        }
        read.close();
    }
    bool change_pass() {
        int pre;
        cout << "Enter Previous Password" << endl;
        cin >> pre;

        if (pre == passkey) {
            cout << "Enter New password" << endl;
            cin >> passkey;
            ofstream in;
            in.open("Pass.txt");    
            if (in.is_open()) {
                cout << "Password Succesfully Changed" << endl;
                attempt = 0;
                in << passkey;  ////saving Password in file
                in.close();
                return true;
            }
        }
        else if (attempt > 1) {
            cout << "Too Much Wrong Attempt" << endl;
            return false;
        }
        else {
            attempt++;
            cout << "Wrong Password" << endl;
            change_pass();
        }

    }
   



};

//////Multi Level Inheritance
class Form : public Pass {
private:
    int After_Scholarship;
public:
    //////Default Constructor
    Form(){
        After_Scholarship = 0;
    }
    void Welcome() {

        system("cls");      /////clearing screen    
        
        cout << "\t\t\t\t---------------------------------------------" << endl;
        cout << "\t\t\t\t-------Welcome to University Admission-------" << endl;
        cout << "\t\t\t\t---------------------------------------------" << endl;



        cout << "\n\n\n\n\n";
        cout << "\t\t\t Loading";
        char y = 219;
        for (int a = 0; a < 30; a++) {
            cout << y;
            Sleep(100);

        }

        system("cls");
        menu();     /////Calling Menu function
    }
    void insert() {

        system("cls");
        
        
        /// Taking User Data
        
        
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\t--------Welcome to Admission Form----------" << endl;
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\tEnter Your Name :";
        cin >> name;
        cout << "\t\t\tEnter Your Gender : ";
        cin >> Gender;
        cout << "\t\t\tEnter Your Email :";
        cin >> Email;
        cout << "\t\t\tEnter Your phone :";
        cin >> phone;
        roll_no++;
        

        system("cls");

        
        cout << "\n------------------------------------------------------------------------------------------------------------";
        cout << "\n------------------------------------- Students Courses -----------------------------------------------------" << endl;
        
        /////Selection of Course

        cout << "\n\t\t\tEnter Your Course Which Do you want To Study------" << endl;
        cout << "\n\t\t\t (1) For  BS Computer Science  Press  1   ---" << endl;
        cout << "\n\t\t\t (2) For  BS Software Engeneering press 2 ----" << endl;
        cout << "\n\t\t\t (3) For  BS Cyber Security press 3       -----" << endl;



        course();

        /////Writing user Data in files
        ofstream myfile;
        myfile.open("StudentRecord.txt", ios::app);

        myfile <<  "\n" << roll_no<<"\n";
        myfile <<  name << "\n";
        myfile <<  Gender << "\n";
        myfile <<  Email << "\n";
        myfile <<  phone << "\n";
        myfile <<Degree << "\n";
        myfile << Matric_Marks << "\n";
        myfile << Inter_mark << "\n";
        myfile << After_Scholarship ;

        myfile.close();
        
        ofstream myfile2;
        
        myfile2.open("id1.txt");
        myfile2 << roll_no;         /// Writing Roll no used
        myfile2.close();
        cout << "\n\tData save to file";
        char X;
        cout << "\n\t\tDo You want To add More data? (Y/N)  : ";
        cin >> X;

        if (X == 'n' || X == 'N') {
            cout << "\n\t\tGoing Back To Main Menu " << endl;
            Sleep(1000);
            menu();
        }
        if (X == 'y' || X == 'Y') {
            insert();
        }

    }
    void course() {
        int choice;
        cout << "\n\t\t\tEnter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            /////Adding Scholarship and checking Eligiblity
            system("cls");
            Degree = "BSCS";
            total_fee = 87100;
            tution_fee = 56000;
            misscallaneuos = 31100;
            After_Scholarship = total_fee;

            getMarks("BS Computer Science");    ////Checking Marks whether in range or not
            
            if (Inter_mark <= 900 && Inter_mark > 800 && Matric_Marks > 550) {        ///checking  Marks for eligiblity to take admission and scholarship
                feewave(75,"BS Computer Science");
            }

            else if (Inter_mark >= 900 && Inter_mark <= 1100 && Matric_Marks > 550) {
                feewave(100, "BS Computer Science");

            }
            else if (Inter_mark <= 800 && Inter_mark >= 700 && Matric_Marks>550) {
                feewave(50, "BS Computer Science");
            }
            else if (Inter_mark < 700 && Inter_mark >= 550 && Matric_Marks>550) {
                no_wave("BS Computer Science");

            }
            else {
                cout << "\n\t\tSorry you are not eligible to take admission.less than 50% Marks " << endl;
                go_back();
            }

            break;

        case 2:

            system("cls");
            Degree = "BSSE";
            total_fee = 81100;
            tution_fee = 50000;
            misscallaneuos = 31100;
            After_Scholarship = total_fee;

            getMarks("BS Software Engineering");    ////Checking Marks whether in range or not

            if (Inter_mark <= 900 && Inter_mark > 800 && Matric_Marks > 550) {          ///checking  Marks for eligiblity to take admission and scholarship
                feewave(75,"BS Software Engineering");

            }
            else if (Inter_mark >= 900 && Inter_mark <= 1100 && Matric_Marks > 550) {
                feewave(100, "BS Software Engineering");
            }
            else if (Inter_mark <= 800 && Inter_mark >= 700 && Matric_Marks>550) {
                feewave(50, "BS Software Engineering");

            }
            else if (Inter_mark < 700 && Inter_mark >=550 && Matric_Marks>550) {
                no_wave("BS Software Engineering");
            }
            else {
                cout << "\n\t\tSorry you are not eligible to take admission.less than 50% Marks " << endl;
                go_back();
            }

            break;


        case 3:

            system("cls");
            Degree = "BSSS";
            total_fee = 165100;
            tution_fee = 126000;
            misscallaneuos = 39100;
            After_Scholarship = total_fee;

            getMarks("BS Cyber Security");  ////Checking Marks whether in range or not

            if (Inter_mark <= 900 && Inter_mark > 800 && Matric_Marks>550) {        ///checking  Marks for eligiblity to take admission and scholarship
                feewave(75, "BS Cyber Security");
            }


            else if (Inter_mark >= 900 && Inter_mark <= 1100 && Matric_Marks > 550) {
                feewave(100, "BS Cyber Security");
            }


            else if (Inter_mark < 900 && Inter_mark >= 700 && Matric_Marks>550) {
                feewave(50, "BS Cyber Security");
            }

            else if (Inter_mark < 700 && Inter_mark >= 550 && Matric_Marks>550) {
                no_wave("BS Cyber Security");
            }
            else {
                cout << "\n\t\tSorry you are not eligible to take admission.less than 50% Marks "<<endl;
                go_back();
            }
            break;
        default:
            cout << "\n\t\t\tInvalid Choice";
            course();
        }
    }


    void feewave(int perce,string course_name) {
        /////Applying Scholarship according to marks
        Scholarship = perce;
        perce = tution_fee - (tution_fee * Scholarship / 100);
        After_Scholarship = misscallaneuos + perce ;
        cout << "\n\t\t\tYou have got "<< Scholarship<< " % Scholarship on Tution Fee ";
        cout << "\n\t\t\tTotal Fees of "<< course_name<<" is : " << total_fee;
        cout << "\n\t\t\tTotal Tution Fee of " << course_name << " is : " << tution_fee;
        cout << "\n\t\t\tMisscallaneous Charges +  Examination fee : " << misscallaneuos;
        cout << "\n\t\t\tYour fess after Scholarship is : " << After_Scholarship;
    }

    void getMarks(string course_mark) {
        ////Checking Marks whether in range or not
        cout << "\n\t\t\tYou are Applying For " << course_mark << endl;
            int i = 0;
        do {
            cout << "\n\t\t\tEnter Your Marks of Matric : ";
            cin >> Matric_Marks;
            if (Matric_Marks > 1100 || Matric_Marks < 0) {
                cout << "\n\t\t\tMarks are out of Range";
            }
            else
            i=1	;
        }while (i==0);
        do {
            i = 0;
            cout << "\n\t\t\tEnter Your Marks of Inter : ";
            cin >> Inter_mark;
            if (Inter_mark > 1100 || Inter_mark < 0) {
                cout << "\n\t\t\tMarks are out of Range";
            }
            else
                i = 1;
        } while (i == 0);
    }

    void no_wave(string course_name) {
        /////Applying for no Scholarship 
        cout << "\n\t\t\tYour are not Eligible for Scholarship ";
        cout << "\n\t\t\tTotal Fees of "<<course_name<<" is : " << total_fee;
        cout << "\n\t\t\tTotal Tution Fee of " << course_name << " is : " << tution_fee;
        cout << "\n\t\t\tMisscallaneous Charges /  Examination fee : " << misscallaneuos;
        cout << "\n\t\t\tYour Payable fess is : " << After_Scholarship;
    }
    void menu() {

        system("cls");
        /////Welcome Screen Of admin
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\t-----Welcome to Admission Admin portal-----" << endl;
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\n\t\t\t 1.Enter to Fill the Form " << endl;
        cout << "\n\t\t\t 2.Enter To print Your Chalan " << endl;
        cout << "\n\t\t\t 3.Enter Admin Mode " << endl;
        cout << "\n\t\t\t 4.Exit " << endl;

        section();
        }

    void rolle() {
        /////Reading Roll No last used
        ifstream read;
        read.open("id1.txt");
        if (!read.fail()) { ////reading if open succesful
            read >> roll_no;
        }
        read.close();
    }
    void section() {
        int choice;
        cout << "\n\t\t\tEnter Your choice :";
        cin >> choice;
        switch (choice) {
        case 1:
            rolle();    /////taking roll no
            insert();   ////to Insert user data
            break;
        case 2:
            printChalan();  ////print Challan Form
            break;

        case 3:
            if (password()) {   ///checking if password is correct 
                admin();        ///call admin function
            }
            break;
        case 4:
            exit(0);        ////exiting from program

        default:
            cout << "\n\t\t\t Inavalid Number .. Try Again " << endl;
            section();
            break;
        }
    }


    void printChalan() {
        system("color ");
        system("cls");
        int id = searchData();  ////checking ID matched or not
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("StudentRecord.txt");
        string rl, n, g, e, p, d, mm, im, as;
        string a;
        getline(read, a);           
        while (!read.eof()) {       ////reading till end of file

            getline(read, rl);      ///readig line by line
            getline(read, n);
            getline(read, g);
            getline(read, e);
            getline(read, p);
            getline(read, d);
            getline(read, mm);
            getline(read, im);
            getline(read, as);
            int am = 1200 + stoi(as);   ///adding fine after due date in actual fee

            if (stoi(rl) == id) {       ///////Storing Challan Form
                tempFile << "\n\n\t\t\t---------------------------------------------\n";
                tempFile << "\t\t\t|     RIPHAH INTERNATIONAL UNIVERSITY\t    |\n";
                tempFile << "\t\t\t---------------------------------------------\n";
                tempFile << "\t\t\t|\tRoll No :" << rl << "\t\t\t    |\n";
                tempFile << "\t\t\t|\tName : " << n << "\t\t\t    |\n";
                tempFile << "\t\t\t|\tGender : " << g << "\t\t\t    |\n";
                tempFile << "\t\t\t|\tEmail : " << e << "\t    |\n";
                tempFile << "\t\t\t|\tPhone No : " << p << "\t\t    |\n";
                tempFile << "\t\t\t|\tDegree : " << d << "\t\t\t    |\n";
                tempFile << "\t\t\t|\tMatric Marks : " << mm << "\t\t    |\n";
                tempFile << "\t\t\t|\tInter Marks : " << im << "\t\t    |\n";
                tempFile << "\t\t\t|\tTotal Scholarship : " << as<<"\t    |\n";
                tempFile << "\t\t\t| ----------------------------------------- |\n";
                tempFile << "\t\t\t|\tTOTAL PAYABLE FEE(within duedate)   | \n";
                tempFile << "\t\t\t|\t   Due Date :- 30-August-2022       | \n";
                tempFile << "\t\t\t|\t     Amount -->   " << as << "\t            |\n";
                tempFile << "\t\t\t|\tTOTAL PAYABLE FEE(After duedate)    | \n";
                tempFile << "\t\t\t|\t     Amount -->   " << am << "\t            |\n";
                tempFile << "\t\t\t---------------------------------------------\n";

                

            }
        }

        read.close();
        tempFile.close();


        string line;
        read.open("temp.txt");

        /////Printing Challan Form
        if (read.is_open())
        {

            while (getline(read, line))     ////reading line by line 
            {

                cout << line << endl;

            }
            read.close();


        }
        go_back();

    }

    void admin() {

        system("cls");
        /////Admin Portal Welcome
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\t\t\t-----Welcome To  Admin portal-----" << endl;
        cout << "\t\t\t-------------------------------------------" << endl;
        cout << "\n\t\t\t 1.Enter To Show Data Of Student " << endl;
        cout << "\n\t\t\t 2.Enter to Delete Record " << endl;
        cout << "\n\t\t\t 3.Enter To Back Main Menu " << endl;
        cout << "\n\t\t\t 4.Enter To Show Specific Student Data " << endl;
        cout << "\n\t\t\t 5.Enter To Change Login Password " << endl;
        cout << "\n\t\t\t 6.Enter To Exit " << endl;
        admin_choice();     ///calling function

    }
    /////Searching Data present or not
    int searchData() {
        int id;
        cout << "\n\tEnter student id want to search : ";
        cin >> id;
        ifstream read;
        read.open("studentRecord.txt");
        string rl, n, g, e, p, d, mm, im, as;
        string a;
        getline(read, a);
        while (!read.eof()) {   ////reading line by line
            getline(read, rl);
            getline(read, n);
            getline(read, g);
            getline(read, e);
            getline(read, p);
            getline(read, d);
            getline(read, mm);
            getline(read, im);
            getline(read, as);
            if (stoi(rl) == id) {       ////if id find return id
                ifstream i;
                return id;
            }
        }
                cout << "Record Not Found";
                go_back();      /////if not found then go back
        }
    int show_specific_data() { ///Show Specific Student Data for Delete Function
        int id = searchData(); ///calling search function to find whether id present or not
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("StudentRecord.txt");
        string rl, n, g, e, p, d, mm, im, as;
        string a;
        getline(read, a);
        while (!read.eof()) {

            getline(read, rl);
            getline(read, n);
            getline(read, g);
            getline(read, e);
            getline(read, p);
            getline(read, d);
            getline(read, mm);
            getline(read, im);
            getline(read, as);

            /////if ID Finded then write in file
            if (stoi(rl) == id) {
                tempFile << "\nRoll No : " << rl << "\n";
                tempFile <<"Name : " << n << "\n";
                tempFile << "Gender : " << g << "\n";
                tempFile << "Email : " << e << "\n";
                tempFile << "Phone : " << p << "\n";
                tempFile << "Degree : " << d << "\n";
                tempFile << "Matric Marks : " << mm << "\n";
                tempFile << "Inter Marks : " << im << "\n";
                tempFile << "Scholarship : " << as;
            }
        }

        read.close();
        tempFile.close();


        string line;
        read.open("temp.txt");

        ////Showing Data of student
        if (read.is_open())
        {

            while (getline(read, line))
            {
                
                cout << line << endl;

            }
            read.close();

            return id;
        }

    }
    void delete_record() {
       int id= show_specific_data();
       
        cout << "\n\tYou want to delete record (y/n) : ";
        char choice;
        cin >> choice;
    if (choice == 'y') {
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("StudentRecord.txt");
        string rl,n, g, e, p, d, mm, im, as;
        string a;
        getline(read,a);
        while (!read.eof()) {   ////reading till end of file
           
            getline(read, rl);
            getline(read, n);
            getline(read, g);
            getline(read, e);
            getline(read, p);
            getline(read, d);
            getline(read, mm);
            getline(read, im);
            getline(read, as);

            if (stoi(rl) != id) {   /////if id not found then wite data
                tempFile << "\n" << rl << "\n";
                tempFile << n << "\n";
                tempFile << g << "\n";
                tempFile << e << "\n";
                tempFile << p << "\n";
                tempFile << d << "\n";
                tempFile << mm << "\n";
                tempFile << im << "\n";
                tempFile << as;
            }
        }
        
        read.close();
        tempFile.close();

        remove("StudentRecord.txt");
        if (rename("temp.txt", "StudentRecord.txt"))        /////renaming file 
        {
        }
 
        

        cout << "\n\tData deleted successfuly";
        go_back();
    }
    else {
        cout << "\n\tRecord not deleted";
        go_back();
    }
    
    }
    void go_back() {
        char E = 0;
        cout << "\n\t\tPress Y to Go Back = ";
        cin >> E;
        if (E == 'y' || E == 'Y') {
            menu();
        }
    }
    void admin_choice() {
        int choice;
        cout << "\n\t\t\tEnter Your choice ";
        cin >> choice;
        switch (choice) {
        case 1:
            show_allData();         ///to show all entered data
            break;
        case 2:
            delete_record();        ///to delete student data
            break;
        case 3:
            menu();                 ///calling main
            break;
        case 4:
            show();                 ////show specific student data
            break;
        case 5:
            change_pass();          ///To change password
            go_back();
            
           break;
        case 6:
            exit(0);
        default:
            cout << "\n\t\t\t Inavalid Number .. Try Again " << endl;
            admin_choice();
        }
    }
    
   
    void show() {       /////to show specific data
        int id = searchData();
            ofstream tempFile;
            tempFile.open("temp.txt");
            ifstream read;
            read.open("StudentRecord.txt");
            string rl, n, g, e, p, d, mm, im, as;
            string a;
            getline(read, a);
            while (!read.eof()) {       ///reading till end of file
               
                getline(read, rl);      ///reading line by line
                getline(read, n);
                getline(read, g);
                getline(read, e);
                getline(read, p);
                getline(read, d);
                getline(read, mm);
                getline(read, im);
                getline(read, as);

               
                if (stoi(rl)== id) {    ///if id found then store its data in file
                    tempFile << "Roll No :" << rl << "\n";
                    tempFile <<"Name : " << n << "\n";
                    tempFile << "Gender : " << g << "\n";
                    tempFile << "Email : " << e << "\n";
                    tempFile << "Phone No : " << p << "\n";
                    tempFile << "Degree : " << d << "\n";
                    tempFile << "Matric Marks : " << mm << "\n";
                    tempFile << "Inter Marks : " << im << "\n";
                    tempFile << "After Scholarship : " << as;
                }
            }

            read.close();
            tempFile.close();


        string line;
        read.open("temp.txt");


        if (read.is_open())
        {
            ///printing student data 
            while (getline(read, line))
            {

                cout << line << endl;
            }
            read.close();

            
        }
        go_back();
        
    }
    void show_allData() {       ////show all student entered data
        system("cls");          


        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("StudentRecord.txt");
        string rl, n, g, e, p, d, mm, im, as;
        string a;
        getline(read, a);
        while (!read.eof()) {       ////reading till end of file

            getline(read, rl);      ///reading line by line
            getline(read, n);
            getline(read, g);
            getline(read, e);
            getline(read, p);
            getline(read, d);
            getline(read, mm);
            getline(read, im);
            getline(read, as);
            ///storing data in proper format
            tempFile << "\n\t\tRoll No :" << rl << "\n";
            tempFile << "\t\tName : " << n << "\n";
            tempFile << "\t\tGender : " << g << "\n";
            tempFile << "\t\tEmail : " << e << "\n";
            tempFile << "\t\tPhone No : " << p << "\n";
            tempFile << "\t\tDegree : " << d << "\n";
            tempFile << "\t\tMatric Marks : " << mm << "\n";
            tempFile << "\t\tInter Marks : " << im << "\n";
            tempFile << "\t\tAfter Scholarship : " << as << "\n";

        }

        read.close();
        tempFile.close();


        string line;
        read.open("temp.txt");


        if (read.is_open())
        {
            /////Printing Student data 
            while (getline(read, line))
            {

                cout << line << endl;
            }
            read.close();


        }
        go_back();
    }
};





int main() {
    system("color 5e");
    Form  s1;            ////creating non pointer base object of class form
    s1.Welcome();        ////Calling welcome function

}