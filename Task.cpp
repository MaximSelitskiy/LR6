#include <iostream>
using namespace std;
class Task_1
{
public:
    void Task1(char *stroka, int size)
    {
        int min = 81;
        int raz_slova = 0;
        int number = 0;
        int final_number;
        for (int i = 0; i < size; i++)
        {
            if ((stroka[i] >= 0 && stroka[i] <= 64) || (stroka[i] >= 91 && stroka[i] <= 96) || (stroka[i] >= 123 && stroka[i] <= 127))
            {
                if ((stroka[i + 1] >= 65 && stroka[i + 1] <= 90) || (stroka[i + 1] >= 97 && stroka[i + 1] <= 122))
                {
                    number++;
                    if (raz_slova < min)
                    {
                        min = raz_slova;
                        raz_slova = 0;
                        final_number = number;
                    }
                    raz_slova = 0;
                }
            }
            else
            {
                raz_slova++;
            }
        }
        number++;
        if (raz_slova < min && raz_slova != 0)
        {
            min = raz_slova;
            raz_slova = 0;
            final_number = number;
        }
        raz_slova = 0;
        cout << "Количество символов в наименьшем слове:" << '\n';
        cout << min << '\n';
        cout << "Номер слова:" << '\n';
        cout << final_number;
    }
};
class Task_2
{
public:
    bool probel = false;
    void Task2(char *stroka, int size)
    {
        int j = 0, point_counter = 0;
        char stroka1[1000];
        char predlozhenie[1000];
        for (int i = 0; i < size; i++)
        {
            if (stroka[i] == '.')
            {
                point_counter++;
            }
            if ((stroka[i] >= 65 && stroka[i] <= 90) || (stroka[i] >= 97 && stroka[i] <= 122) || (stroka[i] == '.'))
            {
                if (stroka[i] >= 97 && stroka[i] <= 122)
                {
                    stroka[i] = stroka[i] - 32;
                }
                probel = false;
                stroka1[j] = stroka[i];
                j++;
            }
            if ((stroka[i] >= 0 && stroka[i] <= 64) || (stroka[i] >= 91 && stroka[i] <= 96) || (stroka[i] >= 123 && stroka[i] <= 127))
            {
                if (probel == false && stroka[i] != '.')
                {
                    stroka1[j] = ' ';
                    j++;
                    probel = true;
                }
            }
        }
        int h = 0;
        int predl_count = 0;
        int predl_point = 0;
        for (int y = 0; y < point_counter; y++)
        {
            h = 0;
            if (predl_point != 0)
            {
                predl_point++;
            }
            for (int i = predl_point; i < j; i++)
            {
                if (stroka1[i] == '.')
                {
                    predl_point = i;
                    predlozhenie[h] = stroka1[i];
                    break;
                }
                predlozhenie[h] = stroka1[i];
                h++;
            }
            char slovo[1000];
            int g = 0;
            int count = 0;
            int colvo_sim = 0;
            for (int i = 0; i <= h; i++)
            {
                if ((predlozhenie[i] >= 65 && predlozhenie[i] <= 90) || (predlozhenie[i] >= 97 && predlozhenie[i] <= 122))
                {
                    slovo[g] = predlozhenie[i];
                    g++;
                }
                else
                {
                    for (int j = 0, k = 0; k <= g && j <= h; j++, k++)
                    {
                        if (k == g && predlozhenie[j] != ' ' && predlozhenie[j] != '.')
                        {
                            k = -1;
                            count = 0;
                        }
                        if (predlozhenie[j] == slovo[k])
                        {
                            count++;
                        }
                        if (predlozhenie[j] == ' ' || predlozhenie[j] == '.')
                        {
                            if (count == g)
                            {
                                colvo_sim++;
                            }
                            count = 0;
                            k = -1;
                        }
                    }
                    if (colvo_sim > 1)
                    {
                        count = 0;
                        predl_count++;
                        break;
                    }
                    count = 0;
                    g = 0;
                    colvo_sim = 0;
                }
            }
        }
        cout << predl_count << '\n';
    }
};
class Task_3
{
public:
    int Checker(char *stroka, int size)
    {
        int slova_count = 0;
        int tags_count = 1;
        int check = 1;
        for (int i = 0; i < size; i++)
        {
            if (stroka[i] != '#')
            {
                slova_count++;
            }
            if (stroka[i] == '#')
            {
                int j = i;
                while (stroka[j + 1] == '#' && j + 1 < size)
                {
                    tags_count++;
                    j++;
                }
                i += tags_count;
                if (tags_count > slova_count)
                {
                    check = 0;
                    break;
                }
                tags_count = 0;
                slova_count = 0;
            }
        }
        return check;
    }
    void Task3(char *stroka, int size)
    {
        int counter = 0;
        int positions[80];
        for (int i = 0; i < size; i++)
        {
            if (stroka[i] == '#')
            {
                int j = i;
                counter++;
                while (stroka[j + 1] == '#' && j + 1 < size)
                {
                    counter++;
                    j++;
                }
                for (int k = i; k >= i - counter; k--)
                {
                    stroka[k] = '#';
                }
                counter = 0;
            }
        }
        for (int h = 0; h < size; h++)
        {
            if (stroka[h] != '#')
            {
                // cout << stroka[h];
                cout << stroka[h];
            }
        }
        cout << '\n';
    }
};
int main()
{
    cout << "Введите номер задания,чтобы выполнить его: " << '\n';
    int n;
    cin >> n;
    if (n == 3)
    {
        cin.clear();
        cin.ignore();
        Task_3 task;
        char *stroka = new char[1000];
        int i = 0, size = 0;
        char x;
        int k = 0;
        int isword = 0;
        cout << "Введите строку: " << '\n';
        while (x = getchar())
        {
            if ((x!=' ')&&(x!='\n'))
            {
                isword = 1;
            }
            if (isword == 0)
            {
                cout << "Неверный ввод" << '\n';
                continue;
            }
            if (x == '\n')
            {
                i = 0;
                int ans = task.Checker(stroka, size);
                if (ans == 0)
                {
                    stroka[0] = 'R';
                    cout << "Неверный ввод" << '\n';
                    delete[] stroka;
                    char *stroka = new char[80];
                    continue;
                }
                else
                {
                    break;
                }
            }
            stroka[i] = x;
            i++;
            size++;
        }
        task.Task3(stroka, size);

        delete[] stroka;
        stroka = nullptr;
    }
    if (n == 1)
    {
        cin.clear();
        cin.ignore();
        Task_1 task;
        char *stroka = new char[80];
        int i = 0, size = 0;
        char x;
        bool isword = 0;
        cout << "Введите строку: " << '\n';
        while (x = getchar())
        {
            stroka[i] = x;
            if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
            {
                isword = 1;
            }
            if (x == '\n')
            {
                if (isword == 0)
                {
                    stroka[0] = 'R';
                    cout << "Неверный ввод" << '\n';
                    delete[] stroka;
                    char *stroka = new char[80];
                    continue;
                }
                else
                {
                    break;
                }
            }
            i++;
            size++;
        }
        task.Task1(stroka, size);
        delete[] stroka;
        stroka = nullptr;
    }
    if (n == 2)
    {
        cin.clear();
        cin.ignore();
        Task_2 task;
        char *stroka = new char[1000];
        int i = 0, size = 0;
        char x;
        cout << "Введите строку: " << '\n';
        while (x = getchar())
        {
            if (x == '?' || x == '!')
            {
                x = '.';
            }
            if (x == '\n')
            {
                break;
            }
            stroka[i] = x;
            i++;
            size++;
        }
        task.Task2(stroka, size);

        delete[] stroka;
        stroka = nullptr;
    }
    return 0;
}