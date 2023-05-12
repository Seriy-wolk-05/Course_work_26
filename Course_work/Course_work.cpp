//Дорофеев С.В. БАСО-02-22
//Тип файла - текстовый
//Вариант 26. Разбить группу на две части:
//1) сдавших все спец.предметы только на 4 и 5;
//2) сдавших спец.предметы на 3, 4, 5.
//Отсортировать каждую часть по алфавиту.




#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h> // для функции system();
#include <cstdio> // для функции remove();
#include <cstring> // для функции strcpy_s();
#include <windows.h> // для SetConsoleCP(1251);

using namespace std;

struct Initials 
{
    char Surname[20];
    char Name[20];
    char Patronymic[20];
};

struct Birthdate
{
    short Day;
    short Month;
    short Year;
};

struct StudyPlace
{
    short Year;
    char Faculty[6]; //Факультет ИКБ
    char Department[11]; //Кафедра КБ-1
    char Group[11]; // БАСО-02-22
};

struct Semestr {
    short ProgramID;
    short Subjects[10];
};
struct Grade {
    Semestr Terms[9];
};
struct StudyProgram {
    short ProgramID;
    char Subject1;
    char Subject2;
    char Subject3;
    char Subject4;
    char Subject5;
    char Subject6;
    char Subject7;
    char Subject8;
    char Subject9;
    char Subject10;
};

int charlen(char ch[20])
{ 
    return (sizeof(ch) / sizeof(char));
}

void line(unsigned short lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        cout << "-";
    }
};

void PrintDate(unsigned short day, unsigned short month, unsigned short year) {

    cout << left;
    cout << " ";
    if (day > 9) {
        cout << day;
    }
    else {
        cout << "0" << day;
    }
    cout << ".";
    if (month > 9) {
        cout << month;
    }
    else {
        cout << "0" << month;
    }
    cout << ".";
    cout << year;
    cout << " ";
}

int IsItDate(int Day, int Month, int Year)
{
    if (Day < 1 || Day > 31)
    {
        return 0;
    }
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    if (Year < 1900 || Year > 2023)
    {
        return 0;
    }
    return 1;
}

class Student
{

public:
    char ID[8]; //98Б0826
    Initials initials;
    Birthdate birthdate;
    StudyPlace studyplace;
    unsigned short sex;
    Grade grade;
    unsigned short marker;
    

    Student()
    {
        strcpy_s(ID, "00А0000");
        strcpy_s(initials.Surname, "Иванов");
        strcpy_s(initials.Name, "Иван");
        strcpy_s(initials.Patronymic, "Иванович");
        birthdate.Day = 1;
        birthdate.Month = 1;
        birthdate.Year = 2000;
        studyplace.Year = 2020;
        strcpy_s(studyplace.Faculty, "ИКБ");
        strcpy_s(studyplace.Department, "КБ-1");
        strcpy_s(studyplace.Group, "БАСО-02-22");
        sex = 1;
        marker = 5;
        for (int i = 0; i < 9; i++)
        {
            grade.Terms[i].ProgramID = 1;
            for (int j = 0; j < 10; j++)
            {
                grade.Terms[i].Subjects[j] = 0;
            }
        }
    }
    ~Student() {}

