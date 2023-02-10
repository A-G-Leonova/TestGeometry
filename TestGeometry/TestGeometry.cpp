// TestGeometry.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "TestGeometry.h"

//ограничения по координатам для центров всех фигур
double dmin = -50.0;
double dmax = 50.0;
//минимальное и максимальное количество фигур
int fimin = 2;
int fimax = 15;




int main()
{
    srand(time(NULL));
    int Kolvo; //количество фигур

    Kolvo = fimin + rand() % (fimax - fimin + 1);
    std::cout << "Amount of figures in the vector: " << Kolvo << "\n";
    

    Figure* pf = nullptr;
    Figure* p2 = nullptr;
    

    vector<Figure*> spisok;
    vector<Figure> sef;

    vector<int> figu;//для создания массива фигур
    vector<int> indi;//для создания массива окружностей
    int i = 0;
    int l = 0;
    //Задание точек через число Пи. Введены отдельные переменные для Пи/4, как в тексте задания, 
    //а также dot как любое число и Пи, с помощью которой можно получать другие дроби для dot
    //Для замены точки, в которой смотрятся значения кривых ипервые производные, необходимо поменять значение dot
    double pi = acos(-1.0);
    double pi_4 = pi / 4.0;
    double dot = pi_4;
    Circle cir = Circle();
    Ellipse eli = Ellipse();
    Helix hel = Helix();

    while(i<Kolvo)
    {
        figu.push_back(1 + rand() % 3); 
        std::cout << "Element number: " << i << " is " << figu[i] << "\n";
        //принято решение, какую именно фигуру мы добавляем следующей: 1 - окружность, 2 - эллипс, 3 - спираль
            switch (figu[i])
            {
            case 1:
                cir = GenerateRandomCircle(dmin, dmax);
                std::cout << "Circle created\n" << cir.GetCenter()[0] << ", " << cir.GetCenter()[1] << ", " << cir.GetCenter()[2] << endl;
                std::cout << "Radius is " << cir.GetRadius() << endl;
                std::cout << "Point at PI/4 is: " << cir.PointPert(dot)[0] << ", ";
                std::cout << cir.PointPert(dot)[1] << ", ";
                std::cout << cir.PointPert(dot)[2] << "\n";
                std::cout << "Derivative at PI/4 is: " << cir.DerivativePert(dot)[0] << ", ";
                std::cout << cir.DerivativePert(dot)[1] << ", ";
                std::cout << cir.DerivativePert(dot)[2] << "\n";
                sef.push_back(cir);
                std::cout << "Circle added\n"<<sef[i].GetCenter()[0] << ", " << sef[i].GetCenter()[1] << ", " << sef[i].GetCenter()[2]<< endl;
                std::cout << endl;
                //считаем количество окружностей для второго массива и запоминаем их места в первом
                l++;
                indi.push_back(i);

                break;
            case 2:
                eli = GenerateRandomEllipse(dmin, dmax);
                std::cout << "Ellipse created\n" << eli.GetCenter()[0] << ", " << eli.GetCenter()[1] << ", " << eli.GetCenter()[2] << endl;
                std::cout << "Radii are " << eli.GetRadius() << ", " << eli.GetRadius2() << endl;
                std::cout << "Point at PI/4 is: " << eli.PointPert(dot)[0] << ", ";
                std::cout << eli.PointPert(dot)[1] << ", ";
                std::cout << eli.PointPert(dot)[2] << "\n";
                std::cout << "Derivative at PI/4 is: " << eli.DerivativePert(dot)[0] << ", ";
                std::cout << eli.DerivativePert(dot)[1] << ", ";
                std::cout << eli.DerivativePert(dot)[2] << "\n";
                sef.push_back(eli);
                std::cout << "Ellipse added\n" << sef[i].GetCenter()[0] << ", " << sef[i].GetCenter()[1] << ", " << sef[i].GetCenter()[2] << endl;
                std::cout << endl;
                break;
            case 3:
                hel = GenerateRandomHelix(dmin, dmax);
                std::cout << "Helix created\n" << hel.GetCenter()[0] << ", " << hel.GetCenter()[1] << ", " << hel.GetCenter()[2] << endl;
                std::cout << "Radius is " << hel.GetRadius() << " and step is " << hel.GetStep() << endl;
                std::cout << "Point at PI/4 is: " << hel.PointPert(dot)[0] << ", ";
                std::cout << hel.PointPert(dot)[1] << ", ";
                std::cout << hel.PointPert(dot)[2] << "\n";
                std::cout << "Derivative at PI/4 is: " << hel.DerivativePert(dot)[0] << ", ";
                std::cout << hel.DerivativePert(dot)[1] << ", ";
                std::cout << hel.DerivativePert(dot)[2] << "\n";
                sef.push_back(hel);
                std::cout << "Helix added\n" << sef[i].GetCenter()[0] << ", " << sef[i].GetCenter()[1] << ", " << sef[i].GetCenter()[2] << endl;
                std::cout << endl;
                break;
            }

         i++;
        

    }

    std::cout << "\n";
    // сумма радиусов всех окружностей
    double sum = 0;

    std::cout << "Amount of circles: " << l << "\n";
    //если в первом массиве нет окружностей, то второй не заполняется ничем
    if (l == 0)
    {
        std::cout << "No circles formed" << endl;
        spisok = { nullptr };
    }
    else
    {
        i = 0;
        while (i < l)
        {
            //Если есть необходимость, можно вывести позиции окружностей в первом массиве, сняв комментарий со строки ниже
            //std::cout << indi[i] << endl;
            pf = &(sef[indi[i]]);
            spisok.push_back(pf);
            i++;
        }
        i = 0;
        //промежуточный вывод несортированного массива для демонстрации сортировки
        while (i < l)
        {
            std::cout << "Circle number " << i << " is " << spisok[i]->GetCenter()[0] << ", " << spisok[i]->GetCenter()[1] << ", " << spisok[i]->GetCenter()[2] << endl;
            std::cout << "Radius is " << spisok[i]->GetRadius() << endl;
            std::cout << endl;
            sum += spisok[i]->GetRadius();//ищем сумму радиусов
            i++;
        }
        i = 0;
        //сортировку проводим, если есть хотя бы два элемента
        if (l == 1)
        {
            std::cout << "As there is only one circle, no need to sort it" << endl;
        }
        else
        {
            for (i = 0; i < l; i++)
            {
                bool flag = true;
                for (int j = 0; j < l - (i + 1); j++)
                {
                    if (spisok[j]->GetRadius() > spisok[j + 1]->GetRadius())
                    {
                        flag = false;
                        p2 = spisok[j];
                        spisok[j] = spisok[j + 1];
                        spisok[j + 1] = p2;
                    }
                }
                if (flag) { break; }
            }//ускоренная пузырьковая сортировка

            i = 0;
            std::cout << "\n" << "Sorted ascending " << endl;
            while (i < l)
            {
                std::cout << "Circle number " << i << " is " << spisok[i]->GetCenter()[0] << ", " << spisok[i]->GetCenter()[1] << ", " << spisok[i]->GetCenter()[2] << endl;
                std::cout << "Radius is " << spisok[i]->GetRadius() << endl;
                std::cout << endl;
                i++;
            }
        }
    }
    std::cout << "\n" << "Total sum of radii is " << sum << endl;
 
    

}


