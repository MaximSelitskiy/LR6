#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#pragma region TASK1
int Task1(char *stroka, int size, int real_min, int real_final_number)
{
    int min = 81;
    int raz_slova = 0;
    int number = 0;
    int final_number;
    bool isword = 0;
    for (int i = 0; i < size; i++)
    {
        if ((stroka[i] >= 0 && stroka[i] <= 64) || (stroka[i] >= 91 && stroka[i] <= 96) || (stroka[i] >= 123 && stroka[i] <= 127))
        {
            isword = 1;
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
    if (isword == 0)
    {
        return 0;
    }
    if (min == real_min && final_number == real_final_number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
TEST(Task_1, Test1)
{
    char *test = new char[80];
    test = {"I like pizza"};
    EXPECT_EQ(Task1(test, 12, 1, 1), 1);
}
TEST(Task_1, KRAEVIYTest2)
{
    char *test = new char[0];
    test = {""};
    EXPECT_EQ(Task1(test, 12, 0, 0), 0);
}
TEST(Task_1, Test3)
{
    char *test = new char[80];
    test = {"I LIKE PANCACKES"};
    EXPECT_EQ(Task1(test, 17, 1, 1), 1);
}
TEST(Task_1, Test4)
{
    char *test = new char[80];
    test = {"If you want to eat-- go and eat"};
    EXPECT_EQ(Task1(test, 32, 2, 1), 1);
}
TEST(Task_1, Test5)
{
    char *test = new char[80];
    test = {"IHIHIHIHIIHI"};
    EXPECT_EQ(Task1(test, 13, 12, 1), 1);
}
TEST(Task_1, Test6)
{
    char *test = new char[80];
    test = {"ihihiihihihhi"};
    EXPECT_EQ(Task1(test, 14, 13, 1), 1);
}
TEST(Task_1, Test7)
{
    char *test = new char[80];
    test = {"ihihiihi.jijiji i"};
    EXPECT_EQ(Task1(test, 18, 1, 3), 1);
}
TEST(Task_1, Test8)
{
    char *test = new char[80];
    test = {"WOW.THIS IS WONDERFUL.how are you"};
    EXPECT_EQ(Task1(test, 34, 2, 3), 1);
}
TEST(Task_1, Test9)
{
    char *test = new char[80];
    test = {"Hello.I.Am.Like.YOU"};
    EXPECT_EQ(Task1(test, 20, 1, 2), 1);
}
TEST(Task_1, KRAEVIYTest10)
{
    char *test = new char[80];
    test = {"ihihiihikkjkjkjkhlkholiohiohohoohohohlihnin'pjopjopopjopjopjopopjjop.Hello.I frt"};
    EXPECT_EQ(Task1(test, 80, 1, 4), 1);
}
#pragma endregion
#pragma region TASK2
int Task2(char *stroka_m, int size, int real_predl_count)
{
    bool probel = false;
    int j = 0, point_counter = 0;
    char stroka[80];
    for (int i = 0; i < size; i++)
    {
        stroka[i] = stroka_m[i];
    }
    char stroka1[80];
    char predlozhenie[80];
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
                char t;
                t = char(stroka[i] - 32);
                stroka[i] = t;
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
        char slovo[80];
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
    if (predl_count == real_predl_count)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 1;
}

TEST(Task_2, Test1)
{
    char *test = new char[80];
    test = {"rm."};
    // cout << Task2(test, 4, 0);
    EXPECT_EQ(Task2(test, 4, 0), 1);
}
TEST(Task_2, Test)
{
    char *test = new char[80];
    test = {"You you."};
    EXPECT_EQ(Task2(test, 10, 1), 1);
}
TEST(Task_2, Test3)
{
    char *test = new char[80];
    test = {"You you.Hello Hello."};
    EXPECT_EQ(Task2(test, 21, 2), 1);
}
TEST(Task_2, Test4)
{
    char *test = new char[80];
    test = {"Like likelike."};
    EXPECT_EQ(Task2(test, 15, 0), 1);
}
TEST(Task_2, Test5)
{
    char *test = new char[80];
    test = {"Like likelike.LikeLike like."};
    EXPECT_EQ(Task2(test, 15, 0), 1);
}
TEST(Task_2, Test6)
{
    char *test = new char[80];
    test = {"I like twerkin"}; // не злитесь на запись в строке,это предложение реально не давало мне покоя два дня
    EXPECT_EQ(Task2(test, 15, 0), 1);
}
TEST(Task_2, Test7)
{
    char *test = new char[80];
    test = {"I want to ask you--how about going to George,George."};
    EXPECT_EQ(Task2(test, 53, 1), 1);
}
TEST(Task_2, Test8)
{
    char *test = new char[80];
    test = {"I want to ask you--how about going to George,George.George."};
    EXPECT_EQ(Task2(test, 53, 1), 1);
}
TEST(Task_2, KRAEVIYTest9)
{
    char *test = new char[110];
    test = {"I want to ask you--how about going to George,George.Lets go go.YFYVIHGYIGFVYIFHVKIHOIHOII UIGUIOGUOGUGUOGOGO."};
    EXPECT_EQ(Task2(test, 110, 2), 1);
}
TEST(Task_2, KRAEVIYTest10)
{
    char *test = new char[58];
    test = {"GO GO.Go gO.go go.GO go.Og Go.HULUMULU HULUMULU.GOd damn."};
    EXPECT_EQ(Task2(test, 58, 5), 1);
}
#pragma endregion
#pragma region TASK3
int Task3(char *stroka, char *right_stroka, int size)
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
    char final_stroka[size];
    int g = 0;
    for (int h = 0; h < size; h++)
    {
        if (stroka[h] != '#')
        {
            final_stroka[g] = stroka[h];
        }
    }
    for (int i = 0; i < g; i++)
    {
        if (final_stroka[i] != right_stroka[i])
        {
            return 0;
        }
    }
    return 1;
}
TEST(Task_3, Test1) 
{
    char test[12]={"rfrgr##hi##"};
    char right_stroka[8]={"rfrhi"};
    EXPECT_EQ(Task3(test,right_stroka, 12), 1);
}
TEST(Task_3, Test2) 
{
    char test[9]={"thgt##r#"};
    char right_stroka[3]={"th"};
    EXPECT_EQ(Task3(test,right_stroka, 9), 1);
}
TEST(Task_3, Test3) 
{
    char test[4]={"rty"};
    char right_stroka[4]={"rty"};
    EXPECT_EQ(Task3(test,right_stroka, 4), 1);
}
TEST(Task_3, Test4) 
{
    char test[17]={"LEST##TSGOHOMM#E"};
    char right_stroka[11]={"LETSGOHOME"};
    EXPECT_EQ(Task3(test,right_stroka, 17), 1);
}
TEST(Task_3, Test5) 
{
    char test[12]={"NONONO####N"};
    char right_stroka[4]={"NON"};
    EXPECT_EQ(Task3(test,right_stroka, 12), 1);
}
TEST(Task_3, Test6) 
{
    char test[17]={"GOOOOOAL########"};
    char right_stroka[1]={""};
    EXPECT_EQ(Task3(test,right_stroka, 17), 1);
}
TEST(Task_3, Test7) 
{
    char test[19]={"T#H#T#T##D#D#D#T#Y"};
    char right_stroka[2]={"Y"};
    EXPECT_EQ(Task3(test,right_stroka, 19), 1);
}
TEST(Task_3, Test8) 
{
    char test[22]={"T#H#T#T##D#D#D#T#&%^#"};
    char right_stroka[3]={"&%"};
    EXPECT_EQ(Task3(test,right_stroka, 22), 1);
}
TEST(Task_3, KRAEVIYTest9) 
{
    char test[13]={"$%$%&&^&%%##"};
    char right_stroka[9]={"$%$%&&^&"};
    EXPECT_EQ(Task3(test,right_stroka, 13), 1);
}
TEST(Task_3, KRAEVIYTest10) 
{
    char test[45]={"$%$%&&^&%%##RUIGGY#$#$#$#$^%&TFGDHCGJF#$##$#"};
    char right_stroka[26]={"$%$%&&^&RUIGG$^%&TFGDHCGJ"};
    EXPECT_EQ(Task3(test,right_stroka, 45), 1);
}
#pragma endregion
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