    void MarkerCounter()
    {
        //показывает статус студента (отличник/хорошист/троечник/двоечник)
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (grade.Terms[i].Subjects[j] < marker)
                {
                    marker = grade.Terms[i].Subjects[j];
                }
            }
        }
        /*
        if (marker == 5)
        {
            cout << "Студент учится отлично /";
        }
        else if (marker == 4)
        {
            cout << "Студент учится хорошо /";
        }
        else if (marker == 3)
        {
            cout << "Студент учится удовлетворительно /";
        }
        else if (marker == 2)
        {
            cout << "Студент учится неудовлетворительно /";
        }
        else
        {
            cout << "У Студента есть предмет, по которому нет оценки /";
        }
        */
        
    }
    
    void PrintMark(char SubjectName, short Mark)
    {

        if (Mark == 0)
        {
            cout << SubjectName << " - Нет оценки" << endl;
        }
        else
        {
            cout << SubjectName << " - " << Mark << endl;
        }
    }

    void PrintShortInfo()
    {
        if ((string)ID != "00А0000")
        {
            cout << ID << " / " << initials.Surname << " " << initials.Name[0] << "." << initials.Patronymic[0] << "." << "\t/ " << studyplace.Year << " / " << studyplace.Group << endl;
        }
    }

    void PrintInfo(string Subjects[10])
    {
        if ((string)ID != "00А0000") 
        {
            system("cls");
            line(70); cout << endl; line(70); cout << endl; //34
            line(22); cout << "Карточка студента: " << ID; line(22); cout << endl;
            line(4); cout << "ФИО: ";
            cout.width(strlen(initials.Surname)); cout << initials.Surname;
            cout << " " << initials.Name;
            cout << " " << initials.Patronymic;
            cout.width(70 - 16 - strlen(initials.Surname) - strlen(initials.Name) - strlen(initials.Patronymic));
            cout.fill('-');
            cout << right << "Пол: ";
            if (sex == 2) cout << "Ж";
            else if (sex == 1) cout << "М";
            line(4); cout << endl;
            line(4); cout << "Дата рождения: "; PrintDate(birthdate.Day, birthdate.Month, birthdate.Year); line(35);
            line(4); cout << endl;
            line(4); cout << "Год поступления: " << studyplace.Year; line(7);
            cout << "Факультет: " << studyplace.Faculty; line(7);
            cout << "Кафедра: " << studyplace.Department; line(4); cout << endl;
            line(4);
            cout << "Группа: " << studyplace.Group; line(14);
            cout << "Номер зачётной книжки: " << ID; line(4); cout << endl;
            line(70); cout << endl; line(70); cout << endl;
            cout << "\t\t"; line(11); cout << "Успеваемость"; line(10); cout << endl; //34
            cout << "\t\tСеместр №\t";
            for (int i = 0; i < 9; i++)
            {
                cout << i + 1 << " ";
            }
            cout << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << "\t\t" << Subjects[i] << "\t";
                for (int j = 0; j < 9; j++)
                {
                    cout << grade.Terms[j].Subjects[i] << " ";
                }
                cout << endl;
            }
            cout << "\t\t"; line(33);cout << endl;
            line(70); cout << endl;
            line(70); cout << endl;
            
        }
    }

    void SaveStudent(string FileName)
    {
        
        ofstream OutFile;
        OutFile.open(FileName, ios::app);
        if (!OutFile.is_open())
        {
            cout << "Error, file not open! ";
        }
        else
        {
            OutFile << "\n" << ID << " " << initials.Surname << " " << initials.Name << " " << initials.Patronymic
                << " " << birthdate.Day << " " << birthdate.Month << " " << birthdate.Year
                << " " << studyplace.Year << " " << studyplace.Faculty << " " << studyplace.Department << " " << studyplace.Group
                << " " << sex;
            system("cls");
        }
        OutFile.close();
    }

    void RewriteStudent(string FileName)
    {
        ofstream OutFile;
        OutFile.open(FileName, ios::app);
        if (!OutFile.is_open())
        {
            cout << "Error, file not open! ";
        }
        else
        {
            OutFile << "\n" << ID << " " << initials.Surname << " " << initials.Name << " " << initials.Patronymic
                << " " << birthdate.Day << " " << birthdate.Month << " " << birthdate.Year
                << " " << studyplace.Year << " " << studyplace.Faculty << " " << studyplace.Department << " " << studyplace.Group
                << " " << sex;
            system("cls");
        }
        for (int i = 0; i < 9; i++)
        {         
            for (int j = 0; j < 10; j++)
            {
                OutFile << " " << grade.Terms[i].Subjects[j];
            }
        }
        OutFile.close();
    }

    void SaveMark(string FileName)
    {
        ofstream OutFile;
        OutFile.open(FileName, ios::app);
        cout << "Хотите добавить данные об оценках?" << endl;
        cout << "(1) - Да" << endl << "(0) - Нет" << endl;
        int* _action = (int*) new int;
        cin >> *_action;
        if (*_action == 1)
        {
            for (int i = 0; i < 9; i++)
            {
                system("cls");
                cout << "Введите оценки за " << i + 1 << " семестр: " << endl;
                for (int j = 0; j < 10; j++)
                {
                    cout << "Предмет " << j + 1 << ":" << endl;
                    cin >> grade.Terms[i].Subjects[j];
                    OutFile << " " << grade.Terms[i].Subjects[j];
                }
            }
        }
        if (*_action == 0)
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    grade.Terms[i].Subjects[j] = 0;
                    OutFile << " " << grade.Terms[i].Subjects[j];

                }
            }
        }
        if (*_action != 0 && *_action != 1)
        {
            cout << "Такой команды нет" << endl;
        }
        delete _action;
        OutFile.close();
    }
    

};

    



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student student[10];
    Student student45[10];
    Student student345[10];

    string Subjects[10] =
    {
        "Мат.анализ",
        "Физика     ",
        "Физ.культура",
        "Русский язык",
        "Информатика",
        "Дискрет.мат",
        "Иностранный яз.",
        "Теория инф.",
        "Основы Инф.Без.",
        "Языки програм-я"
    };

    unsigned short numberOfStudents;
