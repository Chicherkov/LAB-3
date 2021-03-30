#include <iostream>
#include <string>

#define M 4

using namespace std;

class Kalendar
{
private:
    int day;
    int month;
    int year;

public:

    Kalendar() // конструктор без параметрів
    {
        day = 1;
        month = 1;
        year = 1970;
        
    }

    Kalendar(int day, int month, int year) // конструктор з параметрами
    {
        this->day = day;
        this->month = month;
        this->year = year;
        cout << "Конструктор з параметрами" << endl;
    }

    Kalendar(const Kalendar& obj) // конструктор копіювання
    {
        
        this->day = obj.day;
        this->month = obj.month;
        this->year = obj.year;
    }

    ~Kalendar() { /*delete day; delete month; delete year;*/ cout << "Деструктор!!!" << endl; } // Деструктор

    void SetDay(int userday) 
    {
        day = userday;
    }

    int GetDay() 
    {
        return day;
    }

    void SetMonth(int usermonth) 
    {
        month = usermonth;
    }

    int GetMonth() 
    {
        return month;
    }

    void SetYear(int useryear) 
    {
        year = useryear;
    }

    int GetYear() 
    {
        return year;
    }

    bool isValidDate(int day, int month, int year) // Перевірка дати
    {
        bool flag = false;
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
            (month == 8) || (month == 10) || (month == 12))
        {
            if (day <= 31)
            {
                flag = true;
            }

        }
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            if (day <= 30)
            {
                flag = true;
            }
        }
        else if ((month == 2) && (year % 4 == 0))
        {
            if (day <= 29)
            {
                flag = true;
            }
        }
        else if ((month == 2) && (year % 4 != 0) && (year % 100 != 0))
        {
            if (day <= 28)
            {
                flag = true;
            }
        }

        if (flag == true)
        {
            return true;
        }
        else {
            return false;
        }

    }

    int NumberDayOfWeek() // Функція визначення дня тижня
    {
        int a, y, m, R;
        a = (14 - month) / 12;
        y = year - a;
        m = month + 12 * a - 2;
        R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
        if (R % 7 != 0)
        {
            return R % 7;
        }
        else {
            R = 7;
            return R;
        }
    }

    void NameDayOfWeek()
    {
        string arr[7] = { "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота", "Неділя" };
        if (isValidDate(day, month, year))
        {
            cout << arr[NumberDayOfWeek() - 1];
        }
        else {
            cout << "Невірна дата!";
        }
    }

    void TheNextDateOFThisDay() // Функція визначення дня тижня через 7 дн
    {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
            (month == 8) || (month == 10))
        {
            if (day > 24 && day <= 31 && month < 12)
            {
                day = 7 - (31 - day);
                month += 1;
            }
            else
                day += 7;
        }
        else if (month == 12)
        {
            if (day > 24 && day <= 31)
            {
                day = 7 - (31 - day);
                month = 1;
                year += 1;
            }
            else
                day += 7;
        }
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            if (day > 23 && day <= 30)
            {
                day = 7 - (30 - day);
                month += 1;
            }
            else
                day += 7;
        }
        else if ((month == 2) && (year % 4 == 0) || (year % 400 == 0))
        {
            if (day > 22 && day <= 29)
            {
                day = 7 - (29 - day);
                month += 1;
            }
            else
                day += 7;
        }
        else if ((month == 2) && (year % 4 != 0) && (year % 400) != 0)
        {
            if (day > 21 && day <= 28)
            {
                day = 7 - (28 - day);
                month += 1;
            }
            else
                day += 7;
        }
    }

    void BubbleSort(Kalendar Kalen[])
    {
        Kalendar tmp;
        for (int i = M - 1; i > 0; i--)
        {
            for (int j = M - 1; j > 0; j--)
            {
                if (Kalen[j].NumberDayOfWeek() > Kalen[j - 1].NumberDayOfWeek())
                {
                    tmp = Kalen[j];
                    Kalen[j] = Kalen[j - 1];
                    Kalen[j - 1] = tmp;
                }
            }
        }
    }

    bool operator >= (Kalendar& Kalen1)
    {

        return (NumberDayOfWeek() >= Kalen1.NumberDayOfWeek() ? true : false);
    }

    Kalendar operator +(Kalendar& Kalen2)
    {
        Kalendar t_res;
        t_res.day = day + Kalen2.day;
        t_res.month = month + Kalen2.month;
        t_res.year = year + Kalen2.year;

        if ((t_res.month == 1) || (t_res.month == 3) || (t_res.month == 5) || (t_res.month == 7) ||
            (t_res.month == 8) || (t_res.month == 10))
        {
            while (t_res.day > 31)
            {
                t_res.day -= 31;
                t_res.month++;
            }
        }
        else if (t_res.month == 12)
        {
            while (t_res.day > 31)
            {
                t_res.day -= 31;
                t_res.month = 1;
                t_res.year++;
            }
        }
        else if ((t_res.month == 4) || (t_res.month == 6) || (t_res.month == 9) || (t_res.month == 11))
        {
            while (t_res.day > 30)
            {
                t_res.day -= 30;
                t_res.month++;
            }
        }
        else if ((t_res.month == 2) && (t_res.year % 4 == 0))
        {
            while (t_res.day > 29)
            {
                t_res.day -= 29;
                t_res.month++;
            }
        }
        else if ((t_res.month == 2) && (t_res.year % 4 != 0) && (t_res.year % 100) != 0)
        {
            while (t_res.day > 28)
            {
                t_res.day -= 28;
                t_res.month++;
            }
        }

        return t_res;
    }

    friend istream& operator >>(istream& in, Kalendar& Kalendar);
    friend ostream& operator <<(ostream& out, const Kalendar& Kalendar);
};

istream& operator >>(istream& in, Kalendar& Kalendar)
{
   
    in >> (Kalendar.day);
    in >> (Kalendar.month);
    in >> (Kalendar.year);

    return in;
}

ostream& operator<< (ostream& out, const Kalendar& Kalendar)
{
    
    out << Kalendar.day << "/" << Kalendar.month << "/" << Kalendar.year << endl;

    return out;
}


int main()
{
    system("chcp 1251");
    Kalendar dates[M];
    cout << "Введіть дані по датах: " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << i + 1 << ": ";
        cin >> dates[i];
        cout << "\n";
    }
    cout << endl;
    cout << "Введені вами дані по датах: " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << i + 1 << ": ";
        cout << dates[i];
        cout << "\n";
    }
    Kalendar dates1[M];
    for (int i = 0; i < M; i++)
    {
        dates1[i] = dates[i];
    }
    cout << "\t\t\tТаблиця результатів:" << "\n" << endl;
    dates1[0].BubbleSort(dates);
    for (int i = 0; i < M; i++)
    {
        cout << i + 1 << ":\t\t";
        cout << "Дата: " << dates[i];
        cout << "\t\t";
        cout << "День тижня: ";
        dates[i].NameDayOfWeek();
        cout << "\t\t";
        cout << "\n\t\tНаступна дата: ";
        dates[i].TheNextDateOFThisDay();
        cout << dates[i];
        cout << "\n";
    }

    cout << "Порівняння дат: " << endl;
    for (int j = 0; j < M - 1; j++)
    {
        if (dates1[j] >= dates1[j + 1])
        {
            cout << "День " << dates1[j] << " дати перевищує або дорівнює дню " << dates1[j + 1] << "\n";
        }
        else {
            cout << "День " << dates1[j + 1] << " дати перевищує день " << dates1[j] << "\n";
        }
    }

    Kalendar dates2[M];
    dates2[0].BubbleSort(dates1);

    cout << "Додавання дат: " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << i + 1 << ":\n";
        cout << dates1[i];
        cout << "+ \n";
        cout << dates[i];
        cout << "= \n";
        cout << dates1[i] + dates[i];
        cout << "\n";
    }

    system("pause");
    return 0;
}