StartMenu:
    int* numStud = new int;
    *numStud = -1;
    ifstream InStud;
    InStud.open("Students1.txt");
    if (!InStud.is_open()) 
    { 
        cout << "Error"; 
    }
    else
    {
        while (!InStud.eof())
        {
            *numStud = *numStud + 1;
            InStud >> student[*numStud].ID >> student[*numStud].initials.Surname >> student[*numStud].initials.Name >> student[*numStud].initials.Patronymic >>
                student[*numStud].birthdate.Day >> student[*numStud].birthdate.Month >> student[*numStud].birthdate.Year >>
                student[*numStud].studyplace.Year >> student[*numStud].studyplace.Faculty >> student[*numStud].studyplace.Department >> student[*numStud].studyplace.Group >> student[*numStud].sex;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    InStud >> student[*numStud].grade.Terms[i].Subjects[j];
                }
            }
        }    
    }
    numberOfStudents = *numStud + 1;
    delete numStud;
    InStud.close();
    

    unsigned int action;

    
ChoiceMenu:
    system("cls");
    line(17);
    cout << "Главное меню";
    line(18);
    cout << endl;
    cout << "Введите (1) чтобы вывести список всех студентов" << endl;
    cout << "Введите (2) для добавления нового студента" << endl;
    cout << "Введите (3) для выполнения задания по варианту 26" << endl;
    cout << "Введите (4) для изменения учебного плана" << endl;
    cout << "Введите (0) для выхода из программы" << endl;
    cin >> action;
    if (action == 0)
    {
        goto exitProgram;
    }
    if (action == 1)
    {
        system("cls");
        cout << "Список студентов: " << endl;
        cout << "Данные выводятся в формате: " << endl;
        cout << "Номер зачетной книжки / ФИО / Год поступления / Группа" << endl;
        for (int i = 0; i < numberOfStudents; i++)
        {
            cout << i + 1 << ") ";
            student[i].PrintShortInfo();       
        }
        cout << endl << "Введите: " << endl;
        cout << "(1) - Открыть подробную информацию о студенте " << endl;
        cout << "(2) - Изменить информацию о студенте " << endl;
        cout << "(3) - Удалить студента " << endl;
        cout << "(0) - Вернуться в меню " << endl;

        unsigned short action_ = -1;
        cin >> action_;
        if (action_ == 1)//Подробная инфа о студенте
        {
        InfoStudent:
            int* act_ = (int*) new int;
            cout << "Информацию о каком студенте открыть (0-9)? " << endl;
            cin >> *act_;
            if (*act_ > numberOfStudents)
            {
                
                delete act_;
                goto InfoStudent;
            }
            else
            {
                student[*act_ - 1].PrintInfo(Subjects);
                delete act_;
            }
        }
        else if (action_ == 2)//изменение информации
        {
        ChangeStudent:
            int* act_ = (int*) new int;
            *act_ = -1;
            cout << "Введите номер студента, у которого хотите изменить данные (1-10): " << endl;
            cout << "(0) - Выход в меню" << endl;
            cin >> *act_;
            *act_ = *act_ - 1;
            if (*act_ > -1 && *act_ < numberOfStudents)
            {
                system("cls");                
                int* Temp = new int;
                *Temp = *act_;
                int* act__ = new int;
                cout << "Какие данные хотите изменить? " << endl;
                cout << "(1) - Номер зачётной книжки" << endl;
                cout << "(2) - ФИО" << endl;
                cout << "(3) - Дату рождения" << endl;
                cout << "(4) - Год поступления" << endl;
                cout << "(5) - Факультет (институт)" << endl;
                cout << "(6) - Кафедру" << endl;
                cout << "(7) - Группу" << endl;
                cout << "(8) - Пол" << endl;
                cout << "(9) - Изменить оценки" << endl;
                cout << "(0) - Выйти в главное меню" << endl;
                cin >> *act__;
                system("cls");
                if (*act__ == 1)
                {
                    cout << "Введите новый номер зачётной книжки: ";
                    cin >> student[*Temp].ID;                    
                }
                if (*act__ == 2)
                {
                ChangeSurname:
                    int* a1 = (int*) new int;
                    cout << "Хотите изменить Фамилию? Фамилия: " << student[*Temp].initials.Surname << endl;
                    cout << "(1) - Да" << endl << "(0) - Нет" << endl;
                    cin >> *a1;
                    if (*a1 == 1)
                    {
                        cout << "Введите новую Фамилию: ";
                        cin >> student[*Temp].initials.Surname;
                    }
                    else
                    {
                        delete a1;
                        goto ChangeName;
                    }
                    delete a1;
                ChangeName:
                    int* a2 = (int*) new int;
                    cout << "Хотите изменить Имя? Имя: " << student[*Temp].initials.Name << endl;
                    cout << "(1) - Да" << endl << "(0) - Нет" << endl;
                    cin >> *a2;
                    if (*a2 == 1)
                    {
                        cout << "Введите новое Имя: ";
                        cin >> student[*Temp].initials.Name;
                        delete a2;
                    }
                    else
                    {
                        delete a2;
                        goto ChangePatronymic;
                    }
                ChangePatronymic:
                    int* a3 = (int*) new int;
                    cout << "Хотите изменить Отчество? Отчество: " << student[*Temp].initials.Patronymic << endl;
                    cout << "(1) - Да" << endl << "(0) - Нет" << endl;
                    cin >> *a3;
                    if (*a3 == 1)
                    {
                        cout << "Введите новое Отчество: ";
                        cin >> student[*Temp].initials.Patronymic;
                        delete a3;
                    }
                    else
                    {
                        delete a3;
                        goto ChangePatronymic;
                    }
                    
                }
                if (*act__ == 3)
                {
                    cout << "Введите новую дату рождения в формате 01 01 2001 (ДД ММ ГГГГ):" << endl;
                    cin >> student[*Temp].birthdate.Day >> student[*Temp].birthdate.Month >> student[*Temp].birthdate.Year;
                    while (!IsItDate(student[*Temp].birthdate.Day, student[*Temp].birthdate.Month, student[*Temp].birthdate.Year))
                    {
                        cout << "Неправильный формат даты!" << endl;
                        cout << "Введите дату рождения в формате 01 01 2001 (ДД ММ ГГГГ): " << endl;
                        cin >> student[*Temp].birthdate.Day >> student[*Temp].birthdate.Month >> student[*Temp].birthdate.Year;
                    }
                }
                if (*act__ == 4)
                {
                    cout << "Введите новый год поступления: ";
                    cin >> student[*Temp].studyplace.Year;
                    while ((student[*Temp].studyplace.Year < 1900 || student[*Temp].studyplace.Year > 2023))
                    {
                        cout << "Неправильный формат года!" << endl;
                        cout << "Введите год поступления (от 1900 до 2023): " << endl;
                        cin >> student[*Temp].studyplace.Year;
                    }
                }
                if (*act__ == 5)
                {
                    cout << "Введите факультет (институт): ";
                    cin >> student[*Temp].studyplace.Faculty;
                }
                if (*act__ == 6)
                {
                    cout << "Введите Кафедру: ";
                    cin >> student[*Temp].studyplace.Department;
                }
                if (*act__ == 7)
                {
                    cout << "Введите группу: ";
                    cin >> student[*Temp].studyplace.Group;
                }
                if (*act__ == 8)
                {
                    cout << "Введите пол (1) - Мужской, (2) - Женский: ";
                    cin >> student[*Temp].sex;
                    while (!(student[*Temp].sex == 1 || student[*Temp].sex == 2))
                    {
                        cout << "Такого пола нет, введите пол заново: " << endl;
                        cout << "Введите пол (1) - Мужской, (2) - Женский: ";
                        cin >> student[*Temp].sex;
                    }
                }
                if (*act__ == 9)
                {
                    int* i = (int*) new int;
                    int* j = (int*) new int;
                    int* TempMark = (int*) new int;
                    cout << "Введите номер семестра (1-9): " << endl;
                    cin >> *i;
                    for (int k = 0; k < 10; k++)
                    {
                        cout << "(" << k + 1 << ") - " << Subjects[k] << endl;
                    }
                    cin >> *j;
                    cout << "Введите оценку: ";
                    cin >> student[*Temp].grade.Terms[*i-1].Subjects[*j-1];

                }
                if (*act__ == 0)
                {
                    goto ChoiceMenu;
                }
                
                
                remove("Students1.txt");
                fstream backup;
                backup.open("Students1.txt", ios::out | ios::in | ios::app);
                if (!backup.is_open())
                {
                    cout << "Ошибка, файл Students1.txt не открывается" << endl;
                }
                else
                {
                    for (int i = 0; i < numberOfStudents; i++)
                    {
                        if (i < numberOfStudents)
                        {
                            student[i].RewriteStudent("Students1.txt");
                        }
                    }
                }
                backup.close();

                cout << "Данные успешно изменены!\n";
                system("pause");
                delete act__, Temp;
                goto StartMenu;
            }
            if (*act_ == -1)
            {
                delete act_;
                goto ChoiceMenu;
                
            }
            else
            {
                cout << "Студента под таким номером нет" << endl;
                delete act_;
                system("pause");
                goto ChangeStudent;
            }
            
        }

        //Удалить студента
        else if (action_ == 3)
        {
        DeleteStudent:
            system("cls");
            cout << "Список студентов: " << endl;
            for (int t = 0; t < numberOfStudents; t++)
            {
                cout << t + 1 << ") ";
                student[t].PrintShortInfo();

            }
            cout << "(1-9) - Выберите студента для удаления:" << endl;
            cout << " (0)  - Вернуться в меню" << endl;
            int* act = new int;
            cin >> *act;
            *act = *act - 1;

            if (*act == -1)
            {
                goto ChoiceMenu;
            }
            if (*act > numberOfStudents) //|| *act < 1)
            {
                cout << "Ошибка, студент под таким номером отсутствует " << endl;
                system("pause");
                delete act;
                goto DeleteStudent;
            }
            else
            {
                //string* tempStr = (string*) new string;

                remove("Students1.txt");
                fstream backup;
                backup.open("Students1.txt", ios::out | ios::in | ios::app);
                if (!backup.is_open())
                {
                    cout << "Ошибка, файл Students1.txt не открывается" << endl;
                }
                else
                {
                    for (int i = 0; i < numberOfStudents - 1; i++)
                    {
                        Student* TempStud_ = (Student*) new Student;
                        if (i < *act)
                        {
                            student[i].RewriteStudent("Students1.txt");
                        }
                        else if (i >= *act)
                        {

                            *TempStud_ = student[i + 1];
                            student[i] = *TempStud_;
                            student[i].RewriteStudent("Students1.txt");


                        }

                        //delete TempStud_;
                    }
                    numberOfStudents -= 1;
                }
                backup.close();

                cout << "Студент успешно удалён! " << endl;

            }
            delete act;
            system("pause");
            goto ChoiceMenu;


        }

        else if (action_ == 0)//Вернуться в меню
        {
            goto ChoiceMenu;
        }



        while (action_ != 0)
        {
            action_ = -1;
            cout << "Введите 0 чтобы вернуться" << endl;
            cin >> action_;
            cout << "Вы ввели: " << action_ << ". Такой команды нет.";
        }
        goto ChoiceMenu;
    }
    if (action == 2) //Добваление нового студента
    {
        
    studentAdd:
        system("cls");
        fstream file;
        file.open("Students1.txt", ofstream::app);
        if (file.is_open())
        {
            //Student* TempStud = (Student*) new Student;
            int* Temp = (int*) new int;
            
            *Temp = numberOfStudents;
            //system("cls");
            cout << "Введите номер зачётной книжки: "; //22Б0826
            cin >> student[*Temp].ID;
            cout << "Введите фамилию: ";
            cin >> student[*Temp].initials.Surname;
            cout << "Введите имя: ";
            cin >> student[*Temp].initials.Name;
            cout << "Введите отчество: ";
            cin >> student[*Temp].initials.Patronymic;
            cout << "Введите дату рождения в формате - 01 01 2001: ";
            cin >> student[*Temp].birthdate.Day >> student[*Temp].birthdate.Month >> student[*Temp].birthdate.Year;
            while (!IsItDate(student[*Temp].birthdate.Day, student[*Temp].birthdate.Month, student[*Temp].birthdate.Year))
            {
                cout << "Неправильный формат даты!" << endl;
                cout << "Введите дату рождения в формате 01 01 2001 (ДД ММ ГГГГ): " << endl;
                cin >> student[*Temp].birthdate.Day >> student[*Temp].birthdate.Month >> student[*Temp].birthdate.Year;
            }
            cout << "Введите год поступления: ";
            cin >> student[*Temp].studyplace.Year;
            while ((student[*Temp].studyplace.Year < 1900 || student[*Temp].studyplace.Year > 2023))
            {
                cout << "Неправильный формат года!" << endl;
                cout << "Введите год поступления (от 1900 до 2023): " << endl;
                cin >> student[*Temp].studyplace.Year;
            }
            cout << "Введите Факультет (институт): ";
            cin >> student[*Temp].studyplace.Faculty;
            cout << "Введите кафедру: ";
            cin >> student[*Temp].studyplace.Department;
            cout << "Введите учебную группу: ";
            cin >> student[*Temp].studyplace.Group;
            cout << "Введите пол (1) - Мужской, (2) - Женский: ";
            cin >> student[*Temp].sex;
            while (!(student[*Temp].sex == 1 || student[*Temp].sex == 2))
            {
                cout << "Такого пола нет, введите пол заново: " << endl;
                cout << "Введите пол (1) - Мужской, (2) - Женский: ";
                cin >> student[*Temp].sex;
            }
            cout << "Студент успешно добавлен! ";
            student[*Temp].SaveStudent("Students1.txt");
            student[*Temp].SaveMark("Students1.txt");
            delete Temp;
        }
        else
        {
            cout << "Error ///";
        }
        file.close();
        
        system("cls");
        goto StartMenu;
    }
    if (action == 3)
    {

        //Вариант 26. Разбить группу на две части:
        //1) сдавших все спец.предметы только на 4 и 5;
        //2) сдавших спец.предметы на 3, 4, 5.
        //Отсортировать каждую часть по алфавиту.


        system("cls");

        cout << "1) Группа - студенты, сдавшие все спец.предметы только на 4 и 5: " << endl;
        int kek = 0;
        for (int i = 0; i < numberOfStudents; i++)
        {
            student[i].MarkerCounter();
            if (student[i].marker == 4 or student[i].marker == 5)
            {
                student45[kek] = student[i];
                kek++;
            }
        }

        //Сортировка по Алфавиту
        for (int j = 0; j < kek; j++)
        {
            for (int z = 0; z < kek; z++)
            {
                Student* tempStudent = (Student*) new Student;
                if (student45[z].initials.Surname > student45[z + 1].initials.Surname)
                {
                    *tempStudent = student45[z];
                    student45[z] = student45[z + 1];
                    student45[z + 1] = *tempStudent;
                    break;
                }
                else if (student45[z].initials.Surname == student45[z + 1].initials.Surname)
                {
                    if (student45[z].initials.Name > student45[z + 1].initials.Name)
                    {
                        *tempStudent = student45[z];
                        student45[z] = student45[z + 1];
                        student45[z + 1] = *tempStudent;
                        break;
                    }
                    else if (student45[z].initials.Name == student45[z + 1].initials.Name)
                    {
                    if (student45[z].initials.Patronymic > student45[z + 1].initials.Patronymic)
                    {
                        *tempStudent = student45[z];
                        student45[z] = student45[z + 1];
                        student45[z + 1] = *tempStudent;
                        break;
                    }
                    }
                }
                delete tempStudent;
            } 
        }
        //Вывод отсортированных студентов 1 группы
        for (int i = 0; i < kek; i++)
        {
            cout << i + 1 << ") ";
            student45[i].PrintShortInfo();
        }

        cout << endl << endl;

        int lol = 0;
        cout << "2) Группа - студенты, сдавшие спец.предметы на 3, 4, 5: " << endl;
        for (int i = 0; i < numberOfStudents; i++)
        {
            student[i].MarkerCounter();
            if (student[i].marker == 3 or student[i].marker == 4 or student[i].marker == 5)
            {
                student345[lol] = student[i];
                lol++;
            }
        }


        for (int j = 0; j < lol; j++)
        {
            
            for (int z = 0; z < lol; z++)
            {
                Student* tempStudent = (Student*) new Student;
                if (student345[j].initials.Surname < student345[z].initials.Surname)
                {
                    *tempStudent = student345[j];
                    student345[j] = student345[z];
                    student345[z] = *tempStudent;
                }
                else if (student345[j].initials.Surname == student345[z].initials.Surname)
                {
                    if (student345[j].initials.Name < student345[z].initials.Name)
                    {
                        *tempStudent = student345[j];
                        student345[j] = student345[z];
                        student345[z] = *tempStudent;
                    }
                    else if (student345[j].initials.Name == student345[z].initials.Name)
                    {
                        if (student345[j].initials.Patronymic < student345[z].initials.Patronymic)
                        {
                            *tempStudent = student345[j];
                            student345[j] = student345[z];
                            student345[z] = *tempStudent;
                        }
                    }
                }
                delete tempStudent;
            }
        }

        for (int i = 0; i < lol; i++)
        {
            cout << i + 1 << ") ";
            student345[i].PrintShortInfo();
        }

        unsigned short b = -1;
        while (b != 0)
        {
            cout << "Введите 0 для выхода в Главное меню: " << endl;
            cin >> b;
        }
        goto ChoiceMenu;

        //student[i].MarkerCounter(); 
    }

    if (action == 4)
    {
        system("cls");
        cout << "Список предметов: " << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i + 1 << ") " << Subjects[i] << endl;
        }
        cout << "0 - Выход в главное меню" << endl;
        short arbidol = -1;
        cout << "Какой предмет хотите изменить (1-10)? " << endl;
        cin >> arbidol;
        cout << "Введите новое название предмета: ";
        cin >> Subjects[arbidol - 1];
        while (Subjects[arbidol - 1].length() > 15)
        {
            cout << "Название предмета слишком длинное" << endl;
            cout << "Пожалуйста, сократите название предмета до 14 символов" << endl;
            cout << "Введите новое название предмета: ";
            cin >> Subjects[arbidol - 1];
        }
        if (arbidol == 0)
        {
            goto ChoiceMenu;
        }
        cout << "Предмет успешно изменён! " << endl;
        system("pause");
        goto ChoiceMenu;
    }

    else
    {
        goto StartMenu;
    }

exitProgram:
    return 0;
}